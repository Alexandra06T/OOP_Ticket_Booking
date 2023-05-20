#ifndef TICKET_BOOKING_CLASSES_H
#define TICKET_BOOKING_CLASSES_H


#include <cstring>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
using namespace std;

//exceptii
class wrongType: public exception {
    const string message;
public:
    wrongType(const string& msg): message(msg) {
        cout << "Exception WrongType: " << message;
    };

};
class wrongInput: public exception {
    const string message;
public:
    wrongInput(const string& msg): message(msg) {
        cout << "Exception WrongInput: " << message;
    };
};

// clasa utilitara String
class String {
    char* pointer;
    int lungime;
public:
    //constructor neparametrizat
    String();
    //constructor parametrizat
    String(const char *sir);
    //destructor
    ~String();
    //copy constructor
    String(String &sir);
    //supraincarcarea operatorului =
    String& operator = (String const&sir){
        if(pointer != nullptr)
            delete[] pointer;
        lungime = sir.lungime;
        pointer = new char[lungime];
        ::strncpy(pointer, sir.pointer, lungime);
        return *this;
    }
    //functie afisare
    void display() const;
    //adaugarea unui caracter la finalul stringului
    void add_char(char c);
    //gasirea unui substring intr-un string
    char* find_substr(const char* subsir);
    //supraincarcarea operatorului <<
    friend ostream & operator << (ostream &out, String const& s);
};

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
    void data_display() const;
    //afisare durata
    void durata_display() const;
    //afisare ora si minut
    void display_ora_minut() const;
    //supraincarcarea operatorului != pentru verificarea diferntei dintre doua zile
    friend bool operator != (Data const &d1, Data const &d2);
    //getter an
    int get_an() const;
    //getter luna
    int get_luna() const;
    //getter zi
    int get_zi() const;
    //getter ora
    int get_ora() const;
    //getter minute
    int get_minute() const;

};
class Sala {
    static vector<Sala*> lista_sali;
    static int nr_sali;
    String nume_sala;
    String adresa;
    int nr_locuri_C1;
    int nr_locuri_C2;
    int nr_locuri_C3;
public:
    //constructor parametrizat Sala
    Sala(const char* nume, const char* adr, int nr_C1, int nr_C2, int nr_C3);
    //afiseaza informatii despre nume_sala si adresa
    void display() const;
    //getter nr_locuri_C
    int get_C(int cat) const;
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
    //destructor
    ~Sala();
    //afisare lista sali
    static void display_sali();
    //getter numar sali
    static int get_nr_sali();
    //accesarea salii de pe pozitia i
    static Sala* get_i_sala(int i);

};

class Eveniment {
public:
    virtual string get_nume() const = 0;
    virtual void display() const = 0;
    virtual ~Eveniment() = default;
};

class Balet: public Eveniment {
    string nume_balet;
    string autor;
    string maestru_de_repetitii;
    string coregrafie;
    string decor_costume;
    string lumini;
    Data durata;
public:
    Balet(string nume, string a, string m, string co, string dc, string l, int ore, int min);
    string get_nume() const;
    void display() const;
};

class Piesa_teatru {
    string nume_piesa;
    string autor;
    string regie;
    string decor;
    string costume;
    string muzica;
    Data durata;
    Data pauza;
public:
    //constructor Piesa_teatru parametrizat
    Piesa_teatru(string nume, string a, string r, string d, string c, string m, int od, int md, int op = 0, int mp = 0);
    //afisare informatii despre o piesa de teatru
    void display() const;
    //getter nume piesa
    string get_nume() const;
    //setter nume piesa
    void set_nume(const string &nume);
    //setter nume autor
    void set_autor(const string &a);
    //getter regie
    string get_regie() const;

};

