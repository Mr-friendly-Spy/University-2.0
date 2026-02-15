#include "pch.h"
#include "CppUnitTest.h"
#include "../H_W_1_Algorithms/H_W_1_Algorithms.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestHWAlgorithms
{
	TEST_CLASS(UnitTestHWAlgorithms)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            std::queue<int> q;
            q.push(10);
            q.push(20);
            int initialSize = q.size();
            int valueToAdd = 30;

            int newSize = add_to_queue(q, valueToAdd);

            Assert::AreEqual(initialSize + 1, newSize, L"Размер очереди должен увеличиться на 1");
            Assert::AreEqual(valueToAdd, q.back(), L"Последний элемент должен быть добавленным значением");
            Assert::AreEqual(3, (int)q.size(), L"Общий размер очереди должен быть 3");
        };

        TEST_METHOD(TestMethod2)
        {
            std::queue<int> q;
            int initialSize = q.size();
            int valueToAdd = 42;

            int newSize = add_to_queue(q, valueToAdd);

            Assert::AreEqual(initialSize + 1, newSize, L"Размер очереди должен стать 1");
            Assert::AreEqual(valueToAdd, q.back(), L"Единственный элемент должен быть добавленным значением");
            Assert::AreEqual(1, (int)q.size(), L"Размер очереди должен быть 1");
        };

        TEST_METHOD(TestMethod3)
        {
            std::queue<int> q;
            q.push(10);
            q.push(20);

            auto [result, executionTime] = measure_execution_time(add_to_queue, q, 30);

            Assert::IsTrue(executionTime >= 0, L"Время выполнения должно быть неотрицательным");
            Assert::AreEqual(3, result, L"Результат функции должен быть правильным");
            Assert::AreEqual(30, q.back(), L"Элемент должен быть добавлен в очередь");
        };

	};
}
