#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функции для верхней и нижней границ
double upper(double x) {
    return x * x + 4 * x;
}

double lower(double x) {
    return -x * x - 4 * x;
}

// Метод Монте-Карло для площади между кривыми
double monte_carlo_area(double x_min, double x_max, double y_min, double y_max, int num_points) {
    int points_inside = 0;

    for (int i = 0; i < num_points; ++i) {
        // Случайная точка в прямоугольнике
        double x = x_min + (rand() / (RAND_MAX + 1.0)) * (x_max - x_min);
        double y = y_min + (rand() / (RAND_MAX + 1.0)) * (y_max - y_min);

        // Проверяем, попала ли точка внутрь фигуры
        if (y >= lower(x) && y <= upper(x)) {
            points_inside++;
        }
    }

    double rect_area = (x_max - x_min) * (y_max - y_min); // площадь прямоугольника
    return (points_inside / static_cast<double>(num_points)) * rect_area; 
}

int main() {
    srand(time(0));

    double x_min = 3.0, x_max = 4.0;
    double y_min = -32.0, y_max = 32.0; //Вручную найдём экстремумы на отрезке [3, 4]
    int num_points = 1000000;

    double area = monte_carlo_area(x_min, x_max, y_min, y_max, num_points);
    cout << "Approximate area of the shape: " << area << endl;

    return 0;
}