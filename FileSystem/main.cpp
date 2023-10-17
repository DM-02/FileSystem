//
//  main.cpp
//  FileSystem
//
//  Created by Дмитрий Сергеевич on 17.10.2023.
//

#include <iostream>
#include <string>
#include <fstream> // Библиотека, описывающая классы для работы с файловой ситстемой устройства

const char stat_path[] = "stats.txt";

bool statistic(const std::string str) {
    std::ofstream out;
    out.open(stat_path, std::ios::app);
    if (out.is_open()) {
        out << str << ' ' << str.length() << '\n';
        out.close();
        return true;
    }
    return false;
}

void print_file() {
    static std::ifstream in;
    in.open(stat_path);
    
    if(in.is_open()) {
        char sym;
        while (in.get(sym))
            std::cout << sym;
        std::cout << std::endl;
        in.close();
    }
}


bool clear(){
    static std::ofstream out;
    out.open(stat_path);
    
    if(out.is_open()) {
        out.close();
        return true;
    }
    return false;
}



int main(int argc, const char * argv[]) {
    setlocale (LC_ALL, "RU");
    std::string path = "file.txt";
    
    
    // Класс ofstream
    /*std::ofstream out;// создание объекта для записи в файл
   // out.open(path); //Открытие файла с режимом по умолчанию std::ios::out
    out.open(path, std::ios::app); // открытие файла для бовления записи в конец файла
    
    
    if (out. is_open()){
        std::cout << "Файл открыт для записи.\n";
        std::string msg;
        std::cout << "Введите сообщение ->";
        std::getline(std::cin, msg);
        out << msg; // Добавление строки в файл
    }
    else
        std::cout << "Ошибка открытия файла.\n";
    
    out.close();
    
    
    //Возможные причины ошибки при открытии файла c помощью ofstream;
    //1. Нет доступа к файлу;
    //2. Некоректный путь к файлу*/
    
    
    //Класс ifstream
    //std::ifstream in;
    //in.open(path);
    
    //if (in.is_open()) {
      //  std::cout << "Содержимое файла:\n";
        //std::string file;
        // 1 .Посимвольное счтывание
        //char sym;
        //while (in.get(sym))
           // file += sym;
        //std::cout << file << std::endl;
        // 2. Пословное считывание
        //while (!in.eof()) {
            //std::string str;
            //in >> str;
            //file += str + '\n';
        //}
        //std::cout << file << std::endl;
        // 3. Построчное считывание
        //std::string str;
        //while (std::getline (in,str))
          //  file += str + '\n';
        //std::cout << file;
    //}
    //else
       // std::cout << "Ошибка открытия файла. \n";
        
    //in.close();
    
    // Возможные причины ошибки при открытии файла с помощью ifstream:
    //1. Файла не существует;
    //2. Некоректный путь к файлу;
    //3. Нет доступа к файлу;
    
    //Удаление файла
       // remove(path.c_str()); // простой вариант
    /*if (remove(path.c_str()) == 0)
        std::cout << "Файл удален.\n";
    else
        std::cout << "Ошибка удаления файла.\n";
    
    //Возмлжны причины ошибки при удалении файла:
    // 1. Файла не сущесвует;
    // 2. Нет доступа к файлу;
    // 3. Файл открыт;
    // 4. Некоректный путь к файлу.*/
    
    //task 1. Статистика
    std::cout << "Задача 1.\nВведите строку";
    std::string str1;
    std::getline(std::cin, str1);
    if (statistic(str1))
        std::cout << "Запись добавлена в файл.\n\n";
    else
        std::cout << "Ошибка!\n\n";
    
    
    //task2. Дополнение к задаче 1
    
    
    
    
    return 0;
}
