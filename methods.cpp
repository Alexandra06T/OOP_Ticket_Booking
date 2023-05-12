//
// Created by email on 09.05.2023.
//
#include "Classes.h"

//template <class T*>
//void display() {
//    for(auto it: vct) {
//        T ba = *it;
//        ba.display();
//    }
//}

//constructor neparametrizat
String::String() {
    lungime = 0;
    pointer = nullptr;
}
//constructor parametrizat
String::String(const char *sir) {
    lungime = ::strlen(sir);
    pointer = new char[lungime];
    ::strncpy(pointer, sir, lungime);
    pointer[lungime] = '\0';
}
//destructor
String::~String() {
    if (pointer != nullptr) {
        delete[] pointer;
        lungime = 0;
    }
}
//copy constructor
String::String(String &sir) {
    lungime = sir.lungime;
    pointer = new char[lungime];
    ::strncpy(pointer, sir.pointer, lungime);
    pointer[lungime] = '\0';
}
//functie afisare
void String::display() {
    int i;
    for (i = 0; i < lungime; i++)
        cout << pointer[i];
    cout << endl;
}
//supraincarcarea operatorului <<
ostream & operator << (ostream &out, String const& s) {
    int i;
    for (i = 0; i < s.lungime; i++)
        out << s.pointer[i];
    return out;
}
//adaugarea unui caracter la finalul stringului
void String::add_char(char c) {
    //nullptr
    char* newpointer = new char[lungime+1];
    ::strncpy(newpointer, pointer, lungime);
    newpointer[lungime] = c;
    lungime++;
    newpointer[lungime] = '\0';
    pointer = newpointer;
}
//concatenarea a doua stringuri
void String::concat(const String sir) {
    char* newpointer = new char[lungime+sir.lungime];
    ::strncpy(newpointer, pointer, lungime);
    ::strncpy(&newpointer[lungime], sir.pointer, sir.lungime);
    lungime += sir.lungime;
    pointer[lungime] = '\0';
    pointer = newpointer;
}
//gasirea unui substring intr-un string
char* String::find_substr(const char* subsir) {
    return ::strstr(pointer, subsir);
}
//crearea unei liste vide
IntList::IntList() {
    first = nullptr;
    last = nullptr;
}
//afisarea unei liste
void IntList::display() {
    Node* nod = first;
    while (nod != nullptr) {
        cout << nod->get_val() << " ";
        nod = nod->get_ptr();
    }
    cout << endl;
}
//adaugarea unui nou numar la inceputul listei
void IntList::add_first(int v) {
    if (first == nullptr) {
        first = new Node(v, nullptr);
        last = first;
    }
    else {
        Node *newnode = new Node(v,first);
        first = newnode;
    }
}
//adaugarea unui nou numar la finalul listei
void IntList::add_last(int v) {
    if (first == nullptr) {
        first = new Node(v, nullptr);
        last = first;
    }
    else {
        Node *newNode = new Node(v, nullptr);
        last->set_ptr(newNode);
        last = newNode;
    }
}
// destructor lista
IntList::~IntList() {
    delete first;
}
//crearea unei liste pornind de la un vector dat
IntList::IntList(int dim, int *vector) {
    first  = new Node(vector[0], nullptr);
    last = first;
    for (int i = 1; i < dim; i++) {
        add_last(vector[i]);
    }
}
//crearea unei liste formata din valoarea k repetata de dim ori
IntList::IntList(int dim, int k) {
    first  = new Node(k, nullptr);
    last = first;
    for (int i = 1; i < dim; i++) {
        add_last(k);
    }
}
//constructor de copiere pentru o lista
IntList::IntList(IntList &lista) {
    first = new Node(lista.first->get_val(), nullptr);
    last = first;
    Node* nod = lista.first->get_ptr(), *newnode;
    while (nod != nullptr) {
        newnode = new Node(nod->get_val(), nullptr);
        last->set_ptr(newnode);
        last = newnode;
        nod = nod->get_ptr();
    }
}
//concatenarea a doua liste
IntList IntList::concat(const IntList lista1, const IntList lista2) {
    first = new Node(lista1.first->get_val(), nullptr);
    last = first;
    Node* nod = lista1.first->get_ptr();
    while (nod != nullptr) {
        Node* newnode = new Node(nod->get_val(), nullptr);
        last->set_ptr(newnode);
        last = last->get_ptr();
        nod = nod->get_ptr();
    }
    nod = lista2.first;
    while (nod != nullptr) {
        Node* newnode = new Node(nod->get_val(), nullptr);
        last->set_ptr(newnode);
        last = last->get_ptr();
        nod = nod->get_ptr();
    }
    return *this;
}
//accesarea elementului de pe pozitia i
int IntList::access_val(int i) {
    //pozitiile in lista incep de la 1
    int indice = 0, val, check = 0;// check = 0 - nu s-a gasit pozitia i
    Node *nod = first;
    while (nod != nullptr && indice < i) {
        val = nod->get_val();
        if (indice == i-1)
            check = 1;
        nod = nod->get_ptr();
        indice++;
    }
    if (check == 0) {
        cout << "Pozitia cautata nu se afla in lista.\n";
        return 0;
    }
    return val;
}
//setarea valorii elementului de pe pozitia i
void IntList::set_i_val(int i, int val) {
    if (i==0)
        cout << "Pozitia i nu se afla in lista.\n";
    else {
        int indice = 0, check = 0;// check = 0 - nu s-a gasit pozitia i
        Node *nod = first;
        while (nod != nullptr && indice < i-1) {
            nod = nod->get_ptr();
            indice++;
        }
        if (nod == nullptr) {
            cout << "Pozitia i nu se afla in lista.\n";
        }
        else {
            nod->set_val(val);
        }
    }
}
//gasirea unui numar in lista: returneaza daca este (1) sau nu (0) prezent
int IntList::find_val(int val) {
    Node *nod = first;
    while (nod != nullptr) {
        if(nod->get_val() == val)
            return true;
        nod = nod->get_ptr();
    }
    return false;
}
void IntList::filter(int val) {
    int indice = 1;
    Node *nod = first;
    while (nod != nullptr) {
        if (nod->get_val() == val)
            cout << indice << " ";
        nod = nod->get_ptr();
        indice++;
    }
}
//constructor neparametrizat
Data::Data(): an(2023), luna(1), zi(1), ora(0), minut(0) {};
//constructor Data pentru o data calendaristica
Data::Data(int o, int m, int z = 1, int l = 1, int a = 2023): zi(z), luna(l), an(a), ora(o), minut(m) {};

