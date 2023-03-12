#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

int main(){
    fastio; 
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> va, vb, vc;
	ll ans1 = 0, ans2 = 0, ans3 = 0;
    while(a--) {
        ll numb;
        cin >> numb;
        va.push_back(numb); 
        ans1 += numb;
    }
    while(b--) {
        ll numb; 
        cin >> numb;
        vb.push_back(numb); 
        ans2 += numb;
    }
    while(c--){
        ll numb; 
        cin >> numb;
        vc.push_back(numb);
        ans3 += numb;
    }
    ll maks = 0;
    while (va.size() > 0 && vb.size() > 0 && vc.size() > 0) {
        if (ans1 == ans2 && ans2 == ans3) {
            maks = ans1;
            break;
        }
        ll max_sum = max(ans1, max(ans2, ans3));
        if (max_sum == ans1) {
        	ll temp = va[0]; 
            ans1 -= temp;
            va.erase(va.begin()); 
            continue;
        }
        if (max_sum == ans2) {
        	ll temp = vb[0]; 
         	ans2 -= temp;
            vb.erase(vb.begin());
            continue; 
        }
        ll temp = vc[0]; 
        ans3 -= temp;
        vc.erase(vc.begin());
    }
    cout << maks << endl;
    return 0;
}







