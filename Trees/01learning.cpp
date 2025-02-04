#include<bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        left = NULL;
        right = NULL;
    }

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

};

// void solve() {}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    TreeNode* ptr = new TreeNode(5);
    TreeNode node(10);
    cout << ptr->data << '\n';
    cout << node.data << '\n';
}