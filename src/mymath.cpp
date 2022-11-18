#include <iostream>
#include "mymath.hpp"
using namespace std;
/*
class Integer
{
public:
    Integer()
    {

    }
    ~Integer()
    {

    }
    void show()
    {

    }

    ostream& operator<<(ostream& os, )
    {

    }
    istream& operator>>(istream& os, )
    {

    }
private:
    int val;
};
*/
int Euclid(int v1, int v2) //欧几里得求最大公约数 
{
    int r = 0;
    while(v2)
    {
        r = v1%v2;
        v1 = v2;
        v2 = r;
    }
    return v1;
}


//Fraction::Fraction(int numer=0, int denomi=1)
Fraction::Fraction(int numer, int denomi)
: numerator(numer), denominator(denomi)
{
    if(!denominator)
    {
        std:cerr<< "denominator can not be zero!"<< std::endl;
    }
}
Fraction::~Fraction(){}
string Fraction::get()
{
    return std::to_string(numerator)+"/" + std::to_string(denominator);
}
void Fraction::show()
{
    if(denominator)
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
    else
    {
        std::cout << "denominator can not be 0!" << std::endl;
    }
}
/*
ostream& Fraction::operator<<(ostream& os, const Fraction& val)
{
    return os;
}
istream& Fraction::operator>>(istream& os, const Fraction& val)
{
    
    return os;
}*/

Fraction operator+(const Fraction& a, const Fraction& b)
{
    Fraction res;
    int r = Euclid(a.denominator, b.denominator);
    res.numerator = a.numerator*(b.denominator/r) + b.numerator*(a.denominator/r);
    res.denominator = (a.denominator * b.denominator)/r;
    res.simplify();
    return res;
}
Fraction operator-(const Fraction& a, const Fraction& b)
{
    Fraction res;
    int r = Euclid(a.denominator, b.denominator);
    res.numerator = a.numerator*(b.denominator/r) - b.numerator*(a.denominator/r);
    res.denominator = (a.denominator * b.denominator)/r;
    res.simplify();
    return res;
}
Fraction operator*(const Fraction& a, const Fraction& b)
{
    Fraction res;
    res.numerator = a.numerator * b.numerator;
    res.denominator = a.denominator * b.denominator;
    res.simplify();
    return res;
}
Fraction operator/(const Fraction& a, const Fraction& b)
{
    Fraction res;
    res.numerator = a.numerator * b.denominator;
    res.denominator = a.denominator * b.numerator;
    res.simplify();
    return res;
}
void Fraction::simplify()//欧几里得算法找到最大公约数
{
    int s = 1; // 符号位
    if(numerator < 0)
    {
        s = -s;
        numerator = -numerator;
    }
    if(denominator < 0)
    {
        s = -s;
        denominator = -denominator;
    }
    int r = Euclid(numerator, denominator);
    numerator = s*numerator/r;
    denominator = denominator/r;
}
