// SortowanieBabelkowe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortuj(int[], int);	// tablica i ile element�w

int main()
{
	int ile_el = 40;		// ile elementow w tablicy
	int *elementy = new int[ile_el];	// tworzymy dynamicznie tablicy
	srand(time(NULL));

	cout << "Tablica przed sortowaniem:" << endl;
	for (int i = 0; i < ile_el; i++) {	// losowe liczby do tablicy
		elementy[i] = 1 + rand() % 200;
		cout << elementy[i] << " ";
	}

	sortuj(elementy, ile_el);		// sortuj i wy�wietl

	cout << endl << endl << "Tablica po sortowaniu:" << endl;
	for (int i = 0; i < ile_el; i++)
		cout << elementy[i] << " ";

	delete[] elementy;	// usuwamy z pami�ci tablic�

	getchar();
	return 0;
}

void sortuj(int elementy[], int ile)
{
	int temp, j;
	for (int i = 1; i < ile; i++)
	{
		temp = elementy[i]; // pobieramy kolejne elementy do tymaczasowej
		// przechodzimy po posortowanych elementach w d� a� do 0, lub tak d�ugo p�ki nie napotkamy elementu r�wnego lub wi�kszego
		for (j = i - 1; j >= 0 && elementy[j] > temp; j--)		
		{
			elementy[j + 1] = elementy[j];
		}
		elementy[j + 1] = temp;
	}
}