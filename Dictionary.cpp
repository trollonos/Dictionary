//
// Created by TrollOn on 30.03.2020.
//

#include "Dictionary.h"

void Dictionary::find_russian()
{
    read.open(file_name_rus);
    read.clear();

    ++tries_found_words_rus;

    cout << "Enter word in russian to translate: ";
    string find;
    cin >> find;
    find.push_back(' ');

    char first_letter = find[0];

    string buf;
    string buf_2;
    string translate;


    read.seekg(positions_rus[first_letter]);

    while(!read.eof())
    {
        buf.clear();
        buf_2.clear();
        translate.clear();

        getline(read, buf);

        if(first_letter == -7)
        {
            if(read.tellg() >= positions_rus[first_letter + 4])
            {
                break;
            }
        }
        else
        {
            if(read.tellg() >= positions_rus[first_letter + 1])
            {
                break;
            }
        }

        for(auto x: buf)
        {
            if (x == '=')
            {
                break;
            }
            buf_2 = buf_2 + x;
        }

        if (buf_2 == find)
        {
            ++found_words_rus;

            bool ch_eq = false;

            for (auto x: buf)
            {
                if (x == '=')
                {
                    ch_eq = true;
                }
                else
                {
                    if(ch_eq)
                    {
                        translate += x;
                    }
                }
            }

            cout << translate << endl;

            break;

        }
    }

    read.close();
}

void Dictionary::find_english()
{
    read.open(file_name_en);
    if (read.is_open())
    {
        read.clear();

        ++tries_found_words_en;
        bool words_found = false; // та самая булева переменная - нашли ли мы слова, изначальна она ложь - 0

        cout << "Enter word in english to translate: ";
        string find_en;
        cin >> find_en;

        string find = " ";
        find = find_en;
        find += " ";

        string buf;
        string buf_2;
        string translate;

        read.seekg(positions_en[find_en[0]]);

        while (!read.eof())
        {

            getline(read, buf);
            if(read.tellg() >= positions_en[find_en[0] + 1])
            {
                break;
            }
            if (buf.find(find) != string::npos)
            {
                //cout << "found" << endl;
                cout << buf << endl;
                //++found_words_en; //теперь это не нужно - раньше счетчик найденных слов увеличивался кадлый раз с найденным словом
                words_found = true; //если нашли только один раз, то переменная станет true, даже если нашли больше одного раза, то все равно останется true
                //break;
            }
        }
        if (words_found) // если переменная оказалась true - значит что-то нашли (без разницы, сколько раз)
        {
            ++found_words_en; // тогда увеличиваем число удачной попытки поиска
        }
    }
    else
    {
        cout << "Error" << endl;
    }

    read.close();
}

void Dictionary::write_word()
{
    ++tries_written_words;

    cout << "Enter word in russian: ";
    string rus;
    cin >> rus;
    string rus_buf = rus;
    rus_buf.push_back(' ');

    char first_letter = rus[0];

    cout << "Enter word in english: ";
    string en;
    cin >> en;
    string en_buf = " ";
    en_buf += en;
    en_buf += ".";

    string buf;
    bool not_found = true;

    //ifstream try_find("rus_en.txt");
    read.open(file_name_rus);
    if(!read.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        read.clear();
        read.seekg(positions_rus[first_letter]);

        while(!read.eof())
        {
            buf.clear();
            getline(read, buf);
            if(first_letter == -7)
            {
                if(read.tellg() >= positions_rus[first_letter + 4])
                {
                    break;
                }
            }
            else
            {
                if(read.tellg() >= positions_rus[first_letter + 1])
                {
                    break;
                }
            }
            if((buf.find(rus_buf) != string::npos) || (buf.find(en_buf) != string::npos))
            {
                not_found = false;
                break;
            }
        }
        read.close();

        if(not_found)
        {
            ++written_words;

            string word = rus;
            word += " = ";
            word += en;
            word += ".";

            write.open(file_name_rus, ios::in | ios::out);
            if (!write.is_open())
            {
                cout << "Error" << endl;
            }
            else
            {
                write.clear();
                write.seekp(positions_rus[first_letter]);
                vector<string> file_part;
                string line;
                while(!write.eof())
                {
                    getline(write, line);
                    file_part.push_back(line);
                }
                write.close();
                write.open(file_name_rus, ios::in | ios::out);

                write.clear();
                write.seekp(positions_rus[first_letter]);
                write << word << endl;
                for(string l: file_part)
                {
                    write << l;
                }
                write.close();

                set_positions_rus(file_name_rus);
            }
        }
    }

}

void Dictionary::write_menu()
{
    cout << "To continue, select the command.\n";
    cout << "1. Translation from Russian to English.\n";
    cout << "2. Translation from English to Russian.\n";
    cout << "3. Add a new word to dictionary.\n";
    cout << "4. Current statistics.\n";
    cout << "5. Back to main menu.\n";
}

Dictionary::Dictionary()
{
    cout << "Welcome to the Russian-English dictionary!\n";

    set_positions_rus(file_name_rus);
    set_positions_en(file_name_en);
}

int Dictionary::get_choice()
{
    return choice;
}


int Dictionary::set_choice()
{
    cin >> choice;
    return choice;
}

Dictionary::~Dictionary()
{
    cout << "Thank you for using the program!\n";
}

void Dictionary::set_positions_rus(string file_name)
{
    read.open(file_name);
    if(!read.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        read.clear();
        //map <char, streampos> alph;
        streampos sp1 = 0;
        streampos sp2 = 0;
        char letter = 'а';
        string buf;
        while(!read.eof())
        {
            getline(read, buf);
            sp1 = sp2;
            sp2 = read.tellg();
            if (buf.find('=') != string::npos)
            {
                if (buf[0] == letter)
                {
                    //alph[letter] = bytes - buf.size();
                    positions_rus[letter] = sp1;
                    if (letter == 'щ')
                    {
                        letter = 'э';
                    }
                    else
                    {
                        ++letter;
                    }
                }
            }
        }
        read.clear();
        read.close();
        //return alph;
    }
}

void Dictionary::set_positions_en(string file_name)
{
    read.open(file_name);
    if(!read.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        read.clear();
        //map <char, streampos> alph;
        streampos sp1 = 0;
        streampos sp2 = 0;
        char letter = 'a';
        string buf;
        while(!read.eof())
        {
            getline(read, buf);
            sp1 = sp2;
            sp2 = read.tellg();
            //if ((buf[0] = ' ') && ((buf[1] = ' ')) && ((buf[2] = ' ')))
            if (buf.find("   ") != string::npos)
            {
                if (buf[3] == letter)
                {
                    //alph[letter] = bytes - buf.size();
                    positions_en[letter] = sp1;
                    ++letter;
                }
            }
        }
        read.clear();
        read.close();
    }
}

void Dictionary::statistics()
{
    cout << "Words tried to find in russian: " << tries_found_words_rus << endl;
    cout << "Words found in russian: " << found_words_rus << endl;

    cout << "Words tried to find in english: " << tries_found_words_en << endl;
    cout << "Words found in english: " << found_words_en << endl;

    cout << "Words tried to write: " << tries_written_words << endl;
    cout << "Words written: " << written_words << endl;

    double tries = tries_found_words_rus + tries_found_words_en + tries_written_words;
    double success = found_words_en + found_words_rus + written_words;

    if(tries != 0)
    {
        cout << "Your success rate: ";
        cout << (success / tries) * 100.0 << "%" << endl;
    }
    else
    {
       cout << "Please, do any tries!" << endl;
    }
}
