#include <iostream>
#include <compare>
#include <regex>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include "Massa.h"
#include "Radiation_frequency.h"
#include "Temperature.h"
#include "Wave_length.h"
#include "Energy.h"

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '(' || c == ')')
/*Классы физических величин: масса, энергия, длина волны, частота излучения,
температура, мощность излучения.
Определить для них операторы сложения (+) и вычитания (-) с учетом
физического смысла.
Для каждого класса определить литералы для обозначения размерности:
масса – kg, энергия – J, длина волны – m, частота излучения – Hz,
температура – K, мощность излучения – W.
Для массы и энергии определить взаимнооднозначные операторы преобразования
по формуле E=mc2
, также определить операторы преобразования энергии к
частоте, и частоты к длине волны
*/


std::string result(std::string arg) {
    std::cmatch res;
    std::string s1, s2;
    std::regex reg("([A-Za-z])+");
    auto words_begin = std::sregex_iterator(arg.begin(), arg.end(), reg);
    auto words_end = std::sregex_iterator();
    s1 = (*words_begin).str();
    for (auto i = words_begin; i != words_end; i++)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        s2 = match_str;
        if (s1 != s2) throw std::invalid_argument("Different data");
    }
    arg = std::regex_replace(arg.c_str(), std::regex("([A-Za-z])+"), "");
    return s1;
}


const std::string NAME_FILE = "text.txt";

void second() {
    setlocale(LC_ALL, "Russian");
    std::ifstream fin(NAME_FILE);
    std::string input;
    std::getline(fin, input);
    std::getline(fin, input);
    std::cout << input << std::endl;
    std::regex r("жы");
    std::string out = std::regex_replace(input, r, "жи");
    r = std::regex("шы");
    out = std::regex_replace(out, r, "ши");
    r = std::regex("чю");
    out = std::regex_replace(out, r, "чу");
    r = std::regex("щю");
    out = std::regex_replace(out, r, "щу");
    r = std::regex("чя");
    out = std::regex_replace(out, r, "ча");
    r = std::regex("щя");
    out = std::regex_replace(out, r, "ща");
    std::cout << out << std::endl;
    fin.close();
}
int op_preced(const char c)
{
    switch (c)
    {
   

    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    }
    return 0;
}

void one() {
    std::ifstream fin(NAME_FILE);
    std::string input;
    std::getline(fin, input);

    std::regex words_regex("(\\d*[,.]{0,1}\\d+)|([+*\\/\\-])|(\\()|(\\))");
    std::string suffix;
    try
    {
        suffix = result(input);
    }
    catch (const std::exception&)
    {
        cout << "bad expression" << endl;
        fin.close();
        return ;
    }
    auto words_begin =
        std::sregex_iterator(input.begin(), input.end(), words_regex);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
        << std::distance(words_begin, words_end)
        << " words:\n";
    vector<string> reverse_dance_polish_cow;
    {
        stack <char> steck;
        while (words_begin != words_end) {
            auto something = words_begin->str();
            if (something.length() == 1) {
                if (is_operator(something[0])) {
                    if (something[0] == '(') {
                        steck.push(something[0]);
                    }
                    else if (something[0] == ')') {
                        bool pe = false;

                        while (!steck.empty()) {
                            char c = steck.top();
                            if (c == '(') {
                                pe = true;
                                steck.pop();
                                continue;
                            }
                            string str;
                            str.push_back(c);
                            reverse_dance_polish_cow.push_back(str);
                            steck.pop();
                        }
                        if (!pe) {

                            throw invalid_argument("no (");
                        }

                    }
                    else if (op_preced(something[0]) == 3) {
                        steck.push(something[0]);
                    }
                    else if (op_preced(something[0]) == 2) {

                        if (!steck.empty() && (steck.top() == '(')) {
                            steck.push(something[0]);
                        }
                        else {
                            while (!steck.empty())
                            {
                                if (steck.top() == '(') break;
                                reverse_dance_polish_cow.push_back(std::string(1, steck.top()));
                                steck.pop();
                            }
                            steck.push(something[0]);
                        }
                    }
                }
                else {
                    reverse_dance_polish_cow.push_back(something);
                }
            }
            else {
                reverse_dance_polish_cow.push_back(something);
            }


            ++words_begin;
        }

        while (!steck.empty())
        {
            reverse_dance_polish_cow.push_back(std::string(1, steck.top()));
            steck.pop();
        }
        for (auto item : reverse_dance_polish_cow) {
            cout << item << endl;
        }
        int count = 0;
        for (auto i : reverse_dance_polish_cow) {
            if (is_operator(i[0])) count++;
        }
        if (count != reverse_dance_polish_cow.size() / 2) {
            cout << "bad expression" << endl;
            fin.close();
            return;
        }
    }

    stack<double> steck;
    for (auto i : reverse_dance_polish_cow) {
        if (is_operator(i[0])) {
            if (steck.size()<2) {
                cout << "bad expression" << endl;
                fin.close();
                return;
            }
            double x = steck.top();
            steck.pop();
            double y= steck.top();
            steck.pop();
            switch (i[0])
            {
            case '*':
                steck.push(x * y);
                break;
            case '/':
                steck.push( y/x);
                break;
            case '+':
                steck.push(x + y);
                break;
            case '-':
                steck.push( y-x);
                break;
            }
        }
        else {
            steck.push(stod(i));
        }
    }
    cout << steck.top();


    fin.close();
}

int main()
{
    one();


}