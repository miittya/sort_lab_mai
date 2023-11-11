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
    setlocale(LC_ALL, "Russian"); // Локализация
    ofstream outputFile(fileName); // Вывод в файл

    // Переменные хранения времени
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    std::chrono::nanoseconds result;

    long compareCount; // Счетчик сравнений
    long swapCount; // Счетчик пересылок
    int iterationCount; // Счетчик итераций
    int size; // Размер массивов
    int sizeArray[] = {1000, 10000, 15000, 20000};

    int* shakerSortArray = new int[100000]();
    int* quickSortArray = new int[100000]();

    for (int i = 0; i < 4; ++i) {
        size = sizeArray[i];
        for (int j = 0; j < 3; ++j) {
            switch (j) {
                case 0:
                    generateRandomSequenceInt(shakerSortArray, size);
                    generateRandomSequenceInt(quickSortArray, size);
                    break;
                case 1:
                    generateIncreasingSequenceInt(shakerSortArray, size, 0, size);
                    generateIncreasingSequenceInt(quickSortArray, size, 0, size);
                    break;
                case 2:
                    generateDecreasingSequenceInt(shakerSortArray, size, 0, size);
                    generateDecreasingSequenceInt(quickSortArray, size, 0, size);
                    break;
            }

            if (size <= 50000) {
                compareCount = 0;
                swapCount = 0;
                iterationCount = 0;

                begin = chrono::steady_clock::now(); // Начало отсчета времени
                shakerSort(shakerSortArray, size, compareCount, swapCount, iterationCount, outputFile);
                end = chrono::steady_clock::now();  // Конец отсчета времени
                result = chrono::duration_cast<std::chrono::nanoseconds>(end - begin); // Время работы в наносекундах

                outputFile << 0 << ' ' << size << ' ' << j << ' ' << compareCount << ' ' << swapCount << ' ' << result.count() << endl;
            }


            //quickSort
            compareCount = 0;
            swapCount = 0;
            iterationCount = 0;


            begin = chrono::steady_clock::now(); // Начало отсчета времени
            quickSort(quickSortArray, 0, size - 1, compareCount, swapCount, iterationCount, outputFile);
            end = chrono::steady_clock::now();  // Конец отсчета времени
            result = chrono::duration_cast<std::chrono::nanoseconds>(end - begin); // Время работы в наносекундах

            outputFile << 1 << ' ' << size << ' ' << j << ' ' << compareCount << ' ' << swapCount << ' ' << result.count() << endl;

        }
    }

    delete[] shakerSortArray;
    delete[] quickSortArray;
    return 0;
}