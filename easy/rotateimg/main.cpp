#include <iostream>
#include <vector>

using namespace std;

void rotateImg(vector<vector<int>>&);

int main() {
    int arr[16] = {5,1,9,11,2,4,8,10,13,3,6,7,15,14,12,16};
    vector<vector<int>> mtx(4);
    for (int i = 0; i < 4; i++) {
        mtx[i] = vector<int>(4);
        for (int j = 0; j < 4; j++) {
            mtx[i][j] = arr[i*4+j];
        }
    }
    rotateImg(mtx);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void rotateImg(vector<vector<int>>& matrix) {    
    int size = matrix.size();
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    int first = 0;
    int last = size-1;
    while (last > first) {
        for (int i = 0; i < size; i++) {
            int temp = matrix[i][first];
            matrix[i][first] = matrix[i][last];
            matrix[i][last] = temp;
        }
        first++;
        last--;
    }
}