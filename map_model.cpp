/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include "map_model.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;



void map_model::initialize(string text, int order) {
    _order=order;

//remove space from the back, cause it was causing problems

    if (text.back()==' '){
text.pop_back();
    }


//simulate circular (from brute model)

    _data = text+text.substr(0, order);

//loop for making the map

      for (int j=0; j<_data.size()-2;j++){
string kgram;
kgram.clear();
vector<char> followups;
followups.clear();

//get kgram

        for(int k=j; k<order+j;k++){
            kgram=kgram+_data[k];
        }

//get followup character and put in map

        if (_char_map.find(kgram)==_char_map.end()){
            if(_data[j+order]!='\0'){
            followups.push_back(_data[j+order]);
_char_map.insert(pair<string,vector<char>>(kgram,followups));}}

//if kgram already in map, push_back another followup character

        else{
            if(_data[j+order]!='\0'){
_char_map[kgram].push_back(_data[j+order]);}
        }
    }
}






string map_model::generate(int size) {

//starting stuff (taken from brute model)

    int start = rand() % (_data.length() - _order);
    string seed = _data.substr(start, _order);


    string answer;
    answer.reserve(size);


    for (int i = 0; i < size; i++) {


        // find first occurrence of k-gram (seed)
       char most_likely;

//This is pretty much just brute model stuff


       vector<char> followups=_char_map.at(seed);
       most_likely=followups[rand() % followups.size()];
       answer.push_back(most_likely);
        seed = seed.substr(1)+most_likely;}

return answer;}
