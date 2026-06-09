#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll n;
ll a[100'005];
ll b[100'005];

list<int> helpa;
list<int> helpb;

int possiblegeq(ll igbig){
    helpa.clear(); helpb.clear();
    ll cnts[2] = {0};
    for(int i = 1; i <= n; i++){
        helpa.push_back(igbig <= a[i]);
        cnts[helpa.back()]++;
    }

    for(int i = 1; i <= n; i++){
        helpb.push_back(igbig <= b[i]);
        cnts[helpb.back()]++;
    }

    auto ita = helpa.begin();
    auto itb = helpb.begin();
    
    while(ita != --helpa.end()){
        vector<int> elements;
        elements.push_back(*ita);
        elements.push_back(*itb);
        elements.push_back(*(next(ita)));
        elements.push_back(*(next(itb)));
        sort(elements.begin(), elements.end());

        int remove = true;
        if(elements[0] == 1 && elements[3] == 1){
            remove = false;
        }
        if(elements[0] == 0 && elements[3] == 1 && 
            *next(ita) == 0 && *next(itb) == 0){
            remove = false;
        }

        if(remove){
            cnts[elements[0]]--;
            cnts[elements[3]]--;
            helpa.erase(next(ita));
            helpb.erase(next(itb));

            *ita = elements[1];
            *itb = elements[2];
        }

        fini:
        ita++;
        itb++;

        if(remove){
            ita--;
            itb--;
            if(ita != helpa.begin()){
                ita--;
                itb--;
            }
        }

    }

    return cnts[1] > cnts[0];
}

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        
        cin >> n;
        ll minv = 999'999'999'999;
        ll maxv = -1;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            minv = min(minv, a[i]);
            maxv = max(maxv, a[i]);
        }

        for(int i = 1; i <= n; i++){
            cin >> b[i];
            minv = min(minv, b[i]);
            maxv = max(maxv, b[i]);
        }

        ll l = minv; ll r = maxv;

        while(r - l > 3){
            ll mid = (l + r)/2;
            if(possiblegeq(mid)){
                l = mid;
            } else {
                r = mid - 1;
            }

        }

        ll last = -1;
        for(int i = l; i <= r; i++){
            if(possiblegeq(i)) last = i;
        }
        cout << last << '\n';

    }

    return 0;
}
