#include "mymath.hpp"


int main()
{
    Fraction a;
    a.show();
    Fraction b(1,2);
    b.show();
    Fraction c(2,5);
    c.show();
    a = b + c;
    a.show();
    a = b-c;
    a.show();
    a = b*c;
    a.show();
    a = b/c;
    a.show();
    return 0;
}