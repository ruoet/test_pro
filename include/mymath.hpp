#ifndef _MY_MATH_H
#define _MY_MATH_H
#include <string>
using namespace std;
int Euclid(int v1, int v2); //欧几里得求最大公约数 

class Fraction
{ 
public:
    Fraction(int numer=0, int denomi=1);
    ~Fraction();
    std::string get();
    void show();

    //friend ostream& operator<<(ostream& os, const Fraction& val);
    //friend istream& operator>>(istream& os, const Fraction& val);

    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const Fraction& b);
    void simplify();//欧几里得算法找到最大公约数
private:
    int numerator; // 分子
    int denominator; // 分母
};
#endif