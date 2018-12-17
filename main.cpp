#include<iostream>
#include"Pracownik.h"
#include"Data.h"
#include"Napis.h"
#include"ListaPracownik.h"

using namespace std;

int main()
{
	int z;
	ListaPracownik listaPracownikow;
	Pracownik* nowy;
	/*Pracownik pierwszy;
	pierwszy.Wpisz();
	cout << pierwszy.SprawdzImie("Jan");
	cout << pierwszy.SprawdzNazwisko("Kowalski");
	cout << endl;
	pierwszy.Wypisz();
	*/
	while (1)
	{
		cout << "1.dodaj Pracownik" << endl;
		cout << "2. wyswietl Pracownik" << endl;
		cout << "0. zakoncz program" << endl;
		cin >> z;
		switch (z) 
		{
		case 1:
		{
			cin.clear();
			nowy = new Pracownik;
			nowy->Wpisz();
			listaPracownikow.Dodaj(*nowy);
			break;

		}
		case 2:
		{
			listaPracownikow.WypiszPracownikow();
			break;
		}
		case 0:
		{
			exit(0);
		}
		}
	}

	
	system("pause");

}