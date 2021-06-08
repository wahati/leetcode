#include <iostream>
#include <vector>

using namespace std;

int missnum(vector<int>&);

int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    cout << missnum(nums) << endl;
    return 0;
}

int missnum(vector<int>& nums) {
    int result = -nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result += i - nums[i];
    }
    return result + nums.size();
}