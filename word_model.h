/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include "model.h"
#include <vector>
#include <map>
using namespace std;

class word_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

  protected:
    int _order;
    string _data;
    map<string, vector<string>> _word_map;
    vector<string> _words;
  };

#endif
