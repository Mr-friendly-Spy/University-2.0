#include "pch.h"
#include "CppUnitTest.h"
#include "../EMP/Engineer.cpp"
#include "../EMP/Employee.cpp"
#include "../EMP/Manager.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EMPTest
{
	TEST_CLASS(EMPTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Engineer engineer1(160, 25.5);
			Assert::AreEqual(engineer1.Salary(), 4080, 0.1);
		}

		TEST_METHOD(TestMethod2)
		{
			Engineer engineer2(140, 30.0);
			Assert::AreEqual(engineer2.Salary(), 4200, 0.1);
		}

		TEST_METHOD(TestMethod3)
		{
			Manager manager1(0, 5000.0, 1000.0);
			Assert::AreEqual(manager1.Salary(), 6000, 0.1);
		}
		
		TEST_METHOD(TestMethod4)
		{
			Manager manager2(0, 6000.0, 1500.0);
			Assert::AreEqual(manager2.Salary(), 7500, 0.1);
		}
		TEST_METHOD(TestMethod5)
		{
			Manager manager2(3, 6000.0, 1500.0);
			Assert::AreEqual(manager2.Salary(), 7500, 0.1);
		}
	};
}
