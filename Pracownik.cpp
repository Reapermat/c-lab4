#include "Pracownik.h"
#include "Napis.h"
#include "Data.h"
#include "string.h"
#include <iostream>

using namespace std;


Pracownik::Pracownik()
{
}


Pracownik::~Pracownik()
{
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);

}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << " "  ;
	m_Nazwisko.Wypisz();
	cout << " "  ;
	m_DataUrodzenia.Wypisz();

}

void Pracownik::Wpisz()
{
	cout << "Imie: " << endl;
	m_Imie.Wpisz();
	cout << "Nazwisko: " << endl;
	m_Nazwisko.Wpisz();
	cout << "Data urodzenia" << endl;
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik & wzorzec) const
{
	if (m_Imie.SprawdzNapis(wzorzec.Imie()) == 0 && m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 && m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia)==0)
	return 0;
	else {
		if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) > 0)
			return 1;
		else if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 && m_Imie.SprawdzNapis(wzorzec.Imie()) > 0)
			return 1;
		else if ((m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 && m_Imie.SprawdzNapis(wzorzec.Imie()) == 0) && m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) > 0)
			return 1;
		else
			return -1;
	}

}


