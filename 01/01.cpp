#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

//Задача 1. Адреса

class Adress //Класс Адрес с методами
{
private:
    std::string cNameCity;
    std::string cNameStreet;
    int cNumberHouse = 0;
    int cNumberApartment = 0;
    std::string cFullAdress;

public:
    // Конструктор
    Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
    {
        this->cNameCity = NameCity;
        this->cNameStreet = NameStreet;
        this->cNumberHouse = NumberHouse;
        this->cNumberApartment = NumberApartment;
    }

    // Метод создания строки полного адреса для вывода
    std::string createAdress2Out()
    {
        cFullAdress =  cNameCity + ", " + cNameStreet + ", " + std::to_string(cNumberHouse)
                       + ", " + std::to_string(cNumberApartment);
        return cFullAdress;
    };
};

enum class codeCommit
{
    fileInOpenError, fileOutOpenError
};

//Функция печати массива в файл
int print_arrayForClassObjects(std::string* arrayForClassObjects, const int quantityAdresses)
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
    
    fileOut << "Адреса:\t" << std::endl;
        
    for (int i = 0; i < quantityAdresses; i++)
    {
        fileOut << i+1 << ". " << arrayForClassObjects[i] << std::endl;
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
void delete_TextArr(std::string* TextArr, const int quantityAdresses)
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

    print_arrayForClassObjects(arrayForClassObjects, quantityAdresses);
    delete_TextArr(arrayForClassObjects, quantityAdresses);
    
    std::cout << "Результат работы программы смотри в файле out.txt" << std::endl;
}