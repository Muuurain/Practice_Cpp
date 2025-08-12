#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int sumn[3] = {0};
    int sum = 0;
    for(int &i : a) {
        cin >> i;
        sum += i;
        sumn[i]++;
    }
    if(sum == s) {
        cout << -1 << endl;
        return;
    }
    else if(sum > s) {
        for(int i : a) cout << i << " ";
        cout << endl;
        return;
    }
    else {
        int x = s - sum;
        if(x == 1) {
            while(sumn[0]--) cout << "0 ";
            while(sumn[2]--) cout << "2 ";
            while(sumn[1]--) cout << "1 ";
            cout << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }

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