#include <bits/stdc++.h>

using namespace std; 

const int N = 100000+7; 

vector<vector<int>> v(3, vector<int>(N)); 

int n{}, q{}, l{}, r{}, cow{}; 

int main(){
    //ifstream in("bcount.in");
    //ofstream out("bcount.out");

    cin >> n >> q; 

    for(int i=1; i<=n; i++){
        cin >> cow; 

        v[cow-1][i] = 1;  

        for(int j=0; j<3; j++)
            v[j][i] += v[j][i-1];  
    }

    while(q--){
        cin >> l >> r; 
        
        cout << v[0][r] - v[0][l-1] << " ";
        cout << v[1][r] - v[1][l-1] << " ";
        cout << v[2][r] - v[2][l-1] << endl;
    }
   

    return 0; 
}
