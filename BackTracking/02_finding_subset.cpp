#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;  // lexographically
    }
    return a.length() < b.length();
}

void findSubsets(char *input, char *output, int i, int j, vector<string> &v)
{
    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        string temp(output); // char array to string conversion so that we pass in vector as string
        v.push_back(temp);
        return;
    }
    // rec case
    // Include the ith letter
    output[j] = input[i];
    findSubsets(input, output, i+1, j+1, v);
    // exclude the ith letter
    findSubsets(input, output, i+1, j, v);
}

int main() {
    char input[100];
    char output[100];

    vector<string> list;
    
    cout << "Enter the input:-> ";
    cin >> input;
    cout << '\n';

    findSubsets(input, output, 0, 0, list);
    sort(list.begin(), list.end(), compare);


    for(auto s:list) {
        cout << s << ", ";
    }
}