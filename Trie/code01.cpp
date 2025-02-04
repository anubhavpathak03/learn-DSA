#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    vector<TrieNode*> children;
    // map<char, TrieNode*> mp
    bool flag = false;

    TrieNode() {
        children.resize(26, NULL);
    }
};

class Trie {
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->children[word[i]-'a']) {
                node = node->children[word[i]-'a'];
            }
            else {
                node->children[word[i]-'a'] = new TrieNode;
                node = node->children[word[i] - 'a'];
            }
        }
        node->flag = true;
    }   

    bool search(string word) {
        TrieNode *node = root;
        for(int i=0;i<word.size(); i++) {
            if(node->children[word[i]-'a']) {
                node = node->children[word[i]-'a'];
            }else {
                return false;
            }
        }
        return node->flag;
    }
};


int main() {
    Trie t;
    t.insert("hello");
    t.insert("car");
    t.insert("java");
    t.insert("learn");
    t.insert("learnYard");
    t.insert("JavaScript");
    t.insert("cars");
    t.insert("home");
    t.insert("table");
    t.insert("carpet");


    cout << t.search("hello") << endl;
    cout << t.search("hell") << endl;
    cout << t.search("cars") << endl;
    cout << t.search("car") << endl;
    return 0;
}