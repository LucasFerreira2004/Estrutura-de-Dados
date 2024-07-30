#include <iostream>
using namespace std;
int merge(int u[], int p, int r, int q){ //p até r e outro é r + 1 até q, supomos que ambos são ordenados. 
    int m = r-p+1; //tamanho do primeiro vetor.
    int n = q-r; //tamanho do segundo vetor. é q-r pois começa da posição r+1.

    int A[m], B[n]; //backups. 
    for (int i=0; i < m; i++) A[i] = u[i+p]; //pois começa em p;
    for (int i=0; i < n; i++) B[i] = u[i+r+1];

    int i = 0, j = 0; //ponteiros para o topo das pilhas
    int k = p;
    while (i < m && j < n){
        if (A[i] < B[j])
            u[k++] = A[i++];
        else
            u[k++] = B[j++];
    }

    if (i == m) //se o primeiro foi preenchido
        for (j; j < n; j++) u[k++] = B[j];
    else
        for (i; i < m; i++) u[k++] = A[i];

    return 0;
}

void mergesort_(int u[], int p, int q){

}

void mergesort(int u, int n){

}
int main(){
    int n = 8;
    int u[8] = {2,5,11,19, 1, 2,7,8};
    merge(u, 0, 3, 7);
    for (int i = 0; i < n; i++) cout << u[i] << " ";
    cout << endl;

    return 0; 
}