#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v, distin;
    int n;
    scanf("%d", &n);
    unordered_map<int, int> fre;
    for(int i = 0; i < n; i++) {
        int t = 0;
        scanf("%d", &t);
        v.push_back(t);
        fre[t]++;
        if(fre[t] == 1) {
            distin.push_back(1);
        }
        else {
            distin.push_back(0);
        }
        distin[i] += (i ? distin[i - 1] : 0);
    }
    fre.clear();
    int ret = 0;
    int dt = 0;
    int end = n - 1;
    int j = end;
    while(j >= 0) {
        for(j = end; j >= 0; j--) {
            fre[v[j]]++;
            if(fre[v[j]] == 1) {
                dt++;
                if(dt == distin[end]) {
                    ret++;
                    end = j - 1;
                    fre.clear();
                    dt = 0;
                    break;
                }
            }
        }
    }
    printf("%d\n", ret);
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}