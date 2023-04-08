#include <iostream>
#include "Classes.h"

int main() {

//    int v[5] = {1, 2, 3, 4,5 };
//    IntList li(5, v), l2(li), l3 = li, l4;
//    l4.concat(l2,l3);
//    l2.display();
//    l3.display();
//    l4.display();
//    l2.display();
//    l3.display();
//    cout << li.access_val(1) << endl;
//    l2.set_i_val(5, 7);
//    l2.display();
//    cout << l2.find_val(3);
//    Sala A("Aaa", "Str. nr.", 15, 20, 40);
//    A.display();
//    cout << A.get_C1() << endl;
//    A.set_C1(1);
//    A.set_nume("Bbb");
//    A.display();
//    cout << A.get_C1() << endl;
//    cout << ::strlen("ana");
//    String s("Ana"), t("bbb");
//    cout << s;
//    s.concat(t);
//    s.display();
    Piesa_teatru p("Cei drepti", "Albert Camus", "Mihai Maniutiu", "Adrian Damian", "Luiza Enescu", "Mihai Dobre", 1, 30);
    p.piesa_display();
    Data d;
    d.data_display();
    Categorie c(50, 20);
    c.set_rezervat(3);
    c.display_disponibil();
    cout << endl << c.pret_final(0);
    return 0;
}

