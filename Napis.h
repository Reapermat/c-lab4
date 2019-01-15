#pragma once
#include <iostream>
#include <string>
using namespace std;

class Napis
{

private:
	char* m_pszNapis;
	int m_nD1;
public:
	Napis(const char* nap = "");
	~Napis();
	Napis(const Napis & wzor);
	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;
	bool operator==(const Napis & wzor);
	Napis & operator=(const Napis & wzor);
	friend ostream & operator<< (ostream & wy, const Napis & p);
	friend istream & operator >> (istream & we, Napis & p);



};

