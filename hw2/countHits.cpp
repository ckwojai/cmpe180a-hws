#include "countHits.h"

int countHits(vector<Asteroid> a){
    vector<Asteroid> ast_hits;
    for (auto i=0; i < a.size(); i++) {
        Asteroid asti = a.at(i);
        if (asti.d == right) {
            ast_hits.push_back(asti);
        }
        if (asti.d == left) {
            for (auto j=0; j < ast_hits.size(); j++) {
                if (asti.m >= ast_hits.at(j).m) {
                    ast_hits.erase(ast_hits.begin() + j);  // can erase (destroy) since we don't need it anymore 
                }
            }
        }
    }
    return ast_hits.size();
}