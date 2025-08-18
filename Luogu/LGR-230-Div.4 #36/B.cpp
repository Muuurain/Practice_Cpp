#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a1, b1, a2, b2, a3, b3, c;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> c;
    int dl = max({b1, b2, b3});
    int r1 = a1 - (dl - b1) * c;
    int r2 = a2 - (dl - b2) * c;
    int r3 = a3 - (dl - b3) * c;
    if(r1 <= r2 && r1 <= r3) {
        cout << "1 " << r1 << endl;
    }
    else if(r2 <= r1 && r2 <= r3) {
        cout << "2 " << r2 << endl;
    }
    else if(r3 <= r1 && r3 <= r2) {
        cout << "3 " << r3 << endl;
    }

    return 0;
}