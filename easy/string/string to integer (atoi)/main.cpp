#include <iostream>
#include <vector>

using namespace std;

int integer(string);

int main() {
    string str = "-2147483648";
    cout << integer(str) << endl;
    return 0;
}

int integer(string s) {
    bool isNega = false;
    bool isNonZero = false;
    bool isRecording = false;
    // record digits
    vector<int> digits;
    for (int i = 0; i < s.length(); i++) {
        if (isRecording) {
            if (s[i] == '0') {
                if (isNonZero)
                    digits.push_back(0);
            } else if (s[i] > 48 && s[i] < 58) {
                if (isNonZero == false)
                    isNonZero = true;
                digits.push_back(s[i]-48);
            } else {
                break;
            }
        } else {
            if (s[i] == ' ') {
                // do nothing.
            } else if (s[i] == '-') {
                isNega = true;
                isRecording = true;
            } else if (s[i] == '+') {
                isRecording = true;
            } else if (s[i] > 47 && s[i] < 58) {
                isRecording = true;
                if (s[i] != '0') {
                    digits.push_back(s[i]-48);
                    isNonZero = true;
                }
            } else {
                break;
            }
        }
    }
    // overflow checking
    if (digits.size() > 10) {
        if (isNega)
            return INT32_MIN;
        return INT32_MAX;
    } else if (digits.size() == 10) {
        int pole[10] = {2,1,4,7,4,8,3,6,4,7};
        if (isNega)
            pole[9] = 8;
        for (int i = 0; i < 10; i++) {
            if (digits[i] > pole[i]) {
                if (isNega)
                    return INT32_MIN;
                return INT32_MAX;
            } else if (digits[i] < pole[i]) {
                break;
            }
        }
    }
    // covert to number
    int ans = 0;
    for (int i = 0; i < digits.size(); i++) {
        ans *= 10;
        if (isNega) {
            ans += -digits[i];
        } else {
            ans += digits[i];   
        }
    }
    return ans;
}