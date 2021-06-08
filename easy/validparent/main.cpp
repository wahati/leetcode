#include <iostream>
#include <stack>

using namespace std;

bool validparent(string);

int main() {
    cout << validparent("()[]{}") << endl;
    return 0;
}

bool validparent(string s) {
    stack<char> parenthesis;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                parenthesis.push(s[i]);
                break;
            case ')':
                if (!parenthesis.empty()&&parenthesis.top() == '(') {
                    parenthesis.pop();
                    break;
                }
                return false;
            case ']':
                if (!parenthesis.empty()&&parenthesis.top() == '[') {
                    parenthesis.pop();
                    break;
                }
                return false;
            case '}':
                if (!parenthesis.empty()&&parenthesis.top() == '{') {
                    parenthesis.pop();
                    break;
                }
                return false;
        }
    }
    if (parenthesis.empty())
        return true;
    return false;
}