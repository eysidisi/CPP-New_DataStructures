#include "Recursion.h"
#include <iostream>
#include <memory>
#include <random>
#include <iterator>
#include <algorithm>
#include <functional>

int Recursion::Factorial(int num)
{
	if (num == 0)
	{
		return 1;
	}

	return num * Factorial(num - 1);
}

int Recursion::FactorialWithStaticVar(int num)
{
	static int result = 1;

	if (num == 0)
	{
		return result;
	}

	result = result * num;
	FactorialWithStaticVar(num - 1);
}

void Recursion::TailRecursionExample(int num)
{
	if (num == 0)
		return;
	std::cout << num << " ";
	return TailRecursionExample(num - 1);
}

void Recursion::HeadRecursionExample(int num)
{
	if (num == 0)
		return;
	HeadRecursionExample(num - 1);
	std::cout << num << " ";
}

void Recursion::TreeRecursion(int num)
{
	if (num > 0)
	{
		std::cout << num << " ";
		TreeRecursion(num - 1);
		TreeRecursion(num - 1);
	}
}

void Recursion::IndirectRecursion(int num)
{
	if (num > 1)
	{
		std::cout << num << " ";
		IndirectRecursionB(num / 2);
	}
}

void Recursion::IndirectRecursionB(int num)
{
	if (num > 1)
	{
		std::cout << num % 2 << " ";
		IndirectRecursion(num - 1);
	}
}

int Recursion::NestedRecursion(int num)
{
	if (num > 100)
		return num - 10;

	return NestedRecursion(NestedRecursion(num + 11));
}

int Recursion::SumOfNaturalNumbers(int num)
{
	if (num <= 0)
		return 0;
	return num + SumOfNaturalNumbers(num - 1);
}

int Recursion::Power(int m, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return m;

	if (n % 2 == 0)
		return Power(m * m, n / 2);

	return m * Power(m * m, floor(n / 2));

	return m * Power(m, n - 1);
}

/// <summary>
/// Calculated e^pownum with given precision num
/// </summary>
/// <param name="powNum"></param>
/// <param name="precision"></param>
/// <returns></returns>
double Recursion::EulerNumPow(int powNum, int precision)
{
	if (powNum == 0 || precision == 0)
		return 1;

	return EulerNumPow(powNum, precision - 1) + (double)Power(powNum, precision) / (double)Factorial(precision);

}

int Recursion::Fibonacci(int termIndex)
{
	if (termIndex <= 1)
		return termIndex;
	return Fibonacci(termIndex - 1) + Fibonacci(termIndex - 2);
}

int Recursion::OptimizedFibonacci(int termIndex)
{
	auto func = [](int size) {
		std::vector<int> newVec;

		for (size_t i = 0; i < size; i++)
		{
			newVec.push_back(-1);
		}

		return newVec;
	};

	static std::vector<int> fibArr = func(termIndex + 1);

	if (termIndex <= 1)
		return termIndex;

	if (fibArr[termIndex - 1] != -1 && fibArr[termIndex - 2] != -1)
	{
		fibArr[termIndex] = fibArr[termIndex - 1] + fibArr[termIndex - 2];
	}

	else if (fibArr[termIndex - 1] != -1)
	{
		fibArr[termIndex] = fibArr[termIndex - 1] + OptimizedFibonacci(termIndex - 2);
	}

	else if (fibArr[termIndex - 2] != -1)
	{
		fibArr[termIndex] = fibArr[termIndex - 2] + OptimizedFibonacci(termIndex - 1);
	}

	else
	{
		fibArr[termIndex] = OptimizedFibonacci(termIndex - 2) + OptimizedFibonacci(termIndex - 1);
	}

	return fibArr[termIndex];
}

