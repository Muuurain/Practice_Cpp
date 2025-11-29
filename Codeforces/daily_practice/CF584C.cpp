#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n >> t;
    string s1, s2;
    cin >> s1 >> s2;
    int samec = 0;
    int aim = n - t;
    vector<int> samep;
    for(int i = 0; i < n; i++) {
        if(s1[i] == s2[i]) {
            samec++;
            samep.push_back(i);
        }
    }
    vector<char> ans(n);
    if((samec + (n - samec) / 2) >= aim) {
        for(int i = 0; i < samep.size(); i++) {
            if(aim == 0) break;
            int p = samep[i];
            ans[p] = s1[p];
            aim--;
        }
        if(aim) {
            int aim1 = aim, aim2 = aim;
            for(int i = 0; i < n; i++) {
                if(!ans[i] && aim1) {
                    ans[i] = s1[i];
                    aim1--;
                }
                else if(!ans[i] && aim2) {
                    ans[i] = s2[i];
                    aim2--;
                }
                else if(!ans[i]) {
                    char c = s1[i] + 1;
                    if(c >= 'z') c = 'a';
                    if(c == s2[i]) c++;
                    ans[i] = c;
                }
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                if(!ans[i]) {
                    char c = s1[i] + 1;
                    if(c >= 'z') c = 'a';
                    if(c == s2[i]) c++;
                    ans[i] = c;
                }
            }
        }
        for(auto c : ans) cout << c;
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}