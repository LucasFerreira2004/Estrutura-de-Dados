#include <iostream>

template <typename T> 
class stack{
    T *vet; //vetor
    int height, length; //length é a capacidade da pilha, o height é quantos elementos ela tem, vai de 0 até length. 
                        //o height tbm corresponde ao indice para onde irá o pŕoximo elemento a ser inserido na pilha. 
    public:
    stack(int length){
        this->length = length;
        vet = new T[length];
        height = 0;
    }

    void push(T x){
        if (height == length) throw "Stack Overflow";
        vet[height++] = x;
    }

    void pop(){
        if (isEmpty()) throw "Stack Underflow";
        height--;
    }
    T top(){
        if (isEmpty()) throw "Stack Underflow";
        return vet[ height-1];
    }
    bool isEmpty(){
        return height==0;
    }
    bool isFull(){
        return height==length;
    }
    ~stack(){ delete [] vet;} //destrutur pq vet foi alocado dinamicamente
};

int main(){
    int x = 100;
    stack<int> u(50);
    //vamos converter x em binário

    while (x>0){
        u.push(x % 2);
        x/=2;
    }
    while(!u.isEmpty()){
        std::cout << u.top();
        u.pop();
    }
    return 0;
}