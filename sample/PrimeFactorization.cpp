#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll=long long;


// 素因数分解を行う
// 参考[https://qiita.com/drken/items/a14e9af0ca2d857dad23#4-%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3]

// 引数: 素因数分解したい数値
// 戻り値: pairの配列
//  first: 素数, second: 指数
//  ex) 60 -> [{2, 2}, {3, 1}, {5, 1}]
vector<pair<ll, ll>> prime_factorization(ll n){
    vector<pair<ll, ll>> res;

    ll ex = 0;
    while (n%2 == 0) {
        ex++;
        n /= 2;
    }
    if(ex != 0) res.push_back({2, ex});

    for(ll i = 3; i*i <= n; i += 2 ){
        ex = 0;
        while(n%i == 0){
            ex++;
            n /= i;
        }
        if(ex != 0) res.push_back({i, ex});
    }

    if(n != 1) res.push_back({n, 1});
    return res;
}

int main(){
    ll N;
    cin >> N;
    const auto &res = prime_factorization(N);
    cout << N << ":";
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    }
    cout << endl;
}
