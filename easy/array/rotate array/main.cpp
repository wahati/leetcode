#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>&, int);

int main() {
    vector<int> nums = {1,2,3,4};
    rotate(nums, 2);
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}

//By the hint.
void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    vector<int> store;
    if (k <= nums.size()/2) {
        for (int i = 0; i < k; i++) {
            store.push_back(nums[nums.size()-1-i]);
        }
        for (int i = nums.size()-1-k; i >= 0; i--) {
            nums[i+k] = nums[i];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = store[store.size()-1-i];
        }
    } else {
        for (int i = 0; i < nums.size()-k; i++) {
            store.push_back(nums[i]);
        }
        for (int i = nums.size()-k; i < nums.size(); i++) {
            nums[i-nums.size()+k] = nums[i];
        }
        for (int i = k; i < nums.size(); i++) {
            nums[i] = store[i-k];
        }
    }
}