#define atividade "1"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"

//AS FUNÇÕES A SEGUIR DEVEM SER 
// IMPLEMENTADAS USANDO RECURSIVIDADE.
// FUNÇÕES AUXILIATES PODEM SER 
// USADAS DESDE QUE SEJAM TAMBÉM RECURSIVAS.

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
bool isPrime(int n, int divisor = 2) {
    if (n < 2) return false;
    if (n == 2) return true;

    if (n % divisor == 0) return false;
    
    if (divisor * divisor < n){
        if(isPrime(n, ++divisor)) return true;
        else return false;
    }
    return true;
}

void loadPrimeVec(int M[], int n, int p = 2)  {
   if (n < 1) return;
    if(isPrime(p)){
        *M = p;
        loadPrimeVec(M+1, n - 1, ++p);
    }
    else{
        loadPrimeVec(M, n, ++p);
    }
}


