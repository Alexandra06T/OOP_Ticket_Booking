#include <iostream>
#include "Classes.h"

int Rezervare::nr_rezervari = 0;
vector<Sala*> Sala::lista_sali;
int Sala::nr_sali = 0;

int main() {
    //piese de teatru
    Piesa_teatru CeiDrepti("Cei drepti", "Albert Camus", "Mihai Maniutiu", "Adrian Damian", "Luiza Enescu", "Mihai Dobre", 1, 30);
    Piesa_teatru TitanicVals("Titanic Vals", "Tudor Musatescu", "Dan Tudor", "Stefan Caragiu", "-", "Mihai Dobre", 2, 45, 0, 15);
    Piesa_teatru CursaDeSoareci("Cursa de Soareci", "Agatha Christie", "Erwin Simensohn", "-", "-", "Vlaicu Golgea", 2, 15, 0, 15 );
    Piesa_teatru RegeleMoare("Regele moare", "Eugene Ionesco", "Andrei si Andreea Grosu", "-", "-", "-", 1, 40);
    Piesa_teatru CraiiDeCurteaVeche("Craii de Curtea-Veche", "Mateiu Caragiale", "Dragos Galgotiu", "Dragos Galgotiu", "Lia Mantoc", "Dragos Galgotiu", 2, 15, 0, 10);
    //EventManager pentru piese de teatru - clasa template specializata
    cout << "Testare\n\n";
    EventManager<Piesa_teatru*> p;
    p.add_event(&CeiDrepti);
    p.add_event(&TitanicVals);
    cout << "EventManager cu piese de teatru\n";
    p.display();
    cout << endl;
    p.info_by_name("Cei drepti");
    cout << endl;
    p.info_by_regie("Dan Tudor");
    cout << endl;
    p.del_event(&CeiDrepti);
    p.display();
    cout << endl;
    //balet
    Balet DonQuijote("Don Quijote", "Miguel de Cervantes", "Katerina Slavicka-Elslegrova", "Jaroslav Slavicky", "-", "-", 3, 30);
    Balet LaculLebedelor("Lacul Lebedelor", "Piotr Ilici Ceaikovski", "-", "Oleg Danovski", "Viorica Petrovici & Adrian Damian", "-", 3, 30);
    //EventManager pentru balet - clasa template generala
    cout << "EventManager cu balet\n";
    EventManager<Balet> b;
    b.add_event(&DonQuijote);
    b.display();
    cout << endl;
    b.del_event(DonQuijote);
    b.display();

    //sali
    Sala Mica("Sala Mica", "Bucuresti, Sector 1, Str. Mare, nr. 5", 20, 30, 40);
    Sala Amfiteatru("Sala Amfiteatru", "Bucuresti, Sector 1, Str. Mare, nr.6", 35, 45, 55);
    Sala Mare("Sala Mare", "Bucuresti, Sector 1, Str. Mare, nr.2", 40, 50, 60);
    //EventManager pentru sali
    cout << "EventManager cu sali\n";
    EventManager<Sala> s;
    s.add_event(&Mica);
    s.add_event(&Amfiteatru);
    s.add_event(&Mare);
    s.display();
    //reprezentatii
    int nr_repr = 7;
    Reprezentatie CD5Mai(&CeiDrepti, 19, 30, 5, 5, 2023, &Mare, 100, 80, 50, 0, 0);
    Reprezentatie CD12Mai(&CeiDrepti, 20, 0, 12, 5, 2023, &Mare, 100, 80, 50, 1, 0.3);
    Reprezentatie TV5Mai(&TitanicVals, 19, 30, 5, 5, 2023, &Amfiteatru, 80, 60, 50, 2, 0.2);
    Reprezentatie TV20Mai(&TitanicVals, 20, 0, 20, 5, 2023, &Amfiteatru, 80, 60, 50, 3, 0.1);
    Reprezentatie CS12Mai(&CursaDeSoareci, 20, 30, 12, 5, 2023, &Mica, 50, 30, 20, 0, 0.4);
    Reprezentatie RM18Mai(&RegeleMoare, 19, 30, 18, 5, 2023, &Amfiteatru, 90, 80, 70, 0);
    Reprezentatie CCV12Mai(&CraiiDeCurteaVeche, 20, 0, 12, 5, 2023, &Mica, 50, 30, 20, 0);
    // amanam o reprezentatie cu oferta
    cout << "\nTestare clase mostenire multipla\nAmanam o reprezentatie cu oferta\n";
    CD12Mai.get_cat(1)->display_start_date();
    CD12Mai.get_cat(1)->amana(20, 0, 13, 5, 2023);
    CD12Mai.get_cat(1)->display_start_date();
    cout << "\namanam o reprezentatie cu reducere de ultima zi\n";
    // amanam o reprezentatie cu reducere de ultima zi
    TV5Mai.get_cat(1)->display_start_date();
    TV5Mai.get_cat(1)->amana(19, 30, 8, 5, 2023);
    TV5Mai.get_cat(1)->display_start_date();
    cout << "\namanam o reprezentatie cu reducere dubla\n";
    // amanam o reprezentatie cu reducere dubla
    TV20Mai.get_cat(1)->display_start_date();
    TV20Mai.get_cat(1)->amana(20, 0, 25, 5, 2023);
    TV20Mai.get_cat(1)->display_start_date();
    cout << endl;
    //lista de reprezentatii
    ReprList lista_reprezentatii;
    lista_reprezentatii.add_repr(&CD5Mai);
    lista_reprezentatii.add_repr(&CD12Mai);
    lista_reprezentatii.add_repr(&TV5Mai);
    lista_reprezentatii.add_repr(&TV20Mai);
    lista_reprezentatii.add_repr(&CS12Mai);
    lista_reprezentatii.add_repr(&RM18Mai);
    lista_reprezentatii.add_repr(&CCV12Mai);
    //rezervari
    Rezervare r1(&CCV12Mai, 1, 7, 1);
    Rezervare r2(&RM18Mai, 2, 23, 0);
    Rezervare r3(&TV5Mai, 3, 15, 2);
    //istoric rezervari - clasa care mosteneste privat Rezervare
    cout << "Testare IstoricRezervari - clasa care mosteneste privat Rezervare\n";
    IstoricRezervari ir;
    ir.add_rez(&r1);
    //ir.display();
    //cout << endl;
    ir.add_rez(&r2);
    //ir.display();
    //cout << endl;
    ir.add_rez(&r3);
    ir.display();
    cout << "\nafisarea rezervarilor pentru o data anume\n";
    Data d(19, 30, 5, 5, 2023);
    ir.get_by_date(Data(19, 30, 5, 5, 2023));
    cout << "\nafisarea rezervarilor pentru o anumita piesa\n";
    ir.get_by_piesa("Titanic Vals");
    RezList lista_rezervari;
//    lista_rezervari.add_rez(&r1);
//    lista_rezervari.add_rez(&r2);
//    lista_rezervari.add_rez(&r3);
    //meniu
    cout << "\nCALENDAR\nInformatii despre numele_piesei, ora de incepere, sala in care se desfasoara, numarul de locuri disponibile,\n codul reprezentatiei\n\n";
    cout << "OBS: Aplicatia ofera doar informatii despre sectiunea Balet. Pentru rezervari, va rugam sa mergeti la casa de bilete.\n";
    lista_reprezentatii.display_list();
    while (true) {
        Rezervare::initiere();

        cout << "\nOPTIUNI:\nAfisare detalii spectacol___1\nAfisare detalii sala___2\nRezerva___3\nAfisare rezervari___4\nModifica rezervarea___5\nAnuleaza rezervarea___6\nCreeaza sala___7\nCreeaza piesa de teatru___8\n";
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
                r->get_piesa().display();
            }
            else {
                cout << "\nCod de reprezentatie incorect.";
                return 0;
            }
        }
        else if(opt == 2) {
            Sala::display_sali();
            cout << "\nIntroduceti codul salii:";
            int s;
            cin >> s;
            Sala::get_i_sala(s)->display();
            }
        else if(opt == 3) {
            cout << "\nIntroduceti codul reprezentatiei:";
            int rez;
            cin >> rez;
            Reprezentatie* r = lista_reprezentatii.access_i_repr(rez);
            cout << "\nCategorie 1   locuri disponibile " << r->get_cat(1)->nr_disp() << "   " << r->get_pret(1, 0) << " lei" << endl;
            cout << "Categorie 2   locuri disponibile " << r->get_cat(2)->nr_disp() << "   " << r->get_pret(2, 0) << " lei" << endl;
            cout << "Categorie 3   locuri disponibile " << r->get_cat(3)->nr_disp() << "   " << r->get_pret(3, 0) << " lei" << endl;
            cout << "\nIntroduceti codul categoriei:";
            int cat;
            cin >> cat;
            if(cat < 1 || cat >3) {
                cout << "Cod categorie incorect.";
                return 0;
            }
            cout << "\nLocuri disponibile Categoria "<< cat << endl;
            r->get_cat(cat)->display_disponibil();
            cout << "\nIntroduceti numarul locului:";
            int loc;
            cin >> loc;
            if (loc < 1 || loc > r->get_sala().get_C(cat)) {
                cout << "Numar loc incorect.";
                return 0;
            }
            cout << "Introduceti codul de reducere:\n100% elev___ 1\n50% student___ 2\nnu se aplica nicio reducere___0\n";
            int cod_r;
            cin >> cod_r;
            Rezervare *rezervare = new Rezervare(r, cat, loc, cod_r);
            lista_rezervari.add_rez(rezervare);
            r->rezerva(cat, loc);
            cout << "Rezervare finalizata.\n";
            rezervare->display_info_rez();

            Rezervare::fidelizare();
        }
        else if(opt == 4) {
            lista_rezervari.display_list();
        }
        else if(opt == 5) {
            lista_rezervari.display_list();
            cout << "\nIntroduceti cod rezervare\n";
            double i_rez;
            cin >> i_rez;//
            try {
                try {
                    verifica_int(i_rez);
                    Rezervare::verifica_valabilitate(i_rez);
                }
                catch (const wrongType& exceptie) {
                    cout << "\nVa rugam ca data viitoare sa introduceti date compatibile.\n";
                    throw (wrongInput("Nu au fost introduse date compatibile.\n"));
                }
                catch (const wrongInput& exceptie) {
                    cout << "\nVa rugam ca data viitoare sa introduceti date valide.\n";
                    throw;
                }
                Rezervare* r = lista_rezervari.access_i_rez(i_rez);
                cout << "\nCategorie 1   locuri disponibile " << r->get_repr()->get_cat(1)->nr_disp() << "   " << r->get_repr()->get_pret(1, 0) << " lei" << endl;
                cout << "Categorie 2   locuri disponibile " << r->get_repr()->get_cat(2)->nr_disp() << "   " << r->get_repr()->get_pret(2, 0) << " lei" << endl;
                cout << "Categorie 3   locuri disponibile " << r->get_repr()->get_cat(3)->nr_disp() << "   " << r->get_repr()->get_pret(3, 0) << " lei" << endl;
                cout << "\nIntroduceti codul categoriei:";
                int cat_noua;
                cin >> cat_noua;
                if(cat_noua < 1 || cat_noua >3) {
                    cout << "Cod categorie incorect.";
                    return 0;
                }
                cout << "\nLocuri disponibile Categoria "<< cat_noua << endl;
                r->get_repr()->get_cat(cat_noua)->display_disponibil();
                cout << "\nIntroduceti numarul locului:";
                int loc;
                cin >> loc;
                if (loc < 1 || loc > r->get_repr()->get_sala().get_C(cat_noua)) {
                    cout << "Numar loc incorect.";
                    return 0;
                }
                cout << "Introduceti codul de reducere:\n20% rezervare in ultima zi___ 1\n50% student___ 2\n100% elev___ 3\nnu se aplica nicio reducere___0\n";
                int cod_r;
                cin >> cod_r;
                r->modif_rez(cat_noua, loc);
                cout << "Rezervare modificata.\n";
                r->display_info_rez();
            }
            catch (...) {
                cout << "Datele nu au putut fi validate. Va rugam reluati procesul.";
                continue;
            }
        }
        else if(opt == 6) {
            lista_rezervari.display_list();
            cout << "\nIntroduceti cod rezervare\n";
            int i_rez;
            cin >> i_rez;
            try {
                try {
                    verifica_int(i_rez);
                    Rezervare::verifica_valabilitate(i_rez);
                }
                catch (const wrongType& exceptie) {
                    cout << "\nVa rugam ca data viitoare sa introduceti date compatibile.\n";
                    throw (wrongInput("Nu au fost introduse date compatibile.\n"));
                }
                catch (const wrongInput& exceptie) {
                    cout << "\nVa rugam ca data viitoare sa introduceti date valide.\n";
                    throw;
                }
                lista_rezervari.sterge_rez(i_rez);
                cout << "Rezervare anulata.\n";
            }
            catch(...) {
                cout << "Datele nu au putut fi validate. Va rugam reluati procesul.";
                continue;
            }
        }
        else if(opt == 7) {
            cout << "in loc de spatiu, folositi _\n";
            //citirea datelor
            cout << "\nIntroduceti numele salii\n";
            char nume[100];
            cin >> nume;
            cout << "\nIntroduceti adresa\n";
            char adresa[300];
            cin >> adresa;
            cout << "\nIntroduceti numarul de locuri din Categoria 1\n";
            int nr_C1;
            cout << "\nIntroduceti numarul de locuri din Categoria 2\n";
            int nr_C2;
            cin >> nr_C2;
            cout << "\nIntroduceti numarul de locuri din Categoria 3\n";
            int nr_C3;
            cin >> nr_C3;
            //crearea obiectului
            Sala *s = new Sala(nume, adresa, nr_C1, nr_C2, nr_C3);
            cout << "Sala a fost introdusa in aplicatie.\n";
            s->display();
            cout << "\nVreti sa efectuati vreo modificare? da (1) sau nu (0)\n";
            int modif;
            cin >> modif;
            if (modif == 1) {
                cout << "Modificati numele___ 1\nModificati adresa___ 2\nModificati numarul de locuri la categoria 1___ 3\nModificati numarul de locuri la categoria 2___ 4\nModifiacti numarul de locuri la categoria 3___5\n";
                cin >> modif;
                if(modif == 1) {
                    cout << "\nIntroduceti numele salii\n";
                    cin >> nume;
                    s->set_nume(nume);
                }
                else if(modif == 2) {
                    cout << "\nIntroduceti adresa\n";
                    cin >> adresa;
                    s->set_adresa(adresa);
                }
                else if(modif == 3) {
                    cout << "\nIntroduceti numarul de locuri din Categoria 1\n";
                    cin >> nr_C1;
                    s->set_C1(nr_C1);
                }
                else if(modif == 4) {
                    cout << "\nIntroduceti numarul de locuri din Categoria 2\n";
                    cin >> nr_C2;
                    s->set_C2(nr_C2);
                }
                else if(modif == 5) {
                    cout << "\nIntroduceti numarul de locuri din Categoria 3\n";
                    cin >> nr_C3;
                    s->set_C3(nr_C3);
                }
                cout << "Modificarea a fost efectuata.\n";
                s->display();
            }
        }
        else if(opt == 8) {
            //citirea datelor
            cout << "\nIntroduceti numele piesei de teatru\n";
            char nume[100];
            cin >> nume;
            cout << "\nIntroduceti numele autorului\n";
            char a[100];
            cin >> a;
            cout << "\nIntroduceti numele responsabilului pentru regie\n";
            char r[100];
            cin >> r;
            cout << "\nIntroduceti numele responsabilului pentru decor\n";
            char d[100];
            cin >> d;
            cout << "\nIntroduceti numele responsabilului pentru costume\n";
            char c[100];
            cin >> c;
            cout << "\nIntroduceti numele responsabilului pentru muzica\n";
            char m[100];
            cin >> m;
            cout << "\nIntroduceti durata piesei (numarul de ore)\n";
            int od;
            cin >> od;
            cout << "\nIntroduceti durata piesei (numarul de minute)\n";
            int md;
            cin >> md;
            cout << "\nIntroduceti durata pauzei (numarul de ore)\n";
            int op;
            cin >> op;
            cout << "\nIntroduceti durata pauzei (numarul de minute)\n";
            int mp;
            cin >> mp;
            //crearea obiectului
            Piesa_teatru *p = new Piesa_teatru(nume, a, r, d, c, m, od, md, op, mp);
            cout << "Piesa a fost introdusa in aplicatie\n";
            p->display();
            cout << "\nVreti sa efectuati vreo modificare? da (1) sau nu (0)\n";
            int modif;
            cin >> modif;
            if (modif == 1) {
                cout << "Modificati numele___ 1\nModificati autorul___ 2\n";
                cin >> modif;
                if(modif == 1) {
                    cout << "\nIntroduceti numele piesei\n";
                    cin >> nume;
                    p->set_nume(nume);
                }
                else if(modif == 2) {
                    cout << "\nIntroduceti numele autorului\n";
                    cin >> a;
                    p->set_autor(a);
                }
                cout << "Modificarea a fost efectuata.\n";
                p->display();
            }
        }
        else {
            cout <<"Cod de optiune incorect.";
            return 0;
        }
    }
    return 0;
}

