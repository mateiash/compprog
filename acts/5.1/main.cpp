#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<vector<int>> adjA;
vector<int> to;
vector<bool> usedA;
vector<bool> usedB;

bool gateste(int v){
    if(usedA[v]) return false;
    usedA[v] = true;
    for(auto el : adjA[v]){
        if(to[el] == 0 || gateste(to[el])){
            to[el] = v;
            return true;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;

    while(n != 0){
        

        cin >> n;
    }
       
    return 0;
}