//  NÃO ENVIAR ESSE ARQUIVO !!!!!!!!!!!
// !!!!!!!
#include <iostream>
#include <cmath>
#define atividade "2"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"

using namespace std;
/*
Seja uma classe que representa um ponto no plano dada por,.
*/

class ponto
{
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

float reta(ponto &p, ponto &q)
{
    // retorna coeficiente angular da reta
    // que passa por p e q
    if (p.X() == q.X())
        throw std::runtime_error("Erro: os pontos tem o mesmo x");
        
    return (p.Y() - q.Y()) / (p.X() - q.X());
}

float minDist(const ponto& p, ponto kust[], int n) //tem que tirar a const pra essa porra funcionar
{
    // retorna a menor distância entre p e os // pontos da lista list dada de
    // comprimento n.
    if (n == 1){
        return kust[0].dist(p);
    }
    float distancia = kust[0].dist(p);
    if (distancia > minDist(p, kust + 1, n - 1))
        return minDist(p, kust + 1, n - 1);
    else 
        return distancia;
}

int main()
{
    ponto p_a(100,100);
    ponto points[4];
    int n = 4;
    while (n--){
        ponto p;
        cout << "p : ";
        cin >> p.X() >> p.Y();
        points[n] = p;
        cout << "coeficiente angular: " << reta(p_a, p) << endl;
    }
    
    cout << minDist(p_a, points, 4) << "\n";
    
    
    return 0;
}
