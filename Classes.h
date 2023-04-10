//
// Created by email on 07.04.2023.
//

#ifndef TICKET_BOOKING_CLASSES_H
#define TICKET_BOOKING_CLASSES_H

#endif //TICKET_BOOKING_CLASSES_H

#include <cstring>
#include <iostream>
using namespace std;

// clasa utilitara String
class String {
    char* pointer;
    int lungime;
public:
    String();
    String(const char *sir);
    ~String();
    String(String &sir);
    String& operator = (String const&sir){
        if(pointer != nullptr)
            delete[] pointer;
        lungime = sir.lungime;
        pointer = new char[lungime];
        ::strncpy(pointer, sir.pointer, lungime);
        return *this;
    }
    void display();
    void add_char(char c);
    void concat(String sir);
    char* find_substr(const char* subsir);
    friend ostream & operator << (ostream &out, String const& s);
};

String::String() {
    lungime = 0;
    pointer = nullptr;
}
String::String(const char *sir) {
    lungime = ::strlen(sir);
    pointer = new char[lungime];
    ::strncpy(pointer, sir, lungime);
    pointer[lungime] = '\0';
}
String::~String() {
    if (pointer != nullptr) {
        delete[] pointer;
        lungime = 0;
    }
}
String::String(String &sir) {
    lungime = sir.lungime;
    pointer = new char[lungime];
    ::strncpy(pointer, sir.pointer, lungime);
    pointer[lungime] = '\0';
}
void String::display() {
    int i;
    for (i = 0; i < lungime; i++)
        cout << pointer[i];
    cout << endl;
}
ostream & operator << (ostream &out, String const& s) {
    int i;
    for (i = 0; i < s.lungime; i++)
        out << s.pointer[i];
    return out;
}
void String::add_char(char c) {
    char* newpointer = new char[lungime+1];
    ::strncpy(newpointer, pointer, lungime);
    newpointer[lungime] = c;
    lungime++;
    newpointer[lungime] = '\0';
    pointer = newpointer;
}
void String::concat(const String sir) {
    char* newpointer = new char[lungime+sir.lungime];
    ::strncpy(newpointer, pointer, lungime);
    ::strncpy(&newpointer[lungime], sir.pointer, sir.lungime);
    lungime += sir.lungime;
    pointer[lungime] = '\0';
    pointer = newpointer;
}
char* String::find_substr(const char* subsir) {
    return ::strstr(pointer, subsir);
}

// clasa utilitara lista simplu inlantuita cu noduri alocate dinamic
class IntList {
    class Node {
        int valoare;
        Node* next;
    public:
        Node(int val,Node *ptr){
            valoare = val;
            next = ptr;
        };
        void set_val(int val) {
            valoare = val;
        };
        void set_ptr(Node* ptr) {
            next = ptr;
        };
        int get_val() {
            return valoare;
        }
        Node* get_ptr() {
            return next;
        }
        ~Node() {
            if (next != nullptr) {
                delete next;
            }
        }
    };
    Node *first;
    Node *last;
public:
    IntList();
    void display();
    void add_first(int v);
    void add_last(int v);
    ~IntList();
    IntList(int dim, int *vector);
    IntList(int dim, int k);
    IntList(IntList &lista);
    IntList& operator = (IntList const&lista){
        if (first != nullptr)
            delete first;
        Node* nod = lista.first->get_ptr(), *newnode;
        first = new Node(lista.first->get_val(), nullptr);
        cout << first->get_val();
        last = first;
        cout << first << " " << last;
        while (nod != nullptr) {
            newnode = new Node(nod->get_val(), nullptr);
            last->set_ptr(newnode);
            last = last->get_ptr();
            nod = nod->get_ptr();
        }
        return *this;
    }
    IntList concat(const IntList lista1, const IntList lista2);
    int access_val(int i);
    void set_i_val(int i, int val);
    int find_val(int val);
    //afiseaza indicii nodurilor care au valorarea val
    void filter(int val);

};
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


