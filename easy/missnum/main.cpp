#include <iostream>

using namespace std;

uint32_t reversebit(uint32_t);

int main() {
    cout << reversebit(0b11111111111111111111111111111101) << endl;
    return 0;
}

uint32_t reversebit(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n >> i) & 1;
    }
    return result;
}