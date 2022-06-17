/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include "word_model.h"
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iostream>




void word_model::initialize(string text, int order) {
    _order =order;

//Remove space at back that can be inconsistent --> makes sure everything should work/look the same when read in

    if (text.back()==' '){
        text.pop_back();
    }

//Make text circular

    _data=text;
    istringstream iss (text);
    for (int i=0; i<order; i++){
    string word;
        iss>>word;
    _data=_data+" "+word;
        }

//always ONE space at end of things

_data=_data+" ";




string kgram;
    vector<string> followups;



    int count=0;
    string word;

//Make vector of all the words
//count number of words in data

for (int i=0; i<=_data.size(); i++){
        if (_data[i] != ' '){word=word+_data[i];}
    else{_words.push_back(word);
    count =count+1;
    word.clear();}
}

//Big loop for making map


    for (int i=0; i<count-1; i++) {
        kgram.clear();
        followups.clear();

//Get kgram

        for(int j=i; j<order+i; j++){
           kgram =kgram+_words[j]+" ";
        }

//Put kgram/followups in map


        if (_word_map.find(kgram)==_word_map.end()){
            if(_data[i+order]!='\0'){
                followups.push_back(_words[i+order]);
                    _word_map.insert(pair<string,vector<string>>(kgram,followups));}}
        else{
            if(_data[i+order]!='\0') {
                _word_map[kgram].push_back(_words[i+order]);
            }
        }
}}










string word_model::generate(int size) {
string answer;
answer.reserve(size);
//brute model stuff

    int start = rand() % (_words.size() - _order);
    string seed;

//Slight tweaks to make seed for word_model
//The seed is one string (of k words) hopefully that is an acceptable way of doing it
//I could have made it a vector of (k words) or whatever, making it more
//k-gram-y, but it would've yielded the same result, so i just did it this way......


    for(int i=start; i<_order+start; i++){
        seed=seed+_words[i]+" ";
    }


//loop to make answer text


    for (int i = 0; i < size; i++) {


// find first occurrence of k-gram (seed)
        string most_likely;

        vector<string> followups=_word_map.at(seed);
        most_likely=followups[rand() % followups.size()];
        answer=answer+most_likely+" ";
        int j=0;

//erase first word from seed

        while (seed[0]!=' '){
        seed.erase(seed.begin());
        j++;}
        seed.erase(seed.begin());

//add new generated word too seed

        seed=seed+most_likely+" ";
    }


    return answer;
}