class Data {
    int an;
    int luna;
    int zi;
    int ora;
    int minut;
public:
    //constructor neparametrizat
    Data();
    //constructor Data pentru o data calendaristica
    Data(int o, int m, int z, int l, int a);
    //afisare data calendaristica
    void data_display();
    //afisare durata
    void durata_display();
    //afisare ora si minut
    void display_ora_minut();
    //supraincarcarea operatorului != pentru verificarea diferntei dintre doua zile
    friend bool operator != (Data const d1, Data const d2);
    //getter an
    int get_an();
    //getter luna
    int get_luna();
    //getter zi
    int get_zi();
    //getter ora
    int get_ora();

};
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
int Data::get_an() {
    return an;
}
//getter luna
int Data::get_luna() {
    return luna;
}
//getter zi
int Data::get_zi() {
    return zi;
}
//getter an
int Data::get_ora() {
    return ora;
}

class Sala {
    String nume_sala;
    String adresa;
    int nr_locuri_C1;
    int nr_locuri_C2;
    int nr_locuri_C3;
public:
    //constructor parametrizat Sala
    Sala(const char* nume, const char* adr, int nr_C1, int nr_C2, int nr_C3);
    //afiseaza informatii despre nume_sala si adresa
    void display();
    //getter nr_locuri_C
    int get_C(int cat);
    //setter nume_sala
    void set_nume(const char* nume);
    //setter adresa
    void set_adresa(const char* adr);
    //setter nr_locuri_C1
    void set_C1(int nr_C1);
    //setter nr_locuri_C2
    void set_C2(int nr_C2);
    //setter nr_locuri_C3
    void set_C3(int nr_C3);
    //getter nume_sala
    String get_nume_sala();

};
//constructor parametrizat Sala
Sala::Sala(const char* nume, const char* adr, int nr_C1, int nr_C2, int nr_C3): nume_sala(nume), adresa(adr), nr_locuri_C1(nr_C1), nr_locuri_C2(nr_C2), nr_locuri_C3(nr_C3)  {}

