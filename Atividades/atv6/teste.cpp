#include <iostream> //remover depois
#include <cstdlib>
#include <ctime>

#include <queue>

using namespace std;

#define atividade "06"
#define nome "meu nome"
#define matricula "123456"



void alternativeRadixsort(int u[], int n,int d) {
  queue<int> buckets[2];
  int m = 1; //serve para pegar o digito que temos interesse. Vamos usar %
  int copy[n];

  for (int i=0; i<d; i++){
      for (int i=0; i<n; i++)
        copy[i] = u[i];
      int cont=0;

      for (int i=0; i<9; i+=2){
        for (int k=0; k < n; k++){ //povoando os buckets
          int dig = (copy[k] % (10*m)) / m;
          if (dig == i)
            buckets[0].push(copy[k]);
          if (dig == i + 1)
            buckets[1].push(copy[k]);
        }

        for (int j=0; j<2; j++){ //esvaziando os buckets
          while(!buckets[j].empty()){
              u[cont++] = buckets[j].front();
              buckets[j].pop();
          }
        }
      }  
      m *=10;
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


