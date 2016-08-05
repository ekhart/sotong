#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

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
	// check if all values in pockets are the same
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

	// test all_pockets_the_same
	int a[] = {1, 2, 3};
	int b[] = {1, 1, 1};
	PRINT_EXPR(all_pockets_the_same(a, 3));
	PRINT_EXPR(all_pockets_the_same(b, 3));

    return 0;
}