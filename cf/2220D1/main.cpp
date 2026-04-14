#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;
vector<int> cand;

void cquery(int begin, int end){
    //cout << "? ";
    //cout << end - begin << ' ';
    for(int i = begin; i < end; i++){
        cout << cand[i] << ' ';
    }
    //cout << '\n';
    cout.flush();
}

int main(){

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        cand.clear();

        for(int i = 1; i <= 2*n + 1; i++){
            cand.push_back(i);
        }

        while(cand.size() > 3){
            /*
            cout << "viable: ";
            cquery(0, cand.size());
            cout << '\n';
            cout.flush();
            */
            int s1 = 0;
            int s2 = cand.size()/4 + s1;
            int s3 = cand.size()/4 + s2;
            int s4 = cand.size()/4 + s3;
            int s5 = cand.size();
            int len;
            int r;

            // exclud 1
            {
            cout << "? ";
            len = (s5) - (s2 - s1);
            cout << len << ' ';

            cquery(s2, s5);
            cout << '\n';
            cout.flush();
            cin >> r;

            if(r % 2 != len % 2){
                cand.erase(cand.begin() + s1, cand.begin() + s2);
                continue;
            }
            }

            // exclud 2
            {
            cout << "? ";
            len = (s5) - (s3 - s2);
            cout << len << ' ';

            cquery(s1, s2);
            cquery(s3, s5);
            cout << '\n';
            cout.flush();
            cin >> r;

            if(r % 2 != len % 2){
                cand.erase(cand.begin() + s2, cand.begin() + s3);
                continue;
            }
            }

            // exclud 3
            {
            cout << "? ";
            len = (s5) - (s4 - s3);
            cout << len << ' ';

            cquery(s1, s3);
            cquery(s4, s5);
            cout << '\n';
            cout.flush();
            cin >> r;

            if(r % 2 != len % 2){
                cand.erase(cand.begin() + s3, cand.begin() + s4);
                continue;
            }
            }

            cand.erase(cand.begin() + s4, cand.begin() + s5);

        }

        cout << "! ";
        cquery(0, cand.size());
        cout << '\n';
        cout.flush();

    }

    return 0;
}
