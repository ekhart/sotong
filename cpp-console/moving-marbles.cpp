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

int get_moving_marbles_count(int* pockets, int n)
{
	// get max element in pockets
	// save it index & value
	// remove marble from it
	// and give it to the min pockets
	// v check if all values in pockets are the same
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

void process_test_case()
{
	int n;
	cin >> n;
	cout << "n = " << n << endl;

	int* pockets = get_pockets(n);

	print_array(pockets, n);

	int count = get_moving_marbles_count(pockets, n);

	cout << count << endl;
}

#define PRINT_EXPR(a) cout << (#a) << " = " << (a) << endl;

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

	PRINT_EXPR(all_pockets_the_same(a, size));
	PRINT_EXPR(all_pockets_the_same(b, size));

	PRINT_EXPR(min(a, size));

	PRINT_EXPR(max(a, size));
}

int main()
{
	freopen("simple_input.txt", "r", stdin);
	// ifstream in("simple_input.txt");
	int t, n;

	cin >> t;
    cout << "t = " << t << endl;

	for(int tc = 0; tc < t; tc++)
	{
		process_test_case();
	}

	test();

    return 0;
}