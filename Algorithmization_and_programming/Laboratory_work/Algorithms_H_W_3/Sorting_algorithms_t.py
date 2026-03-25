# Функция сортировки пузырьком с визуализацией
def bubble_sort(array):
    n = len(array)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array
#Функция сортировки Шелла
def shell_sort(array):
    n = len(array)
    gap = n // 2  # Начальный шаг

    while gap > 0:
        for i in range(gap, n):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= 2  # Уменьшаем шаг
    return array

#поразрдная сортировка
def radix_sort(array):
    max_num = max(array)
    exp = 1  # Начинаем с разряда единиц
    while max_num // exp > 0:
        # Подсчитываем количество элементов для каждого разряда
        count = [0] * 10
        output = [0] * len(array)

        for num in array:
            index = (num // exp) % 10
            count[index] += 1

        # Преобразуем count в префиксную сумму
        for i in range(1, 10):
            count[i] += count[i - 1]

        # Строим выходной массив
        i = len(array) - 1
        while i >= 0:
            num = array[i]
            index = (num // exp) % 10
            output[count[index] - 1] = num
            count[index] -= 1
            i -= 1

        # Копируем выходной массив обратно в основной массив
        for i in range(len(array)):
            array[i] = output[i]

        exp *= 10  # Переход к следующему разряду
    return array
#функция быстрой сортировки
def quick_sort(start, end, array):

    if start >= end:
        return

    pivot = array[end]
    left = start
    for right in range(start, end):
        if array[right] < pivot:
            array[left], array[right] = array[right], array[left]
            left += 1
    array[left], array[end] = array[end], array[left]

    quick_sort(start, left - 1, array)
    quick_sort(left + 1, end, array)
    return array[start:end]

# Функция гномьей сортировки с визуализацией
def gnom_sort(array):
    n = len(array)
    j = 1;
    while j < n:
            if j>0 and array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
                j -= 1
            else:
                j += 1
    return array

''''
print(bubble_sort([35, 33, 42, 10, 14, 19, 27, 44]))
print(shell_sort([35, 33, 42, 10, 14, 19, 27, 44]))
print(radix_sort([35, 33, 42, 10, 14, 19, 27, 44]))
array = [35, 33, 42, 10, 14, 19, 27, 44, 55]
print(quick_sort(0, len(array) - 1, array))
print(gnom_sort([35, 33, 42, 10, 14, 19, 27, 44]))

'''
















































