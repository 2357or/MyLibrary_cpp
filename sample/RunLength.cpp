#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)

vector<pair<char, int>> RunLength_encode(const string& s) {
    vector<pair<char, int>> res;
    ll len = s.size();
    ll l = 0;
    while(l < len){
        int r = l + 1;
        while(r < len && s[l] == s[r]) r++;
        res.push_back({s[l], r-l});
        l = r;
    }
    return res;
}
string RunLength_decode(const vector<pair<char, int>>& p){
    string res = "";
    for(auto x : p){
        int c = x.first, len = x.second;
        rep(_, 0, len) res += c;
    }
    return res;
}

int main(){
    string s; cin >> s;

    const auto &res1 =  RunLength_encode(s);
    for(auto x : res1) cout << x.first << x.second << ' ';
    cout << endl;

    auto res2 = RunLength_decode(res1);
    cout << res2 << endl;

    return 0;
}

