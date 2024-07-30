#include "vec.h"

int main(){
    vec a(10);

    int b = a.get(5);
    a.get(5) == 11; //posso fazer isso pq get retorna uma referência.
}