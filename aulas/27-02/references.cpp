#include <iostream>
using namespace std;

void swap (int &x, int &y){
    int t = y;
    y = x;
    x = t;
}

int main(){
    int x = 10;
    int &r = x;

    cout << x << " " << r << endl;

    int a = 2, b = 3;

    swap(a, b);
    cout << a << " " << b << endl; 

    return 0;
}