class Categorie {
    //pentru fiecare categorie in parte, locurile sunt etichetate de la 1 la nr de locuri total din categorie
    int nr_locuri_disponibile;
    int nr_locuri_rezervate;
    //lista alocata dinamic ce retine pt fiecare loc in parte daca este disponibil(0) sau ocupat(1)
    IntList lista_locuri;
    Data start_pret;
protected:
    float pret;

public:
    //constructor neparametrizat Categorie
    Categorie();
    //constructor parametrizat Categorie
    Categorie(float p, int d, int o, int m, int z , int l, int a );
    //getter pret
    float get_pret() const;
    //setter pret
    void set_pret(float pret_nou);
    //setter loc devine rezervat
    void set_rezervat(int i);
    //setter loc devine disponibil
    void set_disponibil(int i);
    //getter nr_locuri disponibile
    int nr_disp() const;
    //afiseaza lista locuri disponibile
    void display_disponibil();
    //calculeaza pret, aplicand eventuale reduceri (0% (cod reducere 0), 100% elev (cod reducere 1), 50% student (cod reducere 2)
    virtual float pret_final() const;
    virtual ~Categorie() = default;
    virtual void amana(int o, int m, int z , int l, int a);
    virtual void display_start_date();
    Data get_start_pret();

};

class Oferta: virtual public Categorie {
    float procent;
protected:
    Data start_oferta;
public:
    Oferta();
    Oferta(const float &pr, float p, int disp, int o, int m, int z , int l, int a);
    float get_procent() const;
    float pret_final() const;
    void amana(int o, int m, int z , int l, int a);
    void display_start_date();
};

class Reducere_last_day: virtual public Categorie {
    bool last_day;
protected:
    Data start_reducere;
public:
    Reducere_last_day();
    Reducere_last_day(bool ld, float p, int disp, int o, int m, int z , int l, int a);
    void set_last_day(bool ld);
    float procent_ld() const;
    float pret_final() const;
    void amana(int o, int m, int z , int l, int a);
    void display_start_date();
};

class Reducere_dubla: public Oferta, public Reducere_last_day {
    Data start_rd;
public:
    float pret_final() const;
    Reducere_dubla() = default;
    Reducere_dubla(const float &pr, bool ld, float p, int disp,  int o , int m, int z , int l, int a);
    void change_start();
    void amana(int o, int m, int z , int l, int a);
    void display_start_date();
};

class Reprezentatie {
    static int nr_reprezentatii;
    Piesa_teatru* piesa;
    Data data_repr;
    Sala* s;
    Categorie *C1;
    Categorie *C2;
    Categorie *C3;
public:
    //crearea unei reprezentatii vide
    Reprezentatie();
    //constructor parametrizat
    Reprezentatie(Piesa_teatru* p, int o, int m, int z , int l, int a, Sala* sl, float p1, float p2, float p3, int cod, float pr = 0);
    //afisarea detaliilor unei reprezentatii
    void display_info_repr() const;
    //getter data
    Data get_data() const;
    //getter pret
    float get_pret(int categorie, int cod) const;
    //getter piesa
    Piesa_teatru get_piesa() const;
    //getter sala
    Sala get_sala() const;
    //getter cat
    Categorie* get_cat(int i) const;
    //setter categorie
    void set_cat(int i, Categorie* c);
    //calculeaza numarul total de locuri disponibile pentru o reprezentatie
    int total_disp() const;
    //rezerva loc
    void rezerva(int cat, int loc);
    //modifica locul rezervat
    void modif_loc(int cat_vechi, int cat_nou, int loc_vechi, int loc_nou);
    //anuleaza rezervarea locului
    void sterge_rez_loc(int cat, int loc);
    //destructor reprezentatie
    ~Reprezentatie();

};

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

