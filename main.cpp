#include <iostream>
#include "triangle.cpp"

int main() {
    Triangle t;
    Point points[100];
    int n;


    cout << "Vvedit koordinaty trykutnyka (x y) dlya tochok A, B, C:\n";
    cin >> t.A.x >> t.A.y >> t.B.x >> t.B.y >> t.C.x >> t.C.y;

    if (cin.fail()) {
        cout << "Pomylka\n";
        return 1; 
    }

    if (t.vyrodzhenyi()) {
        cout << "Trykutnyk vyrodzhenyi (tochky lezhat na odnij pryamij).\n";
    } else {
        cout << "Trykutnyk ne vyrodzhenyi\n";
    }

    cout << "Vvedit kilkist tochok dlya perevirky:\n";
    cin >> n;


    cout << "Vvedit koordinaty " << n << " tochok:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Tochka " << (i + 1) << ": ";
        cin >> points[i].x >> points[i].y;
    }
    

    int method;
    cout << "Vyberit metod perevirky (1 - Heron, 2 - Vector): ";
    cin >> method;


    for (int i = 0; i < n; ++i) {
        cout << "Tochka " << (i + 1) << ": ";
        if (t.onborder(points[i])) {
            cout << "lezhyt na mezhi trykutnyka.\n"; 

        } else if (t.contains(points[i], method)) {
            cout << "nalezhyt trykutnyku.\n";
        } else {
            cout << "ne nalezhyt trykutnyku.\n";
        }
    }

    return 0;
}