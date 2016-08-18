#include <cstdio>
#include <iostream>

using namespace std;

#define DEBUG 1		// comment out to turn off PRINT_EXPR

#ifdef DEBUG
	#define PRINT_EXPR(a) cout << (#a) << " = " << (a) << endl
#else
	#define PRINT_EXPR(a) do { } while(0)
#endif

#define ASSERT(expr, expected)											\
{																		\
	int value = (expr); 												\
	if (value != (expected))											\
	{																	\
		cout << __DATE__ << " " << __TIME__ << " FAIL at line " << __LINE__ << ":\n" ;		\
		PRINT_EXPR(expr);												\
	}																	\
}

// Zadanie 1 (Labirynt)
// Czy istnieje ścieżka miedzy wskazanymi punktami (i1,j1) i (i2,j2) 
// w labiryncie reprezentowanym przez prostokątną tablicę liczb całkowitych o rozmiarze M×N, 
// zawierającą zera (ściana) i jedynki (droga)? 
// Zakładamy, że nie można przechodzić z pola na pole po skosie (np. z (2,5) na (3,6)), 
// a tylko w czterech podstawowych kierunkach (np. z (2,5) na (3,5), (2,4) itd.) 

int** get_maze(int m, int n)
{
    int** maze = new int*[m];
    for (int i = 0; i < m; i++) 
    {
        maze[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    return maze;
}

void print_maze(int** maze, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		cout << "[";

		for (int j = 0; j < n; ++j)
		{
			cout << maze[i][j];

			if (j + 1 < n)
			{
				cout << ", ";
			}
		}

		cout << "]" << endl;
	}
}

const int WALL_SYMBOL = 0;
const int PATH_SYMBOL = 1;

bool is_path(int** maze, int i, int j)
{
    return maze[i][j] == PATH_SYMBOL;
}

bool is_wall(int** maze, int i, int j)
{
    return maze[i][j] == WALL_SYMBOL;
}

void is_path_step(int** maze, int m, int n, int i, int j)
{
    if (is_path(maze, i, j))
    {
        if (i-1 >= 0)
        {
            is_path_step(maze, m, n, i-1, j);
        }
        else if (j-1 >= 0)
        {
            is_path_step(maze, m, n, i, j-1);
        }
        else if (i+1 <= m) 
        {
            is_path_step(maze, m, n, i+1, j);
        }
        else if (j+1 <= n)
        {
            is_path_step(maze, m, n, i, j+1);
        }
    }
}

bool is_path_between(int** maze, int m, int n, int i1, int j1, int i2, int j2)
{
    int i = i1, 
        j = j1;

    
    
    return false;
}

int test(int** maze, int m, int n, int i1, int j1, int i2, int j2)
{
    cout << "\nTESTS:" << endl;

    ASSERT(is_path(maze, 0, 0), true);
    ASSERT(is_path(maze, 0, 1), false);

    ASSERT(is_wall(maze, 0, 0), false);
    ASSERT(is_wall(maze, 0, 1), true);
}

int main(int argc, char** argv)
{
    freopen("input.txt", "r", stdin);

    int m, n;
    cin >> m;
    cin >> n;

    PRINT_EXPR(m);
    PRINT_EXPR(n);

    int i1, j1, i2, j2;

    cin >> i1 >> j1;
    cin >> i2 >> j2;

    PRINT_EXPR(i1);
    PRINT_EXPR(j1);
    PRINT_EXPR(i2);
    PRINT_EXPR(j2);

    int** maze = get_maze(m, n);
    print_maze(maze, m, n);

    test(maze, m, n, i1, j1, i2, j2);

    //cout << (is_path_between(maze, m, n, i1, j1, i2, j2) ? "yes" : "no") << endl;
    
    return 0;
}