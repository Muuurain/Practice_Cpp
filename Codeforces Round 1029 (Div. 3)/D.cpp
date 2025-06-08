#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        int arr[200010] = {0};
        int dir = 0;
        int value = 1;
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if(i == 1) {
                dir = (arr[1] > arr[0] ? 1 : 0); 
            }
            if(i > 1 && dir == 1) {
                if(arr[i] < arr[i - 1]) {
                    value = 0;
                }
            }
            else if(i > 1 && dir == 0) {
                if(arr[i] > arr[i - 1]) {
                    value = 0;
                }
            }
        }
        if(value == 0) {
            printf("NO\n");
            continue;
        }
        if(dir == 1) {
            int num = arr[n - 1] % n;
            int cnt = arr[n - 1] / n;
            for(int i = 0; i < n; i++) {
                if((arr[i] - cnt * (i + 1)) / (n - i) != num) {
                    value = 0;
                    break;
                }
            }
        }
        else {
            int num = arr[0] % n;
            int cnt = arr[0] / n;
            for(int i = 0; i < n; i++) {
                if((arr[i] - cnt * (n - i)) / (i + 1) != num) {
                    value = 0;
                    break;
                }
            }
        }
        if(value) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
