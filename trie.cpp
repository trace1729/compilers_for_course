#include <iostream>
#include <cassert>
#include <algorithm>
#include "trie.h"
using namespace std;


MyTrie::Node::Node () : isKey(false) {}
MyTrie::Node::Node (bool iskey) : isKey(iskey) {}
MyTrie::Node::~Node() = default;


MyTrie::MyTrie() {
    root = new Node(false);
}

MyTrie::~MyTrie() {
    clear(root);    
}

void MyTrie::clear(Node* nodeptr) {
    if (nodeptr == nullptr) {
        return;
    } 
    
    if (nodeptr->trie_map.size() == 0) {
        delete nodeptr;
    }
    
    for (auto&[k, v]: nodeptr->trie_map) {
        clear(v);
    }
}

void MyTrie::add(string key) {
    if (key.length() < 1) {
        return;
    }

    Node* curr = root;

    for (int i = 0, n = key.length(); i < n; i++) {
        char c = key[i];
        if (curr->trie_map.count(c) < 1) {
            // Node t(false);  allocated in stack, should use new
            curr->trie_map[c] = new Node(false);

        }
        curr = curr->trie_map.find(c)->second;
    }
    curr->isKey = true;
}


bool MyTrie::contains(Node* table, string key) {
    if (key.length() < 1) {
        return table->isKey;
    }
    
    if (table->trie_map.count(key[0]) == 0) {
        return false;
    }

    return contains(table->trie_map[key[0]], key.substr(1));
}

/* 
 * if len(key) < 0:
 *    return true
 * if (!table.contains(key[0])) 
 *    return false;
 * Node* d = table->trie_map[c]
 * return contains(d)
* */
bool MyTrie::contains(string key) {
    return contains(root, key);
}

MyTrie::Node* MyTrie::get(Node* node, string prefix) {
    if (prefix.length() < 1) {
        return node;
    }

    char cur_char = prefix[0];
    for (const auto&[k, v]: node->trie_map) {
        if (k == cur_char) {
            return get(v, prefix.substr(1));
        }
    }
    return nullptr;
}

void MyTrie::keysWithPrefix(Node* node, string word, vector<string>& lst) {
    if (node == nullptr) {
        return;
    }
    
    if (node->isKey) {
        lst.push_back(word);
    }
    
    if (node->trie_map.size() > 0) {
        for (auto&[k, v] : node->trie_map) {
            keysWithPrefix(v, word + k, lst);
        }
    }    
}

vector<string> MyTrie::keysWithPrefix(string prefix) {
    vector<string> lst;
    if (prefix.length() >= 1) {
        auto cur = this->get(root, prefix);
        if (cur != nullptr) {
            keysWithPrefix(cur, prefix, lst);
        }
    }
    return lst;
}

void MyTrie::findLongestPrefix(Node* node, string word, vector<string>& lst) {
    if (node == nullptr || node->isKey)  {
        return;
    }

    if (word.length() >= 1)
        lst.push_back(word);

    for (const auto&[k, v]: node->trie_map) {
        findLongestPrefix(v, word + k, lst);        
    }

}

string MyTrie::findLongestPrefix() {
    vector<string> prefix;
    string longest = "";
    findLongestPrefix(root, "", prefix);
    unordered_map<string, vector<string>> res;
    for (auto p : prefix) {
        res[p] = keysWithPrefix(p); 
    }

    for (auto&[k, v]: res) {
        if (v.size() > 1) {
            if (k.length() > longest.length()) {
                longest = k;
            }
        }
    }
    return longest;
}


void test_add() {
  MyTrie trie;

  // Test adding a single element to the trie
  trie.add("hello");
  assert(trie.contains("hello"));

  // Test adding multiple elements to the trie
  trie.add("world");
  trie.add("foo");
  trie.add("bar");
  assert(trie.contains("world"));
  assert(trie.contains("foo"));
  assert(trie.contains("bar"));
  assert(!trie.contains("w"));
  assert(!trie.contains("ss"));

}

void test_keysWithPrefix() {
    MyTrie trie;
    
    // Add some test keys
    trie.add("apple");
    trie.add("apricot");

    trie.add("banana");
    trie.add("orange");
    trie.add("pear");
    trie.add("peach");
    
    // Test keys with prefix "a"
    vector<string> keys = trie.keysWithPrefix("a");

    assert(keys.size() == 2);
    assert(find(keys.begin(), keys.end(), "apple") != keys.end());
    assert(find(keys.begin(), keys.end(), "apricot") != keys.end());
    
    // Test keys with prefix "ap"
    keys = trie.keysWithPrefix("ap");
    assert(keys.size() == 2);
    assert(find(keys.begin(), keys.end(), "apple") != keys.end());
    assert(find(keys.begin(), keys.end(), "apricot") != keys.end());
    
}


void test_LongestPrefix() {
    MyTrie trie;
    
    // S->[1 abcA] [2 bcA] [3 cA] [4 cabA]
    trie.add("abcA");
    trie.add("bcA");
    trie.add("cA");
    trie.add("cabA");
    cout << "long prefix " << trie.findLongestPrefix() << endl; 

}

// int main()
// {
//   test_add();
//   test_keysWithPrefix();
//   test_LongestPrefix();
//   std::cout << "All tests passed!" << std::endl;
//   return 0;
// }

