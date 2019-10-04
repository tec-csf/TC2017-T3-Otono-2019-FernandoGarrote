// Complejidad del algoritmo: O(m*n)
// Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/cpp-program-for-longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);

int subsecuencia( char *X, char *Y, int m, int n )
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;

        else if (X[i - 1] == Y[j - 1])
            L[i][j] = L[i - 1][j - 1] + 1;

        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int main()
{
    char X[] = "GGATB";
    char Y[] = "BGXTGG";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "El tamaño de la subsecuencia es:  "
         << subsecuencia( X, Y, m, n );

    return 0;
}
