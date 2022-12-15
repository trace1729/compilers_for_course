#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
using std::string;

class MyTrie {
    
    class Node {

    public:
        using NodePtr=Node*;
        bool isKey;
        unordered_map<char, NodePtr> trie_map;
        Node ();
        Node (bool iskey);
        ~Node();
    };
    Node* root;
    Node* get(Node*node, string prefix);
    void clear(Node* nodeptr);
    bool contains(Node* table, string key);
    void keysWithPrefix(Node* node, string word, vector<string>& lst);
    void findLongestPrefix(Node* node, string word, vector<string>& lst);

public:
    MyTrie ();
    ~MyTrie();
    void add (string key);
    bool contains(string key);
    vector<string> keysWithPrefix(string prefix);
    string findLongestPrefix();
};


#endif
