#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> v1 = {{}};

    for (unsigned int i = 0; i < v1.size(); i++) {
        for (unsigned int j = 0; j < v1[i].size(); j++) {
            cout << v1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "v1.size() = " << v1.size() << endl;

    return 0;
}