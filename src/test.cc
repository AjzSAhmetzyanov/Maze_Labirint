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
    std::cout << ' ';
    for (int j = 0; j < v[0]; j++) {
        std::cout << '_';
    }
    std::cout <<std::endl << '|';
    for (int i = 2, j = (v[0]*v[0])+2; j < v.size(); i++, j++) {
        if (v[i] == 1) {
            std::cout << '|';
        } else if (v[j] == 1) {
            std::cout << '_';
        } else if (v[i] != 1 || v[j] != 1){
            std::cout << ' ';
        }
        if (!((i-1) % v[0])) {
            std::cout << std::endl;
            if (j != v.size()-1)
                std::cout << '|';
        }
    }
    return 0;
}