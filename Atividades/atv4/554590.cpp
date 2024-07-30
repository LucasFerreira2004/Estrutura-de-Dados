#define atividade "04"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"

// 1
class vetor {
   int *u;  // ponteiro para vetoe
   int size; // tamanho do vetor
   int index;
   bool percorrido;
public:
   vetor(int n) { 
        u=new int[n]; 
        size=n; 
        index = 0;
        percorrido = false;
    }
   ~vetor() { delete [] u; }
   int& operator[] (int k) { return u[k]; } 
   void put(int k) {
        u[index++] = k;
        if (index == size) percorrido = true;
    }
   int len() { return size; }
   void percorrer(){
        index++;
        if (index == size) percorrido = true;
   }
   int getIndexAPercorrer (){
        return index;
   }
   bool getPercorrido (){
        return percorrido;
   }

};

vetor mergeAll(vetor U[], int n) {
    int total_size = 0;
    for (int i=0; i<n; i++) 
        total_size += U[i].len();
    vetor merged(total_size);
    
    int menor_index = 0;
    int menor_vetor = 0;
    while (true){
        int iteracoes = 0;
        for (int i=0; i<n; i++){
            if (U[i].getPercorrido()) continue;
            if (iteracoes == 0){
                menor_vetor = i;
                menor_index = U[i].getIndexAPercorrer();
                iteracoes++;
            }
            if (i == n-1) iteracoes = 0;
            int index = U[i].getIndexAPercorrer();
            if(U[i][index] < U[menor_vetor][menor_index]){
                menor_vetor = i;
                menor_index = index;
            }
        }
        merged.put(U[menor_vetor][menor_index]);
        U[menor_vetor].percorrer();
        if (merged.getPercorrido()) break;
    }

    return merged; 
}
/*
Exemplo 1

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [2,1], [4,0,9] } => {3}
{ [6,8,5], [1], [4,0,9] } => {3,2}
{ [6,8,5], [], [4,0,9] } => {3,2,1}
{ [6,8,5], [], [0,9] } => {3,2,1,4}
{ [6,8,5], [], [9] } => {3,2,1,4,0}
{ [8,5], [], [9] } => {3,2,1,4,0,6}
{ [5], [], [9] } => {3,2,1,4,0,6,8}
{ [], [], [9] } => {3,2,1,4,0,6,8,5}
{ [], [], [] } => {3,2,1,4,0,6,8,5,9}

Exemplo 2

U = { [1,3,5], [2,4,6], [7,8,9] }

{ [3,5], [2,4,6], [7,8,9] } => {1}
{ [3,5], [4,6], [7,8,9] } => {1,2}
{ [5], [4,6], [7,8,9] } => {1,2,3}
{ [5], [6], [7,8,9] } => {1,2,3,4}
{ [], [6], [7,8,9] } => {1,2,3,4,5}
{ [], [], [7,8,9] } => {1,2,3,4,5,6}
{ [], [], [8,9] } => {1,2,3,4,5,6,7}
{ [], [], [9] } => {1,2,3,4,5,6,7,8}
{ [], [], [] } => {1,2,3,4,5,6,7,8,9}

*/
