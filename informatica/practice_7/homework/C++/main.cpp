#include <iostream>
#include <Windows.h>


void calculateMaxValue(const int* arr, int size, int& mx) {
    mx = 0; // ������������� ���������� mx
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

    // ��������� ������������ �������� ��������
    calculateMaxValue(arrA, size1, mxA);
    calculateMaxValue(arrB, size2, mxB);

    // ������� ������������ �������� ������� � ��� ���������� �����
    if (mxA > mxB) {
        std::cout << "������ A ����� ���������� ��������: " << mxA << std::endl;
        std::cout << "���������� ����� ����������� �������� ������� A: ";
        for (int i = 0; i < size1; i++) {
            if (arrA[i] == mxA) {
                std::cout << i << std::endl;
            }
        }
        std::cout << "�������� ������� �: ";
        for (int i = 0; i < size1; i++) {
            std::cout << arrA[i] << " ";
        }
    }
    else {
        std::cout << "������ B ����� ���������� ��������: " << mxB << std::endl;
        std::cout << "���������� ����� ����������� �������� ������� B: ";
        for (int i = 0; i < size2; i++) {
            if (arrB[i] == mxB) {
                std::cout << i << std::endl;
            }
        }
        std::cout << "�������� ������� B: ";
        for (int i = 0; i < size2; i++) {
            std::cout << arrB[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int* A = new int[5]; // ������������ ��������� ������ ��� ������� A
    int* B = new int[4]; // ������������ ��������� ������ ��� ������� B

    // ���� ��������
    std::cout << "������� " << 5 << " ��������� ��� ������� A:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> A[i];
    }

    std::cout << "������� " << 4 << " �������� ��� ������� B:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cin >> B[i];
    }

    // ����� ������� � ���������� ���������
    findArrayWithMaxValue(A, B, 5, 4);

    // ������������ ���������� ������
    delete[] A;
    delete[] B;

    system("pause");
    return 0;
}
