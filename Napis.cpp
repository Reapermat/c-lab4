#define _CRT_SECURE_NO_WARNINGS
#include "Napis.h"


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
	m_nD1 = strlen(nowy_napis) + 1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	cout << m_pszNapis << endl;
}

void Napis::Wpisz()
{
	string napis;
	cin >> napis;
	Ustaw(napis.c_str());
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	/*if (this->m_pszNapis == por_napis) return 0;
	else if (this->m_pszNapis > por_napis) return 1;*/
	return strcmp(m_pszNapis, por_napis);
}

bool Napis::operator==(const Napis & wzor)
{
	if (this == &wzor)
		return true;
	else if (m_nD1 == wzor.m_nD1 && strcmp(m_pszNapis, wzor.m_pszNapis) == 0)
		return true;
	else
		return false;
}

Napis & Napis::operator=(const Napis & wzor)
{
	if (this == &wzor)
		return *this;
	m_nD1 = wzor.m_nD1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
	return *this;
}

ostream & operator<<(ostream & wy, const Napis & p)
{
	wy << p.m_pszNapis;
	return wy;
}

istream & operator >> (istream & we, Napis & p)
{
	string str;
	we >> str;
	p.m_nD1 = str.length() + 1;
	p.m_pszNapis = new char[p.m_nD1];
	strcpy(p.m_pszNapis, str.c_str());
	return we;
}
