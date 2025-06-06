#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long b, a, c, p;
    cin >> a >> c >> p;
    if(a % p == 0) {
        b = p;
    }
    else {
        if(c & 1 == 0) {
            b = p - 1;
        }
        else {
            b = (p - 1) * (p - 1);
        }
    }
    cout << b << endl;

    return 0;

}