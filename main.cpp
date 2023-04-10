#include <iostream>
#include "Classes.h"

int main() {
    //piese de teatru
    Piesa_teatru CeiDrepti("Cei drepti", "Albert Camus", "Mihai Maniutiu", "Adrian Damian", "Luiza Enescu", "Mihai Dobre", 1, 30);
    Piesa_teatru TitanicVals("Titanic Vals", "Tudor Musatescu", "Dan Tudor", "Stefan Caragiu", "-", "Mihai Dobre", 2, 45, 0, 15);
    Piesa_teatru CursaDeSoareci("Cursa de Soareci", "Agatha Christie", "Erwin Simensohn", "-", "-", "Vlaicu Golgea", 2, 15, 0, 15 );
    Piesa_teatru RegeleMoare("Regele moare", "Eugene Ionesco", "Andrei si Andreea Grosu", "-", "-", "-", 1, 40);
    Piesa_teatru CraiiDeCurteaVeche("Craii de Curtea-Veche", "Mateiu Caragiale", "Dragos Galgotiu", "Dragos Galgotiu", "Lia Mantoc", "Dragos Galgotiu", 2, 15, 0, 10);
    //sali
    Sala Mica("Sala Mica", "Bucuresti, Sector 1, Str. Mare, nr. 5", 20, 30, 40);
    Sala Amfiteatru("Sala Amfiteatru", "Bucuresti, Sector 1, Str. Mare, nr.6", 35, 45, 55);
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
    RezList lista_rezervari;
    //meniu
    cout << "\nCALENDAR\nInformatii despre numele_piesei, ora de incepere, sala in care se desfasoara, numarul de locuri disponibile,\n codul reprezentatiei\n\n";
    lista_reprezentatii.display_list();
    while (true) {
        cout << "\nOPTIUNI:\nAfisare detalii spectacol___1\nAfisare detalii sala___2\nRezerva___3\nAfiseaza rezervarile___4\nModifica rezervarea___5\n";
        cout << "\nIntroduceti codul optiunii alese:";
        int opt;
        cin >> opt;
        if(opt == 1) {
            cout << "\nIntroduceti codul reprezentatiei:";
            int rez;
            cin >> rez;
            Reprezentatie* r = lista_reprezentatii.access_i_repr(rez);
            if(rez <= nr_repr && rez >= 1) {
                cout << endl;
                r->get_piesa().piesa_display();
            }
            else {
                cout << "\nCod de reprezetatie incorect.";
                return 0;
            }
        }
        else if(opt == 2) {
            cout << "\nIntroduceti codul reprezentatiei:";
            int rez;
            cin >> rez;
            Reprezentatie* r = lista_reprezentatii.access_i_repr(rez);
            r->get_sala().display();
        }
        else if(opt == 3) {
            cout << "\nIntroduceti codul reprezentatiei:";
            int rez;
            cin >> rez;
            Reprezentatie* r = lista_reprezentatii.access_i_repr(rez);
            cout << "\nCategorie 1   locuri disponibile " << r->get_cat(1).nr_disp() << "   " << r->get_pret(1, 0) << " lei" << endl;
            cout << "Categorie 2   locuri disponibile " << r->get_cat(2).nr_disp() << "   " << r->get_pret(2, 0) << " lei" << endl;
            cout << "Categorie 3   locuri disponibile " << r->get_cat(3).nr_disp() << "   " << r->get_pret(3, 0) << " lei" << endl;
            cout << "\nIntroduceti codul categoriei:";
            int cat;
            cin >> cat;
            if(cat < 1 || cat >3) {
                cout << "Cod categorie incorect.";
                return 0;
            }
            cout << "\nLocuri disponibile Categoria "<< cat << endl;
            r->get_cat(cat).display_disponibil();
            cout << "\nIntroduceti numarul locului:";
            int loc;
            cin >> loc;
            if (loc < 1 || loc > r->get_sala().get_C(cat)) {
                cout << "Numar loc incorect.";
                return 0;
            }
            cout << "Introduceti codul de reducere:\n20% rezervare in ultima zi___ 1\n50% student___ 2\n100% elev___ 3\nnu se aplica nicio reducere___0\n";
            int cod_r;
            cin >> cod_r;
            r->get_cat(cat).display_disponibil();
            Rezervare rezervare(r, cat, loc, cod_r);
            lista_rezervari.add_rez(&rezervare);
            r->rezerva(cat, loc);
            cout << "Rezervare finalizata.\n";
            rezervare.display_info_rez();
        }
        else if(opt == 4) {
            lista_rezervari.display_list();
        }
        else if(opt == 5) {
            lista_rezervari.display_list();
            cout << "\nIntroduceti cod rezervare\n";
            int i_rez;
            cin >> i_rez;
            Rezervare* r = lista_rezervari.access_i_rez(i_rez);
            cout << "\nCategorie 1   locuri disponibile " << r->get_cat(1).nr_disp() << "   " << r->get_pret(1, 0) << " lei" << endl;
            cout << "Categorie 2   locuri disponibile " << r->get_cat(2).nr_disp() << "   " << r->get_pret(2, 0) << " lei" << endl;
            cout << "Categorie 3   locuri disponibile " << r->get_cat(3).nr_disp() << "   " << r->get_pret(3, 0) << " lei" << endl;
            cout << "\nIntroduceti codul categoriei:";
            //de terminat;
        }
        else {
            cout <<"Cod de optiune incorect.";
            return 0;
        }
    }
    return 0;
}

