#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cal(char c, int cnt, int st, vector<char> &s) {
    int ct = 1;
    ll ret = 0;
    for(int i = st + 1; i < s.size(); i++) {
        if(s[i] == c) {
            ret += i - (st + ct);
            ct++;
        }
    }
    return ret;
}
void solve() {
    int n;
    cin >> n;
    vector<char> s(n);
    vector<int> pa, pb;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        if(s[i] == 'a') pa.push_back(i);
        else pb.push_back(i);
    }
    ll reta = 0, retb = 0;
    if(!pa.empty()) {
        for(int i = 0; i < pa.size(); i++) pa[i] -= i;
        int La = pa[pa.size() / 2];
        for(auto &i : pa) reta += abs(La - i);
    }
    else {
        for(int i = 0; i < pb.size(); i++) pb[i] -= i;
        int Lb = pb[pb.size() / 2];
        for(auto &i : pb) retb += abs(Lb - i);    
        cout << retb << '\n';
        return;
    }
    if(!pb.empty()) {
        for(int i = 0; i < pb.size(); i++) pb[i] -= i;
        int Lb = pb[pb.size() / 2];
        ll retb = 0;
        for(auto &i : pb) retb += abs(Lb - i);
        ll ret = min(reta, retb);
        cout << ret << '\n';   
    }
    else cout << reta << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}