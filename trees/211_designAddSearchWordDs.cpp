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


class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
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

        return (searchTrieNode(root, word, 0));
    }

private:
    TrieNode*   root = new TrieNode();

    bool    searchTrieNode(TrieNode* curr, string& word, int index) {
        if (curr == nullptr)
            return (false);
        if (index == word.size())
            return (curr->isWord);

        if (word[index] != '.') {
            curr = curr->children[word[index] - 'a'];
            return (searchTrieNode(curr, word, index + 1));
        }
        for (unsigned int j = 0; j < 26; ++j) {
            if (searchTrieNode(curr->children[j], word, index + 1))
                return (true);
        }
        return (false);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */