#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

typedef pair<ll, string> pi;

int main(){
    fastio; 
    int t, n; 
    cin >> t >> n; 
    priority_queue<pi, vector<pi>, greater<pi> > data;
    while(t--){
        string pacar;
        char tanggal[5], bulan[5]; 
        cin >> pacar >> tanggal >> bulan;
        int bln = atoi(bulan); 
        if (bln == 1 || bln == 1 ||bln == 3 || bln == 5 || bln == 7 ||bln == 8 ||bln == 10 ||bln == 12 ){
            bln *= 31; 
        }
        else if(bln == 2){
            bln *= 29; 
        } 
        else {
            bln *= 30;
        }
        int jumlah_hari= atoi(tanggal) + bln; 
        data.push(make_pair(jumlah_hari, pacar)); 
    }
    while(n--){
        data.pop(); 
    }

    if(data.size() <= 0){
        cout << "Miko TOP G" << endl;  
        return 0; 
    }
    pi temp = data.top(); 
    cout << "Waifu selanjutnya adalah " << temp.second << " chan"  << endl; 
    
    return 0; 
}
