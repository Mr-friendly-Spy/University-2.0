import pygame
import random
import time

# Настройки окна
WIDTH, HEIGHT = 800, 600
ARRAY_SIZE = 50
BAR_WIDTH = WIDTH // ARRAY_SIZE

# Цвета
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (100, 100, 255)
RED = (255, 100, 100)

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Алгоритмы сортировки")
font = pygame.font.Font(None, 36)


# Генерация случайного массива
def generate_array():
    return [random.randint(10, HEIGHT - 100) for _ in range(ARRAY_SIZE)]


array = generate_array()

# кнопки 
button_random = pygame.Rect(0, 550, 300, 30)
button_algorithm = pygame.Rect(320, 550, 200, 30)
button_sort = pygame.Rect(550, 550, 250, 30)

selected_algorithm = "Пузырьком"
algorithms = ["Пузырьком", "Гномья", "Быстрая", "Поразрядная", "Шелла"]
algorithm_index = 0


# Функция сортировки пузырьком с визуализацией
def bubble_sort_visual():
    global array
    n = len(array)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
###########################################################################33
                screen.fill(WHITE)
                for k, value in enumerate(array):
                    color = RED if k == j or k == j + 1 else BLUE
                    pygame.draw.rect(screen, color, (k * BAR_WIDTH, HEIGHT - value - 50, BAR_WIDTH - 2, value))
                pygame.draw.rect(screen, RED, button_random)
                pygame.draw.rect(screen, RED, button_algorithm)
                pygame.draw.rect(screen, RED, button_sort)
                screen.blit(font.render("Генерировать массив", True, WHITE),
                            (button_random.x + 30, button_random.y + 5))
                screen.blit(font.render("Отсортировать", True, WHITE), (button_sort.x + 30, button_sort.y + 5))
                screen.blit(font.render(selected_algorithm, True, WHITE),
                            (button_algorithm.x + 30, button_algorithm.y + 5))
                pygame.display.flip()
                time.sleep(0.02)
#########################################################################
#Функция сортировки Шелла
def shell_sort_visual():
    global array
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
###########################################################################################################
        screen.fill(WHITE)
        for k, value in enumerate(array):
            color = RED if k == j or k == j + 1 else BLUE
            pygame.draw.rect(screen, color, (k * BAR_WIDTH, HEIGHT - value - 50, BAR_WIDTH - 2, value))
        pygame.draw.rect(screen, RED, button_random)
        pygame.draw.rect(screen, RED, button_algorithm)
        pygame.draw.rect(screen, RED, button_sort)
        screen.blit(font.render("Генерировать массив", True, WHITE),
                    (button_random.x + 30, button_random.y + 5))
        screen.blit(font.render("Отсортировать", True, WHITE), (button_sort.x + 30, button_sort.y + 5))
        screen.blit(font.render(selected_algorithm, True, WHITE),
                    (button_algorithm.x + 30, button_algorithm.y + 5))
        pygame.display.flip()
        time.sleep(0.02)
###########################################################################################################

#поразрдная сортировка
def radix_sort_visual():
    global array
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

        # Визуализируем состояние массива после каждого разряда
        screen.fill(WHITE)
        for k, value in enumerate(array):
            pygame.draw.rect(screen, BLUE, (k * BAR_WIDTH, HEIGHT - value - 50, BAR_WIDTH - 2, value))
        pygame.draw.rect(screen, RED, button_random)
        pygame.draw.rect(screen, RED, button_algorithm)
        pygame.draw.rect(screen, RED, button_sort)
        screen.blit(font.render("Генерировать массив", True, WHITE), (button_random.x + 30, button_random.y + 5))
        screen.blit(font.render("Отсортировать", True, WHITE), (button_sort.x + 30, button_sort.y + 5))
        screen.blit(font.render(selected_algorithm, True, WHITE), (button_algorithm.x + 30, button_algorithm.y + 5))
        pygame.display.flip()
        time.sleep(0.05)

        exp *= 10  # Переход к следующему разряду