//afiseaza informatii despre nume_sala si adresa
void Sala::display() {
    nume_sala.display();
    adresa.display();
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

class Piesa_teatru {
    String nume_piesa;
    String autor;
    String regie;
    String decor;
    String costume;
    String muzica;
    Data durata;
    Data pauza;
public:
    //constructor Piesa_teatru parametrizat
    Piesa_teatru(String nume, String a, String r, String d, String c, String m, int od, int md, int op, int mp);
    //afisare informatii despre o piesa de teatru
    void piesa_display();
    //getter nume piesa
    String get_nume();

};
//constructor Piesa_teatru parametrizat
Piesa_teatru::Piesa_teatru(String nume, String a, String r, String d, String c,
                           String m, int od, int md, int op = 0, int mp = 0):
                           durata(od, md),
                           nume_piesa(nume),
                           autor(a),
                           regie(r),
                           decor(d),
                           costume(c),
                           muzica(m),
                           pauza(op, mp) {};
//afisare informatii despre o piesa de teatru
void Piesa_teatru::piesa_display() {
    cout << nume_piesa << "\nde " << autor << endl;
    cout << "Regie: " << regie << endl;
    cout << "Decor: " << decor << endl;
    cout << "Costume: " << costume << endl;
    cout << "Muzica: " << muzica << endl;
    cout << "Durata: "; durata.durata_display();
    cout << "Pauza: "; pauza.durata_display();
}
String Piesa_teatru::get_nume() {
    return nume_piesa;
}
class Categorie {
    //pentru fiecare categorie in parte, locurile sunt etichetate de la 1 la nr de locuri total din categorie
    float pret;
    int nr_locuri_disponibile;
    int nr_locuri_rezervate;
    //lista alocata dinamic ce retine pt fiecare loc in parte daca este disponibil(0) sau ocupat(1)
    IntList lista_locuri;
public:
    //constructor neparametrizat Categorie
    Categorie();
    //constructor neparametrizat Categorie
    Categorie(float p, int d);
    //getter pret
    float get_pret();
    //setter pret
    void set_pret(float pret_nou);
    //setter loc devine rezervat
    void set_rezervat(int i);
    //setter loc devine disponibil
    void set_disponibil(int i);
    //getter nr_locuri disponibile
    int nr_disp();
    //afiseaza lista locuri disponibile
    void display_disponibil();
    //calculeaza pret, aplicand eventuale reduceri (0% (cod reducere 0), 20% ultima zi (cod reducere 1), 50% student (cod reducere 2), 100% elevi (cod reducere 3)
    float pret_final(int cod);

};
//constructor neparametrizat Categorie
Categorie::Categorie(): pret(0), nr_locuri_rezervate(0), nr_locuri_disponibile(0), lista_locuri() {};
//constructor parametrizat Categorie: la crearea unei categorii, toate locurile sunt disponibile
Categorie::Categorie(float p, int d): pret(p), nr_locuri_disponibile(d), nr_locuri_rezervate(0), lista_locuri(d, 0)  {};

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
float Categorie::pret_final(int cod) {
    if(cod == 1)
        return pret/5;
    else if(cod ==2)
        return pret/2;
    else if(cod == 3)
        return 0;
    return pret;
}
class Reprezentatie {
    Piesa_teatru* piesa;
    Data data_repr;
    Sala* s;
    Categorie C1;
    Categorie C2;
    Categorie C3;
public:
    //crearea unei reprezentatii vide
    Reprezentatie();
    //constructor parametrizat
    Reprezentatie(Piesa_teatru* p, int o, int m, int z , int l, int a, Sala* sl, float p1, float p2, float p3);
    //afisarea detaliilor unei reprezentatii
    void display_info_repr();
    //getter data
    Data get_data();
    //getter pret
    float get_pret(int categorie, int cod);
    //getter piesa
    Piesa_teatru get_piesa();
    //getter sala
    Sala get_sala();
    //getter cat
    Categorie get_cat(int i);
    //calculeaza numarul total de locuri disponibile pentru o reprezentatie
    int total_disp();
    //rezerva loc
    void rezerva(int cat, int loc);
    //modifica locul rezervat
    void modif_loc(int cat_vechi, int cat_nou, int loc_vechi, int loc_nou);

};
//getter data
Data Reprezentatie::get_data() {
    return data_repr;
}
//getter pret
float Reprezentatie::get_pret(int categorie, int cod) {
    if (categorie == 1) {
        return C1.pret_final(cod);
    }
    else if(categorie == 2) {
        return C2.pret_final(cod);
    }
    else return C3.pret_final(cod);
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
Categorie Reprezentatie::get_cat(int i) {
    if(i == 1)
        return C1;
    else if(i == 2)
        return C2;
    else
        return C3;
}

//calculeaza numarul total de locuri disponibile pentru o reprezentatie
int Reprezentatie::total_disp() {
    return C1.nr_disp() + C2.nr_disp() + C3.nr_disp();
}
//rezerva loc
void Reprezentatie::rezerva(int cat, int loc) {
    if(cat == 1) {
        C1.set_rezervat(loc);
    }
    else if(cat == 2) {
        C2.set_rezervat(loc);
    }
    else {
        C3.set_rezervat(loc);
    }
}
//modifica locul rezervat
void Reprezentatie::modif_loc(int cat_vechi, int cat_nou, int loc_vechi, int loc_nou) {
    if(cat_vechi == 1) {
        C1.set_disponibil(loc_vechi);
    }
    else if(cat_vechi == 2) {
        C2.set_disponibil(loc_vechi);
    }
    else {
        C3.set_disponibil(loc_vechi);
    }
    if(cat_nou == 1) {
        C1.set_rezervat(loc_nou);
    }
    else if(cat_nou == 2) {
        C2.set_disponibil(loc_vechi);
        C2.set_rezervat(loc_nou);
    }
    else {
        C3.set_disponibil(loc_vechi);
        C3.set_rezervat(loc_nou);
    }
}

class ReprList {
    class Node {
        Reprezentatie* repr;
        Node* next;
    public:
        //constructor parametrizat
        Node(Reprezentatie* r,Node *ptr){
            repr = r;
            next = ptr;
        };
        void set_repr(Reprezentatie* r) {
            repr = r;
        };
        void set_ptr(Node* ptr) {
            next = ptr;
        };
        Reprezentatie* get_repr() {
            return repr;
        }
        Node* get_ptr() {
            return next;
        }
        ~Node() {
            if (next != nullptr) {
                delete next;
            }
        }
    };
    Node *first;
public:
    //crearea unei liste vide
    ReprList();
    //copy constructor
    ReprList(ReprList &rl);
    //inserare inaintea unui nod
    void insert_before(Reprezentatie *r, Node* pre, Node* post);
    //adaugarea unei reprezentatii in lista
    void add_repr(Reprezentatie *r);
    //afisarea listei sub forma de calendar
    void display_list();
    //destructor
    ~ReprList();
    //acceseaza al i lea element
    Reprezentatie* access_i_repr(int i);
};

//

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
        cout << "_____________ " << indice;
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
//crearea unei reprezentatii vide
Reprezentatie::Reprezentatie(): piesa(nullptr), data_repr(), s(nullptr), C1(), C2(), C3()  {}

//constructor parametrizat
Reprezentatie::Reprezentatie(Piesa_teatru* p, int o, int m, int z , int l, int a, Sala* sl, float p1, float p2, float p3): piesa(p), data_repr(o,m,z,l,a), s(sl), C1(p1, sl->get_C(1)), C2(p2, sl->get_C(2)), C3(p3, sl->get_C(3)) {}

//afisarea detaliilor unei reprezentatii
void Reprezentatie::display_info_repr() {
    cout << piesa->get_nume() << "   ";
    data_repr.display_ora_minut();
    cout << "  Sala " <<  s->get_nume_sala() << "   Numar locuri disponibile " << total_disp() << " ";
}

class Rezervare {
    int cod_r; // cod reducere
    int categorie;
    int loc;
    Reprezentatie* reprezentatie;
public:
    //constructor neparametrizat
    Rezervare();
    //constructor parametrizat
    Rezervare(Reprezentatie* r, int cat, int l, int cod);
    //getter data
    Data get_data();
    //afisare informatii rezervare
    void display_info_rez();
    //modifica loc rezervare
    void modif_rez(int categ_noua, int loc_nou);
};
//constructor neparametrizat
Rezervare::Rezervare(): categorie(0), loc(0), reprezentatie(nullptr), cod_r(0) {}

//constructor parametrizat
Rezervare::Rezervare(Reprezentatie* r, int cat, int l, int cod): categorie(cat), loc(l), reprezentatie(r), cod_r(cod) {}

//getter data
Data Rezervare::get_data() {
    return reprezentatie->get_data();
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
    categorie = categ_noua;
    loc = loc_nou;
}

class RezList {
    class Node {
        Rezervare* rez;
        Node* next;
    public:
        //constructor parametrizat
        Node(Rezervare* r,Node *ptr){
            rez = r;
            next = ptr;
        };
        void set_rez(Rezervare* r) {
            rez = r;
        };
        void set_ptr(Node* ptr) {
            next = ptr;
        };
        Rezervare* get_rez() {
                return rez;
        };
        Node* get_ptr() {
            return next;
        };
        ~Node() {
            if (next != nullptr) {
                delete next;
            }
        }
    };
    Node *first;
public:
    //crearea unei liste vide
    RezList();
    //copy constructor
    RezList(RezList &rl);
    //inserare inaintea unui nod
    void insert_before(Rezervare *r, Node* pre, Node* post);
    //adaugarea unei rezervari in lista
    void add_rez(Rezervare *r);
    //afisarea listei sub forma de calendar
    void display_list();
    //accesarea reprezentatiei de pe pozitia i
    Rezervare* access_i_rez(int i);
    //destructor
    ~RezList();
};
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
            cout << "_____________ " << indice << endl;
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
//destructor
RezList::~RezList() {
    delete first;
}