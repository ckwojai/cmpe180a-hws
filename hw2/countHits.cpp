#include "countHits.h"
#include <iostream>


int countHits(vector<Asteroid> a){
    vector<Asteroid> ast_hits;
    for (int i=0; i < a.size(); i++) {
        Asteroid asti = a.at(i);
        if (asti.d == Right) {
            ast_hits.push_back(asti);
        }
        if (asti.d == Left) {
            for (int j=ast_hits.size()-1; j >= 0; j--) {  // iterate from right to left
                if (asti.m == ast_hits.at(j).m) {
                    // same mass asteroids cancel each other
                    ast_hits.erase(ast_hits.begin() + j);  // can erase (destroy) since we don't need it anymore
                    break; // effectively remove asti
                }
                if (asti.m < ast_hits.at(j).m) { // asteroid going left got destroyed by the right
                   break;
                }
                if (asti.m > ast_hits.at(j).m) {
                    ast_hits.erase(ast_hits.begin() + j);  // can erase (destroy) since we don't need it anymore 
                }
            }
        }
    }
    return ast_hits.size();
}
