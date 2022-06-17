/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include <string>
#include <map>
#include "model.h"
#include <vector>
using namespace std;

class map_model : public markov_model {
public:
    virtual void initialize(string text, int order);
    virtual string generate(int size);

protected:
    string _data;
    map<string, vector<char>> _char_map;
    int _order;

};

#endif
