#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    vector<int> v1 = {1, 2, 3, 4, 5};

    for (unsigned int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    return 0;
}