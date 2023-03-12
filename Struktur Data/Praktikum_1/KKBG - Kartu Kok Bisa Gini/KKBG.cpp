#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

void solve(ll jumlah_kartu){
	vector<ll> kartu(jumlah_kartu); 
    deque<ll> dq; 
    int i; 
    for (i = 1; i <= jumlah_kartu; i++){
        kartu[i-1] = i ; 
    }

    while(kartu.size() > 1){
        dq.push_back(kartu[0]);
        kartu.erase(kartu.begin()); 
        kartu.push_back(kartu[0]); 
        kartu.erase(kartu.begin()); 
    }
    
    cout << "Discarded cards: "; 
    while(!dq.empty()){
        if(dq.size() == 1){
            cout << dq.front(); 
            dq.pop_front();
            continue;
        }
        cout << dq.front() << ", "; 
        dq.pop_front(); 
    }
    
    cout << endl; 
    cout << "Remaining card: " << kartu[0] << endl; 
}


int main(){
    fastio; 
    ll jumlah_kartu; 
    while(1){
        cin >> jumlah_kartu;
        if (jumlah_kartu <= 0){
        	if (jumlah_kartu < 0){
        		cout << "Mana ada kartu minus!" << endl; 
			}
            break;
        }
        solve(jumlah_kartu);  
    }
    return 0; 
}
