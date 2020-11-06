// class_string.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "String.h"

int main()
{    
    String f = String("meoww");
    String d = String("catsays");
    std::cout << f.length() << "\n";
    std::cout << f.c_str() << "\n";
    std::cout << f.countChar('w') << "\n";
    std::cout << f.findFirstOf('w') << "\n";
    std::cout << f[2] << "\n";
    String* result = d.split(3);
    std::cout << result[0].c_str() << "\n" << result[1].c_str() << "\n";
    String a = f + d;
    std::cout << a.c_str() << "\n";
    char* p = new char[10];
    std::cin >> p;
    std::cout << d.findstr(p) << "\n";    
}
