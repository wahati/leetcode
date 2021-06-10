#include <iostream>
#include <vector>

using namespace std;

void move(vector<int>&);

int main() {
    vector<int> nums(5);
    nums[0] = 0;
    nums[1] = 1;
    nums[2] = 0;
    nums[3] = 3;
    nums[4] = 12;
    move(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

void move(vector<int>& nums) {
    int size = nums.size();
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
            nums[index] = nums[i];
            index++;
        }
    }
    for (int i = index; i < size; i++) {
        nums[i] = 0;
    }
}