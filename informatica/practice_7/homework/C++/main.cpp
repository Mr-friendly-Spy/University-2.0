#include <iostream>
#include <set>
#include <Windows.h>


void CreateAndWorkWithSets(const int* arrC, const int* arrD, int size) {

    std::set<int> A;
    std::set<int> B;
    std::set<int> Z;

    for (int i = 0; i < size; i++) {
        A.insert(arrC[i]);
    }
    for (int i = 0; i < size; i++) {
        Z.insert(arrC[i]);
    }

    for (int i = 0; i < size; i++) {
        B.insert(arrD[i]);
    }

    for (int n : A)
        for (int j : B)
            if (n == j) {
                Z.erase(n);
            }
    int mx = 0;

    for (int n : Z)
        if (n < mx) {
            mx = n - 1;
        }
    for (int n : Z) {
        mx = max(n, mx);
    }
    std::cout << "Максимальный элемент из разности множеств A и B: " << mx << std::endl;
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
    
