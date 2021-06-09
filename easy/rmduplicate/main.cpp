#include <iostream>
#include <vector>

using namespace std;

int rmduplicate(vector<int>&);

int main() {
    vector<int> nums(10);
    nums[0] = 0;
    nums[1] = 0;
    nums[2] = 1;
    nums[3] = 1;
    nums[4] = 1;
    nums[5] = 2;
    nums[6] = 2;
    nums[7] = 3;
    nums[8] = 3;
    nums[9] = 4;
    cout << rmduplicate(nums) << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

int rmduplicate(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int size = nums.size();
    int index = 1;
    for (int i = 1; i < size; i++) {
        if (nums[i] != nums[i-1]) {
            nums[index] = nums[i];
            index++;
        }
    }
    for (int i = 0; i < size-index; i++) {
        nums.pop_back();
    }
    return index;
}