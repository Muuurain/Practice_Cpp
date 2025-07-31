#include <bits/stdc++.h>
using namespace std;

struct node{
    int a;
    int b;
    int c;
    int d;
};
void solve() {
    int n;
    cin >> n;
    node pl[n + 10];
    long long ret = 0;
    for(int i = 0; i < n; i++) {
        cin >> pl[i].a >> pl[i].b >> pl[i].c >> pl[i].d;
        if(pl[i].b > pl[i].d) ret += pl[i].a + pl[i].b - pl[i].d;
        else if(pl[i].a > pl[i].c) ret += pl[i].a - pl[i].c;
    }
    cout << ret << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}