#include <iostream>
#include <vector>

using namespace std;

bool is_valid(string, string);

int main() {
    cout << is_valid("anagram", "nagaram") << endl;
    return 0;
}

bool is_valid(string s, string t) {
    if (s.length() != t.length())
        return false;
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        count[s[i]-97]++;
    }
    for (int i = 0; i < t.length(); i++) {
        count[t[i]-97]--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i]) {
            return false;
        }
    }
    return true;
}