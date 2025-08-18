#include <bits/stdc++.h>

using namespace std;

int a[10010];
int b[10010];
int c[10010];
int d[10010];


int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i]; 
    }
    int ax;
    int ay;
    cin >> ax >> ay;
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(ax >= a[i] && ax <= a[i] + c[i]) {
            if(ay >= b[i] && ay <= b[i] + d[i]) {
                ans = i + 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}