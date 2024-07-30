    //esse arquivo não tá com erro, é besteira do analizador do code. 
    #include <iostream>

    using namespace std;

    struct Nodo{
        int chave;  //valor que ele vai guardar.
        Nodo *proximo; //ponteiro para o próximo nodo

        Nodo (int chave){
            this->chave = chave;
            this->proximo = nullptr;
        }

    };

    class Lista{
        Nodo *ptr_raiz;
        Nodo *ptr_atual;
        public:
        Lista (){
            ptr_raiz = nullptr;
        }

        Lista& operator>>(int x){
            Nodo *p = new Nodo(x); //variáveis alocadas dinâmicamente não tem nome.
            if (ptr_raiz == nullptr){
                ptr_raiz = p;
            }else{
                //algoritmo do comandante
                Nodo *q = ptr_raiz;
                while(q->proximo != nullptr){
                    q = q->proximo;
                }
                q->proximo = p;
            }
            return *this;
        }

        void print(){
            Nodo *q = ptr_raiz;
            while (q != nullptr){
                cout << q->chave << " ";
                q = q->proximo;
            }
            cout << endl;
        }
        bool remover(int chave){
            if (ptr_raiz == nullptr) 
                return false;
            if (ptr_raiz->chave == chave){
                Nodo* p = ptr_raiz;
                ptr_raiz = ptr_raiz->proximo;
                delete p;
                return true;
            }
            else{
                Nodo* p = ptr_raiz;
                while(p->proximo != nullptr && p->proximo->chave != chave){
                    p = p->proximo; //p vai anteceder o nó a ser eliminado
                }
                if (p->proximo == nullptr){
                    return false;
                }
                Nodo *backup = p->proximo; //que será eliminado
                p->proximo = backup->proximo; //basicamente o prox de p agora apontará para o elemento após o que será eliminado.
                delete backup;
                return true;
            }
        }

        ~Lista (){
            while(ptr_raiz != nullptr){
                Nodo *t = ptr_raiz;
                ptr_raiz = ptr_raiz->proximo;
                delete t;
            }
        }    

        void iniciar(){
            ptr_atual = ptr_raiz;
        }    
        bool fim(){
            return ptr_atual == nullptr || ptr_raiz->proximo == nullptr;
        }

        void proximo(){
            if (ptr_atual != nullptr){
                ptr_atual = ptr_atual->proximo;
            }
        }

        int leia(){
            if (ptr_atual != nullptr)
                return ptr_atual->chave;
            return 0;
        }
    };

    int main(){
        Lista l;
        for (int i=0; i < 10; i++){
            l >> i >> i+1;
        }
        
        for (l.iniciar(); !l.fim(); l.proximo()){
            cout << l.leia() << " ";
        }
        cout << endl;
        l.remover(10);
        l.print();

        cout << endl;
        return 0;
    }