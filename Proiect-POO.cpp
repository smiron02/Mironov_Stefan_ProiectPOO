#include <iostream>
#include <fstream>
using namespace std;


// Domeniu de activitate: alpinism

class Definitie {
public:
	virtual void definitie() = 0;
	virtual ~Definitie() {

	}
};

class alpinist:public Definitie {
	string nume;
	int experienta;   ///ani
	int varsta;
	char* varf_urcat;
	const int an_certificare;
	string traseu;
	int cost_instructie;    /// pe ora
	static float TVA;        /// 19%
public:
	alpinist():an_certificare(2004) {
		this->nume = "John Alpinistul";
		this->experienta = 10;
		this->varsta = 40;
		this->varf_urcat = new char[strlen("Moldoveanu")+1];
	    strcpy_s(this->varf_urcat, strlen("Moldoveanu")+1, "Moldoveanu");
		this->traseu = "Drumul Rosu";
		this->cost_instructie = 100;

	}
	void definitie() {
		cout << " Persoana care practica alpinismul, ramura sportiva care cuprinde ascensiunile in munti, in special escaladarea partilor greu accesibile ale acestora.";
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
	void setVarsta() {
		this->varsta = varsta;
	}
	char* getVarf_urcat() {
		return this->varf_urcat;
	}
	void setVarf_urcat(char* vf) {
			varf_urcat = vf;
	}
	int getAn_urcare() {
	    int v;
		v = this->an_certificare;
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
			if (this->varf_urcat!= NULL) 
				delete[]this->varf_urcat;
	}
	alpinist(string nume, int experienta, int varsta, char* varf_urcat, string traseu, int cost_instructie, int an_urcare):an_certificare(an_certificare) {
		this->nume = nume;
		this->experienta = experienta;
		this->varsta = varsta;
		this->varf_urcat = new char[strlen(varf_urcat) + 1];
		strcpy_s(this->varf_urcat,strlen(varf_urcat) + 1, varf_urcat);
		this->traseu = traseu;
		this->cost_instructie = cost_instructie;

	}
	alpinist(string nume, int experienta, int varsta, char* varf_urcat, int an_urcare):an_certificare(an_certificare) {

		this->nume = nume;
		this->experienta = experienta;
		this->varsta = varsta;
		this->varf_urcat = new char[strlen(varf_urcat)+1];
		strcpy_s(this->varf_urcat, strlen(varf_urcat) + 1, varf_urcat);
		this->traseu = "Toate traseele";
		this->cost_instructie = 120;
	}
	alpinist& operator=(const alpinist& a) {
		this->nume = a.nume;
		this->experienta = a.experienta;
		this->varsta = a.varsta;
			if (this->varf_urcat != NULL) {
				delete[]this->varf_urcat;
				this->varf_urcat = NULL;
			}
		this->varf_urcat = new char[strlen(a.varf_urcat)+1];
		strcpy_s(this->varf_urcat,strlen(a.varf_urcat) + 1, a.varf_urcat);
		this->traseu = a.traseu;
		this->cost_instructie = a.cost_instructie;
		return *this;
	}

	friend ostream& operator<<(ostream& consola, const alpinist& a) {
		cout << "Nume: " << a.nume << "\nExperienta: " << a.experienta << "\nVarsta: " << a.varsta << "\nVarf urcat: ";
		cout << a.varf_urcat << ", ";
		cout << "\nAn certificare: ";
		cout << a.an_certificare << " ";
		cout << endl;
		cout << "Traseu: " << a.traseu << "\nCost instructie: " << a.cost_instructie << "\nTVA: " << a.TVA;
		return consola;
	}
	friend ofstream& operator<<(ofstream& consola, const alpinist& a) {
		cout << "Nume: " << a.nume << "\nExperienta: " << a.experienta << "\nVarsta: " << a.varsta << "\nVarf urcat: ";
		cout << a.varf_urcat << ", ";
		cout << "\nAn certificare: ";
		cout << a.an_certificare << " ";
		cout << endl;
		cout << "Traseu: " << a.traseu << "\nCost instructie: " << a.cost_instructie << "\nTVA: " << a.TVA;
		return consola;
	}
	friend istream& operator>>(istream& in, alpinist& a) {
		cout << "Nume: "; in >> a.nume;
		cout << "Experienta: "; in >> a.experienta;
		cout << "Varsta:"; in >> a.varsta;
		if (a.varf_urcat)
			delete[]a.varf_urcat;
		a.varf_urcat = new char[100];
		cout << "Varf urcat: ";
	    in >> a.varf_urcat;
		cout << "Traseu: "; in >> a.traseu;
		cout << "Cost instructie: "; in >> a.cost_instructie;
		return in;
	}
	friend ifstream& operator>>(ifstream& in, alpinist& a) {
		cout << "Nume: "; in >> a.nume;
		cout << "Experienta: "; in >> a.experienta;
		cout << "Varsta:"; in >> a.varsta;
		if (a.varf_urcat)
			delete[]a.varf_urcat;
		a.varf_urcat = new char[100];
		cout << "Varf urcat: ";
		in >> a.varf_urcat;
		cout << "Traseu: "; in >> a.traseu;
		cout << "Cost instructie: "; in >> a.cost_instructie;
		return in;
	}
	alpinist operator++() {
		this->varsta += 1;
		this->experienta += 1;
		return *this;
	}
	alpinist operator++(int) {
		alpinist temp = *this;
		this->varsta += 1;
		this->experienta += 1;
		return temp;
	}
	alpinist(const alpinist& a):an_certificare(an_certificare) {
		this->nume = a.nume;
		this->experienta = a.experienta;
		this->varsta = a.varsta;
		this->varf_urcat = new char[strlen(a.varf_urcat) + 1];
		strcpy_s(this->varf_urcat, strlen(a.varf_urcat) + 1, a.varf_urcat);
		this->traseu = a.traseu;
		this->cost_instructie = a.cost_instructie;
	}

	void afisare() {
		cout << "Nume: " << this->nume << "\nExperienta: " << this->experienta << "\nVarsta: " << this->varsta << "\n";
		cout << "Varf urcat: ";
		cout << varf_urcat;
		cout << "\nAn certificare: ";
		cout << this->an_certificare;
		cout << "\nTraseu: " << this->traseu << "\nCost instructie: " << this->cost_instructie << "\nTVA: " << TVA << "\n";

	}
	friend int ReturnezaCostMinim(alpinist a1, alpinist a2);
};
float alpinist::TVA = 0.19;

class Altitudine {
	virtual float calcul_altitudine() = 0;

};
int ReturnezaCostMinim(alpinist a1, alpinist a2) {
	int a = a1.cost_instructie;
	int b = a2.cost_instructie;
	if (a1.cost_instructie > a2.cost_instructie)
		return b;
	return a;
}
class varf: public Altitudine, public Definitie {
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