void Data::data_display() {
    char l[4];
    if (luna == 1) strcpy(l,"Ian");
    else if(luna == 2) ::strcpy(l, "Feb");
    else if(luna == 3) ::strcpy(l, "Mar");
    else if(luna == 4) ::strcpy(l, "Apr");
    else if(luna == 5) ::strcpy(l, "Mai");
    else if(luna == 6) ::strcpy(l, "Iun");
    else if(luna == 7) ::strcpy(l, "Iul");
    else if(luna == 8) ::strcpy(l, "Aug");
    else if(luna == 9) ::strcpy(l, "Sep");
    else if(luna == 10) ::strcpy(l, "Oct");
    else if(luna == 11) ::strcpy(l, "Nov");
    else if(luna == 12) ::strcpy(l, "Dec");
    if(zi < 10) cout << 0;
    cout << zi << " " << l << " " << an << " ";
}
//afisare durata
void Data::durata_display() {
    if( ora == 0 && minut == 0)
        cout << "-\n";
    else
        cout << ora << " h " << minut << " min\n";
}
//afisare ora si minut
void Data::display_ora_minut() {
    if(ora < 10) cout << 0;
    cout << ora << ":";
    if(minut < 10) cout << 0;
    cout << minut << " ";
}
//supraincarcarea operatorului != pentru verificarea diferntei dintre doua zile
bool operator != (Data const d1, Data const d2) {
    if (d1.zi != d2.zi || d1.luna != d2.luna || d1.an != d2.an)
        return true;
    return false;
}
//getter an
int Data::get_an() const {
    return an;
}
//getter luna
int Data::get_luna() const {
    return luna;
}
//getter zi
int Data::get_zi() const {
    return zi;
}
//getter ora
int Data::get_ora() const {
    return ora;
}
//getter ora
int Data::get_minute() const {
    return minut;
}
//constructor parametrizat Sala
Sala::Sala(const char* nume, const char* adr, int nr_C1, int nr_C2, int nr_C3): nume_sala(nume), adresa(adr), nr_locuri_C1(nr_C1), nr_locuri_C2(nr_C2), nr_locuri_C3(nr_C3)  {
    lista_sali.push_back(this);
    nr_sali++;
}

//afiseaza informatii despre nume_sala si adresa
void Sala::display() {
    nume_sala.display();
    adresa.display();
    cout << "Numar total de locuri la Categoria 1: " << nr_locuri_C1 << endl;
    cout << "Numar total de locuri la Categoria 2: " << nr_locuri_C2 << endl;
    cout << "Numar total de locuri la Categoria 3: " << nr_locuri_C3 << endl;
}
//getter nr_locuri_C1
int Sala::get_C(int cat) {
    if(cat == 1)
        return nr_locuri_C1;
    else if(cat == 2)
        return nr_locuri_C2;
    else
        return nr_locuri_C3;
}
//setter nume_sala
void Sala::set_nume(const char* nume) {
    nume_sala = nume;
}
//setter adresa
void Sala::set_adresa(const char* adr) {
    adresa = adr;
}
//setter nr_locuri_C1
void Sala::set_C1(int nr_C1) {
    nr_locuri_C1 = nr_C1;
}
//setter nr_locuri_C2
void Sala::set_C2(int nr_C2) {
    nr_locuri_C2 = nr_C2;
}
//setter nr_locuri_C3
void Sala::set_C3(int nr_C3) {
    nr_locuri_C3 = nr_C3;
}
String Sala::get_nume_sala() {
    return nume_sala;
}
Sala::~Sala() {
    nr_sali--;
    lista_sali.pop_back();
}
int Sala::get_nr_sali() {
    return nr_sali;
}
void Sala::display_sali() {
    int contor = 0;
    for (auto it = lista_sali.begin();
        it != lista_sali.end();
        ++it)
    {
        contor++;
        Sala* s = *it;
        cout << s->get_nume_sala() << " ___ " << contor << endl;
        }
}
Sala* Sala::get_i_sala(int i) {
    return lista_sali[i-1];
}

