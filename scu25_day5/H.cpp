#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cnta[10], cntb[10];
ll mypow10[20], sum[20];
void cal(ll num, ll *cnt) {
    int n[20];
    int dig = 0;
    while(num) {
        n[++dig] = num % 10;
        num /= 10;
    }

    for(int i = dig; i >= 1; i--) {
        for(int j = 0; j < 10; j++) {
            cnt[j] += sum[i - 1] * n[i];
        }
        for(int j = 0; j < n[i]; j++) {
            cnt[j] += mypow10[i - 1];
        }
        long long t = 0;
        for(int j = i - 1; j > 0; j--) {
            t = t * 10 + n[j];
        }
        cnt[n[i]] += t + 1;
        cnt[0] -= mypow10[i - 1];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll a, b;
    cin >> a >> b;
    for(int i = 0; i < 13; i++) {
        mypow10[i] = pow(10, i);
    }
    for(int i = 1; i < 13; i++) {
        sum[i] = i * mypow10[i - 1];
    }
    cal(a - 1, cnta);
    cal(b, cntb);
    for(int i = 0; i < 10; i++) {
        cout << (cntb[i] - cnta[i]) << " ";
    }

    return 0;
}