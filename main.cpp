#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"
#include "Test.h"

using namespace std;

void total_menu(Dictionary &dict, Test &test)
{
    int ch;

    do
    {
        cout << "Select action:" << endl << "1. Translation" << endl << "2. Tests." << endl << "3. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                do
                {
                    dict.write_menu();
                    dict.set_choice();
                    switch (dict.get_choice())
                    {
                        case 1:
                        {
                            dict.find_russian();
                            break;
                        }
                        case 2:
                        {
                            dict.find_english();
                            break;
                        }
                        case 3:
                        {
                            dict.write_word();
                            break;
                        }
                        case 4:
                        {
                            dict.statistics();
                            break;
                        }
                        case 5:
                        {
                            break;
                        }
                        default:
                        {
                            cout << "Please, enter the correct command.\n";
                            break;
                        }
                    }
                } while (dict.get_choice() != 5);

                break;
            }
            case 2:
            {
                test.menu();
                break;
            }

            case 3:
            {
                break;
            }

            default:
            {
                cout << "Please, enter the correct command.\n";
                break;
            };
        }
    }
    while (ch != 3);
}

int main()
{
    system("chcp 1251>nul");

    Dictionary my_dict;
    Test my_test;

    total_menu(my_dict, my_test);

    return 0;
}