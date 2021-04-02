#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define ALL(x) x.begin(),x.end()

template<class T, class U>
bool compare_by_second(const pair<T,U>& A, const pair<T,U>& B){
    if(A.second != B.second) return A.second < B.second;
    else return A.first < B.first;
}

int main(){
    int n; cin >> n;
    vector<pair<int, string>> p(n);
    rep(i, 0, n){
        int f; string s; cin >> f >> s;
        p[i].first = f;
        p[i].second = s;
    }
    sort(ALL(p), compare_by_second<int, string>);
    for(auto x : p){
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}

