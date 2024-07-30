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
        Nodo *ptr_cabeca;
        public:
        Lista (){
            ptr_cabeca = new Nodo(0);
            ptr_raiz = nullptr;
        }

        Lista& operator>>(int x){
            Nodo *p = ptr_cabeca; //variáveis alocadas dinâmicamente não tem nome.
    
            while(p->proximo != nullptr){
                p = p->proximo;
            }
            p->proximo = new Nodo(x);
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
           Nodo *p = ptr_cabeca;
            while (p->proximo != 0 || p->proximo->chave != chave){
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