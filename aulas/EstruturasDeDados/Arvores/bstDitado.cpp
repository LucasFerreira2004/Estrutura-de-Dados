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
    // bool remove(int x) {
    //     if (pt_raiz == nullptr) {
    //         return false;
    //     }

    //     // busca do nó a ser removido
    //     node *p = nullptr;
    //     node *q = pt_raiz;

    //     while (q != nullptr) {
    //         if (q->key == x)
    //             break;
    //         if (x < q->key) {
    //             p = q;
    //             q = q->left;
    //         }
    //         else if (x > q->key) {
    //             p = q;
    //             q = q->right;
    //         }
    //     }

    //     if (q == nullptr) {
    //         return false;
    //     }
        
    //     node *r = p;
    //     node *s = q;

    //     while (s != nullptr) {
    //         r = s;
    //         s = s->right;
    //     }
    // }
    ~tree(){
        clear(pt_raiz);
    }
};

int main(){
    int vet[] = {20, 10, 40, 5, 12};
    tree t;
    t.insertVet(vet, 5);

    t.path("red");
    cout << '\n';
    t.path("erd");
    cout << '\n';
    t.path("edr");
    cout << '\n';

    cout << "lf: \n";
    t.lf();
    cout << "\n";
    return 0;
}