//
//  main.cpp
//  lab2
//
//  Created by Alexander Chernyi on 13/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <string>
#include "Tokenizer.h"

/*
 Разработать программу, которая должна сделать следующее:
 1.    Прочитать содержимое текстового файла. Файл может содержать:
     a.    Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
     b.    Знаки препинания – «.», «,» «!» «?» «:» «;»
     c.    Пробельные символы – пробел, табуляция, символ новой строки.
 
 2.    Отформатировать текст следующим образом:
     a.    Не должно быть  пробельных символов отличных от пробела
     b.    Не должно идти подряд более одного пробела
     c.    Между словом и знаком препинания не должно быть пробела
     d.    После знака препинания всегда должен идти пробел
     e.    Слова длиной более 10 символов заменяются на слово «Vau!!!»
 
 3.    Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно целиком находиться в строке) и ее длинна не превышает 40 символов.

 */

string formattedStringFromTokens(vector<Token> tokens) {
    string str;
    
    // Счетчик количества символово в строке
    int counter = 0;
    
    for (auto it = tokens.begin(); it != tokens.end(); it++) {
        
        // Если длина строки превышает 40 символов – переходим на новую строку
        if ((*it).value.size() + counter > 40) {
            str += "\n";
            counter = 0;
        }
        
        if ((*it).value.size() < 10) {
            str += (*it).value;
            counter += (*it).value.size();
        } else {
            const string wow = "Vau!!!";
            str += wow;
            counter += wow.size();
        }
        
        if ((*it).kind == WORD && (*next(it, 1)).kind == PUNCTUATION) {
            continue;
            
        }
        
        if ((*it).kind == WORD || (*it).kind == PUNCTUATION) {
            str += " ";
            counter++;
        }
    }
    
    return str;
}

int main(int argc, const char * argv[]) {

    ifstream file;
    file.open("main.cpp");
    
    if (!file) {
        cerr << "Error reading file" << endl;
        return 1;
    }
    
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    Tokenizer tokenizer;
    auto tokens = tokenizer.tokenize(data);

    auto resultString = formattedStringFromTokens(tokens);
    cout << resultString << endl;
    
    return 0;
}
