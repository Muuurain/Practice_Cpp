#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(vector<string> s1, vector<string> s2) {
    int p = 0;
    while(p < s1.size() && p < s2.size()) {
        if(s1[p] != s2[p]) return s1[p] < s2[p];
    }
    return s1.size() < s2.size();
}
void solve() {
    int n;
    cin >> n;
    vector<vector<string> > vec(n);
    int maxnum = 0;
    for(int i = 0; i < vec.size(); i++) {
        int num;
        cin >> num;
        maxnum = max(maxnum, num);
        vec[i].resize(num);
        for(int j = 0; j < vec[i].size(); j++) {
            string s;
            cin >> s;
            vec[i][j] = s;
        }
    }
    vector<bool> vis(n);
    sort(vec.begin(), vec.end(), cmp);
    vector<string> ret;
    for(auto s : vec[0]) ret.push_back(s);
    int p = vec[0].size();
    while(p < maxnum) {
        maxnum -= p;
        vector<int> delt;
        for(int i = 0; i < vec.size(); i++) {
            vec[i].erase(vec[i].begin(),vec[i].begin() + p);
            if(vec[i].empty()) {
                delt.push_back(i);
            }
        }
        reverse(delt.begin(), delt.end());
        for()
    }
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