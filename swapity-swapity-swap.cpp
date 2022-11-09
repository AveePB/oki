#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 10007; 

vector<int> rot, q(MAXN), w(MAXN);
vector<bool> checked(MAXN);

int n{}, m{}, k{}, l{}, r{};

int main(){
    //ifstream in("swap.in"); 
    //ofstream out("swap.out");

    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n >> m >> k; 

    for(int i=1; i<=n; i++)
        q[i] = i;

    for(int i=0; i<m; i++){
        cin >> l >> r;
        reverse((q.begin()+l), (q.begin()+r+1));
    }

    for(int i=1; i<=n; i++){
        if(checked[i])
            continue;
        int curr_i = i; 

        while(!checked[curr_i]){
            rot.push_back(q[curr_i]); 
            checked[curr_i] = true; 
            curr_i = q[curr_i]; 
        }

        for(int j=0; j<rot.size(); j++){
            int q_pos = rot[j]; 
            int shift = k % rot.size(); 
            int val = rot[(j+shift)%rot.size()]; 
            w[q_pos] = val;             
        }
        rot.clear();
    }

    
    for(int i=1; i<=n; i++)
        cout << w[i] << endl; 
    
    return 0; 
}
