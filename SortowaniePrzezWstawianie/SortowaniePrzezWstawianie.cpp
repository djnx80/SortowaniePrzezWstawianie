// SortowanieBabelkowe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortuj(int[], int);	// tablica i ile elementów

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

	sortuj(elementy, ile_el);		// sortuj i wyœwietl

	cout << endl << endl << "Tablica po sortowaniu:" << endl;
	for (int i = 0; i < ile_el; i++)
		cout << elementy[i] << " ";

	delete[] elementy;	// usuwamy z pamiêci tablicê

	getchar();
	return 0;
}

void sortuj(int elementy[], int ile)
{
	int temp, j;
	for (int i = 1; i < ile; i++)
	{
		temp = elementy[i]; // pobieramy kolejne elementy do tymaczasowej
		// przechodzimy po posortowanych elementach w dó³ a¿ do 0, lub tak d³ugo póki nie napotkamy elementu równego lub wiêkszego
		for (j = i - 1; j >= 0 && elementy[j] > temp; j--)		
		{
			elementy[j + 1] = elementy[j];
		}
		elementy[j + 1] = temp;
	}
}