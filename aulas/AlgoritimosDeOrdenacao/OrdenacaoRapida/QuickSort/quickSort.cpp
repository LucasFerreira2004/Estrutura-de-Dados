#include <iostream>

//esse algoritimo só particiona, ainda não ordenada. 
int part(int u[], int p, int q){ //p e q representam os valores dos índices do primeiro e do último ele. do vetor
    int i = p+1; //seta de cima, a frente do pivô
    int j = p; //seta de baixo
    for (i; i<=q; i++){
        if (u[i] < u[p]){ //u[p] e o pivo
            int x = u[i];
            u[i] = u[j];
            u[j] = x;
            j++;
        }
    }
    int x = u[p];
    u[p] = u[j];
    u[j] =x;
    return j; //retorna o indice pra onde foi o pivô. 
}

void quicksort_(int u[],int p, int q){ //esse irá ordenar um subvetor, entre p e q. 
    if (p >= q) return; //irá executar quando o tamanho do vetor for 1 (==) ou 0 (>)

    int r = part(u, p, q);
    quicksort_(u, p, r-1);
    quicksort_(u, p, r+1);
}

void quicksort(int u[], int n){
    quicksort_(u, 0, n-1);
}

int main(){
    int n = 8;
    int u[8] = {12, 6, 5, 23, 15, 11, 24, 2};
    quicksort(u, n);
    for (int i=0; i<n; i++)
        std::cout << u[i] <<'\n';
    return 0;
}