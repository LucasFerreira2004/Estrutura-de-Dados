#define atividade "8"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"

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

void loadVec(node* root, int u[], int n, int& i = indexGlobal){ //essa referência é um parâmetro a mais.
  if (root == nullptr)
    return;
  loadVec(root->left, u, n, i);
  u[i++] = root->key;
  loadVec(root->right, u, n, i); 
  if (indexGlobal == n) indexGlobal =0;
}

