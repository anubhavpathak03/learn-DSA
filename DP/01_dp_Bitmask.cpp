#include<bits/stdc++.h>
using namespace std;

int noOfSetBits(int m) 
{
    int ans = 0;
    while(m>0) {
        ans++;
        m &= (m-1);
    }
    return ans;
}

int main() {
    int n; cin >> n;

    vector<vector<int>> rew(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> rew[i][j];
        }
    }

    vector<int> dp(1<<n);

    for(int m=1; m<(1<<n); m++) {
        // trying to find dp[m]
        // mask = 00101101
        // subset =  {0, 2, 3, 5} if no. of set bits are 4 so position is 4-1 =3 [0, 1, 2, 3]
        int indx = noOfSetBits(m)-1;
        for(int i=0; i<n; i++) {
            if(((m>>i)&1) > 0) {
                int curRew = rew[i][indx];
                int furtherRew = dp[m ^ (1<<i)];
                dp[m] = max(dp[m], curRew + furtherRew);
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}