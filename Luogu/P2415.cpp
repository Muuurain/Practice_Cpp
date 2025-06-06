#include <bits/stdc++.h>

using namespace std;

vector<int> intset;

int main() {
    int temp;
    while(cin >> temp) {
        intset.push_back(temp);
    }
    long long sum = 0;
    for(int i = 0; i < intset.size(); i++) {
        sum += pow(2, intset.size() - 1) * intset[i];
    }
    cout << sum << endl;

    return 0;
}