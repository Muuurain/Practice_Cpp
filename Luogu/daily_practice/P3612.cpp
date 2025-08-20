#include<bits/stdc++.h>
using namespace std;

string s;
typedef long long ll;
ll cal(ll n) {
    if(n <= s.length()) return n;
    ll t = s.length();
    while(n - t > 0) t <<= 1;
    t >>= 1;
    n -= t + 1;
    if(n == 0) n = t;
    return cal(n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> s >> n;
    n = cal(n);

    cout << s[n - 1] << endl;

    return 0;
}