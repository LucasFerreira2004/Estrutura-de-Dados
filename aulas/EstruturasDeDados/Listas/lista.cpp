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
        
        public:
        Lista (){
            ptr_raiz = nullptr;
        }

        void inserir(int x){
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
        }

        void print(){
            Nodo *q = ptr_raiz;
            while (q != nullptr){
                cout << q->chave << " ";
                q = q->proximo;
            }
            cout << endl;
        }

        ~Lista (){
            while(ptr_raiz != nullptr){
                Nodo *t = ptr_raiz;
                ptr_raiz = ptr_raiz->proximo;
                delete t;
            }
        }        
    };

    int main(){
        Lista l;
        for (int i=0; i < 10; i++){
            l.inserir(i);
        }
        l.print();

        return 0;
    }