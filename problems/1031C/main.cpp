#include <bits/stdc++.h>

#define int long long

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int,int,int> tp;
typedef vector<tp> vtp;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int MAX = 1e8 + 5;
const int NONE = 0;

void solve(){
    int a,b;
    cin >> a >> b;
    int maximo = ((-1 + sqrt(1 + 8 * (a + b)))/2);
    vi la;
    vi lb;
    for(int i = 1; i <= maximo; i++) lb.push_back(i);

    for(int i=maximo; i>=1; i--){
        if(a==0) break;
        int agr = min(a, i);
        a-=agr;
        la.push_back(agr);
        lb.erase(remove(lb.begin(), lb.end(), agr), lb.end());
    }
    cout << la.size() << endl;
    for(int i = 0; i < la.size(); i++){
        cout << la[i] << " ";
    }
    cout << endl;
    cout << lb.size() << endl;
    for(int i = 0; i < lb.size(); i++){
        cout << lb[i] << " ";
    }
    cout << endl;

}

signed main(){
	fastInp;
 
	int t = 1;
	//cin >> t;

	while(t--){
	    solve();
    }  

}
