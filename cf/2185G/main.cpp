#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<int, int> ip;

vector<ip> mexes;
vector<map<int, int>> freqs;

vector<int> spfirst;
vector<int> spsecond;

vector<ip> ogmexes;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        freqs.clear();
        mexes.clear();
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int l; cin >> l;
            map<int, int> freqlocal;
            for(int j = 0; j < l; j++){
                int el; cin >> el;
                freqlocal[el]++;
            }
            freqs.push_back(freqlocal);
        }
        ll sumfirst = 0;
        ll sumsecond = 0;
        for(int i = 0; i < n; i++){
            int foundfirst = 0;
            ip rez = {0, 0};
            for(int j = 0; j <= 1'000'005; j++){
                if(freqs[i][j] == 0){
                    if(!foundfirst){
                        rez.first = j;
                        sumfirst += j;
                        foundfirst = 1;
                    } else {
                        rez.second = j;
                        sumsecond += j;
                        break;
                    }
                }
            }
            mexes.push_back(rez);
        }
        

        ll ans = 0;
        // ts pmo unefficient AF ts shall not fly :wilted_Rose;
        for(int i = 0; i < n; i++){
            for(auto el : freqs[i]){
                // mexes of not arrays concenred
                ll localans = 0;
                localans += (sumfirst - mexes[i].first) * (n - 2);
                localans *= el.second;
                ans += localans;
            }
        }

        //cout << ans << " ans before\n";

        ogmexes = mexes;

        sort(mexes.begin(), mexes.end());

        spfirst.clear();
        spsecond.clear();
        spfirst.push_back(0);
        spsecond.push_back(0);
        /*
        cout << "ogmex\n";
        for(auto el : ogmexes){
            cout << el.first << ' ' << el.second << '\n';
        }
        cout << "sorted mex\n";
        for(auto el : mexes){
            cout << el.first << ' ' << el.second << '\n';
        }
        */
        for(int i = 0; i < n; i++){
            spfirst.push_back(
                spfirst[i] + mexes[i].first
            );
            spsecond.push_back(
                spsecond[i] + mexes[i].second
            );
        }
        /*
        cout << "spfirst\n";
        for(auto el : spfirst){
            cout << el << ' ';
        }cout << '\n';

        cout << "spsecond\n";
        for(auto el : spsecond){
            cout << el << ' ';
        }cout << '\n';
        */
        for(int i = 0; i < n; i++){
            for(auto el : freqs[i]){
                // mexes of arrays concenred
                if(el.second == 0) continue;

                ll homeans = 0;
                int homemex = ogmexes[i].first;
                if(el.first < homemex && el.second == 1){
                    homeans = el.first;
                }else {
                    homeans = homemex;
                } homeans *= el.second * (n - 1);

                //cout << homeans << " homeans\n";

                // now for the other ones :sob:
                ip lbp = {el.first, -1};
                ip ubp = {el.first, 999'999'999};
                int beg = lower_bound(mexes.begin(), mexes.end(), lbp) - mexes.begin() + 1;
                int end = upper_bound(mexes.begin(), mexes.end(), ubp) - 1 - mexes.begin() + 1;
                //cout << beg << ' ' << end << "seq\n";
                ll otherrans = 0;
                if(end - beg + 1 > 0){
                    otherrans += spfirst[beg - 1];
                    otherrans += spfirst[n] - spfirst[end];
                    otherrans += spsecond[end] - spsecond[beg - 1];
                } else {
                    otherrans += spfirst[n];
                }
                otherrans -= ogmexes[i].first;
                otherrans *= el.second;
                //cout << otherrans << "otherrans\n";
                ans += homeans + otherrans;
            }
            //cout << "\nnew array\n";
        }

        cout << ans << '\n';
        // i hate this problem
    }

    return 0;
}
