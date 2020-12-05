#pragma once
class Recursion
{
public:
	static int  Factorial(int num);
	static int  FactorialWithStaticVar(int num);
	static void TailRecursionExample(int num);
	static void HeadRecursionExample(int num);
	static void TreeRecursion(int num);
	static void IndirectRecursion(int num);
private:
	static void IndirectRecursionB(int num);
public:
	static int NestedRecursion(int num);
	static int SumOfNaturalNumbers(int num);
	static int Power(int m, int n);
	static double EulerNumPow(int powNum, int precision);
	static int Fibonacci(int termIndex);
	static int OptimizedFibonacci(int termIndex);
};

