#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

template<typename T>
std::vector<T> parse_stream(std::istream &stream) {
    std::vector<T> v;
    std::istream_iterator<T> input(stream);
    std::copy(input, std::istream_iterator<T>(), std::back_inserter(v));
    return v;
}

int main(int argc, char* argv[]) {
    std::ifstream input("file.txt");
    std::vector<int> v = parse_stream<int>(input);
//    using Iter = std::vector<int>::const_iterator;
//    for(Iter item = v.begin() + 2; item != v.end() - 100; item++) {
    for (int item = 2; item < v.size() - 100; item++) {
        if (v[item] == 1) {
            std::cout << '|';
        } else {
            std::cout << " ";
        }
        if (!(item % 11)) {
            std::cout << std::endl;
        }
    }
    return 0;
}