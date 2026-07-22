#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int a[6005];
int mins[6005];
int maxs[6005];

typedef pair<int, int> ip;

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
            mins[i] = a[i];
            maxs[i] = a[i];
        }
        
        int ans = 0;

        vector<int> freq(n + 1, 0);
        vector<ip> valid;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                mins[j] = min(mins[j], a[j - i + 1]);
                maxs[j] = max(maxs[j], a[j - i + 1]);
            }

            valid.clear();
            int j = 1;
            int nonsingle = 0;
            
            
            for(; j <= i; j++){
                freq[a[j]]++; if(freq[a[j]] == 2) nonsingle++;
            }

            if(
                nonsingle == 0 &&
                maxs[i] - mins[i] == i - 1
            ) valid.push_back({i, mins[i]});

            for(; j <= n; j++){
                freq[a[j]]++; if(freq[a[j]] == 2) nonsingle++;

                freq[a[j - i]]--; if(freq[a[j - i]] == 1) nonsingle--;

                if(
                    nonsingle == 0 &&
                    maxs[j] - mins[j] == i - 1
                ) valid.push_back({j, mins[j]});

            }

            fill(freq.begin(), freq.end(), 0);
            
            for(auto el : valid){
                freq[el.second]++;
            }
            
            int secondpoint = 0;
            for(int j = 0; j < valid.size(); j++){
                while(secondpoint < valid.size() && valid[secondpoint].first - valid[j].first < i){
                    freq[valid[secondpoint].second]--;
                    secondpoint++;
                }

                if(valid[j].second + i <= n && freq[valid[j].second + i] > 0)
                    ans = i;

                if(valid[j].second - i >= 1 && freq[valid[j].second - i] > 0)
                    ans = i;
            }

            fill(freq.begin(), freq.end(), 0);

        }

        cout << ans;
        cout << '\n';
    }

    return 0;
}
