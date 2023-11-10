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
    setlocale(LC_ALL, "Russian"); // �����������
    ofstream outputFile(fileName); // ����� � ����

    // ���������� �������� �������
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    std::chrono::nanoseconds result;

    int* shakerSortArray; // ���������� ������� ��� ��������� ����������
    int* quickSortArray; // ���������� ������� ��� ������� ����������
    int compareCount; // ������� ���������
    int swapCount; // ������� ���������
    int iterationCount; // ������� ��������
    int size; // ������ ��������

    // ������� ��������
    cout << "������� ����������� ��������: ";
    if (!(cin >> size)) {
        cout << "������: ����������� �������� ������ ���� ����� ������!\n";
        return -2;
    }
    if (size < 1) {
        cout << "������: ����������� �������� ������ ���� ������������� ������";
        return -1;
    }
    shakerSortArray = new int[size]();
    quickSortArray = new int[size]();

    // ������� ��������� ������������������
    generateRandomSequenceInt(shakerSortArray, size);
    generateRandomSequenceInt(quickSortArray, size);

    // ������� ������������ ������������������
//    generateIncreasingSequenceInt(shakerSortArray, size, 0, size);
//    generateIncreasingSequenceInt(quickSortArray, size, 0, size);

    // ������� ��������� ������������������
//    generateDecreasingSequenceInt(shakerSortArray, size, 0, size);
//    generateDecreasingSequenceInt(quickSortArray, size, 0, size);



    //shakerSort
    compareCount = 0;
    swapCount = 0;
    iterationCount = 0;

    outputFile << "��������� ����������\n";
    outputFile << "�������� ������: ";
    printArray(shakerSortArray, 0, size, outputFile);
    outputFile << "\n";
    begin = chrono::steady_clock::now(); // ������ ������� �������
    shakerSort(shakerSortArray, size, compareCount, swapCount, iterationCount, outputFile);
    end = chrono::steady_clock::now();  // ����� ������� �������
    result = chrono::duration_cast<std::chrono::nanoseconds>(end - begin); // ����� ������ � ������������

    outputFile << "������������ ������:" << endl;
    printArray(shakerSortArray, 0, size, outputFile);
    outputFile << endl;
    outputFile << "���������� ���������: " << compareCount << endl;
    outputFile << "���������� ���������: " << swapCount << endl;
    outputFile << "����� ������: " << result.count() << "\n\n\n";

    //quickSort
    compareCount = 0;
    swapCount = 0;
    iterationCount = 0;

    outputFile << "������� ����������\n";
    outputFile << "�������� ������: ";
    printArray(quickSortArray, 0, size, outputFile);
    outputFile << "\n";
    begin = chrono::steady_clock::now(); // ������ ������� �������
    quickSort(quickSortArray, 0, size - 1, compareCount, swapCount, iterationCount, outputFile);
    end = chrono::steady_clock::now();  // ����� ������� �������
    result = chrono::duration_cast<std::chrono::nanoseconds>(end - begin); // ����� ������ � ������������

    outputFile << "������������ ������:" << endl;
    printArray(quickSortArray, 0,size, outputFile);
    outputFile << endl;
    outputFile << "���������� ���������: " << compareCount << endl;
    outputFile << "���������� ���������: " << swapCount << endl;
    outputFile << "����� ������: " << result.count() << "\n\n";



    delete[] shakerSortArray;
    delete[] quickSortArray;
    return 0;
}