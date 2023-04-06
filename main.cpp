#include <iostream>
#include <iterator>
#include <algorithm>

enum MenuIteam
{
    Exit            = 0, // Выход из программы
    Print           = 1, // Вывести массив на консоль
    Find            = 2, // Найти адрес числа в массиве
    Recreate        = 3, // Создать массив заново
    Change          = 4, // Поменять местами 1й и последний элемент массива
    Sort            = 5, // Отсортировать массив
    ReplaceOn       = 6, // Замена чисел в массиве
    Arithmetic_mean = 7  // Среднее арифметическое массива
};


int* arrNumber = nullptr;
int* end = nullptr;

// Функция генерирует числа заданном диапазоне min/max
int GetRandomNumber(int min, int max)
{
    int num = min + rand() % (max - min + 1);

    return num;
}

// Функция печатает значения из массива
void printValue( int* arr, int* end, bool* ok = nullptr )
{
    if(arr == nullptr || end == nullptr)
    {
        if(ok != nullptr)
        {
            *ok = false;
        }

        return;
    }

    if(ok != nullptr)
    {
        *ok = true;
    }

    for(int* p = arr; p != end; p++)
    {
        std::cout << p << " : " << *p << '\n';
    }
}

// Функция ищет заданное число
int* findPointerValue( int* start, int* end, int value, bool* ok = nullptr)
{
    if(start == nullptr || end == nullptr)
    {
        if( ok != nullptr)
        {
            *ok = false;
        }

        return end;
    }

    if(ok != nullptr)
    {
        *ok = true;
    }
    for(int* p = start; p != end; p++)
    {
        if(*p == value)
        {
            return p;
        }
    }

    return end;
}

// Функция создает массив в диапазоне чисел
void createArr()
{
    int countNum = 0;
    int min = 0;
    int max = 0;

    std::cout << " enter a min number: " << '\n';
    std::cin >> min;

    std::cout << " enter a max number: " << '\n';
    std::cin >> max;

    std::cout << " enter a count numbers: " << '\n';
    std::cin >> countNum;

    arrNumber = new int[countNum];
    end = arrNumber + countNum;

    for(int* p = arrNumber; p != end; p++)
    {
        *p = GetRandomNumber(min, max);
    }
}

// Функция производит замену чисел
int replaceOn( int* start, int* end, int valueArr, int valueChange)
{
    int countChange = 0;
    //int valueArr = 0;

    if(start == nullptr || end == nullptr)
    {
        return 0;
    }

    for(int* p = start; p != end; p++)
    {
        if(*p == valueArr)
        {
            *p = valueChange;
            countChange++;
        }
    }

    return countChange;
}

// Функция сортирует массив
void sortArr(int* arrNumber,int* end)
{
    if(arrNumber == nullptr || end == nullptr)
    {
        return;
    }

    for(int* currentA = arrNumber; currentA != end; currentA++)
    {
        int* smallP = currentA;

        for(int* currentB = currentA + 1; currentB != end; currentB++)
        {
            if(*currentB < *smallP)
            {
                smallP = currentB;
            }
        }

        int tmp = *smallP;
        *smallP = *currentA;
        *currentA = tmp;
    }
}

// Функция рассчитывает среднее арифметическое число массива
double arithmeticMean(int* arrNumber, int* end, bool* ok = nullptr)
{
    if(arrNumber == nullptr || end == nullptr)
    {
        if(ok != nullptr)
        {
            *ok = false;
        }
        return 0;
    }

    double sum = 0.0;
    int countElements = 0;

    if(ok != nullptr)
    {
        *ok = true;
    }

    for(int* p = arrNumber; p != end; p++)
    {
        sum += *p;
        countElements++;
    }

    return sum / countElements;
}

int main()
{
    createArr();

    bool t = true;

    while(t)
    {
        std::cout << "[" << Exit            << "] Exit" << '\n'
                  << "[" << Print           << "] Print: address : value" << '\n'
                  << "[" << Find            << "] Find : address : value" << '\n'
                  << "[" << Recreate        << "] Recreate array" << '\n'
                  << "[" << Change          << "] Change 1 and end value" << '\n'
                  << "[" << Sort            << "] Sort" << '\n'
                  << "[" << ReplaceOn       << "] ReplaceOn" << '\n'
                  << "[" << Arithmetic_mean << "] Arithmetic_mean" << '\n';

        int operation;

        std::cout << " -> ";

        std::cin >> operation;

        switch(operation)
        {
            case Exit:
            {
                t = false;
                break;
            }

            case Print:
            {
                bool ok;

                printValue(arrNumber, end, &ok);

                if(ok == false)
                {
                    std::cout << "can not print!" << '\n';
                }
                break;
            }

            case Find:
            {
                std::cout << " Enter rand value of min max " << '\n';

                int valueAnyNum;
                std:: cin >> valueAnyNum;

                bool ok;

                int* val2 = findPointerValue( arrNumber, end, valueAnyNum, &ok);

                if(val2 != end)
                {
                    std::cout << "Value is found: " << val2 << '\n';
                }
                if( ok = true)
                {
                    std::cout << "Value is not found!" << '\n';
                }

                break;
            }

            case Recreate:
            {
                delete[] arrNumber;
                createArr();

                break;
            }

            case Change:
            {
                std::cout << "before swap" << '\n';
                printValue(arrNumber, end);

                int* first = arrNumber;
                int* last = end - 1;

                int tmp = *first;
                *first = *last;
                *last = tmp;

                std::cout << "after swap" << '\n';
                printValue(first, end);

                break;
            }

            case Sort:
            {
                sortArr(arrNumber, end);
                break;
            }

            case ReplaceOn:
            {

                std::cout << "Enter the number which need to be changed" << '\n';
                int valueArr;
                std::cin >> valueArr;

                std::cout << "Enter the number to be changed to" << '\n';
                int valueChange;
                std::cin >> valueChange;

                std::cout << "Array before replacement" << '\n';
                std::cout << " " << '\n';
                printValue(arrNumber, end);

                int countChanged = replaceOn(arrNumber, end, valueArr, valueChange);

                std::cout << " " << '\n';
                std::cout << "Array after replacement" << '\n';

                std::cout << " " << '\n';
                printValue(arrNumber, end);

                std::cout << " " << '\n';
                std::cout << "Replacements made: " << countChanged << '\n';
                std::cout << " " << '\n';

                break;
            }

            case Arithmetic_mean:
            {
                bool ok;

                double arKMean = arithmeticMean(arrNumber, nullptr, &ok);

                if(ok == false)
                {
                    std::cout << "Error" << '\n';
                    break;
                }

                std::cout << " Arithmetic mean: " << arKMean << '\n';

                break;
            }

            default:
            {
                std::cout << "Error!" << '\n';
                break;
            }
        }
    }

    delete [] arrNumber;

    return 0;
}
