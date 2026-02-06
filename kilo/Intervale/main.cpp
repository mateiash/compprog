#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int aib[200'005];

int lsb(int x){
    return x & (-x);
}

void update(int ind, int val){
    while(ind <= 200'000){
        aib[ind] += val;
        ind += lsb(ind);
    }
}

int query(int ind){
    int rez = 0;
    while(ind){
        rez += aib[ind];
        ind -= lsb(ind);
    }
    return rez;
}

int a[200'005];
int dones[200'005];


int respond(int ind){
    int times = query(ind) - dones[ind];
    dones[ind] += times;
    int rez = a[ind];
    while(times){
        rez = sqrt(rez);
        times--;
        if(rez <= 1){
            break;
        }
    }
    a[ind] = rez;
    return rez;
}

int main(){
    int N, Q;
    cin >> N >> Q;

    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= Q; i++){
        int typeo; cin >> typeo;
        if(typeo == 1){
            int l, r; cin >> l >> r;
            update(l, 1);
            update(r + 1, -1);
        }
        if(typeo == 2){
            int ind; cin >> ind;
            cout << respond(ind) << '\n';
        }
    }


    return 0;
}