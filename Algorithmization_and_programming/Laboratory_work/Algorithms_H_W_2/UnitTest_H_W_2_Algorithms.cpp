#include "pch.h"
#include "CppUnitTest.h"
#include "../H_W_2_Algorithms/H_W_2_Algorithms.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestHW2Algorithms
{
	TEST_CLASS(UnitTestHW2Algorithms)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
            srand(time(0)); // Для повторяемости
            double x_min = 3.0, x_max = 4.0;
            double y_min = -32.0, y_max = 32.0;
            int num_points = 100000;

            // Запускаем дважды
            double result1 = monte_carlo_area(x_min, x_max, y_min, y_max, num_points);
            double result2 = monte_carlo_area(x_min, x_max, y_min, y_max, num_points);

            // Должны получить одинаковые результаты
            double epsilon1 = 0.1;
            Assert::AreEqual(result1, result2, epsilon1, L"Значения не совпали с данной точностью");
		}

        TEST_METHOD(TestMethod2)
        {
            double x_min = 3.0, x_max = 4.0;
            double y_min = -32.0, y_max = 32.0;
            int num_points = 10000;

            double rect_area = (x_max - x_min) * (y_max - y_min); // 1 * 64 = 64
            double result = monte_carlo_area(x_min, x_max, y_min, y_max, num_points);

            // Проверка, что площадь меньше пощади прямоугольника
            Assert::IsTrue(result < rect_area); 
        }

        TEST_METHOD(TestMethod3)
        {
            double x_min = 3.0, x_max = 4.0;
            double y_min = -32.0, y_max = 32.0;
            int num_points = 10000;

            double result = monte_carlo_area(x_min, x_max, y_min, y_max, num_points);

            // Проверка, что площадь фигуры положительна
            Assert::IsTrue(result > 0);
        }
	};
}
