#include <iostream>
#include <vector>

using namespace std;

int count(int);

int main() {
    cout << count(5000000) << endl;
    return 0;
}

int count(int n) {
    // bool index_maybe_prime[5000000] = {0};
    // for (int i = 3; i < 5000000; i+=2) {
    //     if (index_maybe_prime[i] == false) {
    //         if (i % 3 || i % 5 || i % 7) {
    //             index_maybe_prime[i] = true;
    //         }
    //     }
    // }
    if (n < 3)
        return 0;
    vector<int> primes(1,2);
    for (int i = 3; i < n; i+=2) {
        // if (index_maybe_prime[i]) {
            int j = 1;
            for (; j < primes.size(); j++) {
                if (primes[j]*primes[j] > i) {
                    j = primes.size();
                    break;
                }
                if (i % primes[j] == 0)
                    break;
            }
            if (j == primes.size())
                primes.push_back(i);
        // }
    }
    return primes.size();
}