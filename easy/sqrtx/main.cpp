#include <iostream>

using namespace std;

int mySqrt(int);

int main() {
    cout << mySqrt(100000) << endl;
    return 0;
}

int mySqrt(int x) {
    int start = 0;
    int end = 46341;
    while (end - start > 1) {
        int median = (start + end) / 2;
        if (median * median > x) {
            end = median;
        } else if (median * median == x) {
            return median;
        } else {
            start = median;
        }
    }
    return start;
}