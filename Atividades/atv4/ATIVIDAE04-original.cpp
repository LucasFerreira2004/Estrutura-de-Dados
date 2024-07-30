#define atividade "04"
#define nome "Garibaldi"
#define matricula "***123"

// 1

class vetor {  
   int *u;  // ponteiro para vetoe
   int size; // tamanho do vetor
public:
   vetor(int n) { u=new int[n]; size=n; }
   ~vetor() { delete [] u; }
   int& operator[] (int k) { return size; } 
   int len() { return size; }

};

vetor mergeAll(vetor U[], int n) {
    /*
    Esta função funde os n vetores na entrada U 
    num vetor de saída . Note que se os vetores 
    em U são ordenados então o vetor de saída 
    também o será. Porém mantenha em mente 
    que as entradas em U NÃO são necessariamente 
    ordenadas nos casos de testes.     
    */
    return vetor(1); 
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
