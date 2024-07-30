#include <iostream>
#include <queue>
using namespace std;

void radixSort(int vet[], int lenght, int d){ //length= vet size, d radical size
    queue<int> buckets[10]; //buckets é um vetor de filas de inteiros.
    int m = 1; //serve para pegar o digito que temos interesse. Vamos usar %
    
    for (int i=0; i<d; i++){
        for (int k=0; k < lenght; k++){ //povoando os buckets
            int dig = (vet[k] % (10*m)) / m;
            buckets[dig].push(vet[k]);
        }
        int cont=0;
        for (int j=0; j<10; j++){
            while(!buckets[j].empty()){
                vet[cont++] = buckets[j].front();
                buckets[j].pop();
            }           
        }
        m *=10;
    }
}

int main(){
    int size = 500;
      int vet[500] = {
        57, 84, 95, 67, 39, 42, 78, 21, 63, 55,
        34, 89, 12, 73, 88, 29, 40, 68, 25, 51,
        76, 90, 32, 87, 60, 93, 18, 45, 38, 79,
        33, 56, 74, 94, 81, 20, 61, 47, 70, 58,
        13, 92, 86, 27, 54, 75, 11, 35, 77, 99,
        2, 66, 19, 49, 64, 85, 15, 50, 91, 7,
        96, 22, 65, 9, 46, 71, 80, 4, 52, 10,
        36, 98, 41, 83, 16, 28, 59, 6, 69, 24,
        17, 82, 30, 62, 1, 53, 72, 31, 43, 8,
        48, 5, 97, 26, 23, 44, 37, 3, 14, 100,

        57, 84, 95, 67, 39, 42, 78, 21, 63, 55,
        34, 89, 12, 73, 88, 29, 40, 68, 25, 51,
        76, 90, 32, 87, 60, 93, 18, 45, 38, 79,
        33, 56, 74, 94, 81, 20, 61, 47, 70, 58,
        13, 92, 86, 27, 54, 75, 11, 35, 77, 99,
        2, 66, 19, 49, 64, 85, 15, 50, 91, 7,
        96, 22, 65, 9, 46, 71, 80, 4, 52, 10,
        36, 98, 41, 83, 16, 28, 59, 6, 69, 24,
        17, 82, 30, 62, 1, 53, 72, 31, 43, 8,
        48, 5, 97, 26, 23, 44, 37, 3, 14, 100,

        57, 84, 95, 67, 39, 42, 78, 21, 63, 55,
        34, 89, 12, 73, 88, 29, 40, 68, 25, 51,
        76, 90, 32, 87, 60, 93, 18, 45, 38, 79,
        33, 56, 74, 94, 81, 20, 61, 47, 70, 58,
        13, 92, 86, 27, 54, 75, 11, 35, 77, 99,
        2, 66, 19, 49, 64, 85, 15, 50, 91, 7,
        96, 22, 65, 9, 46, 71, 80, 4, 52, 10,
        36, 98, 41, 83, 16, 28, 59, 6, 69, 24,
        17, 82, 30, 62, 1, 53, 72, 31, 43, 8,
        48, 5, 97, 26, 23, 44, 37, 3, 14, 100,

        57, 84, 95, 67, 39, 42, 78, 21, 63, 55,
        34, 89, 12, 73, 88, 29, 40, 68, 25, 51,
        76, 90, 32, 87, 60, 93, 18, 45, 38, 79,
        33, 56, 74, 94, 81, 20, 61, 47, 70, 58,
        13, 92, 86, 27, 54, 75, 11, 35, 77, 99,
        2, 66, 19, 49, 64, 85, 15, 50, 91, 7,
        96, 22, 65, 9, 46, 71, 80, 4, 52, 10,
        36, 98, 41, 83, 16, 28, 59, 6, 69, 24,
        17, 82, 30, 62, 1, 53, 72, 31, 43, 8,
        48, 5, 97, 26, 23, 44, 37, 3, 14, 100,

        57, 84, 95, 67, 39, 42, 78, 21, 63, 55,
        34, 89, 12, 73, 88, 29, 40, 68, 25, 51,
        76, 90, 32, 87, 60, 93, 18, 45, 38, 79,
        33, 56, 74, 94, 81, 20, 61, 47, 70, 58,
        13, 92, 86, 27, 54, 75, 11, 35, 77, 99,
        2, 66, 19, 49, 64, 85, 15, 50, 91, 7,
        96, 22, 65, 9, 46, 71, 80, 4, 52, 10,
        36, 98, 41, 83, 16, 28, 59, 6, 69, 24,
        17, 82, 30, 62, 1, 53, 72, 31, 43, 8,
        48, 5, 97, 26, 23, 44, 37, 3, 14, 100
    };

    radixSort(vet, size, 3);
    for (int i=0; i<size; i++){
        cout << vet[i] << " ";
    }
    cout << endl;
    
    return 0;
}