class Rezervare {
    static int nr_rezervari;
    int cod_r; // cod reducere
    int categorie;
    int loc;
    Reprezentatie* reprezentatie;
public:
    //constructor neparametrizat
    Rezervare();
    //constructor parametrizat
    Rezervare(Reprezentatie* r, int cat, int l, int cod);
    //destructor
    ~Rezervare();
    //getter data
    Data get_data() const;
    //getter reprezentatie
    Reprezentatie* get_repr()const ;
    //getter categorie
    int get_nr_cat() const;
    //getter loc
    int get_nr_loc() const;
    //afisare informatii rezervare
    void display_info_rez();
    //modifica loc rezervare
    void modif_rez(int categ_noua, int loc_nou);
    //setter static member
    void static set_nr_rez(int val);
    //getter static member
    int static get_nr_rez();
    //fidelizare
    void static fidelizare();
    //intitiere
    void static initiere();
    //verificare interval
    static void verifica_valabilitate(int i);
};

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
    //sterge din lista rezervarea de pe pozitia i
    void sterge_rez(int i);
    //destructor
    ~RezList();
};
class IstoricRezervari: private Rezervare {
    vector<Rezervare*> lista_rezervari;
public:
    //afisare lista rezervari
    void display();
    //adaugarea unei rezervari in lista
    void add_rez(Rezervare *r);
    //stergerea unei rezervari
    void sterge_rez();
    //afisarea rezervarilor de la o anumita data
    void get_by_date(const Data &d) ;
    //afisarea rezervarilor la o anumite piesa
    void get_by_piesa(const string &p);

};
template <typename T>
class EventManager {
    vector <T*> ev;
public:
    void add_event(T* e) {
        ev.push_back(e);
    }
    void del_event(T e) {
        ev.pop_back();
    }
    void display() {
        for(auto it: ev) {
            it->display();
        }
    }
};

template <>
class EventManager<Piesa_teatru*> {
    vector<Piesa_teatru*> piese;
public:
    void add_event(Piesa_teatru* e) {
        piese.push_back(e);
    }
    void del_event(Piesa_teatru* e) {
        piese.pop_back();
    }
    void info_by_name(const string &s) {
        vector<Piesa_teatru*> copie(piese.size());
        copy_if(piese.begin(), piese.end(), copie.begin(), [=](Piesa_teatru* p) -> bool{
            return (s == p->get_nume());
        } );
        if(!(*copie.begin()))
        {
            cout << "Nu s-au gasit informatii despre piesa " << s << endl;
        }
        else{
            for(auto it = copie.begin(); bool(*it); it++) {
                Piesa_teatru* p = *it;
                p->display();
                cout << endl;
            }
        }
    }
    void info_by_regie(const string &s) {
        vector<Piesa_teatru*> copie(piese.size());
        copy_if(piese.begin(), piese.end(), copie.begin(), [=](Piesa_teatru* p) -> bool{
            return (s == p->get_regie());
        } );
        if(!(*copie.begin()))
        {
            cout << "Nu sunt informatii despre piesele in regia lui " << s << endl;
        }
        else{
            for(auto it = copie.begin(); bool(*it); it++) {
                Piesa_teatru* p = *it;
                p->display();
                cout << endl;
            }
        }
    }
    void display() {
        for(auto it: piese) {
            it->display();
        }
    }
};

class Cladire {
    vector<string>parti;
    string denumire;
public:
    void display();
    Cladire() = default;
    Cladire(const string &d);
    void add_part(const string &p);
    void set_denumire(const string &s);
};

class Builder {
public:
    virtual ~Builder() = default;
    virtual void set_denumire(const string &s) = 0;
    virtual void produceGradinaDeVara() const = 0;
    virtual void produceSala() const = 0;
    virtual void produceCafenea() const = 0;
};

class ConcreteBuilder: public Builder{
    Cladire* cladire;
public:
    ConcreteBuilder();
    ~ConcreteBuilder();
    void reset();
    void set_denumire(const string &s) override;
    void produceGradinaDeVara() const override;
    void produceSala() const override;
    void produceCafenea() const override;
    Cladire* GetCladire();
};

class Director {
    Builder* builder;
public:
    void set_builder(Builder* b);
    void BuildCladireMica();
    void BuildCladireMedie();
    void BuildCladireMare();
};





void verifica_int(double i);

template <class T>
void get_oferte(vector <Reprezentatie*> v) {
    for (auto it: v) {
        if(dynamic_cast<T*> (it->get_cat(1)) != nullptr) {
            it->display_info_repr();
            cout << endl;
            cout << "Categoria 1 " << it->get_pret(1,0) << endl;
            cout << "Categoria 2 " << it->get_pret(2,0) << endl;
            cout << "Categoria 3 " << it->get_pret(3,0) << endl;
        }
    }
}

#endif //TICKET_BOOKING_CLASSES_H