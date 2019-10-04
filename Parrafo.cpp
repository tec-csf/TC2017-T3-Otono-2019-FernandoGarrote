//  Complejidad del algoritmo: O(n^2)
//Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/word-wrap-problem-dp-19/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF INT_MAX

int Respuesta(int sol[], int tam);

void DivisionParrafos(int letras[], int tam, int espacio){

 int espacioEX[tam+1][tam+1];
 int costo[tam+1][tam+1];
 int costoTot[tam+1];
 int sol[tam+1];
 int a, b;

 for (a = 1; a <= tam; a++)
 {
	 espacioEX[a][a] = espacio - letras[a-1];
	 for (b = a+1; b <= tam; b++)
		 espacioEX[a][b] = espacioEX[a][b-1] - letras[b-1] - 1;
 }

 for (a = 1; a <= tam; a++)
 {
	 for (b = a; b <= tam; b++)
	 {
		 if (espacioEX[a][b] < 0)
			 costo[a][b] = INF;
		 else if (b == tam && espacioEX[a][b] >= 0)
			 costo[a][b] = 0;
		 else
			 costo[a][b] = espacioEX[a][b]*espacioEX[a][b];
	 }
 }

 costoTot[0] = 0;
 for (b = 1; b <= tam; b++)
 {
	 costoTot[b] = INF;
	 for (a = 1; a <= b; a++)
	 {
		 if (costoTot[a-1] != INF && costo[a][b] != INF &&
					 (costoTot[a-1] + costo[a][b] < costoTot[b]))
		 {
			 costoTot[b] = costoTot[a-1] + costo[a][b];
			 sol[b] = a;
		 }
	 }
 }

 Respuesta(sol, tam);
}

int Respuesta(int sol[], int tam)
{
 int linea;
 if (sol[tam] == 1)
	 linea = 1;
 else
	 linea = Respuesta(sol, sol[tam]-1) + 1;

 cout << "\nNúmero de línea: " << linea << "\nDe la palabra número: " << sol[tam] << " a " << tam << "\n\n";

 return linea;
}

int main()
{
 int letras[] = {9, 4, 4, 2};
 int tam = sizeof(letras)/sizeof(letras[0]);
 int espacio = 6;

 DivisionParrafos(letras, tam, espacio);

 return 0;
}
