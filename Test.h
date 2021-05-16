//
// Created by User on 10.05.2020.
//
#pragma once
#ifndef COURSEWORKDICTIONARY_TEST_H
#define COURSEWORKDICTIONARY_TEST_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <clocale>

using namespace std;

class Test
{
    const string file_test_rus = "structwordsRE.txt";
    const string file_test_en  = "structwordsER.txt";

    string path;

    ifstream read;

    const char ch = '\n';
    const int len = 200;
    const int strings = 88;
    string word, word1, answer;
    //char mass[200][88];

    string type;
    string group;
    string aim;

public:

    void RusEn(int, int, string);
    void EnRus(int, int, string);

    void LearnAndTest(string type, int m, int r, string aim);

    void menu();
};


#endif //COURSEWORKDICTIONARY_TEST_H
