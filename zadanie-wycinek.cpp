#include <bits/stdc++.h>

using namespace std; 

int n{}, x{}, t{}, p{}, len{};
map<int, int> m;  

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    
    m[0] = -1;
    for(int i=0; i<n; i++){
        cin >> x; 
        p += x;
        
        if(m.find(p-t) != m.end())
            len = max(len, i-m[p-t]);
        
        if(m.find(p) == m.end())
            m[p] = i;
    }
    
    if(len == 0)
        cout << "BRAK" << endl; 
    else 
        cout << len << endl; 

    

    return 0; 
}
