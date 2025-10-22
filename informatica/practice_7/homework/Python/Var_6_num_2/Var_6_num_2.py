def WorksWithSets(A, B):

    Z = set()
    mx = 0
    for i in A:
        Z.add(i)

    for i in A:
        for j in B:
            if i == j:
                Z.discard(i)

    mx = max(Z)

    return mx


try:
    print('Введите множество A(через пробел): ')
    A = set(int(x) for x in input().split())
    print('Введите множество B(через пробел): ')
    B = set(int(x) for x in input().split())
    print(f'Максимальный элемент из разницы множеств A и B равен: {WorksWithSets(A, B)}')
except ValueError:
    print('Введите число!')














