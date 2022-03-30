#include <iostream>

#include "SLL/SLL.h"
#include "SLL/SLL.cpp"

using namespace std;

class fraction{
public:
    int num,den;
    fraction();
    fraction(int n, int d);
    fraction(const fraction &f);
};
fraction::fraction() {
    num = 0;
    den = 1;
}
fraction::fraction(int n, int d) {
    num = n;
    den = d;
}
fraction::fraction(const fraction &f) {
    num = f.num;
    den = f.den;
}
ostream &operator<<(std::ostream &ost, fraction f) {
    ost << f.num << "/" << f.den;
    return ost;
}

int main() {
    SLL<fraction> list{};
    int level=0;
    fraction f1{0,1},f2{1,1};
    list.addToTail(f1);
    list.addToTail(f2);

    cout << "Enter the level of fractions: " << "\n";
    cin >> level;

    for(size_t i=2; i<=level; i++) {
        for(size_t j=0; j<list.size()-1; j++) {
            int denominator{};
            denominator = list[j].den + list[j+1].den;
            if(denominator <= i) {
                int numerator{};
                numerator = list[j].num + list[j+1].num;
                list.insertAfter(fraction{numerator,denominator},j);
            }
        }
    }

    list.print();



    return 0;
}