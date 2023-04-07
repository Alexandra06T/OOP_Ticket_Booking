//
// Created by email on 07.04.2023.
//

#ifndef TICKET_BOOKING_CLASSES_H
#define TICKET_BOOKING_CLASSES_H

#endif //TICKET_BOOKING_CLASSES_H

#include <cstring>
#include <iostream>
using namespace std;

// clasa utilitara MyString
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
};

String::String() {
    lungime = 0;
    pointer = nullptr;
}
String::String(const char *sir) {
    lungime = ::strlen(sir);
    pointer = new char[lungime];
    ::strncpy(pointer, sir, lungime);
}
String::~String() {
    delete[] pointer;
    lungime = 0;
}
String::String(String &sir) {
    lungime = sir.lungime;
    pointer = new char[lungime];
    ::strncpy(pointer, sir.pointer, lungime);
}
void String::display() {
    int i;
    for (i = 0; i < lungime; i++)
        cout << pointer[i];
    cout << endl;
}
void String::add_char(char c) {
    char* newpointer = new char[lungime+1];
    ::strncpy(newpointer, pointer, lungime);
    newpointer[lungime] = c;
    lungime++;
    pointer = newpointer;
}
void String::concat(const String sir) {
    char* newpointer = new char[lungime+sir.lungime];
    ::strncpy(newpointer, pointer, lungime);
    ::strncpy(&newpointer[lungime], sir.pointer, sir.lungime);
    lungime += sir.lungime;
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