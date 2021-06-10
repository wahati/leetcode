#include <iostream>
#include <stack>

using namespace std;

bool is_valid(string);

int main() {
    cout << is_valid("()[]{}") << endl;
    return 0;
}

bool is_valid(string s) {
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