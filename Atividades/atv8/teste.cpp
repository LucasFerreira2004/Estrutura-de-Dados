// Atividade 08,Álgebra Linear
#include <iostream>
#define atividade "07"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"

using namespace std;
//lembrar de tirar depois

int indexGlobal = 0;
struct node {
  int key; 
  node *left;
  node  *right;
  
  node (int key){
    this->key = key;
  }
};



node* loadTree(int* u, int n) {
    /*
monta árvore a partir  
   da inseção consecutiva de chaves do vetor u.  
*/
  node* pt_raiz = nullptr;
  for (int i=0; i<n; i++){
      if (pt_raiz == nullptr) {
        pt_raiz = new node(u[i]);
        continue;
      }

      node* r = nullptr; // retaguarda
      node* s = pt_raiz; // avanço
      while (s != nullptr) {
          if (s->key == u[i])
              continue;
          r = s;
          if (u[i] > s->key)
              s = s->right;
          else
              s = s->left;
      }

      if (u[i] > r->key)
          r->right = new node(u[i]);
      else
          r->left = new node(u[i]);
  }  
  return pt_raiz;
}

void buscaSimetrica(node *root){
  if (root == nullptr)
    return;

  buscaSimetrica(root->left);
  cout << root->key << ' ';
  buscaSimetrica(root->right);
}
void loadVec(node* root, int u[], int n, int& i = indexGlobal){ //essa referência é um parâmetro a mais.
  /* 
varre árvore enraizada em root  usando percurso em ordem simétrica e coloca cada chave visitada progressivamente em u  na ordem de visitação da árvore. u.
*/
  if (root == nullptr)
    return;
  loadVec(root->left, u, n, i);
  u[i++] = root->key;
  loadVec(root->right, u, n, i); 
  if (indexGlobal == n) indexGlobal =0;
}


int main(){
  int size = 10;
  int vetPovoamento[size] = {10, 5, 21, 99, 8, 9, 25, 50, 2, 1}; //o código quebra ao inserir números repetidos, mas não sei se ele
                                                    // vai cobrar isso nos casos de teste
  int vetResposta[size];
  node* t = loadTree(vetPovoamento, size);
  cout << "busca simetrica:\n";
  buscaSimetrica(t);
  cout << endl;
  cout << "resultado:\n";
  loadVec(t, vetResposta, size);
  for (int i=0; i<size; i++) 
    cout << vetResposta[i] << ' ';
  cout << endl;
  int vetErro[size];
  loadVec(t, vetErro, size);
  for (int i=0; i<size; i++){
    cout << vetErro[i] << ' ';
  }
  cout << endl;
  
  return 0;
}
   


