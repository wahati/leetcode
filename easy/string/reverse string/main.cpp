#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<char>&);

int main() {
    vector<char> string = {'h','e','l','l','o','h'};
    reverse(string);
    for (int i = 0; i < string.size(); i++) {
        cout << string[i] << " ";
    }
    cout << endl;
    return 0;
}

void reverse(vector<char>& s) {
    int start = 0;
    int end = s.size()-1;
    while (end-start > start) {
        char temp = s[start];
        s[start] = s[end-start];
        s[end-start] = temp;
        start++;
    }
}