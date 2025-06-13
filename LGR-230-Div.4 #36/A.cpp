#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int r1 = t / 60;
    int r11 = 0;
    int r2 = t % 60;
    int r22 = 0;
    if(r1 > 9) {
        r11 = r1 / 10;
        r1 = r1 %  10;
    }
    if(r2 > 9) {
        r22 = r2 / 10;
        r2 = r2 % 10;
    }

    cout << '|' << r11 << '|' << r1 << '|' << ':' << '|' << r22 << '|' << r2 << '|' << endl;

    return 0;
}