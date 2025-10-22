def CalculateMaxValue(A, B):
    mx1 = min(A) - 1
    mx2 = min(B) - 1
    mx3 = 0
    for i in range(len(A)):
        mx1 = max(A[i], mx1)
    for i in range(len(B)):
        mx2 = max(B[i], mx2)
    mx3 = max(mx1, mx2)
    return mx3, mx1


def findArrayWithMaxValue(A ,B):

    mx3, mx1 = CalculateMaxValue(A, B)

    if mx3 == mx1:
        print(f'Элементы массива A: {A}')
        print(f'Наибольшее значение массива A: {mx3}')
        for i in range(len(A)):
            if A[i] == mx3:
                print(f'Порядковый номер наибольшего значения массива A: {i}')
    else:
        print(f'Элементы массива B: {B}')
        print(f'Наибольшее значение массива B: {mx3}')
        for j in range(len(B)):
            if B[j] == mx3:
                print(f'Порядковый номер наибольшего значения массива B: {j}')

try:
    print("Введите 5 элементов для массива A:")
    A = [int(input()), int(input()), int(input()), int(input()), int(input()),]
    print("Введите 4 элемента для массива B:")
    B = [int(input()), int(input()), int(input()), int(input())]
    findArrayWithMaxValue(A, B)
except ValueError:
    print('Введите число!')
























