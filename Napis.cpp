#include "Napis.h"
#include "string.h"
#include <iostream>


using namespace std;




Napis::Napis(const char * nap)
{
	m_nD1 = strlen(nap) + 1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, nap);
}

Napis::~Napis()
{
	delete[] m_pszNapis;
}

Napis::Napis(const Napis & wzor)
{
	m_nD1 = wzor.m_nD1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
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
