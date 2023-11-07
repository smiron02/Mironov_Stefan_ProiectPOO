#include <iostream>

using namespace std;


// Domeniu de activitate: alpinism

class alpinist {
	string nume;
	int experienta;   ///ani
	int varsta;
	char** varfuri_urcate;
	const int ani_urcare[4] = { 2002,2004,2005,2010 };
	string traseu;
	int cost_instructie;    /// pe ora
	static float TVA;        /// 19%
public:
	alpinist() {
		this->nume = "John Alpinistul";
		this->experienta = 10;
		this->varsta = 40;
		this->varfuri_urcate = new char* [4];
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
	float getTVA() {
		return TVA;
	}
	string getNume() {
		return this->nume;
	}
	void setNume(string nume) {
			this->nume = nume;
	}
	int getExperienta() {
		return this->experienta;
	}
	void setExperienta(int experienta) {
		this->experienta = experienta;
	}
	int getVarsta() {
		return this->varsta;
	}
	void setVarsta(int varsta) {
		this->varsta = varsta;
	}
	char** getVarfuri_urcate() {
		return this->varfuri_urcate;
	}
	void setVarfuri_urcate(char** vf) {
		for (int i = 0;i < 4;i++)
			varfuri_urcate[i] = vf[i];
	}
	int* getAni_urcare() {
		int* v;
		v = new int(4);
		for (int i = 0; i < 4; i++)
			v[i] = this->ani_urcare[i];
		return v;
	}
	string getTraseu() {
		return this->traseu;
	}
	void setTraseu(string tr) {
		this->traseu = tr;
	}
	int getCostinstructie() {
		return this->cost_instructie;
	}
	void setCostintstructie(int c) {
		this->cost_instructie = c;
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
			strcpy_s(this->varfuri_urcate[i], 15, varfuri_urcate[i]);
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
	alpinist& operator=(const alpinist& a) {
		this->nume = a.nume;
		this->experienta = a.experienta;
		this->varsta =a.varsta;
		for (int i = 0;i < 4;i++)
			if (this->varfuri_urcate[i] != NULL) {
				delete[]this->varfuri_urcate[i];
				this->varfuri_urcate[i] = NULL;
			}
		this->varfuri_urcate = new char* [4];
		for (int i = 0;i < 4;i++) {
			this->varfuri_urcate[i] = new char[15];
			strcpy_s(this->varfuri_urcate[i], 15, a.varfuri_urcate[i]);
		}
		this->traseu = a.traseu;
		this->cost_instructie = a.cost_instructie;
		return *this;
	}
	alpinist(const alpinist& a) {
		this->nume = a.nume;
		this->experienta = a.experienta;
		this->varsta = a.varsta;
		this->varfuri_urcate = new char* [4];
		for (int i = 0;i < 4;i++) {
			this->varfuri_urcate[i] = new char[15];
			strcpy_s(this->varfuri_urcate[i], 15, a.varfuri_urcate[i]);
		}
		this->traseu = a.traseu;
		this->cost_instructie = a.cost_instructie;
	}

	void afisare() {
		cout << "Nume: " << this->nume << "\nExperienta: " << this->experienta << "\nVarsta: " << this->varsta << "\n";
		cout << "Varfuri urcate: ";
		for (int i = 0;i < 4;i++) {
			cout << varfuri_urcate[i] << " ";
		}
		cout << "\nAni urcare: ";
		for (int i = 0;i < 4;i++)
			cout << this->ani_urcare[i] << " ";
		cout << "\nTraseu: " << this->traseu << "\nCost instructie: " << this->cost_instructie << "\nTVA: " << TVA << "\n";

	}
	friend int ReturnezaCostMinim(alpinist a1, alpinist a2);
};
float alpinist::TVA = 0.19;


class varf {
	char* denumire;
	const float altitudine;
	string grad_dificultate;
	string lant_muntos;
	int nr_trasee;
	static int nivel_de_referinta;  /// Nivelul marii= 0m
public:
	static void setnivel_de_referinta(float nivel_de_referinta_nou) {
		nivel_de_referinta = nivel_de_referinta_nou;
	}
	float getnivel_referinta() {
		return this->nivel_de_referinta;
	}

	char* getDenumire() {
		return this->denumire;
	}
	void setDenumire(char* denumire) {
		this->denumire = denumire;
	}
	float getAltitudine() {
		return this->altitudine;
	}
	string getGrad_dificultate() {
		return this->grad_dificultate;
	}
	void setGrad_dificultate(string g) {
		this->grad_dificultate = g;
	}
	string getLantMuntos() {
		return this->lant_muntos;
	}
	void setLantMuntos(string l) {
		this->lant_muntos = l;
	}
	int getNrtrasee() {
		return this->nr_trasee;
	}
	void setNrtrasee(int nr) {
		this->nr_trasee = nr;
	}

	varf() : altitudine(2544) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 15, "Moldoveanu");
		this->grad_dificultate = "mediu";
		this->lant_muntos = "Carpati";
		this->nr_trasee = 5;
	}
	varf(char* denumire, float altitudine, string grad_dificultate, string lant_muntos, int nr_trasee) : altitudine(altitudine) {
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
	varf& operator=(const varf& v) {

		if (this->denumire != NULL)
			delete[]this->denumire;
		this->denumire = NULL;
		this->denumire = new char[50];
		strcpy_s(this->denumire, 15,v.denumire);
		this->grad_dificultate = v.grad_dificultate;
		this->lant_muntos = v.lant_muntos;
		this->nr_trasee =v.nr_trasee;
		return *this;
	}
	varf(const varf& v):altitudine(altitudine){
		this->denumire = new char[50];
		strcpy_s(this->denumire, 15, v.denumire);
		this->grad_dificultate = v.grad_dificultate;
		this->lant_muntos = v.lant_muntos;
		this->nr_trasee = v.nr_trasee;
	}
	void afisare() {
		cout << "Denumire: " << denumire << "\nAltitudine: " << altitudine << "\nGrad dificultate: " << grad_dificultate << "\nLant muntos: " << lant_muntos << "\nNumar trasee: " << nr_trasee << "\nNivel de referinta: " << nivel_de_referinta << "\n";
	}

	friend void TotalTrasee(varf& v1, varf& v2);

};
int varf::nivel_de_referinta = 0;


class traseu {
	char* denumire;
	string grad_dificultate;
	const float lungime;
	static int amenda;  /// amenda pentru deteriorarea semnelor de pe traseu
public:
	static void setamenda(float amenda_nou) {
		amenda = amenda_nou;
	}
	int getAmenda() {
		return this->amenda;
	}
	char* getDenumire() {
		return this->denumire;
	}
	void setDenumire(char* d) {
		this->denumire = d;
	}
	string getGradDificultate() {
		return this->grad_dificultate;
	}
	void setGradDificultate(string GD) {
		this->grad_dificultate = GD;
	}
	int getLungime() {
		return this->lungime;
	}
	traseu() : lungime(5000) {
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
	traseu& operator=(const traseu& t) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 50,t.denumire);
		this->grad_dificultate = t.grad_dificultate;
		return *this;
	}
	traseu(const traseu& t):lungime(lungime) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 50, t.denumire);
		this->grad_dificultate = t.grad_dificultate;
	}
	void afisare() {
		cout << "Denumire: " << denumire << "\nGrad dificultate: " << grad_dificultate << "\nLungime: " << lungime << "\nAmenda:" << amenda << "\n";
	}



};
int traseu::amenda = 500;

