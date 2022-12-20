#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

static const string karakterListesi = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_.-+";
string secim;
string secim2;
int harfsayisi;
string sifre;
string sifrehesap;
string satir1, satir2;


void passwordcreate() {
	sifre = "";
	for (int i = 0; i < harfsayisi; i++) {
		sifre = sifre + karakterListesi[rand() % karakterListesi.size()];
	}
	ofstream dosyaYaz("passwords.txt", ios::app);
	dosyaYaz << sifrehesap + "/" + sifre<<endl;

	cout << sifre << endl;
}
void fileread() {
	ifstream dosyaOku("dosya.txt");
	char karakter;

	if (dosyaOku.is_open()) {

		while (dosyaOku.get(karakter)) {
			cout << karakter;
		}

		dosyaOku.close();
	}
}



int main() {
	while (true) {
	cout << "Sifrelerim-1\nSifre Olustur-2" << endl;
	cin >> secim2;
	if (secim2 == "2") {
		srand(time(NULL));
		cout << "Sifre ismi:" << endl;
		cin >> sifrehesap;
		cout << "dusuk guvenlik:1\norta guvenlik:2\nyuksek guvenlik\nfbi bile bulamasin:4" << endl;
		cin >> secim;
		if (secim == "1") {
			harfsayisi = 10;
			passwordcreate();
		}

		else if (secim == "2") {
			harfsayisi = 16;
			passwordcreate();
		}

		else if (secim == "3") {
			harfsayisi = 20;
			passwordcreate();
		}

		else if (secim == "4") {
			harfsayisi = 32;
			passwordcreate();
		}

		else {
			cout << "Düzgün Seç";
		}

	}
	else if (secim == "1") {
		fileread();
	}
}

}
