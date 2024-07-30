#include <iostream>

template <typename T>
void selectionSort(T u[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (u[j] < u[i])
                k = j;
        }
        if (k != i) {
            T x = u[i];
            u[i] = u[k];
            u[k] = x;
        }
    }
}

int main()
{
    int u[5] = {0, 2, 0, 12, 5};
    selectionSort(u, 5);
    for (int i=0; i < 5; i++)
        std::cout << u[i] << "\n";
    return 0;
}