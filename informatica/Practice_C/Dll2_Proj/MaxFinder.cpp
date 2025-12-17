#include "pch.h"
#include "MaxFinder.h"
#include <iostream>
#include <chrono>
// Определяем макрос для экспорта (ВАЖНО!)
#define MAXFINDER_DLL_EXPORTS
// ========== РЕАЛИЗАЦИЯ ФУНКЦИЙ ==========
// 1. Поиск максимума в массиве целых чисел
int __stdcall FindMaxInt(int* arr, int size)
{
    // Начало замера времени
    auto start = std::chrono::high_resolution_clock::now();

    if (size <= 0 || arr == nullptr)
    {
        return 0;
    }

    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    // Конец замера времени
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    #ifdef _DEBUG
    std::cout << "[FindMaxInt] Time in C++: " << duration.count() << " seconds" << std::endl;
    #endif

    return maxVal;
}
// 2. Получение информации о DLL
const char* __stdcall GetDLLInfo()
{
    return "MaxFinder DLL v1.0 - Simplified Version";
}
