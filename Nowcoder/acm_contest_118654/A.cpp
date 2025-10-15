#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> num(N);
    int n;
    cin >> n;
    n--;
    while(n--) {
        int t;
        cin >> t;
        num[t]++;
    }
    for(int i = 1; i < N; i++) {
        if(!num[i]) {
            cout << i << '\n';
            break;
        }
    }
    
    return 0;
}