#include <iostream>
#include <vector>

using namespace std;

int position(string);

int main() {
    cout << position("aabb") << endl;
    return 0;
}

int position(string s) {
    int count[26] = {0};
    int first[26] = {0};
    for (int i = 0; i < 26; i++) {
        first[i] = -1;
    }
    for (int i = 0; i < s.length(); i++) {
        count[s[i]-97]++;
        if (first[s[i]-97] == -1) {
            first[s[i]-97] = i;
        }
    }
    int min = 100000;
    for (int i = 0; i < 26; i++) {
        if (count[i] == 1 && first[i] < min) {
            min = first[i];
        }
    }
    if (min == 100000)
        return -1;
    return min;
}