#include <iostream>
#include <set>
#include <Windows.h>
#include <algorithm>


void CreateAndWorkWithSets(const int* arrC, const int* arrD, int size) { //функция для определения разницы множеств
                                                                         // и последующего вычисления максимального элемента этой разницы
    std::set<int> A;//создаём множества <чисел> A, B, Z                  //функция принимает: массив С, массив D, размер множеств/массивов
    std::set<int> B;
    std::set<int> differenceSet;

    for (int i = 0; i < size; i++) {//перебираем массив С и заполняем множество A
        A.insert(arrC[i]);
    }
    
    for (int i = 0; i < size; i++) {//перебираем массив D и заполняем множество B
        B.insert(arrD[i]);
    }
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(differenceSet, differenceSet.begin()));//использем функцию set_difference
    int mx = 0;                                                                                                      //из библиотеки algorithm
                                                                                                                     //для вычисления разицы множеств
    for (int n : differenceSet)//перебираем множество Z и находим минимум для mx
        if (n < mx) {//если элемент множества Z меньше mx, то mx равно этому элементу минус 1
            mx = n - 1;
        }
    for (int n : differenceSet) {//перебираем множество Z
        mx = max(n, mx);//сохраняем в mx максимальное из (элемента множества Z, mx)
    }
    std::cout << "Максимальный элемент из разницы множеств A и B: " << mx << std::endl;//выводим максимальный эелемент разницы множеств
}


int main() 
{
	setlocale(LC_ALL, "Russian");
    int N; // Размер множества

    // Ввод размера множества
    std::cout << "Введите размер множеств (N): ";
    std::cin >> N;
    int* C = new int[N]; // Динамическое выделение памяти для массива A
    int* D = new int[N]; // Динамическое выделение памяти для массива B

    std::cout << "Введите " << N << " элементов для множества A:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
    }
    std::cout << "Введите " << N << " элементов для множества B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }
    
    CreateAndWorkWithSets(C, D, N);

    system("pause");
    return 0;
    }
    
