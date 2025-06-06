#include <bits/stdc++.h>

using namespace std;

int a[200];

bool prime[100000 + 10] = {1, 1};

void setprime(int n) {
    for(int i = 2; i <= n; i++) {
        if(!prime[i]) {
            for(int j = 2; j * i <= n; j++) {
                prime[i * j] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxn = 0;
    for(int i = 0; i < n; i++) {
        maxn = max(maxn, a[i]);
    }
    setprime(maxn);
    for(int i = 0; i < n; i++) {
        if(!prime[a[i]]) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    return 0;
}