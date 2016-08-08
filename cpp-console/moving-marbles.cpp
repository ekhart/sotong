#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

// Moving Marbles
// http://sotong.sec.samsung.net/sotong/practice/practiceProbView.do?practiceProbId=AUpvxfDFwOzVldKY#

// void println(std::string s)
// {
// 	cout >> s >> endl;
// }

#define PRINT_EXPR(a) cout << (#a) << " = " << (a) << endl

int* get_pockets(int n)
{
	int* pockets = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> pockets[i];
	}

	return pockets;
}

void print_array(int* a, int n)
{
	cout << "[";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];

		if (i + 1 < n)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

int sum(int* pockets, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += pockets[i];
	}
	return sum;
}

int get_moving_marbles_count(int* pockets, int n)
{
	// get max element in pockets
	// save it index & value
	// remove marble from it
	// and give it to the min pockets
	// v check if all values in pockets are the same
	int pockets_sum = sum(pockets, n);
	PRINT_EXPR(pockets_sum);

	int marbles_per_pocket = pockets_sum / n;
	PRINT_EXPR(marbles_per_pocket);

	return 4;
}

bool all_pockets_the_same(int* pockets, int n)
{
	int value;
	if (n > 0)
	{
		value = pockets[0];
	}

	for (int i = 0; i < n; ++i)
	{
		if (pockets[i] != value)
		{
			return false;
		}
	}

	return true;
}

int min(int* pockets, int n)
{
	int min = pockets[0];
	for (int i = 0; i < n; ++i)
	{
		if (min > pockets[i])
		{
			min = pockets[i];
		}
	}
	return min;
}

int min_index(int* pockets, int n)
{
	int min = pockets[0],
		index = 0;

	for (int i = 0; i < n; ++i)
	{
		if (min > pockets[i])
		{
			min = pockets[i];
			index = i;
		}
	}

	return index;
}

int max(int* pockets, int n)
{
	int max = pockets[0];
	for (int i = 0; i < n; ++i)
	{
		if (max < pockets[i])
		{
			max = pockets[i];
		}
	}
	return max;
}

int max_index(int* pockets, int n)
{
	int max = pockets[0],
		index = 0;

	for (int i = 0; i < n; ++i)
	{
		if (max < pockets[i])
		{
			max = pockets[i];
			index = i;
		}
	}

	return index;
}

void process_test_case()
{
	int n;
	cin >> n;
	PRINT_EXPR(n);

	int* pockets = get_pockets(n);

	print_array(pockets, n);

	int count = get_moving_marbles_count(pockets, n);

	cout << count << endl;
}

#define ASSERT(expr, expected) 											\
	if ((expr) != (expected))											\
	{																	\
		cout << __DATE__ << " FAIL at line " << __LINE__ << ":\n" ;		\
		PRINT_EXPR(expr);												\
	}																	\

// void assert(int expected, int actual)
// {
// 	if (expected != actual)
// 	{

// 	}
// }

void test()
{
	// test all_pockets_the_same
	int a[] = {1, 2, 3};
	int b[] = {1, 1, 1};
	int size = 3;

	ASSERT(all_pockets_the_same(a, size), 0);
	ASSERT(all_pockets_the_same(b, size), 1);

	ASSERT(min(a, size), 1);
	ASSERT(max(a, size), 3);

	ASSERT(sum(a, size), 6);
	ASSERT(sum(b, size), 3);

	ASSERT(min_index(a, size), 0);
	ASSERT(max_index(a, size), 2);
}

int main()
{
	freopen("simple_input.txt", "r", stdin);
	// ifstream in("simple_input.txt");
	int t, n;

	cin >> t;
    PRINT_EXPR(t);

	for(int tc = 0; tc < t; tc++)
	{
		process_test_case();
	}

	test();

    return 0;
}