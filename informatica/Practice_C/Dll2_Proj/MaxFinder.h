// MaxFinder.h
// Упрощенный заголовочный файл для MaxFinder DLL

#pragma once

// Для DLL проекта определяем dllexport, для остальных - dllimport
#ifdef MAXFINDER_DLL_EXPORTS
#define MAXFINDER_API __declspec(dllexport)
#else
#define MAXFINDER_API __declspec(dllimport)
#endif

// extern "C" для предотвращения name mangling
#ifdef __cplusplus
extern "C" {
#endif

    // 1. Поиск максимума в массиве целых чисел
    MAXFINDER_API int __stdcall FindMaxInt(int* arr, int size);

    // 2. Получение информации о DLL
    MAXFINDER_API const char* __stdcall GetDLLInfo();

#ifdef __cplusplus
}
#endif