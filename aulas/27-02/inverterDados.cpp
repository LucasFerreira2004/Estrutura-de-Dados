#include <cstdio>

void swap(int* p, int* q){
    int x = *p;
    *p = *q;
    *q = x;
}

void inverse(int* v, int n){
    if (n < 2)
        return;
    else{
        swap(v, v + n - 1); // v + n - 1, significa que ele vai somar e chegar no último elemento do vetor. 
                            //swap(v, &v[n - 1]); tbm funcionaria
        
        inverse (v + 1, n - 2);
    }

}

int main(){
    int v[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        printf("%d ", v[i]);
    printf("\n");
   
    printf("inverse\n");

    inverse(v, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", v[i]);
    printf("\n");
    

    return 0;
}