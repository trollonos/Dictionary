//
// Created by TrollOn on 30.03.2020.
//
#pragma once
#ifndef COURSEWORKDICTIONARY_DICTIONARY_H
#define COURSEWORKDICTIONARY_DICTIONARY_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class Dictionary
{
private:
    const string file_name_rus = "rus_en.txt";
    const string file_name_en = "en_rus.txt";

    ifstream read;
    fstream write;

    int choice;

    int found_words_rus = 0;
    int tries_found_words_rus = 0;

    int found_words_en = 0;
    int tries_found_words_en = 0;

    int written_words = 0;
    int tries_written_words = 0;

    map<char, streampos> positions_rus;
    map<char, streampos> positions_en;

public:

    Dictionary();
    ~Dictionary();

    void find_russian();
    void find_english();

    void write_word();

    void write_menu();

    int get_choice();
    int set_choice();

    void statistics();

    void set_positions_rus(string);
    void set_positions_en(string);
};


#endif //COURSEWORKDICTIONARY_DICTIONARY_H
