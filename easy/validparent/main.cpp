#include <iostream>
#include <stack>

using namespace std;

bool validparent(string);

int main() {
    cout << validparent("()[]{}") << endl;
    cout << validparent("([)]") << endl;
    cout << validparent("{[]}") << endl;
    cout << validparent("(]") << endl;
    cout << validparent("}") << endl;
    return 0;
}

bool validparent(string s) {
    if (s.length() & 1)
        return false;
    int counter = 0;
    int offset = 1;
    for (int i = 1; i < s.length(); i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                offset = 1;
                break;
            case ')':
                if (s[i-offset] == '(') {
                    counter+= 2;
                    offset += 2;
                    break;
                } else {
                    return false;
                }
            case ']':
                if (s[i-offset] == '[') {
                    counter+= 2;
                    offset += 2;
                    break;
                } else {
                    return false;
                }
            case '}':
                if (s[i-offset] == '{') {
                    counter+= 2;
                    offset += 2;
                    break;
                } else {
                    return false;
                }
        }
    }
    if (counter == s.length()) {
        return true;
    }
    return false;
}