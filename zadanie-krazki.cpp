#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 3e5 + 7; 

int n{}, m{}, p{}, curr_n{}; 
vector<int> v(MAXN);

void throw_p(){
    for(int i=curr_n-1; i>0; i--){
        if(v[i] >= p){
            curr_n = i; 
            return; 
        }
    }
    curr_n = 0; 
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
    v[0] = INT_MAX;

    cin >> n >> m; 
    curr_n = n+1;

    for(int i=1; i<=n; i++){
        cin >> v[i]; 
        v[i] = min(v[i-1], v[i]); 
    }

    for(int i=0; i<m; i++){
        cin >> p;
        throw_p();    
    }
    cout << curr_n << endl; 

    return 0; 
}
