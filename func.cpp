#include "header.h"
using namespace std;

void printArray(int* arr,
                int l,
                int r,
                std::ofstream& outputFile
) {
    for (int i = l; i < r; ++i) {
        outputFile << arr[i] << ' ';
    }
    outputFile << endl;
}

void generateRandomSequenceInt(
        int* arr,
        int size
) {
    srand(time(NULL));                      // Инициализация генератора случайных чисел
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size; // Генерация случайных чисел
    }
}

void generateIncreasingSequenceInt(
        int* arr,
        int size,
        int minVal,
        int maxVal
) {
    // Вычисляем шаг последовательности
    int step = (maxVal - minVal) / (size - 1);
    for (int i = 0; i < size; i++) {
        arr[i] = i * step + minVal;
    }
}

void generateDecreasingSequenceInt(
        int* arr,
        int size,
        int minVal,
        int maxVal
) {
    // Вычисляем шаг последовательности
    int step = (maxVal - minVal) / (size - 1);
    for (int i = 0; i < size; i++) {
        arr[i] = maxVal - i * step;
    }
}

void shakerSort(int* Array,
                int size,
                long& compareCount,
                long& swapCount,
                int& iterationCount,
                ofstream& outputFile
) {
    int Left = 1;
    int Right = size - 1;
    while (Left <= Right) {
        compareCount++;
        iterationCount++;
        for (int i = Right; i >= Left; --i) {
            compareCount++;
            if (Array[i - 1] > Array[i]) {
                swap(Array[i - 1], Array[i]);
                swapCount++;
                compareCount++;
            }
        }
        Left++;

        for (int i = Left; i <= Right; ++i) {
            compareCount++;
            if (Array[i - 1] > Array[i]) {
                swap(Array[i - 1], Array[i]);
                swapCount++;
                compareCount++;
            }
        }
        Right--;
    }
}

int Partition(int* Array,
               int p,
               int r,
               long& compareCount,
               long& swapCount
) {
//    int x = Array[r];
//    int L = p - 1;
//    int R = r + 1;
//    while (1) {
//        do {
//            L++;
//        } while (Array[L] < x);
//        do {
//            R--;
//        } while (Array[R] > x);
//        if (L >= R) {
//            return R;
//        }
//        swap(Array[L], Array[R]);
//    }

    int q = p;
    for (int u = p; u < r; ++u) {
        compareCount++;
        if (Array[u] <= Array[r]) {
            swap(Array[q], Array[u]);
            compareCount++;
            swapCount++;
            q++;
        }
    }
    swap(Array[q], Array[r]);
    swapCount++;
    return q;
}

void quickSort(int* Array,
               int p,
               int r,
               long& compareCount,
               long& swapCount,
               int& iterationCount,
               ofstream& outputFile
) {


    if (p < r) {
        compareCount++;
        int q = Partition(Array, p, r, compareCount, swapCount);
//        outputFile << q << ' ' << Array[q] << ' ' << endl;
//        printArray(Array, p, r + 1, outputFile);
//        outputFile << endl;
        quickSort(Array, p, q - 1, compareCount, swapCount, iterationCount, outputFile);
        quickSort(Array, q + 1, r, compareCount, swapCount, iterationCount, outputFile);
    }


}