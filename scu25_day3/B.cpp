#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int H[N], L[N], num[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tot = 0;
    while(cin >> H[tot]) tot++;
    
    L[0] = INT_MAX;
    int t = 0;
    for(int i = 0; i < tot; i++) {
        int l = 0, r = t + 1;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if(L[m] >= H[i]) l = m;
            else r = m;
        }
        int NUM = l + 1;
        if(NUM > t) t = NUM;
        L[NUM] = H[i];
    }
    cout << t << endl;

    int T = 0;
    for(int i = 0; i < tot; i++) {
        int l = 0, r = T + 1;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if(num[m] < H[i]) l = m;
            else r = m;
        }
        int NUM = l + 1;
        if(T < NUM) T = NUM;
        num[NUM] = H[i];
    }
    cout << T << endl;

    return 0;
}