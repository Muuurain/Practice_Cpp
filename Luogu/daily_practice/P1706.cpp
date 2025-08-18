#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    do {
        for(int i : num) cout << setw(5) << i;
        cout << endl;
    }while(next_permutation(num.begin(), num.end()));

    return 0;
}