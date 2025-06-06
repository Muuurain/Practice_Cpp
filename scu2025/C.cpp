#include <bits/stdc++.h>

using namespace std;

void dfs(int &sum, int &n, int times[], int a[], int &way) {
    int next;
    for(int i = sum + 1; i < n; i++) {
        if(times[i]) {
            next = i;
            break;
        }
    }
    if(sum + times[next] > next) {
        sum += times[next];
        for(int i = 1; i <= n; i++) {
            if(a[i] == next) {
                a[i] = 1000000;
            }
        }
        while(1) {
            int temp = sum;
            for(int i = 1; i <=  n; i++) {
                if(a[i] <= sum) {
                    sum++;
                    a[i] = 1000000;
                }
            }
            if(temp == sum) {
                break;
            }
        }
        way++;
    }else {
        sum += times[next];
        for(int i = 1; i <= n; i++) {
            if(a[i] == next) {
                a[i] = 1000000;
            }
        }
        dfs(sum, n, times, a, way);
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		scanf("%d", &n);
		int a[n + 1] = {0};
        int times[n + 1] = {0};
		int sum = 0;
		int way = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
            times[a[i]]++;
			if(a[i] == 0) {
				sum++;
				a[i] = 1000000;
			}
		}
		while(1) {
			int temp = sum;
			for(int i = 1; i <=  n; i++) {
				if(a[i] <= sum) {
                    sum++;
                    a[i] = 1000000;
                }
			}
			if(temp == sum) {
				break;
			}
		}
		way++;
        while(sum != n) {
            dfs(sum, n, times, a, way);
        }
        printf("%d\n", way);
	}
	
	return 0;
}