#include <iostream>
#include <list>
using namespace std;
 
int main()
{

    list<int> ls = {1, 2, 3, 4, 5};
 
    for (auto it = ls.begin(); it != ls.end(); it++) { //it é o iterator
        cout << *it << ' '; //o * é uma sobrecarga, ele não está desreferenciando um ponteiro. 
    }
    cout << endl;
    return 0;
}
