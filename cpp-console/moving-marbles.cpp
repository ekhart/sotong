#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("simple_input.txt");
	int t;

	in >> t;

    cout << "t = " << t;

    return 0;
}