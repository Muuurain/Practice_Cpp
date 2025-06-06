#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long ret = 0;
    while(n--) {
        int t;
        scanf("%d", &t);
        ret += t;
    }
    cout << ret << endl;

    return 0;
}