	float calcul_altitudine() {
		return this->altitudine - this->nivel_de_referinta;
	}
	void definitie() {
		cout << "Partea cea mai de sus (ascutita) a unor obiecte inalte (case, copaci etc.) sau a anumitor forme de relief (deal, munte).";
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
		strcpy_s(this->denumire, 15, v.denumire);
		this->grad_dificultate = v.grad_dificultate;
		this->lant_muntos = v.lant_muntos;
		this->nr_trasee = v.nr_trasee;
		return *this;
	}

	friend ostream& operator<<(ostream& consola, const varf& v) {
		cout << "Denumire: " << v.denumire << "\nAltitudine: " << v.altitudine << "\nGrad de dificultate: " << v.grad_dificultate << "\nLant muntos: " << v.lant_muntos << "\nNumar trasee: " << v.nr_trasee << "\nNivel de referinta: " << v.nivel_de_referinta;

		return consola;
	}
	friend ofstream& operator<<(ofstream& consola, const varf& v) {
		cout << "Denumire: " << v.denumire << "\nAltitudine: " << v.altitudine << "\nGrad de dificultate: " << v.grad_dificultate << "\nLant muntos: " << v.lant_muntos << "\nNumar trasee: " << v.nr_trasee << "\nNivel de referinta: " << v.nivel_de_referinta;

		return consola;
	}
	friend istream& operator>>(istream& in, varf& v) {
		if (v.denumire != NULL)
			delete[]v.denumire;
		v.denumire = new char[15];
		cout << "Denumire: "; in >> v.denumire;
		//cout << "Altitudine: "; in >> v.altitudine;
		cout << "Grad de dificultate:"; in >> v.grad_dificultate;
		cout << "Lant muntos: "; in >> v.lant_muntos;
		cout << "Numar trasee: "; in >> v.nr_trasee;
		return in;
	}
	friend ifstream& operator>>(ifstream& in, varf& v) {
		if (v.denumire != NULL)
			delete[]v.denumire;
		v.denumire = new char[15];
		cout << "Denumire: "; in >> v.denumire;
		//cout << "Altitudine: "; in >> v.altitudine;
		cout << "Grad de dificultate:"; in >> v.grad_dificultate;
		cout << "Lant muntos: "; in >> v.lant_muntos;
		cout << "Numar trasee: "; in >> v.nr_trasee;
		return in;
	}
	varf operator++() {
		this->nr_trasee += 1;
		return *this;
	}
	varf operator++(int) {
		varf temp = *this;
		this->nr_trasee += 1;
		return temp;
	}
	varf(const varf& v) :altitudine(altitudine) {
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


void TotalTrasee(varf& v1, varf& v2) {
	int sum = v1.nr_trasee + v2.nr_trasee;
	cout << "Total numar trasee: " << sum;

}
class traseu:public Definitie {
protected:
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
	string getGD() {
		return this->grad_dificultate;
	}
	void setGD(string GD) {
		this->grad_dificultate = GD;
	}
	int getLungime() {
		return this->lungime;
	}
	void definitie() {
		cout << " Distanta marcata pe care il parcurge (in mod permanent) un vehicul sau o persoana.";
	}
	traseu() : lungime(5000.6) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 50, "Drumul Rosu");
		this->grad_dificultate = "greu";
	}
	traseu(char* denumire, string grad_dificultate, const float lungime) :lungime(lungime) {
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
		strcpy_s(this->denumire, 50, t.denumire);
		this->grad_dificultate = t.grad_dificultate;
		return *this;
	}
	friend ostream& operator<<(ostream& consola, const traseu& t) {
		cout << "Denumire: " << t.denumire << "\nGrad de dificultate: " << t.grad_dificultate << "\nLungime: " << t.lungime << "\nAmenda: " << t.amenda;

		return consola;
	}
	friend ofstream& operator<<(ofstream& consola, const traseu& t) {
		cout << "Denumire: " << t.denumire << "\nGrad de dificultate: " << t.grad_dificultate << "\nLungime: " << t.lungime << "\nAmenda: " << t.amenda;

		return consola;
	}
	friend istream& operator>>(istream& in, traseu& t) {
		if (t.denumire != NULL)
			delete[]t.denumire;
		t.denumire = new char[15];
		cout << "Denumire: "; in >> t.denumire;
		//cout << "Altitudine: "; in >> v.altitudine;
		cout << "Grad de dificultate:"; in >> t.grad_dificultate;
		return in;
	}
	friend ifstream& operator>>(ifstream& in, traseu& t) {
		if (t.denumire != NULL)
			delete[]t.denumire;
		t.denumire = new char[15];
		cout << "Denumire: "; in >> t.denumire;
		//cout << "Altitudine: "; in >> v.altitudine;
		cout << "Grad de dificultate:"; in >> t.grad_dificultate;
		return in;
	}
	bool operator<(traseu t) {
		return this->lungime < t.lungime;
	}
	traseu(const traseu& t) :lungime(lungime) {
		this->denumire = new char[50];
		strcpy_s(this->denumire, 50, t.denumire);
		this->grad_dificultate = t.grad_dificultate;
	}
	void afisare() {
		cout << "Denumire: " << denumire << "\nGrad de dificultate: " << grad_dificultate << "\nLungime: " << lungime << "\nAmenda:" << amenda << "\n";
	}
	



};
int traseu::amenda = 500;


class Expeditie {
	alpinist a;
	varf vf;
	int Durata;
	int Nr_locuri;
	string Dificultate;
public:
	int getNr_locuri() {
		return this->Nr_locuri;
	}
	int getDurata() {
		return this->Durata;
	}
	string getDificultate() {
		return this->Dificultate;
	}
	void setNr_Locuri(int nr) {
		this->Nr_locuri = nr;
	}
	void setDurata(int Durata) {
		this->Durata = Durata;
	}
	void setDificultate(string Dificultate) {
		this->Dificultate = Dificultate;
	}
	alpinist getA() {
		return alpinist();
	}
	varf getVf() {
		return varf();
	}
	Expeditie()
		: a(alpinist()), vf(varf()), Durata(0), Nr_locuri(0), Dificultate("Necunoscuta") {}
	Expeditie(alpinist alp, varf v, int durata, int nr_locuri, std::string dificultate)
		: a(alp), vf(v), Durata(durata), Nr_locuri(nr_locuri), Dificultate(dificultate) {}

