#include <bits/stdc++.h>

using namespace std;

int ret[5100000];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        scanf("%d", &ret[i]);
    }
    sort(ret, ret + n);
    cout << ret[k] << endl;

    return 0;
}