Balet::Balet(string nume, string a, string m, string co, string dc, string l, int ore, int min): nume_balet(nume), autor(a), maestru_de_repetitii(m), coregrafie(co), decor_costume(dc), lumini(l), durata(ore, min) {}

string Balet::get_nume() {
    return nume_balet;
}

void Balet::display() {
    cout << nume_balet << "\nde " << autor << endl;
    cout << "Maestru de repetitii: " << maestru_de_repetitii << endl;
    cout << "Coregrafie: " << coregrafie << endl;
    cout << "Decor si costume: " << decor_costume << endl;
    cout << "Lumini: " << lumini << endl;
    cout << "Durata: "; durata.durata_display();
}
//constructor Piesa_teatru parametrizat
Piesa_teatru::Piesa_teatru(string nume, string a, string r, string d, string c,
                           string m, int od, int md, int op, int mp):
        durata(od, md),
        nume_piesa(nume),
        autor(a),
        regie(r),
        decor(d),
        costume(c),
        muzica(m),
        pauza(op, mp) {};
//afisare informatii despre o piesa de teatru
void Piesa_teatru::display() {
    cout << nume_piesa << "\nde " << autor << endl;
    cout << "Regie: " << regie << endl;
    cout << "Decor: " << decor << endl;
    cout << "Costume: " << costume << endl;
    cout << "Muzica: " << muzica << endl;
    cout << "Durata: "; durata.durata_display();
    cout << "Pauza: "; pauza.durata_display();
}
string Piesa_teatru::get_nume() const{
    return nume_piesa;
}
//setter nume piesa
void Piesa_teatru::set_nume(const string &nume) {
    nume_piesa = nume;
}
void Piesa_teatru::set_autor(const string &a) {
    autor = a;
}
//getter regie
string Piesa_teatru::get_regie() const {
    return regie;
}

//constructor neparametrizat Categorie
Categorie::Categorie(): pret(0), nr_locuri_rezervate(0), nr_locuri_disponibile(0), lista_locuri(), start_pret(Data()) {};
//constructor parametrizat Categorie: la crearea unei categorii, toate locurile sunt disponibile
Categorie::Categorie(float p, int d, int o, int m, int z , int l, int a): pret(p), nr_locuri_disponibile(d), nr_locuri_rezervate(0), lista_locuri(d, 0), start_pret(o, m, z, l, a)  {};

//getter pret
float Categorie::get_pret() {
    return pret;
}
//setter pret
void Categorie::set_pret(const float pret_nou) {
    pret = pret_nou;
}
//setter loc devine rezervat
void Categorie::set_rezervat(int i) {
    if(lista_locuri.access_val(i) == 1)
        cout << "Locul nu este disponibil.\n";
    else {
        lista_locuri.set_i_val(i, 1);
        nr_locuri_disponibile--;
        nr_locuri_rezervate++;
    }
}
//setter loc devine disponibil
void Categorie::set_disponibil(int i) {
    lista_locuri.set_i_val(i,0);
    nr_locuri_disponibile++;
    nr_locuri_rezervate--;
}
//getter nr_locuri disponibile
int Categorie::nr_disp() {
    return nr_locuri_disponibile;
}
//afiseaza lista locuri disponibile
void Categorie::display_disponibil() {
    lista_locuri.filter(0);
}
float Categorie::pret_final() {
    return pret;
}
void Categorie::change_start(int o, int m, int z , int l, int a) {
    start_pret = Data(o, m, z, l, a);
}
void Categorie::amana(int o, int m, int z, int l, int a) {
    start_pret = Data(o, m, z, l, a);
}
void Categorie::display_start_date() {
    cout << "Rezervarile cu pretul de " << pret_final() << " pot fi efectuate incepand cu data de ";
    start_pret.data_display();
}
Data Categorie::get_start_pret() {
    return start_pret;
}

Oferta::Oferta(): procent(0), Categorie(), start_oferta(Data()) {}
Oferta::Oferta(const float &pr, float p, int disp, int o, int m, int z , int l, int a): procent(pr), Categorie(p, disp, o, m, z, l, a), start_oferta(o, m, z, l, a){}

