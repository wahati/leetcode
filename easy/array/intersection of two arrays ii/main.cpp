#include <iostream>
#include <vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

int main() {
    int a1[3] = {4,9,5}, a2[5] = {9,4,9,8,4};
    vector<int> arr1(3), arr2(5);
    for (int i = 0; i < 3; i++)
        arr1[i] = a1[i];
    for (int i = 0; i < 5; i++)
        arr2[i] = a2[i];
    vector<int> ans = intersection(arr1, arr2);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int count1[1001] = {0};
    int size1 = nums1.size();
    for (int i = 0; i < size1; i++) {
        count1[nums1[i]]++;
    }
    int count2[1001] = {0};
    int size2 = nums2.size();
    for (int i = 0; i < size2; i++) {
        count2[nums2[i]]++;
    }
    vector<int> result;
    for (int i = 0; i < 1001; i++) {
        if (count1[i] > count2[i]) {
            for (int j = 0; j < count2[i]; j++) {
                result.push_back(i);
            }
        } else {
            for (int j = 0; j < count1[i]; j++) {
                result.push_back(i);
            }
        }
    }
    return result;
}