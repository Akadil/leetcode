#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (unsigned int i = 0; i < words.size(); ++i) {
            insert(words[i]);
        }

        vector<string>  results;
        ROW = board.size();
        COLUMN = board[0].size();

        for (unsigned int i = 0; i < ROW; ++i) {
            for (unsigned int j = 0; j < COLUMN; ++j) {
                searchWord(board, i, j, "", results, root);
            }
        }
        return (results);
    }

private:
    TrieNode*   root = new TrieNode();
    int         ROW;
    int         COLUMN;

    void    insert(string& str) {
        TrieNode*   curr = root;

        for (unsigned int i = 0; i < str.size(); ++i) {
            if (curr->children[str[i] - 'a'] == nullptr)
                curr->children[str[i] - 'a'] = new TrieNode();
            curr = curr->children[str[i] - 'a'];
        }
        curr->isWord = true;
    }

    void    searchWord(vector<vector<char>>& board, int r, int c, string word, vector<string>& results, TrieNode* node) {
        if (r < 0 || c < 0 || r >= ROW || c >= COLUMN || board[r][c] == '#')
            return;

        char    currChar = board[r][c];

        word += currChar;

        node = node->children[currChar - 'a'];
        if (node == nullptr)
            return;
        else if (node->isWord == true) {
            results.push_back(word);
            node->isWord = false;
        }

        board[r][c] = '#';
        searchWord(board, r + 1, c, word, results, node);
        searchWord(board, r - 1, c, word, results, node);
        searchWord(board, r, c + 1, word, results, node);
        searchWord(board, r, c - 1, word, results, node);
        board[r][c] = currChar;
    }
};

int main(void) {
    Solution    sol;
    vector<vector<char>>    board = {{'o', 'a', 'a', 'n'},
                                     {'a', 't', 'a', 'e'},
                                     {'t', 'h', 'k', 'r'},
                                     {'h', 'f', 'l', 'v'}};
    vector<string>  words = {"oath", "pea", "eat", "rain"};
    vector<string>  results = sol.findWords(board, words);

    for (unsigned int i = 0; i < results.size(); ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    return (0);
}