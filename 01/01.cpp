#include <iostream>
#include <cstring>

//Задача 1. Адреса

class Adress //Класс Адрес с методами
{
private:
    int cCounterResult = 0;

public:

    int cInitialInitValue = 1;

    int setCounter(int initialInitValue) //Метод инициализации начального значения данных
    {
        cCounterResult = initialInitValue;
        return cCounterResult;
    };

    int getCounter() //Метод просмотра значения элементов данных
    {
        return cCounterResult;
    };

    int counterPlus() //Метод увеличения значения на один
    {
        cCounterResult++;
        return cCounterResult;
    };

    int counterMinus() //Метод уменьшения значения на один
    {
        cCounterResult--;
        return cCounterResult;
    };

};

int main()
{
    setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
    system("chcp 1251");

    //std::string checkInitialInitValue;
    //int initialInitValue = 0;
    //bool checkTrueInitialInitValue = false;
    //Counter counter;

    ////Цикл проверки и задания начального значения счётчика
    //do
    //{
    //    std::cout << std::endl << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    //    std::cin >> checkInitialInitValue;
    //    std::cout << std::endl;

    //    if (checkInitialInitValue == "да" || checkInitialInitValue == "Да")
    //    {
    //        std::cout << "Введите начальное значение счётчика: ";
    //        std::cin >> initialInitValue;

    //        counter.setCounter(initialInitValue);
    //        checkTrueInitialInitValue = true;
    //    }
    //    else if (checkInitialInitValue == "нет" || checkInitialInitValue == "Нет")
    //    {
    //        counter.setCounter(1);
    //        checkTrueInitialInitValue = true;
    //    }
    //    else
    //    {
    //        std::cout << "Вы ввели неверное значение.";
    //    }
    //} while (!checkTrueInitialInitValue);

    //std::cout << std::endl;

    //std::string commandValue;
    //bool checkCommand = false;

    ////Цикл работы счётчика
    //do
    //{
    //    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    //    std::cin >> commandValue;

    //    if (commandValue == "x")
    //    {
    //        std::cout << "Пока.";
    //        checkCommand = true;
    //    }
    //    else if (commandValue == "+")
    //    {
    //        counter.counterPlus();
    //    }
    //    else if (commandValue == "-")
    //    {
    //        counter.counterMinus();
    //    }
    //    else if (commandValue == "=")
    //    {
    //        std::cout << "Значение счетчика: " << counter.getCounter() << "." << std::endl;
    //    }
    //    else
    //    {
    //        std::cout << "Вы ввели неверное значение." << std::endl;
    //    }
    //} while (!checkCommand);
}