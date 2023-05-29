#include <iostream>
#include <windows.h>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Со сколькими элементами хотите проверить?" << endl;
    int size;
    cin >> size;
    cout << "Проверка с " << size << " элементов" << endl;
    //проверка записи в динамический массив new
    auto newStart = chrono::system_clock::now();
    BYTE* newArr = new BYTE[size];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = i;
    }
    delete[] newArr;
    auto newEnd = chrono::system_clock::now();
    chrono::duration<double> newSec = newEnd - newStart;
    cout << "Время, затраченное на запись в динамический массив: " << endl;
    cout << newSec.count() << " сек" << endl;
    //проверка записи в Vector через [] с изначальным указанием размера
    auto vecStart = chrono::system_clock::now();
    vector<BYTE> vectArr(size, 0);
    for (int i = 0; i < size; i++)
    {
        vectArr[i] = i;
    }
    auto vecEnd = chrono::system_clock::now();
    chrono::duration<double> vecSec = vecEnd - vecStart;
    cout << "Время, затраченное на запись в вектор через [] с изначальным указанием размера:" << endl;
    cout << vecSec.count() << " сек" << endl;
    //проверка записи в Vector через push_back без изначального указания размера
    auto pushVecStart = chrono::system_clock::now();
    vector<BYTE> pushVectArr;
    for (int i = 0; i < size; i++)
    {
        pushVectArr.push_back(i);
    }
    auto pushVecEnd = chrono::system_clock::now();
    chrono::duration<double> pushVecSec = pushVecEnd - pushVecStart;
    cout << "Время, затраченное на запись в вектор через push_back без изначального указания размера:" << endl;
    cout << pushVecSec.count() << " сек" << endl;
    system("pause");
    return 0;
}