float Oferta::pret_final() {
    return pret * (1 - procent);
}
float Oferta::get_procent() {
    return procent;
}
void Oferta::amana(int o, int m, int z , int l, int a) {
    start_oferta = Data(o, m, z, l, a);
    this -> change_start(o, m, z, l, a);
    cout << "Posibilitatea efectuarii de rezervari a fost amanata pentru data de ";
    get_start_pret().data_display();
    cout << "\nPosibilitatea efectuarii de rezervari la oferta a fost amanata pentru data de ";
    start_oferta.data_display();
}
void Oferta::display_start_date() {
    cout << "Rezervarile pot fi efectuate incepand cu data de ";
    get_start_pret().data_display();
    cout << endl;
    cout << "Rezervarile la oferta cu pretul de " << pret_final() << " pot fi efectuate incepand cu data de ";
    start_oferta.data_display();
    cout << endl;
}
Reducere_last_day::Reducere_last_day(): last_day(true), Categorie(), start_reducere(Data()){}
Reducere_last_day::Reducere_last_day(bool ld, float p, int disp, int o, int m, int z , int l, int a): last_day(ld), Categorie(p, disp, o, m, z, l, a), start_reducere(o, m, z-1, l, a) {}
void Reducere_last_day::set_last_day(bool ld) {
    last_day = ld;
}
float Reducere_last_day::procent_ld() {
    if(last_day)
        return 0.2;
    return 0;
}
float Reducere_last_day::pret_final() {
    return pret * (1 - procent_ld());
}
void Reducere_last_day::amana(int o, int m, int z , int l, int a) {
    this->change_start(o, m, z, l, a);
    start_reducere = Data(o, m, z-1, l, a);
    cout << "Posibilitatea efectuarii de rezervari a fost amanata pentru data de ";
    get_start_pret().data_display();
    cout << "\nPosibilitatea efectuarii de rezervari la reducere a fost amanata pentru data de ";
    start_reducere.data_display();
    cout << endl;
}
void Reducere_last_day::display_start_date() {
    cout << "Rezervarile cu pretul de " << Categorie::pret_final() << " pot fi efectuate incepand cu data de ";
    get_start_pret().data_display();
    cout << endl;
    cout << "Rezervarile la reducere cu pretul de " << pret_final() << " pot fi efectuate incepand cu data de ";
    start_reducere.data_display();
    cout << endl;
}
float Reducere_dubla::pret_final() {
    return get_pret() * (1 - Reducere_last_day::procent_ld() - get_procent());
}
Reducere_dubla::Reducere_dubla():Categorie() {}
Reducere_dubla::Reducere_dubla(const float& pr, bool ld,float p, int disp, int o, int m, int z , int l, int a): start_rd(o, m, z, l, a), Categorie(p, disp, o, m, z, l, a) {
    start_reducere = Data(o, m, z-1, l, a);
    start_oferta = Data(o, m, z, l, a);
}

//start ul aplicarii pretului este data cea mai recenta intre cea a aplicarii ofertei si cea a aplicarii reducerii ld, nu modifica start ul aplicarii pretului categoriei
void Reducere_dubla::change_start() {
    if(start_oferta.get_ora() >= start_reducere.get_ora())
        start_rd = start_oferta;
    else start_rd = start_reducere;

}
void Reducere_dubla::amana(int o, int m, int z, int l, int a) {
    start_reducere = Data(o, m, z-1, l, a);
    start_oferta = Data(o, m, z, l, a);
    change_start();
    cout << "Posibilitatea efectuarii de rezervari a fost amanata pentru data de ";
    get_start_pret().data_display();
    cout << "\nPosibilitatea efectuarii de rezervari la reducere dubla a fost amanata pentru data de ";
    start_rd.data_display();
    cout << endl;
}
void Reducere_dubla::display_start_date() {
    cout << "Rezervarile la reducere dubla cu pretul de " << pret_final() << " pot fi efectuate incepand cu data de ";
    start_rd.data_display();
    cout << endl;
}

//crearea unei reprezentatii vide
Reprezentatie::Reprezentatie(): piesa(nullptr), data_repr(), s(nullptr), C1(nullptr), C2(nullptr), C3(nullptr)  {}

//constructor parametrizat
Reprezentatie::Reprezentatie(Piesa_teatru* p, int o, int m, int z , int l, int a, Sala* sl, float p1, float p2, float p3, int cod, float pr): piesa(p), data_repr(o,m,z,l,a), s(sl) {
    if(cod == 0) {
        C1 = new Categorie(p1, sl->get_C(1), o, m, z, l, a);
        C2 = new Categorie(p2, sl->get_C(2), o, m, z, l, a);
        C3 = new Categorie(p3, sl->get_C(3), o, m, z, l, a);
    }
    else if(cod == 1) {
        C1 = new Oferta(pr, p1, sl->get_C(1), o, m, z, l, a);
        C2 = new Oferta(pr, p2, sl->get_C(2), o, m, z, l, a);
        C3 = new Oferta(pr, p3, sl->get_C(3), o, m, z, l, a);
    }
    else if(cod == 2) {
        C1 = new Reducere_last_day(true, p1, sl->get_C(1), o, m, z, l, a);
        C2 = new Reducere_last_day(true, p2, sl->get_C(2), o, m, z, l, a);
        C3 = new Reducere_last_day(true, p3, sl->get_C(3), o, m, z, l, a);
    }
    else if(cod == 3) {
        C1 = new Reducere_dubla(pr, true, p1, sl->get_C(1), o, m, z, l, a);
        C2 = new Reducere_dubla(pr, true,p2, sl->get_C(2), o, m, z, l, a);
        C3 = new Reducere_dubla(pr, true,p3, sl->get_C(3), o, m, z, l, a);
        //setam data de start conform regulii clasei Reducere_dubla
        if(dynamic_cast <Reducere_dubla*> (C1) == nullptr) cout << "Nu a reusit";
        (dynamic_cast <Reducere_dubla*> (C1))->change_start();
        (dynamic_cast <Reducere_dubla*> (C2))->change_start();
        (dynamic_cast <Reducere_dubla*> (C3))->change_start();
    }
}

