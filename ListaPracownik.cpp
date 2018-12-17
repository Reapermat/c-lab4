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
}

void ListaPracownik::Dodaj(const Pracownik & p)
{
	Pracownik *k = new Pracownik(p);
	Pracownik *aktualny = m_pPoczatek;
	Pracownik *nastepny;
	int licznik = 0;

	
	if (m_nLiczbaPracownikow == 0)
	{
		m_pPoczatek = new Pracownik(p);
		k->m_pNastepny = nullptr;
		m_nLiczbaPracownikow++;
		return;
	}
	else if (m_nLiczbaPracownikow == 1)
	{
		if (aktualny->SprawdzNazwisko(k->Nazwisko()) > 0)
		{
			m_pPoczatek = new Pracownik(p);
			k->m_pNastepny = aktualny;
			m_nLiczbaPracownikow++;
			return;

		}
		else if (aktualny->SprawdzNazwisko(k->Nazwisko()) < 0)
		{
			aktualny->m_pNastepny = k;
			k->m_pNastepny = nullptr;
			m_nLiczbaPracownikow++;
			return;
		}
	}
	else
	{
		nastepny = aktualny->m_pNastepny;
		if (aktualny->SprawdzNazwisko(k->Nazwisko()) > 0)
		{
			m_pPoczatek = new Pracownik(p);
			k->m_pNastepny = aktualny;
			m_nLiczbaPracownikow++;
			return;
		}
		while (licznik <= m_nLiczbaPracownikow)
		{
			if (nastepny->SprawdzNazwisko(k->Nazwisko()) > 0)
			{
				aktualny->m_pNastepny = k;
				k->m_pNastepny = nastepny;
				m_nLiczbaPracownikow++;
				return;
			}
			else if (nastepny->SprawdzNazwisko(k->Nazwisko()) < 0)
			{
				aktualny = nastepny;
				nastepny = aktualny->m_pNastepny;
				licznik++;
			}
			if (nastepny == nullptr)
			{
				aktualny->m_pNastepny = k;
				k->m_pNastepny = nullptr;
				m_nLiczbaPracownikow++;
				return;
			}
		}
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
			aktualny->Wypisz();
			aktualny = aktualny->m_pNastepny;
		}
	}
}

void ListaPracownik::Usun(const Pracownik & wzorzec)
{

}
