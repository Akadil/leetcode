#include <iostream>
#include <unordered_map>

int main(void) {
    std::unordered_map<int, int> map;

    map[1] = 1;

    std::cout << "map[1]: " << map[1] << std::endl;
    std::cout << "map[2]: " << map[2] << std::endl;

    return (0);
}