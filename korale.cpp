#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 

const long long MOD1 = 1e9+9;
const long long MOD2 = 1e9+7;
const int MAXN = 2e5+7;
const int P = 314159; 

vector<int> h1(MAXN), h2(MAXN), h1_rev(MAXN), h2_rev(MAXN);
vector<int> pow_p1(MAXN), pow_p2(MAXN); 
vector<int> k(MAXN), s;

int n{};

pair<int, int> compute_hash(int l, int r){
    //GETTING DATA FROM SUM PREF OF HASHES 
    int hash1 = ((ll)h1[r] - (ll)h1[l-1] + MOD1) % MOD1; 
    int hash2 = ((ll)h2[r] - (ll)h2[l-1] + MOD2) % MOD2; 

    //GETTING EVERYTHING ON THE SAME POWER LVL 
    hash1 = ((ll)hash1 * (ll)pow_p1[n-l+1]) % MOD1; 
    hash2 = ((ll)hash2 * (ll)pow_p2[n-l+1]) % MOD2; 

    return {hash1, hash2}; 
}

pair<int, int> compute_rev_hash(int l, int r){
    //GETTING DATA FROM SUM PREF OF REVERSED HASHES 
    int hash1 = ((ll)h1_rev[l] - (ll)h1_rev[r+1] + MOD1) % MOD1; 
    int hash2 = ((ll)h2_rev[l] - (ll)h2_rev[r+1] + MOD2) % MOD2; 
    
    //GETTING EVERYTHING ON THE SAME POWER LVL 
    hash1 = ((ll)hash1 * (ll)pow_p1[r]) % MOD1; 
    hash2 = ((ll)hash2 * (ll)pow_p2[r]) % MOD2; 

    return {hash1, hash2}; 
}

int get_num_strs(int len){
    set<pair<int, int>> u; //stores hashes 
    int ans{}; //unique strings 
    
    for(int i=1; (i+len-1)<=n; i+=len){
        //GETTING HASHES 
        pair<int, int> my_hash = compute_hash(i, i+len-1);
        pair<int, int> rev_hash = compute_rev_hash(i, i+len-1); 

        //CHECKING IF IS UNIQUE 
        if(u.find(my_hash) == u.end() && u.find(rev_hash) == u.end())
            ans++; 
        u.insert(my_hash);
    } 
    return ans; 
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    //WE COMPUTING POWERS 
    pow_p1[0] = 1, pow_p2[0] = 1; 
    for(int i=1; i<=MAXN; i++){
        pow_p1[i] = ((ll)P * (ll)pow_p1[i-1]) % MOD1; 
        pow_p2[i] = ((ll)P * (ll)pow_p2[i-1]) % MOD2;
    }

    //INPUT DATA
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> k[i];

    //COMPUTING HASHES 
    for(int i=0; i<n; i++){
        h1[i+1] = ((ll)h1[i] + (ll)pow_p1[i] * (ll)k[i]) % MOD1;
        h2[i+1] = ((ll)h2[i] + (ll)pow_p2[i] * (ll)k[i]) % MOD2;
    }
    
    //COMPUTING REVERSED HASHES 
    for(int i=n; i>0; i--){
        h1_rev[i] = ((ll)h1_rev[i+1] + (ll)pow_p1[n-i] * (ll)k[i-1]) % MOD1; 
        h2_rev[i] = ((ll)h2_rev[i+1] + (ll)pow_p2[n-i] * (ll)k[i-1]) % MOD2; 
    }
    
    //LOOKING FOR RESULSTS 
    int ans{}; 
    for(int i=1; i<=n; i++){
        int len = get_num_strs(i); 
        if(ans < len){
            ans = len; 
            s.clear(); 
        }
        if(ans == len)
            s.push_back(i); 
    }

    //OUTPUT 
    cout << ans << ' ' << s.size() << '\n'; 
    for(int i=0; i<s.size(); i++)
        cout << s[i] << ' ';
  
    return 0; 
}
