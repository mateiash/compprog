#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int n;
int p[200'005];

typedef pair<int, int> ip;

vector<ip> links;

void dc(int start, int minbef){
    int pos = start;
    int last = p[pos];

    while(last < p[pos + 1] && pos < n){
        pos++;
    }

    if()

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }

        int maxv = -1;
        int maxind = -1;
        for(int i = 1; i <= n; i++){
            if(p[i] > maxv){
                maxv = p[i];
                maxind = i;
            }
        }

        finish:
        continue;

    }

    return 0;
}
