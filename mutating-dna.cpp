#include <bits/stdc++.h>

using namespace std; 

vector<int> keys = {17, 19, 2, -17, -19, -2}; 
map<int, vector<int>> m; 


int n{}, q{}, x{}, y{};
string a{}, b{}; 

//19 = t -> a
//-2 = a -> c 
//-17 = c -> t;

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
    
    cin >> n >> q; 
    cin >> a >> b;
    
    for(int key: keys)
        m[key].resize(n+1); 
    
    for(int i=0; i<n; i++){
        for(int key: keys)
            m[key][i+1] = m[key][i]; 

        if(a[i] == b[i])
            continue;
        
        m[int(a[i]-b[i])][i+1] += 1;  
    }


    for(int i=0; i<q; i++){
        int ta{}, tc{}, ca{}, ct{}, at{}, ac{}; 
        cin >> x >> y; 

        ta = m[19][y+1] - m[19][x]; 
        at = m[-19][y+1] - m[-19][x]; 
         
        tc = m[17][y+1] - m[17][x]; 
        ct = m[-17][y+1] - m[-17][x];

        ca = m[2][y+1] - m[2][x]; 
        ac = m[-2][y+1] - m[-2][x]; 


        if(!(at - ta == tc-ct && tc-ct == ca-ac)){
            cout << -1 << endl;
            continue; 
        }  

        int result = min(ta, at) + min(tc, ct) + min(ca, ac); 
        result += 2*abs(ta-at); 

        cout << result << endl;
    }    
    

    return 0; 
}
