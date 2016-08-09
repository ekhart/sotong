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

// dont work
// #define DEBUG 1

// #define PRINT_EXPR(a) #ifdef DEBUG			\
// 	cout << (#a) << " = " << (a) << endl	\
// 	#endif

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

int abs(int n)
{
	return n < 0 ? -n : n;
}

int get_moving_marbles_count(int* pockets, int n)
{
	int pockets_sum = sum(pockets, n);
	PRINT_EXPR(pockets_sum);

	int marbles_per_pocket = pockets_sum / n;
	PRINT_EXPR(marbles_per_pocket);

	int max_pocket_index = max_index(pockets, n);
	PRINT_EXPR(max_pocket_index);

	int min_pocket_index = min_index(pockets, n);
	PRINT_EXPR(min_pocket_index);

	int moving_count = 0;

	for (int i = 0; i < n; ++i)
	{
		print_array(pockets, n);

		int diff = marbles_per_pocket - pockets[i];
		PRINT_EXPR(diff);

		pockets[i] += diff;
		moving_count += diff;

		if (diff > 0)
		{
			pockets[max_pocket_index] -= diff;
		}
		else if (diff < 0)
		{
			pockets[min_pocket_index] += diff;
		}

		max_pocket_index = max_index(pockets, n);
		min_pocket_index = min_index(pockets, n);
	}

	return moving_count;
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

void process_test_case()
{
	int n;
	cin >> n;
	PRINT_EXPR(n);

	int* pockets = get_pockets(n);

	print_array(pockets, n);

	cout << get_moving_marbles_count(pockets, n) << endl;
}

#define ASSERT(expr, expected)											\
{																		\
	int value = (expr); 												\
	if (value != (expected))											\
	{																	\
		cout << __DATE__ << " " << __TIME__ << " FAIL at line " << __LINE__ << ":\n" ;		\
		PRINT_EXPR(expr);												\
	}																	\
}

// void assert(int expected, int actual)
// {
// 	if (expected != actual)
// 	{

// 	}
// }

void test()
{
	cout << "\nTESTS:" << endl;
	// test all_pockets_the_same
	int a[] = {1, 2, 3};
	int b[] = {1, 1, 1};
	int c[] = {3, 2, 1};
	int size = 3;

	ASSERT(all_pockets_the_same(a, size), 0);
	ASSERT(all_pockets_the_same(b, size), 1);

	ASSERT(min(a, size), 1);
	ASSERT(max(a, size), 3);

	ASSERT(sum(a, size), 6);
	ASSERT(sum(b, size), 3);

	ASSERT(min_index(a, size), 0);
	ASSERT(max_index(a, size), 2);

	ASSERT(get_moving_marbles_count(a, size), 1);
	ASSERT(get_moving_marbles_count(b, size), 0);
	ASSERT(get_moving_marbles_count(c, size), 1);

	ASSERT(abs(-1), 1);
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