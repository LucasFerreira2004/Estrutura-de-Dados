// Atividade 08,Álgebra Linear


#define atividade "8"
#define nome "Gary"
#define matricula "***123123"



struct node {
  int key;
  int ball;
  node *left;
  node  *right;
  node(int x) : key(x), ball(0), left(nullptr), right(nullptr) {}
};



node* loadTree(int* u, int n) {
    /*
monta árvore a partir  
   da inseção consecutiva de chaves do vetor u.  
*/
  return 0
;
}

void loadVec(node* root, int u[], int n){

  /* 
varre árvore enraizada em root  usando percurso em ordem simétrica e coloca cada chave visitada progressivamente em u  na ordem de visitação da árvore. u.
*/

    return;
}

int height(node* root){
  /*
  determina a altura de uma arvore em raizada em root.
  a altura de uma arvore é a distancia em nodos da raiz ate a nodo de maior desendencia. 
  a arvore vazia tem altura 0 e arvores com um nodo tem altura 1.
  */
  return 0;
 }
  
  void calc_balls(node* root){
  /*
  determina o fator de balanciamento da raiz root.
  o fator de balanciamento ball de um nodo é a diferença 
  entre as alturas de suas subarvores direita e esquerda
  preencha todos os campos de todos os nodos da arvore em raizada em root
  */ 
  }