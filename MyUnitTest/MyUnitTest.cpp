#include "pch.h"
#include "CppUnitTest.h"
#include "../FirstcppWithTests/GenerNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyUnitTest
{
	TEST_CLASS(MyUnitTest)
	{
	public:
		
		TEST_METHOD(Even_Test)
		{
			GenerNumber gn;
			int ff = gn.GenerEven();
			Assert::IsTrue(ff % 2 == 0);
		}
		TEST_METHOD(Even_Test_Static)
		{			
			int ff = GenerNumber::GenerEven();
			Assert::IsTrue(ff % 2 == 0);
		}
		TEST_METHOD(Even_Test_Two_numbers)
		{
			int ff1 = GenerNumber::GenerEven();
			int ff2 = GenerNumber::GenerEven();
			Assert::IsTrue(ff1!=ff2);
		}
		TEST_METHOD(Even_Test_vector_numbers)
		{
			std::vector<int> result = GenerNumber::GetEvenNumbers(8);
			for (size_t i = 0; i < result.size(); i++) {
				Assert::IsTrue(result[i] % 2 == 0);
			}
		}
		TEST_METHOD(Divide_Test_number)
		{
			int number = 2;
			int result = GenerNumber::GetDividedBy(number);
			
			Assert::IsTrue(result % number == 0);
		}
		TEST_METHOD(Primal_Test_random_number)
		{
			srand(time(NULL));
			int primalNumber = GenerNumber::GetPrimalRandom(2,10,false);
			Assert::IsTrue(primalNumber == 7);
			int cantBePrimal = GenerNumber::GetPrimalRandom(4, 4, true);
			Assert::IsTrue(cantBePrimal == -1);
			int maxBiggerThanMin = GenerNumber::GetPrimalRandom(5, 1, true);
			Assert::IsTrue(maxBiggerThanMin == -1);
		}
		TEST_METHOD(Primal_Test_random_vector)
		{
			srand(time(NULL));
			vector<int> primalNumberVector = GenerNumber::GetPrimalRandomVec(2, 100, false);
			for (size_t i = 0; i <= primalNumberVector.size(); i++)
			{
				for (size_t i = 2; i < primalNumberVector.at(i); i++)
				{
					Assert::IsTrue(primalNumberVector.at(i) % i != 0);
				}
			}
		}
	};
}
