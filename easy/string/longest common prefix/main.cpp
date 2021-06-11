#include <iostream>
#include <vector>

using namespace std;

string prefix(vector<string>&);

int main() {
    string str0 = "flower";
    string str1 = "flowchart";
    string str2 = "flight";
    vector<string> strs(3);
    strs[0] = str0;
    strs[1] = str1;
    strs[2] = str2;
    cout << prefix(strs) << endl;
    return 0;
}

string prefix(vector<string>& strs) {
    int min_length = strs[0].length();
    for (int i = 1; i < strs.size(); i++) {
        if (min_length > strs[i].length())
            min_length = strs[i].length();
    }
    string pf = "";
    for (int i = 0; i < min_length; i++) {
        char alpha = strs[0][i];
        for (int j = 0; j < strs.size(); j++) {
            if (alpha != strs[j][i]) {
                return pf;
            }
        }
        pf.append(1, alpha);
    }
    return pf;
}