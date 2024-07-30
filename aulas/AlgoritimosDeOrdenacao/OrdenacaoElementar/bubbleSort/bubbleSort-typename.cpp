#include <iostream>

template <typename T> void buubleSort (T u[], int n){ //agora temos que oferecer o tipo de parâmtro. 
    for (int j=n-1; j > 0 ; j--){
        for (int i=0; i<j; i++){ //parte de trás do barco
            if(u[i] > u[i+1]){
                T x = u[i];
                u[i] = u[i + 1];
                u[i + 1] = x;
            }
        } 
    }
}

int main(){
    float u[5] = {2.3, 1.0, 0.5, 3.1, 0.0};
    int n = 5;
    buubleSort<float>(u, n);
    
    for(int i=0; i<n; i++)
        std::cout << u[i] << " ";
    std::cout << '\n';

    return 0;
}