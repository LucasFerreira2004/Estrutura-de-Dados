#include "vec.h"

vec::vec(int m){
    u = new int [m];
    tam = m;
}
int& vec::get(int k){
    return u[k];
    //retorna uma *referência* ao k-ésimo inteiro do vetor.
}
vec::~vec(){
    delete [] u;
}
