#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define mod 1000000007
using namespace std; 

void Factorial(ll fact[], ll n){
    fact[0] = 1;
    for (ll i = 1; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
}
 
ll perm(ll fact[], ll n, ll r){
    if (r > n){
    	return 0;
	}
    ll temp = fact[n] / ((fact[r])*(fact[n - r]));
    return temp;
}

ll count(vector<ll>& arr, ll fact[]){
    ll n = arr.size();
    if (n <= 2) {
        return 1;
    }
    vector<ll> left, right;
    ll root = arr[0];
 
    for (int i = 1; i < n; i++) {
        if (arr[i] < root) {
            left.push_back(arr[i]);
            continue; 
        }
        right.push_back(arr[i]);
    }
    ll sumL = left.size();
    ll countL = count(left , fact), countR = count(right , fact);
    return perm(fact, n - 1, sumL) * countL * countR;
}
 
int main(){
	fastio; 
    ll t; 
    cin >> t; 
    vector<ll> arr(t);
    for(ll i = 0; i < t; i++ ){
    	cin >> arr[i]; 
	}
    ll fact[arr.size()];
    Factorial(fact, arr.size());
	ll ans = count(arr, fact) - 1;
    cout << ans % mod << endl;
 
    return 0;
}

/*
5
3 4 5 1 2
5

3
1 2 3
0

3
2 1 3
1
*/
