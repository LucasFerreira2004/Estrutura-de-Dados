#define atividade "07"
#define nome "meu nome"
#define matricula "123456"

/*
Seja um BIGnUMBER um inteiro positivo ou zero representado por uma lista encadeada. Cada dígito ocupa um nó da estrutura. A significância dos algarismos é de menor para maior a partir da raiz. Por exemplo, o número 1234 é armazenado pela lista:

|-> 4 -> 3 -> 2 -> 1  

Onde |-> representa o ponteiro da raiz e -> outras conexões entre nós. Implemente bigNumber no modelo de classe a seguir,
*/

class bigNumber {

    struct nodo {
        int digit;
        nodo* next;
    };
    nodo *pt;

public:
    bigNumber(int x) { /* cria um novo bigNumber distribuindo os dígitos de x na lista encadeada. */ }
    bigNumber() { /* inicia um bigNumber com valor zero */ }

    void operator+=(int x) { /* soma x a um bigNumber */ }
    void operator*=(int x) { /* multiplica x a um bigNumber */ }

    void operator+=(bigNumber& bn) { /* soma bigNumber a outro */ }
    void operator*=(bigNumber& bn) { /* multiplica bigNumber a outro */ }
    bool operator==(bigNumber& bn) { /* compara bigNumbers */ }
};