//afisarea detaliilor unei reprezentatii
void Reprezentatie::display_info_repr() {
    cout << piesa->get_nume() << "   ";
    data_repr.display_ora_minut();
    cout <<  s->get_nume_sala() << "   Numar locuri disponibile " << total_disp() << " ";
}
//getter data
Data Reprezentatie::get_data() {
    return data_repr;
}
//getter pret
float Reprezentatie::get_pret(int categorie, int cod) {
    if(cod == 1) return 0;
    if(cod == 0) {
        if (categorie == 1) {
            return C1->pret_final();
        }
        else if(categorie == 2) {
            return C2->pret_final();
        }
        else return C3->pret_final();
    }
    if(cod == 2) {
        if (categorie == 1) {
            return C1->pret_final()/2;
        }
        else if(categorie == 2) {
            return C2->pret_final()/2;
        }
        else return C3->pret_final()/2;
    }
}
//getter piesa
Piesa_teatru Reprezentatie::get_piesa() {
    return *piesa;
}
//getter sala
Sala Reprezentatie::get_sala() {
    return *s;
}
//getter cat
Categorie* Reprezentatie::get_cat(int i) {
    if(i == 1)
        return C1;
    else if(i == 2)
        return C2;
    else
        return C3;
}

//calculeaza numarul total de locuri disponibile pentru o reprezentatie
int Reprezentatie::total_disp() {
    return C1->nr_disp() + C2->nr_disp() + C3->nr_disp();
}
//rezerva loc
void Reprezentatie::rezerva(int cat, int loc) {
    if(cat == 1) {
        C1->set_rezervat(loc);
    }
    else if(cat == 2) {
        C2->set_rezervat(loc);
    }
    else {
        C3->set_rezervat(loc);
    }
}
//modifica locul rezervat
void Reprezentatie::modif_loc(int cat_vechi, int cat_nou, int loc_vechi, int loc_nou) {
    if(cat_vechi == 1) {
        C1->set_disponibil(loc_vechi);
    }
    else if(cat_vechi == 2) {
        C2->set_disponibil(loc_vechi);
    }
    else {
        C3->set_disponibil(loc_vechi);
    }
    if(cat_nou == 1) {
        C1->set_rezervat(loc_nou);
    }
    else if(cat_nou == 2) {
        C2->set_rezervat(loc_nou);
    }
    else {
        C3->set_rezervat(loc_nou);
    }
}
//anuleaza rezervarea locului
void Reprezentatie::sterge_rez_loc(int cat, int loc) {
    if(cat == 1) {
        C1->set_disponibil(loc);
    }
    else if(cat == 2) {
        C2->set_disponibil(loc);
    }
    else {
        C3->set_disponibil(loc);
    }
}

Reprezentatie::~Reprezentatie() {
    delete C1;
    delete C2;
    delete C3;
}
//crearea unei liste vide
ReprList::ReprList() {
    first = nullptr;
}
//copy constructor
ReprList::ReprList(ReprList &rl) {
    first = new Node(rl.first->get_repr(), nullptr);
    Node* last = first;
    Node* nod = rl.first->get_ptr(), *newnode;
    while (nod != nullptr) {
        newnode = new Node(nod->get_repr(), nullptr);
        last->set_ptr(newnode);
        last = newnode;
        nod = nod->get_ptr();
    }
}

