#pragma once
#include "Napis.h"
#include "Pracownik.h"
#include <iostream>

class Kierownik :
	public Pracownik
{
public:
	Kierownik();
	Kierownik(const Kierownik & wzor);
	~Kierownik();
	
private:
	Napis m_NazwaDzialu;
	int m_nliczbaPracownikow;
public:
	bool operator==(const Kierownik & wzor) const;
	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu();
	Kierownik & operator=(const Kierownik & wzor);
	friend ostream & operator<<(ostream & wy, const Kierownik & s);
	friend istream & operator>> (istream & we, Kierownik & s);

};