void TotalTrasee(varf& v1, varf& v2) {
	int sum = v1.nr_trasee + v2.nr_trasee;
	cout << "Total numar trasee: " << sum;

}

int ReturnezaCostMinim(alpinist a1, alpinist a2) {
	if (a1.cost_instructie > a2.cost_instructie)
		return a2.cost_instructie;
	return a1.cost_instructie;
}


int main() {

	alpinist Alpinist;
	char** vf;
	vf = new char* [4];
	for (int i = 0;i < 4;i++) {
		vf[i] = new char[15];

	}
	strcpy_s(vf[0], 15, "Moldoveanu");
	strcpy_s(vf[1], 15, "Om");
	strcpy_s(vf[2], 15, "Negoiu");
	strcpy_s(vf[3], 15, "Retezat");
	alpinist alpinist2("Ion", 5, 25, vf, "Valea Larga", 80);
	varf Varf;
	traseu Traseu;
	alpinist a1=Alpinist;
	a1.afisare();
	varf vf2 = Varf;
	vf2.afisare();
	traseu tr2=Traseu;
	tr2.afisare();

	Alpinist.setNume("Andrei");
	cout << Alpinist.getNume() << endl;

	Alpinist.setExperienta(20);
	cout << Alpinist.getExperienta() << endl;

	Alpinist.setCostintstructie(200);
	cout << Alpinist.getCostinstructie()<<endl;

	Alpinist.setTraseu("Verde");
	cout<<Alpinist.getTraseu() << endl;

	Alpinist.setTVA(24);
	cout << Alpinist.getTVA() << endl;

	Alpinist.setVarsta(40);
	cout << Alpinist.getVarsta()<<endl;

	Alpinist.setVarfuri_urcate(vf);
	char** varfuri = Alpinist.getVarfuri_urcate();
	for (int i = 0;i < 4;i++)
		cout << varfuri[i]<<" ";

	char* d = new char[15];
	strcpy_s(d, 15, "Rarau");
	Varf.setDenumire(d);
	cout << Varf.getDenumire()<<"\n";

	Varf.setGrad_dificultate("Mediu");
	cout << Varf.getGrad_dificultate() << "\n";

	Varf.setLantMuntos("Carpati");
	cout << Varf.getLantMuntos() << "\n";

	Varf.setnivel_de_referinta(-100);
	cout << Varf.getnivel_referinta() << "\n";

	Varf.setNrtrasee(7);
	cout << Varf.getNrtrasee() << "\n";


	char* t = new char[20];
	strcpy_s(t, 20, "Valea Plangerii");
	Traseu.setDenumire(t);
	cout << Traseu.getDenumire() << "\n";

	Traseu.setamenda(1000);
	cout << Traseu.getAmenda() << "\n";

	Traseu.setGradDificultate("Dificil");
	cout << Traseu.getGradDificultate() << "\n";

	alpinist a2;
	a2.setCostintstructie(150);
	int CostMin;
	CostMin = ReturnezaCostMinim(Alpinist, a2);
	cout << CostMin << endl;

	varf v2;
	v2.setNrtrasee(10);
	TotalTrasee(Varf, v2);
	

}