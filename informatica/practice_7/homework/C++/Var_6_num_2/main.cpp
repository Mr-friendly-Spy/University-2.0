#include <iostream>
#include <set>
#include <Windows.h>
#include <algorithm>


void CreateAndWorkWithSets(const int* arrC, const int* arrD, int size) { //������� ��� ����������� ������� ��������
                                                                         // � ������������ ���������� ������������� �������� ���� �������
    std::set<int> A;//������ ��������� <�����> A, B, Z                  //������� ���������: ������ �, ������ D, ������ ��������/��������
    std::set<int> B;
    std::set<int> differenceSet;

    for (int i = 0; i < size; i++) {//���������� ������ � � ��������� ��������� A
        A.insert(arrC[i]);
    }
    
    for (int i = 0; i < size; i++) {//���������� ������ D � ��������� ��������� B
        B.insert(arrD[i]);
    }
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(differenceSet, differenceSet.begin()));//��������� ������� set_difference
    int mx = 0;                                                                                                      //�� ���������� algorithm
                                                                                                                     //��� ���������� ������ ��������
    for (int n : differenceSet)//���������� ��������� Z � ������� ������� ��� mx
        if (n < mx) {//���� ������� ��������� Z ������ mx, �� mx ����� ����� �������� ����� 1
            mx = n - 1;
        }
    for (int n : differenceSet) {//���������� ��������� Z
        mx = max(n, mx);//��������� � mx ������������ �� (�������� ��������� Z, mx)
    }
    std::cout << "������������ ������� �� ������� �������� A � B: " << mx << std::endl;//������� ������������ �������� ������� ��������
}


int main() 
{
	setlocale(LC_ALL, "Russian");
    int N; // ������ ���������

    // ���� ������� ���������
    std::cout << "������� ������ �������� (N): ";
    std::cin >> N;
    int* C = new int[N]; // ������������ ��������� ������ ��� ������� A
    int* D = new int[N]; // ������������ ��������� ������ ��� ������� B

    std::cout << "������� " << N << " ��������� ��� ��������� A:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
    }
    std::cout << "������� " << N << " ��������� ��� ��������� B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }
    
    CreateAndWorkWithSets(C, D, N);

    system("pause");
    return 0;
    }
    
