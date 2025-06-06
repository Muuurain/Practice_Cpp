#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ret = 1;
ll jc(int x) {
    if(x == 1) return ret;
    else {
        ret *= x;
        x--;
        jc(x);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    ret = jc(n);
    cout << ret << endl;

    return 0;
}