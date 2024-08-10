#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Nodo {
    string chave;  // valor que ele vai guardar
    Nodo *proximo; // ponteiro para o próximo nodo

    Nodo(string chave) {
        this->chave = chave;
        this->proximo = nullptr;
    }
};

class ListaCircular {
    Nodo *ptr_atual;

    void kill(Nodo *q){
        if (q == ptr_atual){
            delete q;
            return;
        }
        kill(q->proximo);
        delete q;
    }
    void stacKill(){ //podemos usar essa mesma implementação para deletar otras listas, apenas adaptando a condição de parada no for.
        stack<Nodo*> s;
        Nodo *p = ptr_atual->proximo;
        for (Nodo *p = ptr_atual->proximo;  p != ptr_atual; p = p->proximo){
            s.push(p->proximo);
        }
        while(!s.empty()){
            Nodo *t = s.top();
            s.pop();
            delete t;
        }
        ptr_atual == nullptr;
    }
public:
    ListaCircular() {
        ptr_atual = nullptr;
    }

    void inserir(string x) {
        if (ptr_atual == nullptr) { // se ainda estiver vazia
            ptr_atual = new Nodo(x);
            ptr_atual->proximo = ptr_atual;
        } else { // existe pelo menos um nodo
            Nodo* novo = new Nodo(x);
            novo->proximo = ptr_atual->proximo;
            ptr_atual->proximo = novo;
            ptr_atual = novo;
        }
    }

    void print() {
        if (ptr_atual == nullptr) { // verifica se a lista está vazia
            cout << "Lista está vazia." << endl;
            return;
        }
        Nodo* p = ptr_atual->proximo; // começa pelo próximo do atual
        do {
            cout << p->chave << endl;
            p = p->proximo;
        } while (p != ptr_atual->proximo); // para quando voltar ao primeiro nó
    }

    bool remover(string chave) {
        if (ptr_atual == nullptr){
            return false;
        }
        Nodo *p = ptr_atual;
        while(ptr_atual->proximo != p && ptr_atual->proximo->chave != chave){
            ptr_atual = ptr_atual->proximo;
        }
        if (ptr_atual->proximo->chave == chave){
            Nodo *q = ptr_atual->proximo;
            ptr_atual->proximo = q->proximo;
            delete q;
            return true;
        }
        return false;
    }
    bool busca(string chave){
        Nodo *p = ptr_atual;
        if (ptr_atual == nullptr) return false;
        if (ptr_atual->chave == chave) return true;
        do{
            ptr_atual = ptr_atual->proximo;
            if (ptr_atual->chave == chave){
                ptr_atual = p;
                return true;
            }
        }while(ptr_atual->proximo != p);
        ptr_atual = p;
        return false;

    }


    void iniciar() {
        ptr_atual = ptr_atual;
    }

    bool fim() {
        return ptr_atual == nullptr || ptr_atual->proximo == nullptr;
    }

    void proximo() {
        if (ptr_atual != nullptr) {
            ptr_atual = ptr_atual->proximo;
        }
    }

    string leia() {
        if (ptr_atual != nullptr)
            return ptr_atual->chave;
        return "";
    }

    ~ListaCircular() {
        stacKill();
    }
};

int main() {
    ListaCircular *lc = new ListaCircular();
    lc->inserir("ola mundo");
    if (lc->busca("ola mundo")) cout << "-----achou\n";
    //lc.remover("ola mundo");
    lc->inserir("ola mundo 2");
    lc->inserir("1");
    lc->inserir("teste");
    if (lc->busca("teste")) cout << "-----achou\n";
    //lc.remover("1");
    lc->print();
    
    delete lc;
    return 0;
}