#функция быстрой сортировки
def quick_sort_visual(start, end):
    if start >= end:
        return

    pivot = array[end]
    left = start
    for right in range(start, end):
        if array[right] < pivot:
            array[left], array[right] = array[right], array[left]
            left += 1
    array[left], array[end] = array[end], array[left]
############################################
    screen.fill(WHITE)
    for k, value in enumerate(array):
        color = RED if k == left or k == end else BLUE
        pygame.draw.rect(screen, color, (k * BAR_WIDTH, HEIGHT - value - 50, BAR_WIDTH - 2, value))
    pygame.draw.rect(screen, RED, button_random)
    pygame.draw.rect(screen, RED, button_algorithm)
    pygame.draw.rect(screen, RED, button_sort)
    screen.blit(font.render("Генерировать массив", True, WHITE), (button_random.x + 30, button_random.y + 5))
    screen.blit(font.render("Отсортировать", True, WHITE), (button_sort.x + 30, button_sort.y + 5))
    screen.blit(font.render(selected_algorithm, True, WHITE), (button_algorithm.x + 30, button_algorithm.y + 5))
    pygame.display.flip()
    time.sleep(0.05)
############################################
    quick_sort_visual(start, left - 1)
    quick_sort_visual(left + 1, end)

# Функция гномьей сортировки с визуализацией
def gnom_sort_visual():
    global array
    n = len(array)
    j = 1;
    while j < n:
            if j>0 and array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
                j -= 1
            else:
                j += 1
#############################################################
            screen.fill(WHITE)
            for k, value in enumerate(array):
                color = RED if k == j or k == j + 1 else BLUE
                pygame.draw.rect(screen, color, (k * BAR_WIDTH, HEIGHT - value - 50, BAR_WIDTH - 2, value))
            pygame.draw.rect(screen, RED, button_random)
            pygame.draw.rect(screen, RED, button_algorithm)
            pygame.draw.rect(screen, RED, button_sort)
            screen.blit(font.render("Генерировать массив", True, WHITE),
                        (button_random.x + 30, button_random.y + 5))
            screen.blit(font.render("Отсортировать", True, WHITE), (button_sort.x + 30, button_sort.y + 5))
            screen.blit(font.render(selected_algorithm, True, WHITE),
                        (button_algorithm.x + 30, button_algorithm.y + 5))
            pygame.display.flip()
            time.sleep(0.02)
################################################################3

running = True
while running:
    screen.fill(WHITE)

    # Отрисовка массива
    for i, value in enumerate(array):
        pygame.draw.rect(screen, BLUE, (i * BAR_WIDTH, HEIGHT - value - 50, BAR_WIDTH - 2, value))

    # Отрисовка кнопок
    pygame.draw.rect(screen, RED, button_random)
    pygame.draw.rect(screen, RED, button_algorithm)
    pygame.draw.rect(screen, RED, button_sort)

    screen.blit(font.render("Генерировать массив", True, WHITE), (button_random.x + 30, button_random.y + 5))
    screen.blit(font.render("Отсортировать", True, WHITE), (button_sort.x + 30, button_sort.y + 5))
    screen.blit(font.render(selected_algorithm, True, WHITE), (button_algorithm.x + 30, button_algorithm.y + 5))

    # Обработка событий
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            if button_random.collidepoint(event.pos):
                array = generate_array()
            elif button_algorithm.collidepoint(event.pos):
                algorithm_index = (algorithm_index + 1) % len(algorithms)
                selected_algorithm = algorithms[algorithm_index]
            elif button_sort.collidepoint(event.pos):
                if selected_algorithm== "Пузырьком":
                    bubble_sort_visual()
                if selected_algorithm == "Гномья":
                    gnom_sort_visual()
                if selected_algorithm == "Поразрядная":
                    radix_sort_visual()
                if selected_algorithm == "Быстрая":
                    quick_sort_visual(0, 49)
                if selected_algorithm == "Шелла":
                    shell_sort_visual()
    pygame.display.flip()

pygame.quit()




















































