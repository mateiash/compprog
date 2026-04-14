#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int msleft[500'005];
int msright[500'005];

int a[500'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
           cin >> a[i];
           msleft[i] = 0;
           msright[i] = 0;
        }

        stack<int> ms;
        for(int i = 1; i <= n; i++){
            while(!ms.empty() && a[ms.top()] < a[i]){
                msright[ms.top()] = i;
                ms.pop();
            }
            ms.push(i);
        }

        while(!ms.empty()) ms.pop();
        
        for(int i = n; i >= 1; i--){
            while(!ms.empty() && a[ms.top()] < a[i]){
                msleft[ms.top()] = i;
                ms.pop();
            }
            ms.push(i);
        }
        
        
    }

    return 0;
}
