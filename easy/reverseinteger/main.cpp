#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int reverse(int);
bool overflow(stack<int>);

int main() {
    cout << reverse(2055555555) << endl;
    return 0;
}

int reverse(int x) {
    if (x == 0)
        return 0;
    stack<int> revx;
    while(x != 0) {
        revx.push(x % 10);
        x /= 10;
    }
    int answer = 0;
    int magnification = 1;
    while (revx.size() > 1) {
        answer += revx.top() * magnification;
        revx.pop();
        magnification *= 10;
    }
    if (magnification == 1000000000) {
        if (revx.top() > 2 || revx.top() < -2) {
            return 0;
        } else if (revx.top() == 2 || revx.top() == -2) {
            if (answer > 147483647 || answer < -147483648) {
                return 0;
            }
            answer += revx.top() * magnification;
        }
    } else {
        answer += revx.top() * magnification;
    }
    return answer;
}