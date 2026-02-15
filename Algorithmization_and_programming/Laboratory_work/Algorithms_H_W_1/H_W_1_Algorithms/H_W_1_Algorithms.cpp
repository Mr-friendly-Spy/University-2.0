#include <iostream>
#include <queue>
#include <limits>
#include <chrono>

template <typename Func, typename... Args>
auto measure_execution_time(Func&& func, Args&&... args) { //... - многоточие стилистическое , важно два амперсанта - передаём сколько угдно аргументов, один - один аргумент
    auto start_time = std::chrono::high_resolution_clock::now();  // Начинаем отсчет времени
    auto result = func(std::forward<Args>(args)...);  // Выполняем переданную функцию с аргументами
    auto end_time = std::chrono::high_resolution_clock::now();  // Останавливаем отсчет времени

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);  // Вычисляем продолжительность в наносекундах
    return std::make_pair(result, duration.count());  // Возвращаем результат и время выполнения
}

// Функция для добавления элемента в очередь
int add_to_queue(std::queue<int>& q, int value) {
    q.push(value);
    return q.size(); // Возвращаем размер очереди после добавления
}

int main() {
    std::queue<int> my_queue;

    // Добавляем несколько начальных элементов
    my_queue.push(10);
    my_queue.push(20);
    my_queue.push(30);

    std::cout << "Initial queue size: " << my_queue.size() << std::endl;

    for (int i = 1; i <= 10; i++) {
        // Измеряем время добавления нового элемента
        auto [new_size, execution_time] = measure_execution_time(add_to_queue, my_queue, 40 + i);

        std::cout << "------------------------------------------" << std::endl;
        std::cout << "New queqe size: " << new_size << std::endl;
        std::cout << "The time when the element was added: " << execution_time << " ns" << std::endl;
        std::cout << "The last element in the queue: " << my_queue.back() << " " << std::endl;
    }

    return 0;
}