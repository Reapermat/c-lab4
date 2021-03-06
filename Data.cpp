#include "Data.h"
#include <iostream>

using namespace std;


Data::Data(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
}

Data::~Data()
{
}


void Data::Ustaw(int d, int m, int r)
{
	Koryguj();
}

int Data::Dzien() const
{
	return m_nDzien;
}

int Data::Miesiac() const
{
	return m_nMiesiac;
}

int Data::Rok() const
{
	return m_nRok;
}

void Data::Wypisz() const
{
	cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok << endl;


}

void Data::Wpisz()
{
	cin >> m_nDzien >> m_nMiesiac >> m_nRok;
	Koryguj();
}

int Data::Porownaj(const Data & wzor) const
{
	/*if (this->Dzien() == m_nDzien && this->Miesiac() == m_nMiesiac && this->Rok() == m_nRok) return 0;
	//else if (this->Dzien() <= m_nDzien && this->Miesiac() <= m_nMiesiac && this->Rok() <= m_nRok) return 1;
	//else return -1;
	else if (this->Rok() > m_nRok) return 1;
	else if (this->Rok() < m_nRok) return -1;
	else if (this->Miesiac() > m_nMiesiac) return 1;
	else if (this->Miesiac() < m_nMiesiac) return -1;
	else if (this->Dzien() > m_nDzien) return 1;
	else if (this->Dzien() < m_nDzien) return -1;*/
	if (wzor.Rok() > m_nRok) return 1;
	else if (wzor.Rok() < m_nRok) return -1;

	if (wzor.Miesiac() > m_nMiesiac) return 1;
	else if (wzor.Miesiac() < m_nMiesiac) return -1;

	if (wzor.Dzien() > m_nDzien) return 1;
	else if (wzor.Dzien() < m_nDzien) return -1;

	return 0;
}

void Data::Koryguj()
{
	if (m_nDzien > 31)m_nDzien = 31;
	if (m_nDzien < 1)m_nDzien = 1;
	if (m_nMiesiac < 1)m_nMiesiac = 1;
	if (m_nMiesiac > 12)m_nMiesiac = 12;
	if (m_nMiesiac == 2){
		
		 if (m_nRok % 4 == 0 && m_nRok % 100 != 0 || m_nRok % 400 == 0) {

				if (m_nDzien >= 29)m_nDzien = 29;

			}
		 if (m_nDzien >= 29) m_nDzien = 28;
		}
		
	

}

ostream& operator<<(ostream &wy, const Data &d)
{
	wy << d.m_nDzien << " " << d.m_nMiesiac << " " << d.m_nRok;
	return wy;
	
}

istream & operator >> (istream & we, Data & d)
{
	we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;
	d.Koryguj();
	return we;
}
