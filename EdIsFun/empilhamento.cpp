#include <iostream>

using namespace std;

void process(int value) {
    if (value == 0) 
        return;
    
    int div = value / 2;
    process(div);
    cout << div << " " << value % 2 << endl;   
}

int main() {
    int value;
    cin >> value;
    process(value);

    return 0;
}