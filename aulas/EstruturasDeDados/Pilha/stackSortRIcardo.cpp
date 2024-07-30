#include <iostream>
#include <stack>
using namespace std;

void load(stack<int> &a, stack<int> &b){ 
    while (!b.empty()){
        a.push(b.top());
        b.pop();
    }
}

void stackSort(int vet[], int size){
    stack<int> p1, p2;
    for (int i=0; i < size; i++){
        if (p1.empty() || vet[i] < p1.top()){
            p1.push(vet[i]);
        }else{ 
            while (!p1.empty() && vet[i] > p1.top()){
                p2.push(p1.top());
                p1.pop();
            }
            p1.push(vet[i]);
            load(p1, p2);
        }
    }

    for (int i=0; i<size; i++){
        vet[i] = p1.top();
        p1.pop();
    }
}

int main(){
    int n = 10;
    int vet[n] = {7, 11, 2, 20, 1, -1, 100, 0, 9, 10};
    stackSort(vet, n);
    for (int i : vet) 
        cout << i << ' ';
    cout << endl;
    return 0;
}