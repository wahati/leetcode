#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascaltri(int);

int main() {
    vector<vector<int>> pt = pascaltri(5);
    for (vector<vector<int>>::iterator it = pt.begin(); it != pt.end(); it++) {
        for (vector<int>::iterator itt = it->begin(); itt != it->end(); itt++) {
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<vector<int>> pascaltri(int numRows) {
    vector<vector<int>> result(numRows);
    result[0] = vector<int>(1,1);
    for (int i = 1; i < numRows; i++) {
        vector<int> row(i+1);
        row[0]=1;
        for (int j = 1; j < i; j++) {
            row[j] = result[i-1][j-1]+result[i-1][j];
        }
        row[i]=1;
        result[i]=row;
    }
    return result;
}