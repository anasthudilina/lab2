#include <iostream>
#include <cmath>
#include "triangle.h"

using namespace std;  


double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
} //відстань між двома точками 

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
} //площа за героном

double Triangle::area() const {
    return heronArea(*this);
}

bool Triangle::onborder(const Point &P) const {
    if ((P.x == A.x && P.y == A.y) || 
        (P.x == B.x && P.y == B.y) || 
        (P.x == C.x && P.y == C.y)) {
        return true;
    } //перевірка чи з вершиною співпадає

    auto onSegment = [](const Point &a, const Point &b, const Point &p) {
        double area = 0.5 * fabs((b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x));
        return area < 1e-9 && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
                            min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    };

    return onSegment(A, B, P) || onSegment(B, C, P) || onSegment(C, A, P);
}//перевірка, чи точка лежить на відрізку між двома точками 

bool Triangle::heron(const Point &P) const {
    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();
    
    return fabs(S_main - S_sum) < 1e-9;
}//перевірка, чи точка P належить трикутнику за героном

bool Triangle::vector(const Point &P) const {
    auto cross = [](const Point &a, const Point &b, const Point &c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    };

    double d1 = cross(A, B, P);
    double d2 = cross(B, C, P);
    double d3 = cross(C, A, P);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0); //перевірка, чи векторні добутки мають однакові знаки
    
    return !(has_neg && has_pos); //якщо векторні добутки мають різні знаки, точка знаходиться поза трикутником
}

bool Triangle::contains(const Point &P, int method) const {
    if (method == 1) {
        return heron(P);
    } else {
        return vector(P);
    }
}


bool Triangle::vyrodzhenyi() const {
    return (B.x - A.x) * (C.y - A.y) == (C.x - A.x) * (B.y - A.y); 
}

    