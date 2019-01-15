#include "ListaPracownik.h"
#include "Pracownik.h"
#include <iostream>

using namespace std;

ListaPracownik::ListaPracownik()
{
	m_nLiczbaPracownikow = 0;
	m_pPoczatek = nullptr;
}


ListaPracownik::~ListaPracownik()
{
	Pracownik *aktualny = m_pPoczatek;
	if (m_nLiczbaPracownikow == 0)
	{
		cout << "Lista pracownikow jest pusta!" << endl;
	}
	else
		while (aktualny != nullptr)
		{
			aktualny = aktualny->m_pNastepny;
			delete m_pPoczatek;
			m_pPoczatek = aktualny;

		}

}

void ListaPracownik::Dodaj(const Pracownik & p)
{
	Pracownik *pomoc = m_pPoczatek, *pop = nullptr;

	if (m_nLiczbaPracownikow == 0)
	{
		Pracownik *k = new Pracownik(p);
		m_pPoczatek = k;
		k->m_pNastepny = nullptr;
		m_nLiczbaPracownikow++;
		return;
	}

	else {
		while (pomoc != nullptr)
		{
			if (pomoc->Porownaj(p) > 0)
			{
				Pracownik *k = new Pracownik(p);
				if (pop)
				{
					pop->m_pNastepny = k;
				}
				else
					m_pPoczatek = k;
				k->m_pNastepny = pomoc;
				m_nLiczbaPracownikow++;
				return;
			}
			else if (pomoc->Porownaj(p) == 0)
			{
				cout << "Obiekt juz wystepuje" << endl;
				return;
			}
			pop = pomoc;
			pomoc = pomoc->m_pNastepny;
		}
		Pracownik *k = new Pracownik(p);
		pop->m_pNastepny = k;
		k->m_pNastepny = nullptr;
		++m_nLiczbaPracownikow;
	}
}

void ListaPracownik::WypiszPracownikow() const
{
	Pracownik* aktualny = m_pPoczatek;
	if (m_nLiczbaPracownikow == 0)
	{
		cout << "Lista pracownikow jest pusta" << endl;
	}
	else 
	{
		for (int i = 1; i <= m_nLiczbaPracownikow; i++)
		{
			cout << "Pracownik #" << i << ": ";
			aktualny->WypiszDane();
			aktualny = aktualny->m_pNastepny;
		}
	}
}

void ListaPracownik::Usun(const Pracownik& wzorzec)
{
	Pracownik* aktualny = m_pPoczatek;
	Pracownik* poprzedni = nullptr;
	if (m_nLiczbaPracownikow == 0)
	{
		cout << "Brak Pracownikow" << endl;

	}
	else
	{
		for (int i = 0; i <= m_nLiczbaPracownikow; i++)
		{
			if (aktualny->Porownaj(wzorzec) == 0)
			{
				if (aktualny == m_pPoczatek)
				{
					m_pPoczatek = aktualny->m_pNastepny;
					m_nLiczbaPracownikow--;
					return;
				}
				else
				{
					poprzedni->m_pNastepny = aktualny->m_pNastepny;
					m_nLiczbaPracownikow--;
					return;
				}
			}
			else
			{
				poprzedni = aktualny;
				aktualny = aktualny->m_pNastepny;
			}
		}
		cout << "Nie znaleziono podanego pracownika na liscie" << endl;
	}
}

const Pracownik * ListaPracownik::Szukaj(const char * nazwisko, const char * imie) const
{
	Pracownik* aktualny = m_pPoczatek;
	if (m_nLiczbaPracownikow == 0)
	{
		cout << "nie ma zadnych pracownikow" << endl;

	}
	else
	{
		for (int i = 1; i <= m_nLiczbaPracownikow; i++)
		{
			if ((aktualny->SprawdzImie(imie) == 0) && (aktualny->SprawdzNazwisko(nazwisko) == 0))
			{
				cout << "znaleziono pracownika" << endl;
				aktualny->Wypisz();
				return aktualny;
			}
			else
			{
				cout << "nie znaleziono pracownika" << endl;
				aktualny = aktualny->m_pNastepny;
			}
		}
		return nullptr;
	}
}



void ListaPracownik::ZapisDoPliku()const
{
	ofstream plik;
	plik.open("lista.txt", fstream::out);
	if (!plik.good())
	{
		cout << "Problem z otwarciem pliku docelowego!" << endl;
	}
	else
	{
		Pracownik* aktualny = m_pPoczatek;
		for (int i = 0; i < m_nLiczbaPracownikow; i++)
		{
			if (aktualny != nullptr)
			{
				plik << *aktualny << endl;
			}
			aktualny = aktualny->m_pNastepny;
		}
	}
	plik.close();
}

void ListaPracownik::WczytajZPliku()
{
	ifstream plik;
	plik.open("lista.txt", fstream::out);
	if (!plik.good())
	{
		cout << "Plik z danymi nie istnieje!" << endl;
	}
	else
	{
		m_nLiczbaPracownikow = 0;
		m_pPoczatek = nullptr;
		Pracownik* temp = new Pracownik();
		while (plik >> *temp)
		{
			Dodaj(*temp);
			temp = new Pracownik();
		}
	}
	plik.close();
}