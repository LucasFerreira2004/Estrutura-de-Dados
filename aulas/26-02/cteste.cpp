#include <cstdio>

int sum (int* u, int n){ //u[] poderia ser int * u, pois é um ponteiro. 
    if (n == 1)
        return u[0];
    else
        return u[0] + sum(u + 1, n - 1);
}



int main(){
    int u[] = {1, 2, 3};
    int x;
    int* p = &x;
    p = u + 1;
    p = u - 4;
    printf("%d\n", *p);

    p = u;

    printf("%d\n", sum(u, 3));

    int* v = u + 1; //poderia ser p + 1, pois p aponta para o mesmo endereço de u; 

   for (int i = 0; i < 3; i++){
        //faça alguma coisa;
        //como p aponta para u, posso usar o p como se fosse u, os dois apontam para o mesmo lugar. 
   }
    return 0;
}