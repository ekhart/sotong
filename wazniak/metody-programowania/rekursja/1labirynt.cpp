#include <cstdio>
#include <iostream>

using namespace std;

#define DEBUG 1		// comment out to turn off PRINT_EXPR

#ifdef DEBUG
	#define PRINT_EXPR(a) cout << (#a) << " = " << (a) << endl
#else
	#define PRINT_EXPR(a) do { } while(0)
#endif

// Zadanie 1 (Labirynt)
// Czy istnieje ścieżka miedzy wskazanymi punktami (i1,j1) i (i2,j2) 
// w labiryncie reprezentowanym przez prostokątną tablicę liczb całkowitych o rozmiarze M×N, 
// zawierającą zera (ściana) i jedynki (droga)? 
// Zakładamy, że nie można przechodzić z pola na pole po skosie (np. z (2,5) na (3,6)), 
// a tylko w czterech podstawowych kierunkach (np. z (2,5) na (3,5), (2,4) itd.) 

int main(int argc, char** argv)
{
    freopen("input.txt", "r", stdin);

    int m, n;
    cin >> m;
    cin >> n;

    PRINT_EXPR(m);
    PRINT_EXPR(n);
    
    return 0;
}