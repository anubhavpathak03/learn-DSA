#include<bits/stdc++.h>
using namespace std;

void findPermutation(vector<int>& arr, int n, vector<vector<int>>& ans,
                     vector<int>& temp, vector<bool>& visited)
{
    // base case 
    if(temp.size() == n) {
        ans.push_back(temp);
        return;
    }

    // rec case 
    for(size_t i = 0; i< n; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            temp.push_back(arr[i]);
            findPermutation(arr, n, ans, temp, visited);

            visited[i] = 0;
            temp.pop_back();
        }
    }
}
vector<vector<int>> Permut(vector<int> &arr, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(n, 0);

    findPermutation(arr, n, ans, temp, visited);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);

    for(auto &it : arr) {
        cin >> it;
    }

    vector<vector<int>> answer = Permut(arr, n);

    for(auto it : answer) {
        cout << "[";
        for(size_t i = 0; i < it.size(); i++) {
            cout << it[i];
            if(i != it.size()-1) {
                cout << ",";
            }
        }
        cout << "]";
    }
}