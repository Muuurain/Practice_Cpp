#include <bits/stdc++.h>

using namespace std;

int c[110];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n + 1; i++) {
        cin >> c[i];
    }
    if(n == 0) {
        cout << c[0] << endl;
    }
    else {
        if(c[0] == -1) {
            cout << "-" << "x^" << n;
        }
        else if(c[0] == 1) {
            cout << "x^" << n;
        }
        else {
            cout << c[0] << "x^" << n;
        }
        for(int i = 1; i < n + 1; i++) {
            if(c[i] > 0) {
                cout << "+";
                if(i != n) {
                    if(c[i] != 1) {
                        cout << c[i];
                    }
                    if(i != n - 1) {
                        cout << "x^" << n - i;
                    }
                    else {
                        cout << "x";
                    }
                }
                else {
                    cout << c[i];
                }
            }
            else if(c[i] == 0) {
                continue;
            }
            else {
                if(i != n) {
                    if(c[i] != -1) {
                        cout << c[i];
                    }
                    else {
                        cout << "-";
                    }
                    if(i != n - 1) {
                        cout << "x^" << n - i;;
                    }
                    else {
                        cout << "x";
                    }
                }
                else {
                    cout << c[i];
                }
            }
        }
        cout << endl;
    }


    return 0;
}