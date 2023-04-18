# Rezervarea biletelor de teatru. Aplicatie C++

## Descrierea aplicatiei
Respectand principiile Programarii Orientate pe Obiecte, 
construita folosind limbajul C++, aplicatia gestioneaza 
rezervarile efectuate de clienti la spectacolele
organizate de un teatru. Aceasta ofera un calendar cu reprezentatiile dintr-o anumita perioada si un meniu interactiv ce ii 
ofera utilizatorului posibilitatea de:
- a se informa cu privire la spectacolele organizate
    - numele piesei
    - autorul
    - regizorul
    - responsabilii pentru decor, costume, muzica
    - durata specatcolului
    - durata pauzei
- a se informa cu privire la sala in care se va desfasura spectacolului dorit
  - numele salii
  - adresa
- a rezerva un loc la un spectacol ales (se creeaza un nou obiect de tip rezervare in urma citirii unor date de la tastatura)
  - utilizatorul specifica reprezentatia la care intentioneaza sa participe
  - alege o categorie, fiind informat asupra numarului de locuri disponibile
  ramase si de pretul fiecarei categorii
  - alege numarul locului pe care doreste sa il rezerve din lista de locuri disponibile afisata
  - specifica un cod de reducere
    - avand statut de elev (100%)
    - avand statut de student (50%)
    - rezervand locul in ziua reprezentatiei (20%)
  - este informat ca rezervarea a fost realizata cu succes si ii este afisat rezumatul rezervarii
    - numele piesei
    - data reprezentatiei
    - sala in care se desfasoara spectacolul
    - numarul de locuri ramas disponibil
    - categoria aleasa
    - locul rezervat
    - pretul, caruia i s-a aplicat corespunzator reducerea
- a se informa cu privire la rezervarile realizate in prealabil
- a modifica rezervari realizate in prealabil
  - utilizatorul alege rezervarea pe care doreste sa o modifice
  - alege o noua categorie de locuri
  - alege un nou loc
  - introduce un cod de reducere
  - este informat ca modificarea a avut loc cu succes si i se afiseaza un rezumat
- a anula o rezervare realizata in prealabil
<br> De asemenea, utilizatorul poate introduce informatii despre o piesa de teatru si despre o sala si poate efectua modificari asupra datelor introduse.

## Scurta descriere a provocarilor intalnite in realizarea aplicatiei

Aplicatia trebuie sa puna la dispozitie utilizatorului atat informatii cat si posibilitatea de a face o rezervare.
Astfel, a fost necesara crearea unui calendar de reprezentatii, fiecare reprezentatie fiind programata intr-o anumita zi, la o anumita
ora, intr-o anumita sala. Fiecare piesa de teatru poate avea mai multe reprezentatii, fiecare sala are cate trei categorii de locuri,
iar fiecare loc apartine unei categorii si are un anumit pret in functie se reprezentatie si categorie. In ceea ce priveste rezervarile,
 doi utilizatori nu pot rezerva acelasi loc la aceeasi reprezentatie si este necesara posibilitatea modificarii si a anularii rezervarilor efectuate, cu
 disponibilizarea sau rezervarea adecvata a locurilor.

## Descriere a claselor implementate si a interactiunilor dintre acestea

### Clasa utilitara String

Clasa utilitara pentru siruri de caractere. Foloseste alocare dinamica de memorie.

### Clasa utilitara IntList

Clasa utilitara pentru liste simplu inlantuita cu noduri alocate dinamic. Pentru retinerea unor intregi.

### Clasa Data

Clasa pentru gestionarea datelor calendaristice si a duratelor.

### Clasa Sala

Clasa pentru gestionarea salilor, fiecare cu nume, adresa si numar de locuri.

### Clasa Piesa_teatru

Clasa pentru gestionarea spectacolelor, detinand informatii despre autor, punere in scena, durata, pauza. Foloseste campuri de tip String si Data.

### Clasa Categorie

Clasa pentru gestionarea informatiilor legate de locurile de la o reprezentatie (pret, numar de locuri disponibile, numar de locuri rezervate, lista cu locurile disponibile).
Locurile sunt numerotate de la 1 pana la numarul de locuri din acea categorie. Lista de locuri disponibile este de tip IntList. Are metode specifice pentru rezervare, modificare de loc.

### Clasa Reprezentatie

Clasa pentru gestionarea unei reprezentatii (programarea unei piese de teatru intr-o anumita sala si la o anumita data calendaristica).
Fiecare obiect de tip Reprezentatie are un camp de tip pointer catre o piesa de teatru (obiect de tip Piesa_teatru) si un camp de tip pointer catre o sala (un obiect de tip Sala).
Fiecare obiect de tip reprezentatie creeaza un obiect de tip data si trei obiecte de tip Categorie, pentru cele trei categorii de locuri, astfel incat fiecare reprezentatie retine o "imagine" proprie a locurilor disponibile si rezervate.

### Clasa ReprList

Clasa pentru liste simplu inlantuite de obiecte de tip Reprezentatie, retinute in ordine cronologica. Utilizata pentru programul teatrului si pentru ca utilizatorul sa poate alege o anumita reprezentatie pentru rezervare.

### Clasa Rezervare

Clasa pentru gestionarea rezervarilor utilizatorului. Fiecare obiect de tip Rezervare contine un camp de tip pointer catre un obiect Reprezentatie.

### Clasa RezList

Clasa pentru liste simplu inlantuite de obiecte de tip Rezervare, retinute in ordine cronologica.


