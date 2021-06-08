#include <iostream>

using namespace std;

int hamwei(uint32_t);

int main() {
    cout << hamwei(32) << endl;
    return 0;
}

int hamwei(uint32_t n) {
    int counter = 0;
    for (int i = 0; i < 32; i++) {
        counter += (n >> i) & 1;
    }
    return counter;
}