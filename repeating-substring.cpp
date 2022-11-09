#include <bits/stdc++.h>

using namespace std; 

const long long MOD1 = 1e9 + 9; 
const long long MOD2 = 1e9 + 7; 
const long long P1 = 59; 
const long long P2 = 47;
const int MAXN = 1e5+7;

vector<long long> pow_p1(MAXN), pow_p2(MAXN), 
hash1(MAXN), hash2(MAXN);  

string s{};
int n{}; 

pair<long long, long long> get_hash(int l, int r);
bool check(int len);

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> s;
    
    n = int(s.length());
    pow_p1[0] = 1; 
    pow_p2[0] = 1; 

    for(int i=1; i<=n; i++){
        pow_p1[i] = (pow_p1[i-1] * P1) % MOD1; 
        pow_p2[i] = (pow_p2[i-1] * P2) % MOD2; 
    }

    for(int i=1; i<=n; i++){
        hash1[i] = (hash1[i-1] + s[i-1] * pow_p1[i-1]) % MOD1;    
        hash2[i] = (hash2[i-1] + s[i-1] * pow_p2[i-1]) % MOD2; 
    }
    
    int l=0, r=n; 
    while(r-l > 1){
        int mid = (l+r)/2;
        if(check(mid))
            l = mid;
        else 
            r = mid;
    }
        
    if(l == 0)
        cout << -1 << '\n';  
    else
        cout << l << '\n';
    

    return 0; 
}

pair<long long, long long> get_hash(int l, int r){
    long long h1 = ((hash1[r] - hash1[l-1]) + MOD1) % MOD1; 
    long long h2 = ((hash2[r] - hash2[l-1]) + MOD2) % MOD2;
    
    h1 = (h1 * pow_p1[n-l]) % MOD1;
    h2 = (h2 * pow_p2[n-l]) % MOD2; 
    
    return {h1, h2}; 
}

bool check(int len){
    set<pair<long long, long long>> unique_hashes; 
    for(int r_idx=len; r_idx<=n; r_idx++){
        int l_idx = r_idx-len+1;
        pair<long long, long long> double_hash = get_hash(l_idx, r_idx);
        
        if(unique_hashes.find(double_hash) == unique_hashes.end())
            unique_hashes.insert(double_hash); 
        else 
            return 1; 
    }

    return 0; 
}
