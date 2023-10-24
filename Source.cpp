#include <iostream>

using namespace std;


// Domeniu de activitate: alpinism

class alpinist {
public:
	string nume;
	int experienta;   ///ani
	int varsta;
	char** varfuri_urcate;
	const int ani_urcare[4] = { 2002,2004,2005,2010 };
	string traseu;
	int cost_instructie;    /// pe ora
	static float TVA;        /// 19%
	alpinist() {
		this->nume = "John Alpinistul";
		this->experienta = 10;
		this->varsta = 40;
		this->varfuri_urcate = new char*[4];
		for (int i = 0;i < 4;i++) {
			this->varfuri_urcate[i] = new char[15];
			strcpy_s(this->varfuri_urcate[i], 15, "Moldoveanu");
		}
		this->traseu = "Drumul Rosu";
		this->cost_instructie = 100;

	}
	static void setTVA(float TVAnou) {
		TVA = TVAnou;
	}

	~alpinist() {
		for (int i = 0;i < 4;i++)
			if (this->varfuri_urcate[i] != NULL) {
				delete[]this->varfuri_urcate[i];
				this->varfuri_urcate[i] = NULL;
			}
	}
	alpinist(string nume, int experienta, int varsta, char** varfuri_urcate, string traseu, int cost_instructie) {
		this->nume = nume;
		this->experienta = experienta;
		this->varsta = varsta;
		this->varfuri_urcate = new char* [4];
		for (int i = 0;i < 4;i++) {
			this->varfuri_urcate[i] = new char[15];
			strcpy_s(this->varfuri_urcate[i], 15,varfuri_urcate[i]);
		}
		this->traseu = traseu;
		this->cost_instructie = cost_instructie;


   }
	alpinist(string nume, int experienta, int varsta, char** varfuri_urcate) {
            
		this->nume = nume;
		this->experienta = experienta;
		this->varsta = varsta;
		this->varfuri_urcate = new char* [4];
		for (int i = 0;i < 4;i++) {
			this->varfuri_urcate[i] = new char[15];
			strcpy_s(this->varfuri_urcate[i], 15, varfuri_urcate[i]);
		}
		this->traseu = "Toate traseele";
		this->cost_instructie = 120;


	}


	void afisare() {
		cout << "Nume: " << this->nume << "\nExperienta: " << this->experienta << "\nVarsta: " << this->varsta<<"\n";
		cout << "Varfuri urcate: ";
		for (int i = 0;i < 4;i++) {
			cout<< varfuri_urcate[i] << " ";
		}
		cout << "\nAni urcare: ";
		for (int i = 0;i < 4;i++)
			cout<< this->ani_urcare[i]<<" ";
		cout << "\nTraseu: " << this->traseu << "\nCost instructie: " << this->cost_instructie << "\nTVA: " << TVA<<"\n";

	}

}; 
float alpinist::TVA = 0.19;

class varf {
public:
	char* denumire;
	const float altitudine;
	string grad_dificultate;
	string lant_muntos;
	int nr_trasee;
	static int nivel_de_referinta;  /// Nivelul marii= 0m

	static void setnivel_de_referinta(float nivel_de_referinta_nou) {
		nivel_de_referinta = nivel_de_referinta_nou;
	}

	varf(): altitudine(2544) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 15, "Moldoveanu");
		this->grad_dificultate = "mediu";
		this->lant_muntos = "Carpati";
		this->nr_trasee = 5;
	}
	varf(char* denumire,float altitudine, string grad_dificultate, string lant_muntos, int nr_trasee) : altitudine(altitudine) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 15, denumire);
		this->grad_dificultate = grad_dificultate;
		this->lant_muntos = lant_muntos;
		this->nr_trasee = nr_trasee;
	}
	varf(char* denumire, float altitudine, string grad_dificultate, int nr_trasee) : altitudine(altitudine) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 15, denumire);
		this->grad_dificultate = grad_dificultate;
		this->lant_muntos = "Muntii Carpati";
		this->nr_trasee = nr_trasee;

	}

	~varf() {
		if (this->denumire != NULL)
			delete[]this->denumire;
		this->denumire = NULL;
	}

	void afisare() {
		cout <<"Denumire: "<<denumire<<"\nAltitudine: "<<altitudine<<"\nGrad dificultate: "<<grad_dificultate<<"\nLant muntos: "<<lant_muntos<<"\nNumar trasee: "<<nr_trasee<<"\nNivel de referinta: "<<nivel_de_referinta<<"\n";
	}
		


};
int varf::nivel_de_referinta = 0;

class traseu {
public:
	char* denumire;
	string grad_dificultate;
	const float lungime;
	static int amenda;  /// amenda pentru deteriorarea semnelor de pe traseu

	static void setamenda(float amenda_nou) {
		amenda = amenda_nou;
	}
	traseu(): lungime(5000) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 50, "Drumul Rosu");
		this->grad_dificultate = "greu";
	}
	traseu(char* denumire, string grad_dificultate, float lungime) :lungime(lungime) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 50, denumire);
		this->grad_dificultate = grad_dificultate;
	}
	traseu(char* denumire, float lungime) :lungime(lungime) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 50, denumire);
		this->grad_dificultate = "usor";
	}

	~traseu() {
		if (this->denumire != NULL)
			delete[]this->denumire;
		this->denumire = NULL;
	}
	void afisare() {
		cout << "Denumire: " << denumire << "\nGrad dificultate: " << grad_dificultate << "\nLungime: " << lungime << "\nAmenda:" << amenda<<"\n";
	}



};
int traseu::amenda = 500;

int main() {

	alpinist Alpinist;
	//Alpinist.afisare();
	char** vf;
	vf = new char* [4];
	for (int i = 0;i < 4;i++) {
		vf[i] = new char[15];
	
	}
	strcpy_s(vf[0], 15, "Moldoveanu");
	strcpy_s(vf[1], 15, "Om");
	strcpy_s(vf[2], 15, "Negoiu");
	strcpy_s(vf[3], 15, "Retezat");
	alpinist alpinist2("Ion",5,25,vf,"Valea Larga",80);
	//alpinist2.afisare();
	alpinist alpinist3("Ion", 5, 25, vf);
	//alpinist3.afisare();
	varf varf1;
	varf1.afisare();
	traseu traseu1;
	traseu1.afisare();

}