#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;

        list<int> a;
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            a.push_front(el);
        }

        set<int> after;

        for(auto it = a.begin(); it != prev(a.end()); it++){
            
        }


    }

    return 0;
}
