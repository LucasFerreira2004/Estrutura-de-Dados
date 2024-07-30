#include <iostream>
#include <queue>

using namespace std;

void radixSort(int arr[], int n, int maxDigit) {
    queue<int> buckets[2];
    int exp = 1;

    for (int i = 0; i < maxDigit; i++) {
        // Distribui os elementos nos buckets
        for (int j = 0; j < n; j++) {
            int digit = (arr[j] / exp) % 10;
            buckets[digit % 2].push(arr[j]);
        }

        // Recolhe os elementos dos buckets
        int index = 0;
        int currentBucket = 0;
        while (!buckets[currentBucket].empty() || !buckets[1 - currentBucket].empty()) {
            if (!buckets[currentBucket].empty()) {
                arr[index++] = buckets[currentBucket].front();
                buckets[currentBucket].pop();
            } else {
                arr[index++] = buckets[1 - currentBucket].front();
                buckets[1 - currentBucket].pop();
            }
        }

        // Alterna os buckets e incrementa o expoente
        currentBucket = 1 - currentBucket;
        exp *= 10;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxDigit = 3; // Assumindo que o maior número tem 3 dígitos

    radixSort(arr, n, maxDigit);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