//inserare inaintea unui nod
void ReprList::insert_before(Reprezentatie *r, Node* pre, Node* post) {
    //daca post este primul nod, inseram inainte, modificand first
    if(post == pre) {
        Node *newnode = new Node(r, first);
        first = newnode;
    }
    else {
        Node* newnode = new Node(r, post);
        pre->set_ptr(newnode);
    }
}
//adaugarea unei reprezentatii in lista
void ReprList::add_repr(Reprezentatie *r) {
    Node* pre = first, *post = pre;
    int check = 0; // check devine 1 cand inseram o noua reprezentatie
    //daca lista nu are niciun nod
    if(first == nullptr) {
        first = new Node(r, nullptr);
    }
        //daca lista are un singur nod
    else if (first->get_ptr() == nullptr) {
        if (r->get_data().get_an() == first->get_repr()->get_data().get_an()) {
            //daca anii sunt egali, verificam lunile
            if (r->get_data().get_luna() == first->get_repr()->get_data().get_luna()) {
                //daca lunile sunt egale verificam zilele
                if (r->get_data().get_zi() == first->get_repr()->get_data().get_zi()) {
                    //daca zilele sunt egale verificam orele
                    if (r->get_data().get_ora() < first->get_repr()->get_data().get_ora()) {
                        Node *newnode = new Node(r, first);
                        first = newnode;
                    } else {
                        Node* newnode = new Node(r, nullptr);
                        first->set_ptr(newnode);
                    }
                } else if (r->get_data().get_zi() < first->get_repr()->get_data().get_zi()) {
                    Node *newnode = new Node(r, first);
                    first = newnode;
                }
                else {
                    //insert after
                    Node* newnode = new Node(r, nullptr);
                    first->set_ptr(newnode);
                }
            } else if (r->get_data().get_luna() < first->get_repr()->get_data().get_luna()) {
                insert_before(r, pre, post);
            }
            else {
                //insert after
                Node* newnode = new Node(r, nullptr);
                first->set_ptr(newnode);
                check = 1;
            }
        } else if(r->get_data().get_an() < first->get_repr()->get_data().get_an()) {
            insert_before(r, pre, post);
        }
        else {
            //insert after
            Node* newnode = new Node(r, nullptr);
            first->set_ptr(newnode);
            check = 1;
        }
    }else { //pentru doua sau mai multe noduri
        while(post != nullptr && check == 0) {
            if (r->get_data().get_an() == post->get_repr()->get_data().get_an()) {
                //daca anii sunt egali, verificam lunile
                if (r->get_data().get_luna() == post->get_repr()->get_data().get_luna()) {
                    //daca lunile sunt egale verificam zilele
                    if (r->get_data().get_zi() == post->get_repr()->get_data().get_zi()) {
                        //daca zilele sunt egale verificam orele
                        if (r->get_data().get_ora() < post->get_repr()->get_data().get_ora()) {
                            insert_before(r, pre, post);
                            check = 1;
                        }
                    } else if (r->get_data().get_zi() < post->get_repr()->get_data().get_zi()) {
                        insert_before(r, pre, post);
                        check = 1;
                    }
                } else if (r->get_data().get_luna() < post->get_repr()->get_data().get_luna()) {
                    insert_before(r, pre, post);
                    check = 1;
                }
            } else if(r->get_data().get_an() < post->get_repr()->get_data().get_an()) {
                insert_before(r, pre, post);
                check = 1;
            }
            pre = post;
            post = post->get_ptr();
        }
        if(check == 0) {
            Node* newnode = new Node(r, nullptr);
            pre->set_ptr(newnode);
        }
    }
}

//afisarea listei sub forma de calendar
void ReprList::display_list() {
    Node* nod = first;
    nod->get_repr()->get_data().data_display();
    cout << endl;
    int indice = 1;
    while (nod != nullptr) {
        nod->get_repr()->display_info_repr();
        cout << "_____ " << indice;
        if(nod->get_ptr() != nullptr && nod->get_repr()->get_data() != nod->get_ptr()->get_repr()->get_data()) {
            cout << endl << endl;
            nod->get_ptr()->get_repr()->get_data().data_display();
        }
        cout << endl;
        nod = nod->get_ptr();
        indice ++;
    }
}
Reprezentatie* ReprList::access_i_repr(int i) {
    //pozitiile in lista incep de la 1
    int indice = 0;
    Reprezentatie repr;
    Node *nod = first;
    while (nod != nullptr && indice < i) {
        if (indice == i-1) {
            return nod->get_repr();
        }
        nod = nod->get_ptr();
        indice++;
    }
    cout << "Pozitia cautata nu se afla in lista.\n";
}
//destructor, se apeleaza recursiv pentru toate nodurile
ReprList::~ReprList() {
    delete first;
}
//constructor neparametrizat
Rezervare::Rezervare(): categorie(0), loc(0), reprezentatie(nullptr), cod_r(0) {}

