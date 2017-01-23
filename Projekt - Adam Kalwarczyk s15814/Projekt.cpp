/* 172. Napisz program rysowania znakiem ASCII poni¿szej figury. Program powinien umo¿liwiæ:
? wybór znaku kodu ASCII;
? wczytanie pocz¹tkowych rozmiarów figury;
? przesuwanie figury klawiszami ?, ?, ?, ?;
? powiêkszanie oraz zmniejszanie rozmiaru figury za pomoc¹ klawiszy + i - ;
? ograniczenie przesuwania i rozmiarów figury do obszaru ekranu;
Uwaga: punkt pocz¹tkowy (kropka) znajduje siê w prawym górnym naro¿niku ekranu.

Adam Kalwarczyk, 20.01.2017
*/
#include <iostream> 
#include <conio.h> 
#include <cstdlib>
#include <string>
#include <limits>
using namespace std;
//ustalam rozmiary konsoli, przy mojej rozdzielczosci ekranu jest to 120 x 30 znaków, w razie potrzeby mo¿na dostosowaæ siê do innej rozdzielczoœci zmieniaj¹c tylko te dwie wartoœci
#define szerokosc_tablicy 120
#define wysokosc_tablicy 29
#define gora 72
#define dol 80
#define lewo 75
#define prawo 77
#define wiekszy 43
#define mniejszy 45

void wczytaj_dane(int &dlugosc_ramienia, string &znak);
void pokaz_tablice();
void rysuj_iksa(int X, int Y, int &dlugosc_ramienia, string &znak);
string tablica[wysokosc_tablicy][szerokosc_tablicy];
int main() {
	// ustalam punkt pocz¹tkowy zgodnie z poleceniem - prawy górny naro¿nik ekranu
	// przy zmianie rozmiaru konsoli punkt sam siê dostosuje
	int X = 0, Y = szerokosc_tablicy - 1;
	int dlugosc_ramienia;
	string znak;
	wczytaj_dane(dlugosc_ramienia, znak);
	system("cls");
	rysuj_iksa(X, Y, dlugosc_ramienia, znak);

	while (true) {
		pokaz_tablice();
		char input = _getch();

		switch (input) {
		case gora: {
			if (X > 0) {
				X -= 1;
			}
			break;
		}
		case dol: {
			if (X + 2 * dlugosc_ramienia + 1 < wysokosc_tablicy) {
				X += 1;
			}
			break;
		}
		case lewo: {
			if (Y - 2 * dlugosc_ramienia > 0) {
				Y -= 1;
			}
			break;
		}
		case prawo: {
			if (Y + 1 < szerokosc_tablicy) {
				Y += 1;
			}
			break;
		}
		case wiekszy: {
			if (2 * dlugosc_ramienia + 1 < wysokosc_tablicy && 2 * dlugosc_ramienia + 1 < szerokosc_tablicy && X + 2 * dlugosc_ramienia + 2 < wysokosc_tablicy && Y - 2 * dlugosc_ramienia - 1 > 0) {
				dlugosc_ramienia += 1;
			}
			break;
		}
		case mniejszy: {
			if (dlugosc_ramienia > 1) {
				dlugosc_ramienia -= 1;
			}
			break;
		}
		default:
			break;
		}
		rysuj_iksa(X, Y, dlugosc_ramienia, znak);
		system("cls");
	}
	_getch();
}

void wczytaj_dane(int &dlugosc_ramienia, string &znak) {
	cout << "Ten program pozwala na rysowanie figury X dowolnym znakiem." << endl << "Figure mozna przesuwac klawiszami strzalek, oraz powiekszac i pomniejszac za pomoca klawiszy + oraz -." << endl;
	cout << "Jakim znakiem chcesz rysowac?: ";
	cin >> znak;
	while (cin.fail() || znak.length() != 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Niepoprawna wartosc." << endl << "Podaj jeden znak, ktorym chcesz rysowac." << endl;
		cout << "Jakim znakiem chcesz rysowac?: " << endl;
		cin >> znak;
	}
	cout << "Jaka dlugosc ma miec ramie X-a?: ";
	cin >> dlugosc_ramienia;
	while (cin.fail() || dlugosc_ramienia <= 0 || dlugosc_ramienia > wysokosc_tablicy / 2 - 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Niepoprawna wartosc." << endl << "dlugosc musi byc wieksza od zera i mniejsza od " << wysokosc_tablicy / 2 << " aby figura rysowala sie w calosci." << endl;
		cout << "Jaka dlugosc ma miec ramie X-a?: " << endl;
		cin >> dlugosc_ramienia;
	}
	cout << endl;
}
void pokaz_tablice() {
	cout << "Sterowanie strzalkami, powiekszanie klawiszami + oraz -." << endl;
	for (int i = 0; i < wysokosc_tablicy; i++) {
		for (int j = 0; j < szerokosc_tablicy; j++) {
			cout << tablica[i][j];
		}
	}
}
void rysuj_iksa(int X, int Y, int &dlugosc_ramienia, string &znak) {
	for (int i = 0; i < wysokosc_tablicy; i++) {
		for (int j = 0; j < szerokosc_tablicy; j++) {
			tablica[i][j] = ' ';
		}
		tablica[X][Y] = znak;
	}

	for (int i = 0; i <= 2 * dlugosc_ramienia; i++) {
		tablica[X + i][Y - i] = znak;
		tablica[X + i][Y - 2 * dlugosc_ramienia + i] = znak;
	}
}