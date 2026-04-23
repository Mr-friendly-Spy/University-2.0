#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <random>
#include "C:\\Users\\Егор\\source\\repos\\Quick_sort_parallelisation\Quick_sort_parallelisation.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestforparallesation
{
	TEST_CLASS(UnitTestforparallesation)
	{
	public:
		// Тест на пустом массиве
		TEST_METHOD(TestEmptyArray)
		{
			std::vector<int> arr;
			std::vector<int> expected;

			if (arr.size() > 0)
				quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
			else
				quickSort(arr, 0, -1); // Пустой массив

			Assert::IsTrue(arr == expected);
		}

		// Тест на массиве из одного элемента
		TEST_METHOD(TestSingleElement)
		{
			std::vector<int> arr = { 42 };
			std::vector<int> expected = { 42 };

			quickSort(arr, 0, static_cast<int>(arr.size()) - 1);

			Assert::IsTrue(arr == expected);
		}

		// Тест на уже отсортированном массиве
		TEST_METHOD(TestSortedArray)
		{
			std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			quickSort(arr, 0, static_cast<int>(arr.size()) - 1);

			Assert::IsTrue(arr == expected);
		}
	};
}
