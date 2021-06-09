#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containduplicate(vector<int>&);

int main() {
    vector<int> nums(4);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 1;
    cout << containduplicate(nums) << endl;
    return 0;
}

bool containduplicate(vector<int>& nums) {
    unordered_map<int, int> num_time;
    for (int i = 0; i < nums.size(); i++) {
        num_time[nums[i]]++;
        if (num_time[nums[i]] > 1)
            return true;
    }
    return false;
}