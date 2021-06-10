#include <iostream>
#include <vector>

using namespace std;

int max_subarray_sum(vector<int>&);

int main() {
    vector<int> vect = {0,-3,1,1};
    cout << max_subarray_sum(vect) << endl;
    return 0;
}

int max_subarray_sum(vector<int>& nums) {
    int sumarr[30000] = {0};
    sumarr[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sumarr[i] = sumarr[i-1] + nums[i];
    }
    
}
