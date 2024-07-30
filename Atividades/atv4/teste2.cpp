#include <iostream> //tirar depois.
#define atividade "4"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"

using namespace std;
// 1
class vetor {
   int *u;  // ponteiro para vetor
   int size; // tamanho do vetor
public:
   vetor(int n) { u=new int[n]; size=n; }
   ~vetor() { delete [] u; }
   int& operator[] (int k) { return u[k]; } //faz mais sentido.
   int len() { return size; }
};
void merge (vetor& leftArray, vetor& rightArray, vetor& array, int& i) {  
    int l = 0, r = 0;
    while (l < leftArray.len() && r < rightArray.len()) {
        if (leftArray[l] < rightArray[r]) {
            array[i++] = leftArray[l++];
        } else {
            array[i++] = rightArray[r++];
        }
    }

    while (l < leftArray.len()) {   
        array[i++] = leftArray[l++];
    }
    while (r < rightArray.len()) {
        array[i++] = rightArray[r++];
    }
    cout << "final i: " << i << endl;
}

vetor mergeAll(vetor U[], int n) {
    int totalsize = 0;
    for (int i = 0; i < n; i++) {
        totalsize += U[i].len();
    }

    vetor u(totalsize);
    int index = 0;
    for (int i = 0; i < n - 1; i++) {
        merge(U[i], U[i + 1], u, index);  // No need to update index here
    }

    return u;
}
int main(){
vetor U[3] = {
    vetor(3),
    vetor(3),
    vetor(3)
  };

  U[0][0] = 6;
  U[0][1] = 8;
  U[0][2] = 5;

  U[1][0] = 1;
  U[1][1] = 2;
  U[1][2] = 3;

  U[2][0] = 4;
  U[2][1] = 0;
  U[2][2] = 9;

  vetor vet = mergeAll(U, 3);

   for (int i=0;i<vet.len();i++)
      cout << vet[i] << " ";
   cout << '\n';

  
   return 0;
}

/*
Exemplo

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [3,2], [4,0,9] } => {1}
{ [6,8,5], [3], [4,0,9] } => {1,2}
{ [6,8,5], [], [4,0,9] } => {1,2,3}
{ [6,8], [], [4,0,9] } => {1,2,3,5}
{ [6], [], [4,0,9] } => {1,2,3,5,8}
{ [], [], [4,0,9] } => {1,2,3,5,8,6}
{ [], [], [] } => {1,2,3,5,8,6,9,0,4}

*/
