#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class frac{
int num, den;
    static int mdc(int a, int b){
	    return b!=0 ? mdc(b, a%b) : a;
    }

public:
    frac(int numerador, int denominador){
        int m = mdc(numerador, denominador);
        num = numerador/m;
        den = denominador/m;
    }
    frac& operator + (const frac& b){ //b é a fração de entrada
        return frac(num*b.den + b.num*den, den*b.den); //os * são de multiplicação, não de ponteiro kkkk
    }

    string toStr(){
        stringstream stream;
        stream << num << "/" << den;
        return stream.str();
    }
};

int main(){
    frac f(16, 24);
    cout << f.toStr() <<endl;
    return 0;
}