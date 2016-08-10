// In Practice, You should use the statndard input/output
// in order to receive a score properly.
// Do not use file input and output. Please be very careful.

#include <cstdio>
#include <iostream>

using namespace std;


#define DEBUG 0		// comment out to turn off PRINT_EXPR

#ifdef DEBUG
	#define PRINT_EXPR(a) cout << (#a) << " = " << (a) << endl
#else
	#define PRINT_EXPR(a) do { } while(0)
#endif

// todo
// o array2d -> class SquareArray: init, print, clean

int** get_array2d(int n)
{
	// http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
	int** array2d = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		array2d[i] = new int[n];

		for (int j = 0; j < n; ++j)
		{
			cin >> array2d[i][j];
		}
	}

	return array2d;
}

void print_array2d(int** a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "[";

		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j];

			if (j + 1 < n)
			{
				cout << ", ";
			}
		}

		cout << "]" << endl;
	}
}

void clean_array2d(int** a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
}

int process_test_case()
{
	int n;
	cin >> n;

	PRINT_EXPR(n);

	int** array2d = get_array2d(n);

	#ifdef DEBUG
	print_array2d(array2d, n);
	#endif

	clean_array2d(array2d, n);

	return 0;
}

int main(int argc, char** argv)
{
	int tc, T;

	// The freopen function below opens input.txt file in read only mode, and afterward,
	// the program will read from input.txt file instead of standard(keyboard) input.
	// To test your program, you may save input data in input.txt file,
	// and use freopen function to read from the file when using cin function.
	// You may remove the comment symbols(//) in the below statement and use it.
	// Use #include<cstdio> or #include<stdio.h> to use the function in your program.
	// But before submission, you must remove the freopen function or rewrite comment symbols(//).

	freopen("input.txt", "r", stdin);

	cin >> T;

	PRINT_EXPR(T);

	for(tc = 0; tc < T; tc++)
	{
		/**********************************
		*  Implement your algorithm here. *
		***********************************/

		// Print the answer to standard output(screen).
		cout << process_test_case() << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}