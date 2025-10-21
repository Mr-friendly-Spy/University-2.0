#include <iostream>
#include <Windows.h>


void calculateMaxValue(const int* arr, int size, int& mx) {
    mx = 0; // Инициализация переменной mx
    for (int i = 0; i < size; i++) {
        if (arr[i] < mx) {
            mx = arr[i] - 1;
        }
    }
    for (int i = 0; i < size; i++) {
        mx = max(arr[i], mx);
    }
}

void findArrayWithMaxValue(const int* arrA, const int* arrB, int size1, int size2) {
    int mxA = 0, mxB = 0;

    // Вычисляем максимальные значения массивов
    calculateMaxValue(arrA, size1, mxA);
    calculateMaxValue(arrB, size2, mxB);

    // Выводим максимальное значение массива и его порядковый номер
    if (mxA > mxB) {
        std::cout << "Массив A имеет наибольшее значение: " << mxA << std::endl;
        std::cout << "Порядковый номер наибольшего значения массива A: ";
        for (int i = 0; i < size1; i++) {
            if (arrA[i] == mxA) {
                std::cout << i << std::endl;
            }
        }
        std::cout << "Элементы массива А: ";
        for (int i = 0; i < size1; i++) {
            std::cout << arrA[i] << " ";
        }
    }
    else {
        std::cout << "Массив B имеет наибольшее значение: " << mxB << std::endl;
        std::cout << "Порядковый номер наибольшего значения массива B: ";
        for (int i = 0; i < size2; i++) {
            if (arrB[i] == mxB) {
                std::cout << i << std::endl;
            }
        }
        std::cout << "Элементы массива B: ";
        for (int i = 0; i < size2; i++) {
            std::cout << arrB[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int* A = new int[5]; // Динамическое выделение памяти для массива A
    int* B = new int[4]; // Динамическое выделение памяти для массива B

    // Ввод массивов
    std::cout << "Введите " << 5 << " элементов для массива A:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите " << 4 << " элемента для массива B:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cin >> B[i];
    }

    // Поиск массива с наибольшим значением
    findArrayWithMaxValue(A, B, 5, 4);

    // Освобождение выделенной памяти
    delete[] A;
    delete[] B;

    system("pause");
    return 0;
}
