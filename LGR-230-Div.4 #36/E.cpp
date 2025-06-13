#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), ret(n);
    for(auto &it : a) cin >> it;
    for(int i = 0; i < n; i++) {
        int it = i + 1;
        while(a[i]--) {
            if(it < 10) break;
            vector<int> num;
            while(it) {
                num.push_back(it % 10);
                it /= 10;
            }
            for(auto i : num) it += i;
        }
        ret[i] = it;
    }
    for(auto i : ret) cout << i << " ";
    cout << endl;

    return 0;
}