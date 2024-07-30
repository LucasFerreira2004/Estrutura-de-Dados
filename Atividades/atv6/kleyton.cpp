#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

#define atividade "06"
#define nome "Daniel Lucas Ulisses Magalhaes"
#define matricula "554563"

int digito(int num, int m) {
    int id = (num % (10 * m)) / m; //! obter o digito do numero correponde ao ordenamento atual 723 / 100 = 23 / 10 = 2
    return id;
}

void alternativeRadixsort(int u[], int n,int d) {
  queue<int> buckets[2];
  int m = 1;
  int last;
  /* implementar ordenação por raiz, utilizando apenas dois buckets 

int u[]:vetor de entrada
int n: comprimento de u
int d: numero maximo de digitos
observação: as entradas sao formadas por numeros inteiros positivos  

*/

for(int k = 0; k < d; k++) { //* rodar por todos os algarismos possíveis
        for(int i = 0; i < n; i++) { //* para cada elemento do vetor.
        int id = digito(u[i], m);
            if(i == 0) {
                buckets[0].push(u[i]);
                last = id;
            } else {
                if(id >= last) {
                    buckets[0].push(u[i]);
                    last = id;
                }else {
                    while(id >= digito(buckets[0].front(), m)) {
                        buckets[1].push(buckets[0].front());
                        buckets[0].pop();
                    }
                    buckets[1].push(u[i]);
                    while(!buckets[0].empty()) {
                        buckets[1].push(buckets[0].front());
                        buckets[0].pop();
                    }
                    while(!buckets[1].empty()) {
                        buckets[0].push(buckets[1].front());
                        buckets[1].pop();
                    }

                    last = digito(buckets[0].back(), m);
                }
            }
        }
        
        int cont = 0;
        while(!buckets[0].empty()) {
            int x = buckets[0].front();
            buckets[0].pop();
            u[cont++] = x;
        }
        m *= 10;
    }
  
}
int main(){
  int size = 1000000;
  int vet[size];
  unsigned seed = time(0);
  cout << "vet antes da ordenacao: \n";
  for (int i=0; i<size; i++){
    srand(seed+i);
    vet[i] = rand() % 100000;
    cout << vet[i] << " ";
  }
  cout << endl << "vetor ordenado: \n";
  alternativeRadixsort(vet, size, 5);
  for (int i=0; i<size; i++)
    cout << vet[i] << " ";
  cout << endl;

  return 0;
}
