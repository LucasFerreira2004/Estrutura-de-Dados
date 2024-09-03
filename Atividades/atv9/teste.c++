#include <iostream>
using namespace std;
// Atividade 08,Álgebra Linear


#define atividade "9"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"



struct node {
  int key;
  int ball;
  node *left;
  node  *right;
  node(int x) : key(x), ball(0), left(nullptr), right(nullptr) {}
};

node* loadTree(int* u, int n) {
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

void loadVec(node* root, int u[], int n){
  static int i = 0;
  if (root == nullptr)
    return;
  loadVec(root->left, u, n);
  u[i++] = root->key;
  loadVec(root->right, u, n); 
  if (i == n) i =0; 

}

int height(node* root){
  /*
  determina a altura de uma arvore enraizada em root.
  a altura de uma arvore é a distancia em nodos da raiz ate a nodo de maior descendencia. 
  a arvore vazia tem altura 0 e arvores com um nodo tem altura 1.
  */
  if (root == nullptr)
    return 0;
  if (height(root->left) >= height(root->right)){
    return 1 + height(root->left);
  }else{
    return 1 + height(root->right);
  }
 }
  
  void calc_balls(node* root){
    /*
    determina o fator de balanciamento da raiz root.
    o fator de balanciamento ball de um nodo é a diferença 
    entre as alturas de suas subarvores direita e esquerda
    preencha todos os campos de todos os nodos da arvore em raizada em root
    */ 
    if (root == nullptr) 
      return;
    root->ball = height(root->right) - height(root->left);
    calc_balls(root->right);
    calc_balls(root->left);
  }


  //essa função eu criei só pra printar e tem que tirar depois:
void print_balls(node* p){
  if (p == nullptr) return;
  print_balls(p->left);
  cout << p->key << ":" << p->ball << ' ';
  print_balls(p->right);
}

int main(){
  int size = 7;
  int vetPovoamento[size] = {10, 5, 4, 11, 12, 7, 6};
  int vetResposta[size];
  node* t = loadTree(vetPovoamento, size);
  loadVec(t, vetResposta, size);
  cout << "vetor resultado\n";
  for (int i=0; i<size; i++) 
    cout << vetResposta[i] << ' ';
  cout << endl;

  cout << "altura: \n";
  cout << height(t) << endl;

  cout << "balanceamento: \n";
  calc_balls(t);
  print_balls(t);
  cout << '\n';
  return 0;
}
  