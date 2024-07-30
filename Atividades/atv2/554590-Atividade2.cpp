#define atividade "2"  
#define nome "Lucas Ferreira Nobre" 
#define matricula "554590"

#include <cmath>
/*
Seja uma classe que representa um ponto no plano dada por,.  
*/

class ponto {
    float x; // abcissa
    float y; // ordenada

public:
    ponto(int _x, int _y) // constrói ponto
    {
        x = _x;
        y = _y;
    };
    ponto()
    {
        x = 0, y = 0;
    };

    float dist(const ponto &p)
    {
        // determina a distância do ponto
        // à este passaso como argumeto.
        float disX = (x - p.x);
        float disY = (y - p.y);
        return std::sqrt(disX * disX + disY * disY);
    }
    float &X()
    {
        // retorna referência
        // da abcissa
        return x;
    }
    float &Y()
    { // está faltando a referência na original
        // Retorna referência para
        // a ordenada
        return y;
    }         

};

/* Implemente as funções a seguir usando a classe anterior */

float reta(ponto& p, ponto& q) {
    if (p.X() == q.X())
        throw ("Erro: os pontos tem o mesmo x");
        
    return (p.Y() - q.Y()) / (p.X() - q.X());
}

float minDist(const ponto& p, ponto kust[], int n) {
    if (n == 1){
        return kust[0].dist(p);
    }
    float distancia = kust[0].dist(p);
    if (distancia > minDist(p, kust + 1, n - 1))
        return minDist(p, kust + 1, n - 1);
    else 
        return distancia;
}

