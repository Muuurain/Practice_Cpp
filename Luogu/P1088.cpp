#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    for(int &it : num) cin >> it;
    while(m--) next_permutation(num.begin(), num.end());
    for(int i = 0; i < n; i++) {
        cout << num[i];
        if(i != n - 1) {
            cout << " ";
        }
        else {
            cout << endl;
        }
    }

    return 0;
}