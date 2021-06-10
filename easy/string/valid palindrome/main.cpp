#include <iostream>
#include <vector>

using namespace std;

bool is_valid(string);

int main() {
    cout << is_valid("0P") << endl;
    return 0;
}

bool is_valid(string s) {
    int index = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > 64 && s[i] < 91) {
            index++;
            s[index] = (char)(s[i]+32);
        } else if (s[i] > 96 && s[i] < 123) {
            index++;
            s[index] = s[i];
        } else if (s[i] > 47 && s[i] < 58) {
            index++;
            s[index] = s[i];
        }
    }
    int start = 0;
    while (index > start) {
        if (s[start] != s[index])
            return false;
        start++;
        index--;
    }
    return true;
}