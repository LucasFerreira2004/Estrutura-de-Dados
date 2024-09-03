#include <iostream>
#include <stack>
#include <string>
#include <queue>
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
    void red(node *p){
        if (p == nullptr)
            return;
        cout << p->key << ' ';
        red(p->left);
        red(p->right);
    }
    void erd(node *p){
        if (p == nullptr)
            return;
        erd(p->left);
        cout << p->key << ' ';
        erd(p->right);
    }
    void edr(node *p){
        if (p == nullptr)
            return;
        edr(p->left);
        edr(p->right);
        cout << p->key << ' ';
    }
    void clear(node *p){ //acabamos usando o edr
        if (p == nullptr)
            return;
        clear(p->left);
        clear(p->right);
        delete p;
    }
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

    void insertVet(int vet[], int n){
        for (int i=0; i<n; i++)
            insert(vet[i]);
    }

    void lf(){ //atravessamento em nível, ele vai imprimindo os nodos no mesmo nível
               //equivalente ao bfs.
        queue<node*> fila;
        if (pt_raiz != nullptr)
            fila.push(pt_raiz);
        while(!fila.empty()){
            node *p = fila.front();
            cout << p->key << ' ';
            fila.pop();
            if (p->left != nullptr)
                fila.push(p->left);
            if (p->right != nullptr)
                fila.push(p->right);
        }
    }
    void path(string s){
        if (s == "red") red(pt_raiz);
        else if (s == "erd") erd(pt_raiz);
        else if (s == "edr") edr(pt_raiz); 
        else if (s == "lf"){

        }
    }

    bool remove(int x) {
        if (pt_raiz == nullptr){
            return false;
        }
        node *p = nullptr;
        node *q = pt_raiz;
        while (q != nullptr){
            if(x == q->key)
                break;
            p = q;
            if (x > q->key){
                q = q->right;
            }else{
                q = q->left;
            }
        }
        cout << "teste";
        //ao final do laço p = pai do que vamos remover, q = o que vamos remover;
        if (q == nullptr) 
            return false;
        if (q->right == nullptr && q->left == nullptr){ //se q é folha, mas é um teste reduntate os dois ifs já foram.
            delete q;
        }
        if (q->left == nullptr || q->right == nullptr){
            if (p->right == q){
                if (q->right == nullptr){
                    p->right = q->left;
                    delete q;
                }
                else if(q->left == nullptr){
                    p->right = q->right;
                    delete q;
                }
            }
            else if(p->left == q){
                if (q->right == nullptr){
                    p->left = q->left;
                    delete q;
                }
                else if(q->left == nullptr){
                    p->left = q->right;
                    delete q;
                }
            }
        }
        return true;
    }
    ~tree(){
        clear(pt_raiz);
    }
};

int main(){
    int vet[] = {20};
    tree t;
    t.insertVet(vet, 1);

    t.path("red");
    cout << '\n';
    t.path("erd");
    cout << '\n';
    t.path("edr");
    cout << '\n';

    cout << "lf: \n";
    t.lf();
    cout << "\n";
    t.remove(20);
    t.path("red");
    cout << endl;
    return 0;
}