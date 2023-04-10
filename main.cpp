#include <iostream>
#include "Classes.h"

int main() {
    //piese de teatru
    Piesa_teatru CeiDrepti("Cei drepti", "Albert Camus", "Mihai Maniutiu", "Adrian Damian", "Luiza Enescu", "Mihai Dobre", 1, 30);
    Piesa_teatru TitanicVals("Titanic Vals", "Tudor Musatescu", "Dan Tudor", "Stefan Caragiu", "-", "Mihai Dobre", 2, 45, 0, 15);
    Piesa_teatru CursaDeSoareci("Cursa de Soareci", "Agatha Christie", "Erwin Șimșensohn", "-", "-", "Vlaicu Golgea", 2, 15, 0, 15 );
    Piesa_teatru RegeleMoare("Regele moare", "Eugene Ionesco", "Andrei si Andreea Grosu", "-", "-", "-", 1, 40);
    Piesa_teatru CraiiDeCurteaVeche("Craii de Curtea-Veche", "Mateiu Caragiale", "Dragos Galgotiu", "Dragos Galgotiu", "Lia Mantoc", "Dragos Galgotiu", 2, 15, 0, 10);
    //sali
    Sala Mica("Sala Mica", "Bucuresti, Sector 1, Str. Mare, nr. 5", 20, 30, 40);
    Sala Amfiteatru("Amfiteatru", "Bucuresti, Sector 1, Str. Mare, nr.6", 35, 45, 55);
    Sala Mare("Sala Mare", "Bucuresti, Sector 1, Str. Mare, nr.2", 40, 50, 60);
    //reprezentatii
    int nr_repr = 7;
    Reprezentatie CD5Mai(&CeiDrepti, 19, 30, 5, 5, 2023, &Mare, 100, 80, 50);
    Reprezentatie CD12Mai(&CeiDrepti, 20, 0, 12, 5, 2023, &Mare, 100, 80, 50);
    Reprezentatie TV5Mai(&TitanicVals, 19, 30, 5, 5, 2023, &Amfiteatru, 80, 60, 50);
    Reprezentatie TV20Mai(&TitanicVals, 20, 0, 20, 5, 2023, &Amfiteatru, 80, 60, 50);
    Reprezentatie CS12Mai(&CursaDeSoareci, 20, 30, 12, 5, 2023, &Mica, 50, 30, 20);
    Reprezentatie RM18Mai(&RegeleMoare, 19, 30, 18, 5, 2023, &Amfiteatru, 90, 80, 70);
    Reprezentatie CCV12Mai(&CraiiDeCurteaVeche, 20, 0, 12, 5, 2023, &Mica, 50, 30, 20);
    //lista de reprezentatii
    ReprList lista_reprezentatii;
    lista_reprezentatii.add_repr(&CD5Mai);
    lista_reprezentatii.add_repr(&CD12Mai);
    lista_reprezentatii.add_repr(&TV5Mai);
    lista_reprezentatii.add_repr(&TV20Mai);
    lista_reprezentatii.add_repr(&CS12Mai);
    lista_reprezentatii.add_repr(&RM18Mai);
    lista_reprezentatii.add_repr(&CCV12Mai);
    //meniu
    cout << "Calendar\nInformatii despre numele_piesei, ora de incepere, sala in care se desfasoara, numarul de locuri disponibile,\n codul reprezentatiei\n";
    lista_reprezentatii.display_list();
    cout << "Optiuni:\nAfisare detalii spectacol___1\nAfisare detalii sala___2\nRezerva___3\nAfiseaza rezervarile___4\n";
    cout << "Introduceti codul optiunii alese: ";
    int opt;
    cin >> opt;
    cout << "Introduceti codul reprezentatiei: ";
    int rez;
    cin >> rez;
    if(opt == 1) {
        if(rez <= nr_repr && rez >= 1) {
            lista_reprezentatii.access_i_repr(rez).get_piesa().piesa_display();
        }
        else
            cout << "Cod de reprezetatie incorect.";
        return 0;
    }
    else if(opt == 2) {
        lista_reprezentatii.access_i_repr(rez).get_sala().display();
    }
    else if(opt == 3) {

    }
    else if(opt == 4) {

    }
    else {
        cout <<"Cod de optiune incorect.";
        return 0;
    }
    return 0;
}

