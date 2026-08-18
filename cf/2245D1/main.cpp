#include <bits/stdc++.h>
#include <queue>

#define ll long long
#define ull unsigned long long

using namespace std;

int cnt[1005][3];
vector<vector<int>> one;
vector<vector<int>> two;

queue<int> onlyone;
queue<int> onlytwo;        

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;

        int m; cin >> m;
        
        one.clear();
        one.resize(n + 1);
        two.clear();
        two.resize(n + 1);
        
        for(int i = 1; i <= m; i++){
            int o, a, b;
            cin >> o >> a >> b;
            //if(a == b) continue;
            if(o == 1){
                one[a].push_back(b);
                one[b].push_back(a);
            } else {
                two[a].push_back(b);
                two[b].push_back(a);    
            }
        }



        onlyone = queue<int>();
        onlytwo = queue<int>();
        
        for(int i = 1; i <= n; i++){
            cnt[i][1] = one[i].size();
            cnt[i][2] = two[i].size();
            if(cnt[i][1] == 0) onlytwo.push(i);
            if(cnt[i][2] == 0) onlyone.push(i);
        }

        //if(onlyone.size()) cout << onlyone.back() << " onlyone\n";
        //if(onlytwo.size()) cout << onlytwo.back() << " onlytwo\n";

        int abs = n;
        vector<int> ans(n + 1);
        while(true){
            if(abs == 0 && onlyone.empty() && onlytwo.empty()){
                cout << "YES\n";
                for(int i = 1; i <= n; i++){
                    cout << ans[i] << ' ';
                }
                cout << '\n';
                goto fini;
            }

            if(onlyone.empty() && onlytwo.empty()){
                cout << "NO\n";
                goto fini;
            }

            if(!onlytwo.empty()){
                int pos = onlytwo.front();
                onlytwo.pop();

                for(auto el : two[pos]){
                    cnt[el][2]--;
                    if(cnt[el][2] == 0 && cnt[el][1] != 0) 
                        onlyone.push(el);
                }

                for(auto el : one[pos]){
                    cnt[el][1]--;
                    if(cnt[el][1] == 0 && cnt[el][2] != 0) 
                        onlytwo.push(el);
                }

                //cout << pos << " done\n";
                ans[pos] = -abs;
                abs--;
            }

            if(!onlyone.empty()){
                int pos = onlyone.front();
                onlyone.pop();

                for(auto el : two[pos]){
                    cnt[el][2]--;
                    if(cnt[el][2] == 0 && cnt[el][1] != 0){
                        onlyone.push(el);
                        //cout << el << " push one\n";
                    }
                }

                for(auto el : one[pos]){
                    cnt[el][1]--;
                    if(cnt[el][1] == 0 && cnt[el][2] != 0){ 
                        onlytwo.push(el);
                        //cout << el << " push two\n";
                    }
                }

                //cout << pos << " done\n";
                ans[pos] = abs;
                abs--;
            }
        }

        fini:
        continue;
    }

    return 0;
}
