#include <iostream>

using namespace std;

string talk(int);

int main() {
    cout << talk(5) << endl;
    return 0;
}

string talk(int n) {
    if (n == 1) {
        return "1";
    } else {
        string request = talk(n-1);
        string response = "";
        char cnum = request[0];
        int counter = 0;
        for (int i = 0; i < request.length(); i++) {
            if (cnum == request[i])
                counter++;
            else {
                response.append(1, (char)(48+counter));
                response.append(1, cnum);
                counter = 1;
                cnum = request[i];
            }
        }
        response.append(1, (char)(48+counter));
        response.append(1, cnum);
        return response;
    }
}