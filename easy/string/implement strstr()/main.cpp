#include <iostream>

using namespace std;

int index(string, string);

int main() {
    cout << index("hello", "ll") << endl;
    return 0;
}

int index(string haystack, string needle) {
    if (needle.length()) {
        int end = haystack.length() - needle.length() + 1;
        int find = -1;
        for (int i = 0; i < end; i++) {
            if (haystack[i] == needle[0]) {
                find = i;
                for (int j = 1; j < needle.length(); j++) {
                    if (haystack[i+j] != needle[j]) {
                        find = -1;
                        break;
                    }
                }
                if (find != -1) {
                    return find;
                }
            }
        }
        return -1;
    }
    return 0;
}