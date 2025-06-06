#include<bits/stdc++.h>

using namespace std;

int H[200];
int main() {
    int ret = -1;
    int n;
    cin >> n;
    int h0;
    cin >> h0;
    for(int i = 2; i <= n; i++) {
        scanf("%d", &H[i]);
    }
    for(int i = 2; i <= n; i++) {
        if(H[i] > h0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ret << endl;

    return 0;
}