//constructor parametrizat
Rezervare::Rezervare(Reprezentatie* r, int cat, int l, int cod): categorie(cat), loc(l), reprezentatie(r), cod_r(cod) {
    nr_rezervari++;
}
//destructor
Rezervare::~Rezervare() {
    nr_rezervari--;
}
//getter data
Data Rezervare::get_data() {
    return reprezentatie->get_data();
}
//getter reprezentatie
Reprezentatie* Rezervare::get_repr() {
    return reprezentatie;
}
//getter categorie
int Rezervare::get_nr_cat() {
    return categorie;
}
//getter loc
int Rezervare::get_nr_loc() {
    return loc;
}
//afisare informatii rezervare
void Rezervare::display_info_rez() {
    reprezentatie->display_info_repr();
    cout << " Categorie " << categorie << "   ";
    cout << "Loc " << loc << "   ";
    cout << "Pret " << reprezentatie->get_pret(categorie, cod_r) << " lei";
}
//modifica loc rezervare
void Rezervare::modif_rez(int categ_noua, int loc_nou) {
    reprezentatie->modif_loc(categorie, categ_noua, loc, loc_nou);
    categorie = categ_noua;
    loc = loc_nou;
}
//setter static member
void Rezervare::set_nr_rez(int val) {
    nr_rezervari = val;
}
//getter static member
int Rezervare::get_nr_rez() {
    return nr_rezervari;
}
//fidelizare
void Rezervare::fidelizare() {
    if(nr_rezervari % 2 == 0) {
        cout << "\nFelicitari!!! Ai ajuns la numarul de " << nr_rezervari <<" rezervari realizate in aplicatie.\n Continua tot asa si poti beneficia de oferte speciale si bilete cadou!\n";
    }
}
//initiere
void Rezervare::initiere() {
    if(nr_rezervari == 0) {
        cout << "\nBine ai venit in aplicatie!\n Informeaza-te si rezerva locuri de aici, in timp ce esti premiat.\n";
    }
}
void Rezervare::verifica_valabilitate(int i) {
    if (i < 1 || i > nr_rezervari)
        throw (wrongInput("Nu exista rezervare care sa aiba codul pe care l-ati introdus."));
}


//crearea unei liste vide
RezList::RezList() {
    first = nullptr;
}
//copy constructor
RezList::RezList(RezList &rl) {
    first = new Node(rl.first->get_rez(), nullptr);
    Node* last = first;
    Node* nod = rl.first->get_ptr(), *newnode;
    while (nod != nullptr) {
        newnode = new Node(nod->get_rez(), nullptr);
        last->set_ptr(newnode);
        last = newnode;
        nod = nod->get_ptr();
    }
}
//inserare inaintea unui nod
void RezList::insert_before(Rezervare *r, Node* pre, Node* post) {
    //daca post este primul nod, inseram inainte, modificand first
    if(post == pre) {
        Node *newnode = new Node(r, first);
        first = newnode;
    }
    else {
        Node* newnode = new Node(r, post);
        pre->set_ptr(newnode);
    }
}
//adaugarea unei rezervari in lista
void RezList::add_rez(Rezervare *r) {
    Node* pre = first, *post = pre;
    int check = 0; // check devine 1 cand inseram o noua reprezentatie
    //daca lista nu are niciun nod
    if(first == nullptr) {
        first = new Node(r, nullptr);
    }
        //daca lista are un singur nod
    else if (first->get_ptr() == nullptr) {
        if (r->get_data().get_an() == first->get_rez()->get_data().get_an()) {
            //daca anii sunt egali, verificam lunile
            if (r->get_data().get_luna() == first->get_rez()->get_data().get_luna()) {
                //daca lunile sunt egale verificam zilele
                if (r->get_data().get_zi() == first->get_rez()->get_data().get_zi()) {
                    //daca zilele sunt egale verificam orele
                    if (r->get_data().get_ora() < first->get_rez()->get_data().get_ora()) {
                        Node *newnode = new Node(r, first);
                        first = newnode;
                    } else {
                        Node* newnode = new Node(r, nullptr);
                        first->set_ptr(newnode);
                    }
                } else if (r->get_data().get_zi() < first->get_rez()->get_data().get_zi()) {
                    Node *newnode = new Node(r, first);
                    first = newnode;
                }
                else {
                    //insert after
                    Node* newnode = new Node(r, nullptr);
                    first->set_ptr(newnode);
                }
            } else if (r->get_data().get_luna() < first->get_rez()->get_data().get_luna()) {
                insert_before(r, pre, post);
            }
            else {
                //insert after
                Node* newnode = new Node(r, nullptr);
                first->set_ptr(newnode);
                check = 1;
            }
        } else if(r->get_data().get_an() < first->get_rez()->get_data().get_an()) {
            insert_before(r, pre, post);
        }
        else {
            //insert after
            Node* newnode = new Node(r, nullptr);
            first->set_ptr(newnode);
            check = 1;
        }
    }else { //pentru doua sau mai multe noduri
        while(post != nullptr && check == 0) {
            if (r->get_data().get_an() == post->get_rez()->get_data().get_an()) {
                //daca anii sunt egali, verificam lunile
                if (r->get_data().get_luna() == post->get_rez()->get_data().get_luna()) {
                    //daca lunile sunt egale verificam zilele
                    if (r->get_data().get_zi() == post->get_rez()->get_data().get_zi()) {
                        //daca zilele sunt egale verificam orele
                        if (r->get_data().get_ora() < post->get_rez()->get_data().get_ora()) {
                            insert_before(r, pre, post);
                            check = 1;
                        }
                    } else if (r->get_data().get_zi() < post->get_rez()->get_data().get_zi()) {
                        insert_before(r, pre, post);
                        check = 1;
                    }
                } else if (r->get_data().get_luna() < post->get_rez()->get_data().get_luna()) {
                    insert_before(r, pre, post);
                    check = 1;
                }
            } else if(r->get_data().get_an() < post->get_rez()->get_data().get_an()) {
                insert_before(r, pre, post);
                check = 1;
            }
            pre = post;
            post = post->get_ptr();
        }
        if(check == 0) {
            Node* newnode = new Node(r, nullptr);
            pre->set_ptr(newnode);
        }
    }
}
//afisarea listei sub forma de calendar
void RezList::display_list() {
    if( first != nullptr) {
        Node* nod = first;
        nod->get_rez()->get_data().data_display();
        cout << endl;
        int indice = 1;
        while (nod != nullptr) {
            nod->get_rez()->display_info_rez();
            cout << "_______ " << indice << endl;
            if(nod->get_ptr() != nullptr && nod->get_rez()->get_data() != nod->get_ptr()->get_rez()->get_data())
                nod->get_ptr()->get_rez()->get_data().data_display();
            cout << endl;
            nod = nod->get_ptr();
            indice ++;
        }
        cout << endl;
    }
    else
        cout << "Nu exista rezervari.";
}
//accesarea rezervarii de pe pozitia i
Rezervare* RezList::access_i_rez(int i) {
    //pozitiile in lista incep de la 1
    int indice = 0;
    Rezervare rez;
    Node *nod = first;
    while (nod != nullptr && indice < i) {
        if (indice == i-1) {
            return nod->get_rez();
        }
        nod = nod->get_ptr();
        indice++;
    }
    cout << "Pozitia cautata nu se afla in lista.\n";
}
//sterge din lista rezervarea de pe pozitia i
void RezList::sterge_rez(int i) {
    //pozitiile in lista incep de la 1
    Node *del;
    if(i == 1) {
        del = first;
        first = first->get_ptr();
        delete del;
    }
    else {
        int indice = 0;
        Rezervare rez;
        Node *nod = first;
        while (nod != nullptr && indice < i-2) {
            nod = nod->get_ptr();
            indice++;
        }
        del = nod->get_ptr();
        del->get_rez()->get_repr()->sterge_rez_loc(del->get_rez()->get_nr_cat(), del->get_rez()->get_nr_loc());
        nod->set_ptr(nod->get_ptr()->get_ptr());
        delete del;
    }
}
//destructor
RezList::~RezList() {
    delete first;
}

