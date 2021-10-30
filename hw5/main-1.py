import os
import subprocess

grade_per_test = 10

#Change your path here before testing
base_path_assignment5 = "/Users/kinchang/Documents/SJSU/CMPE 180A/cmpe180a-hws/hw5"


def create_dummy_files(path):
    os.chdir(path)
    f = open("case1.txt", "a")
    f.write("This is a test case file to copy assignment 5")
    f.close()


def print_result(return_code, message, total_grade, expected_type):
    case = return_code == 0 if expected_type == 0 else return_code != 0
    if case:
        print(message, ' Succeeded!')
        return grade_per_test
    else:
        print(message, ' Failed!')
        return 0


def compile_and_run(path):
    os.chdir(path)
    for file in os.listdir(path):
        if (file.endswith(".cc") or file.endswith(".cpp") or file.endswith(".C") or file.endswith(
                ".c++")):
            print("Testing for :", file)
            p1 = subprocess.run(["g++", file, "-o", "output.out"],
                                capture_output=True, text=True)
            # printing the return code
            print("Exit status  : " + str(p1.returncode))
            if p1.returncode == 0:
                total_grade = 0
                # case 1
                tmp = subprocess.run(["./output.out", "-s", "case1.txt", "-t", "copy1.txt"],
                                     stdout=subprocess.PIPE, text=True)
                total_grade += print_result(tmp.returncode, "Test01 : Copying single file ", total_grade, 0)

                tmp = subprocess.run(["./output.out", "-s", "case1.txt", "-t", "copy2.txt", "-t", "copy3.txt"],
                                     stdout=subprocess.PIPE, text=True)
                total_grade += print_result(tmp.returncode, "Test02 : Copying single file to two valid targets",
                                            total_grade, 0)

                tmp = subprocess.run(["./output.out", "-s", "case1.txt", "-t", "copy4.txt", "-t", "copy4.txt"],
                                     stdout=subprocess.PIPE, text=True)

                total_grade += print_result(tmp.returncode, "Test03 : Copying single file to two same targets",
                                            total_grade, 1)

                print('Total Grade : ', total_grade)

                # deleting files
                os.remove('output.out')
                os.remove('case1.txt')
                os.remove('copy1.txt')
                os.remove('copy2.txt')
                os.remove('copy3.txt')
            else:
                print('Grade        : 0')


create_dummy_files(base_path_assignment5)
compile_and_run(base_path_assignment5)
