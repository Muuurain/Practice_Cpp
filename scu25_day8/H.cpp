#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n;

    cout << "digit" << endl;
    cout.flush();
    cin >> x;
    
    cout << "digit" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add -8" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add -4" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add -2" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add -1" << endl;
    cout.flush();
    cin >> x;
    
    cout << "add " << n - 1 << endl;
    cout.flush();
    cin >> x;
    
    cout << "!" << endl;
    cout.flush();
    cin >> x;

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