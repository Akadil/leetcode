#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode*   children[26];
    bool        isWord;

    TrieNode(){
        for (unsigned int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode*   curr = root;

        for (unsigned int i = 0; i < word.size(); ++i) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode*   curr = root;

        for (unsigned int i = 0; i < word.size(); ++i) {
            if (curr->children[word[i] - 'a'] == nullptr)
                return (false);
            curr = curr->children[word[i] - 'a'];
        }
        return (curr->isWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode*   curr = root;

        for (unsigned int i = 0; i < prefix.size(); ++i) {
            if (curr->children[prefix[i] - 'a'] == nullptr)
                return (false);
            curr = curr->children[prefix[i] - 'a'];
        }
        return (true);
    }

private:
    TrieNode*   root = new TrieNode();
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */