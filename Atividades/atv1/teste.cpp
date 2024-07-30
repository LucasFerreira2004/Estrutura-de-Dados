//  NÃO ENVIAR ESSE ARQUIVO !!!!!!!!!!!
// !!!!!!!
#include <iostream>
using namespace std;

// 1
// calcula o mdc de dois inteiros dados.   
int mdc(int a, int b  ) {
    if (b == 0) 
        return a;
    return (mdc (b, a % b));
}

// 2
// Carregar no vetor M de tamanho
// n os n primeiros primos.começando em 2
// Note que o argumento de entrada M é saída neste problema. 

// bool isPrime(int n){
//     if (n < 2) return false;
//     if (n == 2) return true;
//     for (int i = 2; i < n; i++)
//         if (n % i == 0) return false;

//     return true;
// }

bool isPrime(int n, int divisor = 2){
    if (n < 2) return false;
    if (n == 2) return true;

    if (n % divisor == 0) return false;
    
    if (divisor * divisor < n){
        if(isPrime(n, ++divisor)) return true;
        else return false;
    }
    return true;
}

void loadPrimeVec(int M[], int n, int p = 2){
    if (n < 1) return;
    if(isPrime(p)){
        *M = p;
        loadPrimeVec(M+1, n - 1, ++p);
    }
    else{
        loadPrimeVec(M, n, ++p);
    }

}
// void loadPrimeVec(int M[], int n, int)  {
//     int p = 0;
//     for (int i=0; i<n; i++){
//         while(true){
//             if (isPrime(p)){
//                 M[i] = p;
//                 p++;
//                 break;
//             }
//             p++;
//         }
//     }
// }

int main(){
    // int a, b;
    // cin >> a >> b;
    // cout << mdc(a, b) << endl;
    int n;
    cin >> n;   
    int M[n];
    loadPrimeVec(M, n);
    for(int i=0; i<n; i++)
        cout << M[i] << " ";
    cout << endl;
    return 0;
}