#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef unsigned int u_int;

u_int lsb(u_int x){
    return (x) & (-x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        u_int a, b;
        cin >> a >> b;

        u_int initoffset = a & b;

        if(initoffset == 0){
            cout << a << ' ' << b << '\n';
            continue;
        }

        u_int possiblecoorrection = (~a) & (~b);

        //cout << initoffset << ' ' << possiblecoorrection << '\n';

        // op 1 luam bitii mai mici
        u_int mask = (u_int) (1 << (u_int)log2(initoffset)) - 1;
        mask <<= 1;
        mask += 1;
        u_int mincor = possiblecoorrection & mask;

        u_int distmin = 
            initoffset - mincor;

        // op 2 luam bitul mai mare 

        possiblecoorrection = possiblecoorrection & (~mask);
        u_int majcor = lsb(possiblecoorrection);
        //cout << mincor << ' ' << majcor << '\n';
        
        u_int distmaj = min(
            ((a) & (~(majcor*2-1))) + majcor - a,
            ((b) & (~(majcor*2-1))) + majcor - b

        );

        //cout << distmin << ' ' << distmaj << "dist\n";
        //cout << mask << " mask\n";
        //cout << majcor << " majcor\n";
        //cout << ((a) & (~(majcor*2-1))) + majcor << '\n';
        if(distmin < distmaj){
            // a mers op 1
            cout << a - initoffset + mincor << ' ' << b << '\n';
        } else {
            // a mers op 2
            if(
                ( ((a) & (~(majcor*2-1))) + majcor - a) < ( ((b) & (~(majcor*2-1))) + majcor - b)
            ) {
                cout << ( ((a) &(~(majcor*2-1))) + majcor) << ' ' << b << '\n';

            } else {
                cout << ((a)) << ' ' << ( ((b) & (~(majcor*2-1))) + majcor) << "\n";

            }
        }
        
        cout << '\n';
    }

    return 0;
}
