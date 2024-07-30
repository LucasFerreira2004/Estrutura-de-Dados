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
        Nodo *ptr_atual;
        Nodo *ptr_cabeca;
        public:
        Lista (){
            ptr_cabeca = new Nodo(0);
        }

        Lista& operator>>(int x){
            Nodo *p = ptr_cabeca; //variáveis alocadas dinâmicamente não tem nome.
    
            while(p->proximo != nullptr && p->proximo->chave < x){
                p = p->proximo;
            }
            if (p->proximo != nullptr && p->proximo->chave == x){
                return *this;
            }
            Nodo *q = new Nodo(x);
            q->proximo = p->proximo;
            p->proximo = q;

            return *this;
        }

        void print(){
            Nodo *q = ptr_cabeca;
            while (q->proximo != nullptr){
                cout << q->proximo->chave << " ";
                q = q->proximo;
            }
            cout << endl;
        }
        bool remover(int chave){
           Nodo *p = ptr_cabeca;
            while (p->proximo != nullptr && p->proximo->chave != chave){
                p = p->proximo;
            }
            if (p->proximo == nullptr)
                return false;
                
            Nodo *backup = p->proximo; //que será eliminado
                p->proximo = backup->proximo; //basicamente o prox de p agora apontará para o elemento após o que será eliminado.
                delete backup;
                return true;
        }

        ~Lista (){
            while(ptr_cabeca != nullptr){
                Nodo *t = ptr_cabeca;
                ptr_cabeca = ptr_cabeca->proximo;
                delete t;
            }
            delete ptr_cabeca;
        }    

        void iniciar(){
            ptr_atual = ptr_cabeca->proximo;
        }    
        bool fim(){
            return ptr_atual == nullptr;
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
        l >> 10 >> 7 >> 4 >> 1 >> 20 >> 12 >> 7;
        cout << '\n';
        for (l.iniciar(); !l.fim(); l.proximo()){
            cout << l.leia() << " ";
        }
        cout <<endl;
        cout << endl;
        l.remover(10);
        l.print();

        cout << endl;
        return 0;
    }