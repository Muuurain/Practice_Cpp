#include <bits/stdc++.h>

using namespace std;

int ret[11000];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &ret[i]);
    }
    long long cnt = 0;
    for(int i = 0; i < n; ) {
        if(i != n - 1) {
            if(ret[i] > ret[i + 1]) {
                swap(ret[i], ret[i + 1]);
                cnt++;
                i = 0;
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }
    cout << cnt << endl;

    return 0;
}