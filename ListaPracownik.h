#pragma once
#include"Data.h"
#include"Napis.h"
#include"Pracownik.h"

using namespace std;
class ListaPracownik
{
public:
	ListaPracownik();
	~ListaPracownik();

private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;

public:
	void Dodaj(const Pracownik& p);
	void WypiszPracownikow() const;
	void Usun(const Pracownik& wzorzec);
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;


};

