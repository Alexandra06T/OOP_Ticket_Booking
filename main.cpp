#include <iostream>
#include "Classes.h"

int main() {

    int v[5] = {1, 2, 3, 4,5 };
    IntList li(5, v), l2(li), l3 = li, l4;
    l4.concat(l2,l3);
    l2.display();
    l3.display();
    l4.display();
    l2.display();
    l3.display();
    cout << li.access_val(1) << endl;
    l2.set_i_val(5, 7);
    l2.display();
    cout << l2.find_val(3);
    return 0;
}
