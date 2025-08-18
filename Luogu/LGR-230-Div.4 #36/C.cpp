#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    int ret = 0;
    if(x <= 10) {
        ret = x * 20;
    }
    else if(x <= 50) {
        int t1 = (x - 10) / 5;
        if((x - 10) % 5) {
            t1++;
        }
        t1 = 200 + t1 * 80;
        int t2 = 200 + (x - 10) / 5 * 80 + (x - 10) % 5 * 20;
        ret = min(t1, t2);
        
    }
    else {
        int t1 = (x - 50) / 10;
        if((x - 50) % 10) {
            t1++;
        }
        t1 = 840 + t1 * 120;
        int t2 = 840 + (x - 50) / 10 * 120 + (x - 50) % 10 * 20;
        ret = min(t1, t2);
    }
    cout << ret << endl;

    return 0;
}