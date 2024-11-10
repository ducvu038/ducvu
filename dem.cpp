#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

int n, m, s;
vector<vector<int>> a;
vector<int> t;
map<int, int> dem;
map<int, int> check;

int main(){
    cin>>n>>m>>s;
    a.resize(n, vector<int>(m));
    t.resize(s);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            dem[a[i][j]]++;
        }
    }
    for(int i=0;i<s;i++){
       cin>>t[i];
        check[t[i]]++;
    }
    for(auto x:check){
        if(x.first<=n){
            for(int i=0;i<m;i++){
                dem[a[x.first-1][i]]--;
                a[x.first-1][i]+=1*(x.second%3);
                a[x.first-1][i]%=3;
                dem[a[x.first-1][i]]++;
            }
        }
        if(x.first>n){
            for(int i=0;i<n;i++){
                dem[a[i][x.first-n-1]]--;
                a[i][x.first-n-1]+=1*(x.second%3);
                a[i][x.first-n-1]%=3;
                dem[a[i][x.first-n-1]]++;
            }

        }
    }
    cout<<dem[0];
}



