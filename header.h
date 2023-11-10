#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#include <locale>
#include <Windows.h>

void printArray(int* arr,
                int l,
                int r,
                std::ofstream& outputFile
);

// Функция, генерирующая случайную последовательность
void generateRandomSequenceInt(
        int* arr,                              // Указатель на массив целых чисел
        int size                               // Число элементов массива
);

// Функция, генерирующая возрастающую последовательность
void generateIncreasingSequenceInt(
        int* arr,                              // Указатель на массив целых чисел
        int size,                               // Число элементов массива
        int minVal,                             // Минимальное значение
        int maxVal                              // Максимальное значение
);

// Функция, генерирующая возрастающую последовательность
void generateDecreasingSequenceInt(
        int* arr,                              // Указатель на массив целых чисел
        int size,                               // Число элементов массива
        int minVal,                             // Минимальное значение
        int maxVal                              // Максимальное значение
);

//Шейкерная сортировка
void shakerSort(int* Array,
                int size,
                int& compareCount,
                int& swapCount,
                int& iterationCount,
                std::ofstream& outputFile
);

//Процедура Partition
int Partition(int* Array,
               int p,
               int r,
               int& compareCount,
               int& swapCount
);

//Быстрая сортировка
void quickSort(int* Array,
                int p,
                int r,
                int& compareCount,
                int& swapCount,
                int& iterationCount,
               std::ofstream& outputFile
);