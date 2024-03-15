#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int>  emailOwner; // email to index of owner

        for (unsigned int i = 0; i < accounts.size(); ++i) {    // traverse through accounts
            _parent.push_back(i);
            _rank.push_back(0);
            
            for (unsigned int j = 1; j < accounts[i].size(); ++j) { // traverse through emails
                if (emailOwner.find(accounts[i][j]) != emailOwner.end()) {
                    int parent1 = find(i);
                    int parent2 = find(emailOwner[accounts[i][j]]);

                    if (parent1 != parent2) {
                        myUnion(parent1, parent2);
                    }
                }
                emailOwner[accounts[i][j]] = i;
            }
        }

        unordered_map<int, vector<string>> accountEmails;
        for (auto& e : emailOwner) {
            accountEmails[find(e.second)].push_back(e.first);
        }

        vector<vector<string>>  results;
        for (auto& ae : accountEmails) {
            std::sort(ae.second.begin(), ae.second.end());
            results.push_back({accounts[ae.first][0]});
            results.back().insert(results.back().end(),ae.second.begin(),ae.second.end());
        }

        return (results);
    }

private:
    vector<int> _parent;
    vector<int> _rank;

    int find(int i_node) {
        while (i_node != _parent[i_node]) {
            // _parent[i_node] = _parent[_parent[i_node]];
            i_node = _parent[i_node];
        }
        return (i_node);
    }

    void    myUnion(int node_0, int node_1) {
        if (_rank[node_0] > _rank[node_1]) {    // if the rank of node_0 is more
            _parent[node_1] = node_0;
            _rank[node_0] += _rank[node_1];
        } 
        else if (_rank[node_1] > _rank[node_0]) {   // if the rank of node_1 is more
            _parent[node_0] = node_1;
            _rank[node_1] += _rank[node_0];
        } 
        else {
            _rank[node_1] += _rank[node_0];
            _parent[node_1] = node_0;
        }
    }
};

int main() {
    Solution s1;
    
    // Recreate this case:
    /*
        [["John","johnsmith@mail.com","john_newyork@mail.com"],
        ["John","johnsmith@mail.com","john00@mail.com"],
        ["Mary","mary@mail.com"],
        ["John","johnnybravo@mail.com"]]
    */
    /*
            [["Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"],
            ["Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"],
            ["Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"],
            ["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"],
            ["Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"]]
    */
    vector<vector<string>>  accounts ({
        {"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},
        {"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},
        {"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},
        {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},
        {"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}
    });

    vector<vector<string>>  results = s1.accountsMerge(accounts);

    for (unsigned int i = 0; i < results.size(); ++i) {
        for (unsigned int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

/*
    class Solution {
    int findId(int id, vector<int>&vid){
        if(vid[id]==id) return id;
        return vid[id]=findId(vid[id],vid);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> umsi;
        vector<int> vid;
        int id=-1;
        for(auto&a:accounts){
            id++;
            vid.push_back(id);
            for(int i=1;i<a.size();i++){
                if(umsi.find(a[i])==umsi.end()){
                    umsi[a[i]]=findId(id,vid);
                }else{
                    vid[findId(id,vid)]=findId(umsi[a[i]],vid);
                }
            }
        }
        unordered_map<int,vector<string>> umis;
        for(auto&e:umsi){
            umis[findId(e.second,vid)].push_back(e.first);
        }
        vector<vector<string>> ret;
        for(auto&e:umis){
            ret.push_back({accounts[e.first][0]});
            sort(e.second.begin(),e.second.end());
            ret.back().insert(ret.back().end(),e.second.begin(),e.second.end());
        }
        return ret;
    }
};
*/