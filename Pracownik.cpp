#include "Pracownik.h"


using namespace std;


Pracownik::Pracownik(const char* imie, const char* nazwisko, int dzien, int miesiac, int rok):
	m_DataUrodzenia(dzien, miesiac, rok), m_Imie(imie), m_Nazwisko(nazwisko),
	m_nIDZatrudnienia(m_nIDZatrudnienia)
{
}

Pracownik::Pracownik(const Pracownik &wzor) : m_nIDZatrudnienia(m_nIDZatrudnienia + 1), m_Imie(wzor.m_Imie),
m_Nazwisko(wzor.m_Nazwisko), m_DataUrodzenia(wzor.m_DataUrodzenia)
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
	cout << "Imie: ";
	m_Imie.Wpisz();
	cout << "Nazwisko: " ;
	m_Nazwisko.Wpisz();
	cout << "Data urodzenia: " ;
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

Pracownik & Pracownik::operator=(const Pracownik & wzor)
{
	if (this == &wzor)
		return *this;
	m_DataUrodzenia = wzor.m_DataUrodzenia;
	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
}


bool Pracownik::operator==(const Pracownik & wzor) const
{
	if (this == &wzor)
		return true;
	if (this->Porownaj(wzor) == 0)
		return true;
	else
		return false;
}

void Pracownik::WypiszDane()
{
	cout << "ID Zatrudnienia: " << m_nIDZatrudnienia << " " << m_Imie << " " << m_Nazwisko << " " << m_DataUrodzenia << endl;
}

Pracownik * Pracownik::KopiaObiektu() const
{
	Pracownik *Nowy_p;
	Nowy_p = new Pracownik(*this);
	return Nowy_p;
}

ostream & operator<<(ostream & wy, const Pracownik & p)
{
	wy << p.m_Imie << " " << p.m_Nazwisko << " " << p.m_DataUrodzenia;
	return wy;
}

istream & operator>>(istream & we, Pracownik & p)
{
	we >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia;
	return we;
}
