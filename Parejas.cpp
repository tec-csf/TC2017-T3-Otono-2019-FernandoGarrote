//Complejidad del algoritmo: O(n^2)
//Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/stable-marriage-problem/


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define N  4

bool Pref(int prefer[2*N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {

        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
           return false;
    }
}

void RelacionEstable(int prefer[2*N][N])
{

    int parejaM[N];

    bool hombreL[N];

    memset(parejaM, -1, sizeof(parejaM));
    memset(hombreL, false, sizeof(hombreL));
    int freeCount = N;

    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (hombreL[m] == false)
                break;

        for (int i = 0; i < N && hombreL[m] == false; i++)
        {
            int w = prefer[m][i];

            if (parejaM[w-N] == -1)
            {
                parejaM[w-N] = m;
                hombreL[m] = true;
                freeCount--;
            }

            else
            {
                int m1 = parejaM[w-N];

                if (Pref(prefer, w, m, m1) == false)
                {
                    parejaM[w-N] = m;
                    hombreL[m] = true;
                    hombreL[m1] = false;
                }
            }
        }
    }


    cout << "Mujeres Hombres" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "\t" << parejaM[i] << endl;
}

int main()
{
    int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    RelacionEstable(prefer);

    return 0;
}
