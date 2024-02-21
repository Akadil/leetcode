#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};

    v1.insert(v1.end(), v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }

    return 0;
}