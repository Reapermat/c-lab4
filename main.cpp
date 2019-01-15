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
	Napis imie, nazwisko;
	
	/*Pracownik pierwszy;
	pierwszy.Wpisz();
	cout << pierwszy.SprawdzImie("Jan");
	cout << pierwszy.SprawdzNazwisko("Kowalski");
	cout << endl;
	pierwszy.Wypisz();
	*/
	while (1)
	{
		cout << "1. dodaj Pracownik" << endl;
		cout << "2. usun Pracownik" << endl;
		cout << "3. wyswietl Pracownik" << endl;
		cout << "4. szukaj pracownika" << endl;
		cout << "5. Zapis pracownikow do pliku" << endl;
		cout << "6. Zapisanie pracownikow z pliku" << endl;
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
			nowy = new Pracownik;
			nowy->Wpisz();
			listaPracownikow.Usun(*nowy);
			break;
		}
		case 3:
		{
			listaPracownikow.WypiszPracownikow();
			break;
		}
		case 4:
		{
			cout << "Podaj imie i nazwisko " << endl;
			cout << "Imie" <<endl;
			imie.Wpisz();
			cout << "Nazwisko: " << endl;
			nazwisko.Wpisz();		
			listaPracownikow.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			break;
		}
		case 5:
		{
			listaPracownikow.ZapisDoPliku();
			break;
		}
		case 6:
		{
			listaPracownikow.WczytajZPliku();
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