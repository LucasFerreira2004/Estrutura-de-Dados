// Remoção por substituição à esquerda
#include <iostream>
#include <stack>
using namespace std;

struct node{
    int key;
    node *left, *right;
    node(int x){
        key = x;
    }
};

class tree{
    node *pt_raiz;

    public:
    tree(){
        pt_raiz = nullptr;

    }

    void insert(int x) {
        if (pt_raiz == nullptr) {
            pt_raiz = new node(x);
            return;
        }
        node* r = nullptr; // retaguarda
        node* s = pt_raiz; // avanço

        while (s != nullptr) {
            if (s->key == x)
                return;
            r = s;
            if (x > s->key)
                s = s->right;
            else
                s = s->left;
        }

        if (x > r->key)
            r->right = new node(x);
        else
            r->left = new node(x);
    }

    bool remove(int x){ //por substituição usando a subárvore a esquerda
        if (pt_raiz == nullptr){
            return false;
        }
        //busca do nó a ser removido
        node *p = nullptr;
        node* q = pt_raiz;
        while(q != nullptr){
            if (q->key == x){
                break;
            }
            if (x < q->key ){
                p = q;
                q = q->left;
            }else if (x > q->key){
                p = q;
                q = q->right;
            }
            if(p->key == x){

            }
        }
        
        if (pt_raiz->left == nullptr){ // temos um caso de linha
            node *backup = pt_raiz;
            pt_raiz = pt_raiz->right;
            delete backup;
            return true;
        }else{
            node* r = nullptr; //retaguarda
            node* s = pt_raiz; //avanço

            while (s != nullptr){
                r = s;
                s = s->right;
            }

        }
    
    }
};

int main(){
    tree t;
    t.insert(10);
    t.insert(2);
    t.insert(25);
    t.insert(1000);

    return 0;
}