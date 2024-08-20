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

    void remove(int x){
        
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