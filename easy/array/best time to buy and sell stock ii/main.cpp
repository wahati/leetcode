#include <iostream>
#include <vector>

using namespace std;

int profit(vector<int>&);

int main() {
    vector<int> vect = {7,6,4,3,1};
    cout << profit(vect) << endl;
    return 0;
}

int profit(vector<int>& prices) {
    int size = prices.size();
    int sum = 0;
    for (int i = 0; i < size-1; i++) {
        if (prices[i] < prices[i+1]) {
            sum += prices[i+1]-prices[i];
        }
    }
    return sum;
}