#include <iostream>
using namespace std;

void swap(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}

int idMax (int v[], int n){
    int j = 0;
    for (int k = 0; k < n; k++)
        if (v[k] > v[j]) j = k;
    return j;
}

int* min(int v[], int n){
    if (n < 1)
        throw "erro";

    if (n == 1)
        return v; 
    
    int* p = min(v + 1, n - 1);
    
    if (*v < *p)
        return v;
    else    
        return p;
}

void sortIdMax(int v[], int n){ //usando o idMax AAAAA
    if (n == 1)
        return;
    int i = idMax(v, n);
    swap(v[i], v[n - 1]);
    sortIdMax(v, n-1);
}

void sort(int* v, int n){
    if(n == 1)
        return;

    swap(*v, *min(v, n));
    sort (v + 1, n - 1);
}

int main(){
    int v[] = {1, 0, 3, 2, 4};

    sort(v, 5);
    for (int i = 0; i < 5; i++)
        cout << v[i] << " ";

    
    v[2] = 1, v[1] = 2;
    sortIdMax(v, 5);
    cout << "\ncom id max\n";
    for (int i = 0; i < 5; i++)
        cout << v[i] << " ";
    cout << endl;
    
    return 0;
}