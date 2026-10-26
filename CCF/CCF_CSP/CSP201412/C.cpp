// template_pre_standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template <typename T>
void debug_impl(const T& val) {
    cout << val;
}
template <typename T>
void debug_impl(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << ", ";
        debug_impl(vec[i]);
    }
    cout << "]";
}
#define debug(x) do { \
    cout << "debug(" << #x << "): "; \
    debug_impl(x); \
    cout << '\n'; \
} while(0)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string S;
    map<ll, ll> buy, sell;
    vector<pair<int, pair<ll, ll> > > record;
    record.push_back({-1, {-1, -1}});
    vector<ll> price;
    ll sumbuy = 0, sumsell = 0;
    vector<bool> ba(5010);
    while(cin >> S) {
        if(S == "buy") {
            double tp;
            ll s;
            cin >> tp >> s;
            ll p = (tp + 0.005) * 100;
            buy[p] += s;
            sumbuy += s;
            record.push_back({1, {p, s}});
        }
        else if(S == "sell") {
            double tp;
            ll s;
            cin >> tp >> s;
            ll p = (tp + 0.005) * 100;
            sell[p] += s;
            record.push_back({2, {p, s}});
        }
        else {
            int i;
            cin >> i;
            record.push_back({3, {0, i}});
            if(record[i].first == 1) {
                if(!ba[i]) {
                    buy[record[i].second.first] -= record[i].second.second;
                    sumbuy -= record[i].second.second;
                    ba[i] = true;
                }
            }
            else if(record[i].first == 2) {
                if(!ba[i]) {
                    sell[record[i].second.first] -= record[i].second.second;
                    ba[i] = true;
                }
            }
            // 改动 1：删掉 record[i].first == 3 的分支，不允许撤销 cancel 指令
        }
    }

    // 改动 2：只将未被撤销的有效 buy/sell 订单价格加入 price
    for(size_t i = 1; i < record.size(); i++) {
        if((record[i].first == 1 || record[i].first == 2) && !ba[i]) {
            price.push_back(record[i].second.first);
        }
    }

    if(price.empty()) {
        cout << "0.00 0";
        return 0;
    }

    sort(price.begin(), price.end());
    price.resize(unique(price.begin(), price.end()) - price.begin());
    sumsell = sell[price[0]];
    ll ansnum = min(sumbuy, sumsell);
    ll anspri = price[0];
    for(size_t i = 1; i < price.size(); i++) {
        sumbuy -= buy[price[i - 1]];
        sumsell += sell[price[i]];
        if(ansnum <= min(sumbuy, sumsell)) {
            ansnum = min(sumbuy, sumsell);
            anspri = price[i];
        }
    }
    cout << anspri / 100 << ".";
    if(anspri % 100 < 10) cout << 0;
    cout << anspri % 100;
    cout << " " << ansnum;

    return 0;
}