	friend ostream& operator<<(ostream& consola, const Expeditie& E) {
		cout << "Alpinist: " << E.a << "\nVarf: " << E.vf << "\nDurata: " << E.Durata << "\nNr locuri: " << E.Nr_locuri<<"\nDificultate : "<<E.Dificultate;

		return consola;
	}
	friend istream& operator>>(istream& in, Expeditie& E) {
		cout << "Alpnist: "; in >> E.a;
		cout << "Varf:"; in >> E.vf;
		cout << "Durata: "; in >> E.Durata;
		cout << "Nr Locuri: "; in >> E.Nr_locuri;
		cout << "Dificultate: "; in >> E.Dificultate;
		return in;
	}
	Expeditie operator++() {
		this->Nr_locuri += 1;
		return *this;
	}
	Expeditie operator++(int) {
		Expeditie temp = *this;
		this->Nr_locuri += 1;
		return temp;
	}
};

class pista_biciclete : public traseu {
	string tip_suprafata;
	int diferenta_de_nivel;
public:
	string getTip_suprafata() {
		return this->tip_suprafata;
	}
	int getDiferenta_de__nivel() {
		return this->diferenta_de_nivel;
	}
	void setTip_suprafata(string tip_suprafata) {
		this->tip_suprafata = tip_suprafata;
	}
	void setDiferenta_de_nivel(int diferenta) {
		this->diferenta_de_nivel = diferenta;
	}
	pista_biciclete() :traseu() {
		this->tip_suprafata = "pietris";
		this->diferenta_de_nivel = 500;
	};
	pista_biciclete(char* denumire,string grad_dificultate,const float lungime,string tip_suprafata, int diferenta_de_nivel) :traseu(denumire,grad_dificultate,lungime) {
		this->tip_suprafata = tip_suprafata;
		this->diferenta_de_nivel = diferenta_de_nivel;
	};
	friend ostream& operator<<(ostream& out, const pista_biciclete& p) {
		out << (traseu)p;
		out << "\nTip suprafata: " << p.tip_suprafata<<endl;
		out << "Diferenta de nivel: " << p.diferenta_de_nivel << endl;
		return out;
	}
};

class traseu_alpin : public traseu {
	int altitudine_max;
	char* risc_de_avalansa;
public:
	int getAltitudine() {
		return this->altitudine_max;
	}
	char* getRisc_avalansa() {
		return this->risc_de_avalansa;
	}
	void setAltitudine(int alt) {
		this->altitudine_max = alt;
	}
	void setRisc_avalansa(char* risc) {
		this->risc_de_avalansa = risc;
	}
	traseu_alpin() :traseu() {
		this->altitudine_max = 4880;
		this->risc_de_avalansa = new char[10];
		strcpy_s(this->risc_de_avalansa, 10, "mediu");
	}
	traseu_alpin(int alt, char* risc, char* denumire, string dificultate, const float lungime) :traseu(denumire, dificultate, lungime) {
		this->altitudine_max = alt;
		this->risc_de_avalansa = risc;
	}
	friend ostream& operator<<(ostream& out, const traseu_alpin& p) {
		out << (traseu)p;
		out << "\nAltitudine maxima: " << p.altitudine_max << endl;
		out << "Risc de avalansa: " << p.risc_de_avalansa << endl;
		return out;
	}
	traseu_alpin(const traseu_alpin& p) :traseu(p) {
		this->altitudine_max = p.altitudine_max;
		this->risc_de_avalansa = new char[strlen(p.risc_de_avalansa) + 1];
		strcpy_s(this->risc_de_avalansa, strlen(p.risc_de_avalansa) + 1, p.risc_de_avalansa);
	}
	traseu_alpin operator=(const traseu_alpin& p) {
		if (this != &p) {
			traseu::operator=(p);
			this->altitudine_max = p.altitudine_max;
			if (this->risc_de_avalansa)
				delete[]this->risc_de_avalansa;
			this->risc_de_avalansa = new char[strlen(p.risc_de_avalansa) + 1];
			strcpy_s(this->risc_de_avalansa, strlen(p.risc_de_avalansa) + 1, p.risc_de_avalansa);
		}
		return *this;
	}
};
int main() {

	///*alpinist Alpinist;
	//cout << Alpinist.getNume() << endl;
	//Alpinist.setNume("Andrei");
	//cout << Alpinist.getNume() << endl;
	//char* vf;
	//vf = Alpinist.getVarf_urcat();
	//
	//	cout << vf 

	//cout << endl;
	//const int an_certificare;
	//an_certificare = Alpinist.getAn_certificare();
	//	cout << an_certificare;
	//cout << endl;
	//cout << Alpinist;
	//cout << endl;*/


	//alpinist Alpinist;
	//cin >> Alpinist;
	//cout << Alpinist << "\n\n";
	//alpinist a1 = Alpinist;
	//cout << a1 << "\n\n";
	//Alpinist = ++a1;
	//cout << Alpinist << "\n\n";
	//Alpinist = a1++;
	//cout << Alpinist << "\n\n";;

	//varf Varf;
	//cin >> Varf;
	//cout << Varf << "\n\n";
	//varf v1 = Varf;
	//cout << v1 << "\n\n";
	//Varf = ++v1;
	//cout << Varf << "\n\n";
	//Varf = v1++;
	//cout << Varf << "\n\n";

	//traseu Traseu;
	//cin >> Traseu;
	//cout << Traseu << "\n\n";
	//traseu t1 = Traseu;
	//cout << t1 << "\n\n";
	//if (t1 < Traseu)
	//	cout << "Traseul " << Traseu.getDenumire() << " este mai lung decat traseul " << t1.getDenumire();
	//else
	//	cout << "Traseul " << t1.getDenumire() << " este mai lung sau egal decat traseul " << Traseu.getDenumire();

	//alpinist a2;
	//a2.setCostintstructie(150);
	//int CostMin;
	//CostMin = ReturnezaCostMinim(Alpinist, a2);
	//cout << CostMin << endl;

	//varf v2;
	//v2.setNrtrasee(10);
	//TotalTrasee(Varf, v2);


	///  Faza 4
	/*int nr;
	varf vectvf[5];
	alpinist vectalp[5];
	traseu vectr[5];
	traseu matrice_traseu[5][5];
	cout << "Introdu numarul de varfuri:";
	cin >> nr;
	cout << endl;
	cout << "Citeste varfuri: \n";
	for (int i = 1;i <= nr;i++) {
		cin >> vectvf[i];
	}
	cout << "\nAfisare varfuri:\n";
	for (int i = 1;i <= nr;i++) {
		cout << vectvf[i] << endl;
	}
	cout << "Introdu numarul de trasee:";
	cin >> nr;
	cout << endl;
	cout << "Citeste trasee: \n";
	for (int i = 1;i <= nr;i++) {
		cin >> vectr[i];
	}
	cout << "\nAfisare trasee:\n";
	for (int i = 1;i <= nr;i++) {
		cout << vectr[i] << endl;
	}
	cout << "Introdu numarul de linii si coloane(matrice):";
	int n, m;
	cin >>n>>m;
	cout << endl;
	cout << "Citeste trasee: \n";
	for (int i = 1;i <= n;i++) 
		for(int j=1;j<=m;j++)
	{
			cin >> matrice_traseu[n][m];
	}
	cout << "\nAfisare trasee:\n";
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			cout << matrice_traseu[n][m];
		}
	cout << "Introdu numarul de alpinisti :";
	cin >> nr;
	cout << endl;
	for (int i = 1;i <= nr;i++) {
		cin >> vectalp[i];
	}
	cout << "\nAfisare alpinisti:\n";
	for (int i = 1;i <= nr;i++) {
		cout << vectalp[i];
	}*/


	/// Faza 5
  /*  Expeditie A; 
    cin >> A;
    cout << A;*/



/// Faza 6

//// fisiere text
//alpinist a;
////cin >> a;
//ofstream file("fisier.txt", ios::out);
//file << a;
//ifstream citire("fisier.txt", ios::in);
//cin >> a;
//cout << a;
//// fisiere binare
//fstream fisierBinar("fisierBinar.g59", ios::binary | ios::out);


	 //faza 7
//pista_biciclete Pista1;
//cout << Pista1;
//char* denumire;
//denumire = new char[strlen("albastra") + 1];
//strcpy_s(denumire, strlen("albastra") + 1, "albastra");
//pista_biciclete Pista2(denumire, "mediu", 2500, "asfalt", 300);
//cout << Pista2;
//
//traseu_alpin Alpin;
//cout << Alpin;
//char* risc_avalansa = new char[10];
//strcpy_s(risc_avalansa, 10, "mare");
//traseu_alpin Alpin1(8000, risc_avalansa, denumire, "mediu", 10000);
//cout << Alpin1;
// Upcasting
//traseu* t = &Pista2;
//cout << *t;



///// faza 8   late binding
//Definitie** pointeri;
//pointeri = new Definitie * [10];
//pointeri[0] = new traseu();
//pointeri[1] = new varf();
//pointeri[2] = new traseu();
//for (int i = 0;i < 3;i++) 
//	pointeri[i]->definitie();

}
