/**********************************************************************************************
*                                           ???? ???????????                                  *
***********************************************************************************************
*Project type :Win64 Console Application                                                      *
*Project name :Lab1                                                                           *
*File name    :ConsoleApplication2.exe                                                        *
*Language     :CPP, MSVS 2019                                                                 *
*Programmers  :???????? ??????? ????????, ??????? ????????? ????????? ?3?-210?-22             *
*Modified By  :                                                                               *
*Created      :10.11.2023                                                                     *
*Last revision:10.11.2023                                                                     *
*Comment      :????????? ?????????? ??????                                                    *
**********************************************************************************************/

#include "header.h"
using namespace std;
const char fileName[] = "Output.txt";

int main() {
    setlocale(LC_ALL, "Russian"); //???????????
    ofstream outputFile(fileName); // ????? ? ????

    // ?????????? ???????? ???????
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    std::chrono::nanoseconds result;

    int* shakerSortArray; // ?????????? ???????? ???????
    int* quickSortArray;
    int compareCount; // ?????????? ???????? ?????????
    int swapCount; // ?????????? ???????? ?????????
    int iterationCount; // Счетчик итераций
    int size; // ?????????? ??????????? ???????

    // Входной контроль
    cout << "Введите размерность массивов: ";
    if (!(cin >> size)) {
        cout << "Ошибка: размерность массивов должна быть целым числом!\n";
        return -2;
    }
    if (size < 1) {
        cout << "Ошибка: размерность массивов должна быть положительным числом";
        return -1;
    }
    shakerSortArray = new int[size]();
    quickSortArray = new int[size]();

    // Создаем случайную последовательность
    generateRandomSequenceInt(shakerSortArray, size);
    generateRandomSequenceInt(quickSortArray, size);



    //shakerSort
    compareCount = 0;
    swapCount = 0;
    iterationCount = 0;

    outputFile << "ШЕЙКЕРНАЯ СОРТИРОВКА\n";
    outputFile << "Исходный массив: ";
    printArray(shakerSortArray, 0, size, outputFile);
    outputFile << "\nПромежуточные результаты: \n";
    begin = chrono::steady_clock::now(); // Начало отсчета времени
    shakerSort(shakerSortArray, size, compareCount, swapCount, iterationCount, outputFile);
    end = chrono::steady_clock::now();  // Конец отсчета времени
    result = chrono::duration_cast<std::chrono::nanoseconds>(end - begin); // Время работы в наносекундах

    outputFile << "Получившийся массив:" << endl;
    printArray(shakerSortArray, 0, size, outputFile);
    outputFile << endl;
    outputFile << "Количество сравнений: " << compareCount << endl;
    outputFile << "Количество пересылок: " << swapCount << endl;
    outputFile << "Время работы: " << result.count() << "\n\n\n";

    //quickSort
    compareCount = 0;
    swapCount = 0;
    iterationCount = 0;

    outputFile << "БЫСТРАЯ СОРТИРОВКА\n";
    outputFile << "Исходный массив: ";
    printArray(quickSortArray, 0, size, outputFile);
    outputFile << "\nПромежуточные результаты: \n";
    begin = chrono::steady_clock::now(); // Начало отсчета времени
    quickSort(quickSortArray, 0, size - 1, compareCount, swapCount, iterationCount, outputFile);
    end = chrono::steady_clock::now();  // Конец отсчета времени
    result = chrono::duration_cast<std::chrono::nanoseconds>(end - begin); // Время работы в наносекундах

    outputFile << "Получившийся массив:" << endl;
    printArray(quickSortArray, 0,size, outputFile);
    outputFile << endl;
    outputFile << "Количество сравнений: " << compareCount << endl;
    outputFile << "Количество пересылок: " << swapCount << endl;
    outputFile << "Время работы: " << result.count() << "\n\n";



    delete[] shakerSortArray;
    delete[] quickSortArray;
    return 0;
}