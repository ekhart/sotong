#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

// void println(std::string s)
// {
// 	cout >> s >> endl;
// }

void print_array(int* a, int n)
{
	cout << "[";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ", ";
	}
	cout << "]" << endl;
}

void process_test_case()
{
	int n;
	cin >> n;
	cout << "n = " << n << endl;

	int* pocket = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> pocket[i];
	}

	print_array(pocket, n);
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

    return 0;
}