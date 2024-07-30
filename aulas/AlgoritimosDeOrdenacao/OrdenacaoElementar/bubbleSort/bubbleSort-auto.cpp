#include <iostream>
void buubleSort (auto u[], int n){
    for (int j=n-1; j > 0 ; j--){
        for (int i=0; i<j; i++){ //parte de trás do barco
            if(u[i] > u[i+1]){
                int x = u[i];
                u[i] = u[i + 1];
                u[i + 1] = x;
            }
        } 
    }
}

int main(){
    int u[5] = {2.5, -1.1, 0.5, 0.3, 20.2};
    int n = 5;
    buubleSort(u, n);
    
    for(int i=0; i<n; i++)
        std::cout << u[i] << " ";
    std::cout << '\n';

    return 0;
}