#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;
        int points[3];
        points[0] = 1;
        points[1] = 2;
        points[2] = 3;
        int ans = -1;
        
        while(ans != 0){
            cout << "? ";
            for(int i = 0; i < 3; i++){
                cout << points[i] << ' ';
            }
            cout << endl;
            cout.flush();
            cin >> ans;
            if(ans == 0){
                cout << "! ";
                for(int i = 0; i < 3; i++){
                    cout << points[i] << ' ';
                }
                cout << endl;
                break;
            }

            int ind = rand() % 3;
            points[ind] = ans;

        }
        cout.flush();
    }

    return 0;
}
