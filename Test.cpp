//
// Created by User on 10.05.2020.
//

#include "Test.h"

void Test::RusEn(int k, int p, string aim)
{
    read.open(file_test_rus);
    if(read.is_open())
    {
        //setlocale(LC_ALL, "rus.1251");
        char mass[len][strings];
        if (aim == "No")
        {
            for (int n = 0; n < strings; n++)
            {
                read.getline(mass[n], len - 1, ch); //Считываем строки в массив
                if (n >= k && n <= p)
                {
                    cout << mass[n] << endl; //Выводим строку из массива
                }
            }
        }
        else if (aim == "Yes")
        {
            for (int n = 0; n < strings; n++)
            {
                read.getline(mass[n], len - 1, ch); //Считываем строки в массив
                if (n == k)
                {
                    cout << mass[n] << endl;
                }
                if (n >= k && n <= p - 1)
                {
                    read >> word; //Считываем слово
                    cout << word << ' ';
                    read >> word1;
                    cin >> answer;

                    if (answer == word1)
                        cout << "+" << endl;
                    else
                        cout << "-" << endl;
                }
            }
        }
        read.close();
    }
    else
    {
        cout << "Error." << endl;
    }
}

void Test::EnRus(int m, int r, string aim)
{
    read.open(file_test_en);
    if(read.is_open())
    {
        //setlocale(LC_ALL, "rus.1251");
        char mass[len][strings];
        if (aim == "No")
        {
            for (int n = 0; n < strings; n++)
            {
                read.getline(mass[n], len - 1, ch); //Считываем строки в массив
                if (n >= m && n <= r)
                {
                    cout << mass[n] << endl; //Выводи строку из массива
                }
            }
        }
        else if (aim == "Yes")
        {
            for (int n = 0; n < strings; n++)
            {
                read.getline(mass[n], len - 1, ch); //Считываем строки в массив
                if (n == m)
                    cout << mass[n] << endl;
                if (n >= m && n <= r - 1)
                {
                    read >> word; //Считываем слово
                    cout << word << ' ';
                    read >> word1;
                    cin >> answer;

                    if (answer == word1)
                        cout << "+" << endl;
                    else
                        cout << "-" << endl;
                }
            }
        }
        read.close();
    }
    else
    {
        cout << "Error." << endl;
    }
}

void Test::menu()
{
    cout << "Enter type of test: (RE/ER)" << endl;
    cin >> type;
    cout << "Select the topic: All, Fruits, Vegetables, Sports, Clothes, Colors" << endl;
    cin >> group;
    cout << "Do you want to test your knowledge? (Yes/No)" << endl;
    cin >> aim;
    if (type == "ER")
    {
        if (group == "All")
        {
            EnRus(0, 88, aim);
        }
        if (group == "Fruits")
        {
            EnRus(0, 26, aim);
        }
        if (group == "Sports")
        {
            EnRus(27, 36, aim);
        }
        if (group == "Colors")
        {
            EnRus(37, 49, aim);
        }
        if (group == "Vegetables")
        {
            EnRus(50, 64, aim);
        }
        if (group == "Clothes")
        {
            EnRus(65, 88, aim);
        }
    }
    else if (type == "RE")
    {
        if (group == "All")
        {
            RusEn(0, 88, aim);
        }
        if (group == "Fruits")
        {
            RusEn(0, 26, aim);
        }
        if (group == "Sports")
        {
            RusEn(27, 36, aim);
        }
        if (group == "Colors")
        {
            RusEn(37, 49, aim);
        }
        if (group == "Vegetables")
        {
            RusEn(50, 64, aim);
        }
        if (group == "Clothes")
        {
            RusEn(65, 88, aim);
        }
    }
    else cout << "Incorrect type." << endl;
}

void Test::LearnAndTest(string type, int m, int r, string aim)
{
    if (type == "ER")
        path = "structwordsER.txt";
    if (type == "RE")
        path = "structwordsRE.txt";
    ifstream fin(path);
    system("chcp 1251 > nul");
    const char ch = '\n';
    const int len = 200;
    const int strings = 88;
    string word, word1, answer;
    int w = 0;
    char mass[len][strings];
    if (!fin.is_open())
    {
        cout << "ошибка" << endl;
    }
    if (aim == "No")
        for (int n = 0; n < strings; n++)
        {
            fin.getline(mass[n], len - 1, ch); //Считываем строки в массив
            if (n >= m && n <= r)
                cout << mass[n] << endl; //Выводи строку из массива
        }
    if (aim == "Yes")
        for (int n = 0; n < strings; n++)
        {
            fin.getline(mass[n], len - 1, ch); //Считываем строки в массив
            if (n == m)
                cout << mass[n] << endl;
            if (n >= m && n <= r - 1)
            {
                setlocale(LC_ALL, "Russian");
                fin >> word; //Считываем слово
                cout << word << ' ';
                fin >> word1;
                cin >> answer;
                word1.c_str();
                answer.c_str();
                int p = word1.length();
                int c = answer.length();
                for (int i = 0; i < c; i++)
                    answer[i] = toupper(answer[i]);
                for (int i = 0; i < p; i++)
                    word1[i] = toupper(word1[i]);
                if (answer == word1)
                {
                    cout << "+" << endl;
                    w++;
                }
                else
                    cout << "-" << endl;
            }
        }
    cout << "Your result:" << w << "/" << (r - m) << endl;
    fin.close(); //Закрываем файл
}