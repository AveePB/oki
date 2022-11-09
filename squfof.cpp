#include <bits/stdc++.h>

using namespace std; 

bool is_left(long long n, int m, int mid);
long long bin_search(long long n, int m);

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    long long n{}; 
    int T{}, m{};
    cin >> T; 

    while(T--){
        cin >> n >> m;
        cout << bin_search(n, m) << '\n';
    }

    return 0; 
}
bool is_left(long long n, int m, int mid){
    long long help = 1; 
    for(int i=1; i<=m; i++){
        if(n/mid < help)
            return true;
        help *= mid; 
    }
    return false; 
}

long long bin_search(long long n, int m){
    long long l=1, r=n+1;
    while(r-l > 1){
        long long mid = (r+l)/2; 
        if(is_left(n, m, mid))
            r = mid; 
        else 
            l = mid;
    } 
    return l;
}
