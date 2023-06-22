#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb(x) push_back(x)
#define pb2(x, y) push_back(x, y)
using namespace std;

map<string, bool> print;
map<string, string> s;
map<string, vector<vector<string> > > out;

int main(){
    int n, q;
    cin >> n >> q;
    cin.ignore();

    for(int i = 0; i < n; i++){
        string ip, nama;
        cin >> ip >> nama;
        s[ip] = nama;
    }

    cin.ignore();
    
    while (q--){
        string a, b, c;
        cin >> a >> b;
        cin.ignore();
        getline(cin, c);
        map<string, string>::iterator tofound = s.find(b), fromfound = s.find(a);
        if (tofound != s.end() && fromfound != s.end()){
            print[b] = true;
            out[b].pb2({a, c});
        }
    }

    for (map<string, bool>::iterator i = print.begin(); i != print.end(); ++i){
        map<string, vector<string>> s1;
        puts("===========");
        cout << "Mail: " << s[i->first] << endl;
        for (vector<vector<string> >::iterator j = out[i->first].begin(); j != out[i->first].end(); ++j){
            s1[(*j).front()].pb((*j).back());
        }

        for (map<string, vector<string> >::iterator j = s1.begin(); j != s1.end(); ++j){
            cout << "From: " << s[j->first] << endl;
            for (vector<string>::iterator k = j->second.begin(); k != j->second.end(); ++k){
                cout << ">> " << *k << endl;
            }
        }
    }

    return 0;
}
