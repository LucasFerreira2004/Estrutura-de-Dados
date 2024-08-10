//eu mesmo adicionei
#include <string>


#define atividade "07"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"

using namespace std; // também adicionei

/*
Seja um BIGnUMBER um inteiro positivo ou zero representado por uma lista encadeada. Cada dígito ocupa um nó da estrutura. 
A significância dos algarismos é de menor para maior a partir da raiz. Por exemplo, o número 1234 é armazenado pela lista:
|-> 4 -> 3 -> 2 -> 1  

Onde |-> representa o ponteiro da raiz e -> outras conexões entre nós. Implemente bigNumber no modelo de classe a seguir,
*/
class bigNumber {
    struct nodo {
        int digit;
        nodo* next;
    };
    nodo *ptCabeca = new nodo;

    int numDigitos(int x){
        string numString = to_string(x);
        return numString.size();
    }

    void changeValue(int x){
        //deletando a lista antiga
        int qtdBigNumberDig = numDigitos(bigNumberToInt());
        nodo *c = ptCabeca;
        while (qtdBigNumberDig--){
            nodo *atual = c->next;
            c->next = c->next->next;
            delete atual;
        }
        int qtdDig = numDigitos(x);
        int m = 1; //serve para pegar o dig de interesse;
        while (qtdDig--){
            int dig = (x % (10*m)) / m;
            nodo *p = ptCabeca;
            while (p->next != nullptr){
                p = p->next;
            }
            p->next = new nodo();
            p->next->digit = dig;
            m*=10;
        }
    }

    int bigNumberToInt(){
        int x = 0;
        nodo *p = ptCabeca;
        int m = 1;  
        while(p->next != nullptr){
            x += p->next->digit * m;
            p = p->next;
            m*=10;
        }
        return x;
    }
    
public:
    bigNumber(int x) {
        int qtdDig = numDigitos(x);
        int m = 1; //serve para pegar o dig de interesse;
        while (qtdDig--){
            int dig = (x % (10*m)) / m;
            nodo *p = ptCabeca;
            while (p->next != nullptr){
                p = p->next;
            }
            p->next = new nodo();
            p->next->digit = dig;
            m*=10;
        }
    }
    bigNumber() {
        nodo *p = new nodo();
        p->digit = 0;
        ptCabeca->next = p;
    }

    void operator+=(int x) { 
        int bn = bigNumberToInt();
        changeValue(bn + x);
    }
    void operator*=(int x) { 
        int bn = bigNumberToInt();
        changeValue(bn * x);
    }

    void operator+=(bigNumber& bn) { 
        int bn1 = bigNumberToInt();
        int bn2 = bn.bigNumberToInt();
        changeValue(bn1+bn2);
    }
    void operator*=(bigNumber& bn) { 
        int bn1 = bigNumberToInt();
        int bn2 = bn.bigNumberToInt();
        changeValue(bn1*bn2);
    }
    bool operator==(bigNumber& bn) { 
        int bn1 = bigNumberToInt();
        int bn2 = bn.bigNumberToInt();
        return bn1 == bn2;
    };
};
