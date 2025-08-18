#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 20 + 5; 
ll ans[N][N][N];
ll w(ll a, ll b, ll c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if(ans[a][b][c]) return ans[a][b][c];
    if(a < b && b < c) return ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1 ) - w(a, b - 1, c);
    return ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) {
            break;
        }
        ll ret = w(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ret << '\n';
    }

    return 0;
}