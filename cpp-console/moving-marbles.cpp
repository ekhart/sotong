#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

// void println(std::string s)
// {
// 	cout >> s >> endl;
// }

void process_test_case()
{
	int n;
	cin >> n;
	cout << "n = " << n << endl;

	for (int i = 0; i < n; i++)
	{

	}
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