void IstoricRezervari::display() {
    for(auto it: lista_rezervari) {
        (*it).display_info_rez();
        cout << endl;
    }
}
//adaugarea unei rezervari in lista
void IstoricRezervari::add_rez(Rezervare *r) {
    lista_rezervari.push_back(r);
    sort(lista_rezervari.begin(), lista_rezervari.end(), [&](Rezervare* a, Rezervare* b) -> bool {
        if (a->get_data().get_an() == b->get_data().get_an()) {
            if(a->get_data().get_luna() == b->get_data().get_luna()) {
                if(a->get_data().get_zi() == b->get_data().get_zi()) {
                    return (a->get_data().get_ora() < b->get_data().get_ora());
                }
                else return (a->get_data().get_zi() < b->get_data().get_zi());
            }
            else return (a->get_data().get_luna() < b->get_data().get_luna());
        }
        else return (a->get_data().get_an() < b->get_data().get_an());
    });
}
void IstoricRezervari::sterge_rez() {
    lista_rezervari.pop_back();
}
//afisarea rezervarilor de la o anumita data
void IstoricRezervari::get_by_date(Data d) {
    vector<Rezervare*> copie(lista_rezervari.size());
    copy_if(lista_rezervari.begin(), lista_rezervari.end(), copie.begin(), [=](Rezervare* r) -> bool{
        return (d.get_minute() == r->get_data().get_minute() && d.get_ora() == r->get_data().get_ora() && d.get_zi() == r->get_data().get_zi() && d.get_luna() == r->get_data().get_luna() && d.get_an() == r->get_data().get_an());
    } );
    if(copie.empty())
    {
        cout << "Nu s-au gasit rezervari pentru data de ";
        d.data_display();
    }
    else{
        for(auto it = copie.begin(); bool(*it); it++) {
            Rezervare* r = *it;
            r->get_repr()->display_info_repr();
            cout << endl;
        }
    }
}
//afisarea rezervarilor la o anumite piesa
void IstoricRezervari::get_by_piesa(const string &p) {
    vector<Rezervare*> copie(lista_rezervari.size());
    copy_if(lista_rezervari.begin(), lista_rezervari.end(), copie.begin(), [=](Rezervare* r) -> bool{
        return (p == r->get_repr()->get_piesa().get_nume());
    } );
    if(!(*copie.begin()))
    {
        cout << "Nu s-au gasit rezervari pentru piesa " << p << endl;
    }
    else{
        for(auto it = copie.begin(); bool(*it); it++) {
            Rezervare* r = *it;
            r->get_repr()->display_info_repr();
            cout << endl;
        }
    }
}


void verifica_int(double i) {
    if(int(i) != i)
        throw (wrongType("Numarul introdus nu este intreg."));
}