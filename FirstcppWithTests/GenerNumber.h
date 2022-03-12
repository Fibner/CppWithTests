#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class GenerNumber
{
public:
	static int GenerEven() {

		return rand()*2;
	}
	static std::vector<int> GetEvenNumbers(size_t size) {
		std::vector<int> result;
		for(size_t i=0;i<size;i++) {
			result.push_back(GenerEven());
		}
		return result;
	}
	static int GetDividedBy(int divisor) {
		int result;
		do
		{
			result = rand();
		} while (result % divisor != 0);
		return result;
	}
	static int GetPrimalRandom(int min, int max, bool fromDown) {
		int result;
		bool isPrime;
		result = (fromDown) ? min-1 : max+1;
		if (min < max) {
			do {
				isPrime = true;
				if (fromDown && result<max) {
					result++;
				}
				else if (!fromDown && result>min)
				{
					result--;
				}
				else
				{
					result = -1;
				}
				for (int i = 2; i < result; i++)
				{
					if (result % i == 0) {
						isPrime = false;
					}
				}
			} while (!isPrime && result != 0);
		}
		else
		{
			result = -1;
		}		
		
		return result;
	}
	static vector<int> GetPrimalRandomVec(int min, int max, bool fromDown) {
		vector<int> result;
		int primal;
		bool isPrime;
		primal = (fromDown) ? min-1 : max+1;
		if (min < max) {
			for (size_t i = min; i < max; i++){
				isPrime = true;
				if (fromDown && primal < max) {
					primal++;
				}
				else if (!fromDown && primal > min)
				{
					primal--;
				}
				else
				{
					primal = -1;
				}
				for (int i = 2; i < primal; i++)
				{
					if (primal % i == 0) {
						isPrime = false;
					}
				}
				if (isPrime && primal != 0) {
					result.push_back(primal);
				}
			}
		}
		else
		{
			primal = -1;
		}

		return result;
	}
};

