#include <bits/stdc++.h>

using namespace std;

int main() {
    double s = 7.0;
    double dis = 0;
    double a, x;
    cin >> a >> x;
    while(dis + s <= a - x) {
        dis += s;
        s *= 0.98;
    }
    if(a - x <= 0) {
        if(dis + s > a + x) {
            cout << "n" << endl;
        }
        else {
            cout << "y" << endl;
        }
        return 0;
    }
    if(dis + s + s * 0.98 > a + x) {
        cout << "n" << endl;
    }
    else { 
        cout << "y" << endl;
    }

    return 0;
}