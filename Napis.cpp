#include "Napis.h"
#include "string.h"
#include <iostream>


using namespace std;

Napis::Napis()
{
}


Napis::~Napis()
{
}

const char * Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	strcpy_s(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	cout << m_pszNapis << endl;
}

void Napis::Wpisz()
{
	cin >> m_pszNapis;
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	/*if (this->m_pszNapis == por_napis) return 0;
	else if (this->m_pszNapis > por_napis) return 1;*/
	return strcmp(m_pszNapis, por_napis);
}