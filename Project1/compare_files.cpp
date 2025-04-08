//Дано два текстовых файла.Выяснить, совпадают ли их строки.Если нет, то вывести несовпадающую строку из каждого файла.
// 
// compare_files.cpp
#include "compare_files.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string file1 = "E:\\С++\\30.03.2025\\Project1\\file1.txt";
    std::string file2 = "E:\\С++\\30.03.2025\\Project1\\file2.txt";

    compareFiles(file1, file2);
    return 0;
}


void compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream inFile1(file1), inFile2(file2);

    if (!inFile1 || !inFile2) {
        std::cerr << "Ошибка открытия файлов!" << std::endl;
        return;
    }

    std::string line1, line2;
    int lineNum = 1;
    bool filesMatch = true;

    while (std::getline(inFile1, line1) && std::getline(inFile2, line2)) {
        if (line1 != line2) {
            std::cout << "Строка " << lineNum << " не совпадает:" << std::endl;
            std::cout << "Файл 1: " << line1 << std::endl;
            std::cout << "Файл 2: " << line2 << std::endl;
            filesMatch = false;
        }
        lineNum++;
    }

    while (std::getline(inFile1, line1)) {
        std::cout << "Дополнительная строка в файле 1 (" << lineNum << "): " << line1 << std::endl;
        filesMatch = false;
        lineNum++;
    }

    while (std::getline(inFile2, line2)) {
        std::cout << "Дополнительная строка в файле 2 (" << lineNum << "): " << line2 << std::endl;
        filesMatch = false;
        lineNum++;
    }

    if (filesMatch) {
        std::cout << "Файлы полностью совпадают." << std::endl;
    }
}