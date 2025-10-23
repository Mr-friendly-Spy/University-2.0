def WorksWithSets(A, B):
    mx = max(A.difference(B))
    return mx


try:
    print('Введите множество A(через пробел): ')
    A = set(int(x) for x in input().split())
    print('Введите множество B(через пробел): ')
    B = set(int(x) for x in input().split())
    print(f'Максимальный элемент из разницы множеств A и B равен: {WorksWithSets(A, B)}')
except ValueError:
    print('Введите число!')














