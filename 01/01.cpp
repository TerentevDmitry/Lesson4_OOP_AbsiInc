#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

//Задача 1. Адреса

class Adress //Класс Адрес с методами
{
private:
    std::string NameCity_;
    std::string NameStreet_;
    int NumberHouse_ = 0;
    int NumberApartment_ = 0;
    std::string FullAdress_;

public:
    // Конструктор
    Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
    {
        NameCity_ = NameCity;
        NameStreet_ = NameStreet;
        NumberHouse_ = NumberHouse;
        NumberApartment_ = NumberApartment;
    }

    // Метод создания строки полного адреса для вывода
    std::string createAdress2Out()
    {
        FullAdress_ = NameCity_ + ", " + NameStreet_ + ", " + std::to_string(NumberHouse_)
                       + ", " + std::to_string(NumberApartment_);
        return FullAdress_;
    };
};

enum class codeCommit
{
    fileInOpenError, fileOutOpenError
};

//Функция печати массива в файл
int printArrayForClassObjects(std::string* arrayForClassObjects, const int quantityAdresses)
{
    std::ofstream fileOut("out.txt", std::ios_base::trunc);

    if (fileOut.is_open())
    {
        std::cout << "Файл out.txt успешно открыт." << std::endl;
    }
    else
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return static_cast<int>(codeCommit::fileOutOpenError);
    }
    
    fileOut << "Всего количество адресов: " << quantityAdresses << std::endl << std::endl;

    fileOut << "Адреса:" << std::endl;
        
    for (int i = quantityAdresses - 1; i >= 0; i--)
    {
        fileOut << quantityAdresses - i << ". " << arrayForClassObjects[i] << std::endl;
    }
    fileOut.close();
};

//Функция создания текстового динамического массива
std::string* createTextArr(const int quantityAdresses)
{
    std::string* TextArr = new std::string[quantityAdresses]{};

    return TextArr;
}

//Функция удаления динамического массива
void deleteTextArr(std::string* TextArr, const int quantityAdresses)
{
    delete[] TextArr;
    TextArr = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
    system("chcp 1251");

    std::ifstream fileIn("in.txt"); // Открываем файл и проверяем удалось ли открыть
    if (!fileIn)
    {
        std::cout << "Ошибка открытия файла in.txt." << std::endl;
        return static_cast<int>(codeCommit::fileInOpenError);
    }
    else
    {
        std::cout << "Файл in.txt успешно открыт." << std::endl;
    }

    int quantityAdresses = 0;
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    fileIn >> quantityAdresses; //Считываем кол-во адресов из файла(объектов класса) 

    std::string* arrayForClassObjects = createTextArr(quantityAdresses); //Cоздаем динамический массив для объектов класса Adress

    for (int i = 0; i < quantityAdresses; i++) //Считываем адрес
    {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        Adress adress(NameCity, NameStreet, NumberHouse, NumberApartment);
        arrayForClassObjects[i] = adress.createAdress2Out();

    };
    fileIn.close(); //Закрываем файл in.txt

    printArrayForClassObjects(arrayForClassObjects, quantityAdresses);
    deleteTextArr(arrayForClassObjects, quantityAdresses);
    
    std::cout << "Результат работы программы смотри в файле out.txt" << std::endl;
}