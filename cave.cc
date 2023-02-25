#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

#ifdef _WIN32
    #include <windows.h>
    #define msleep(x) Sleep(x)
#else
    #include <unistd.h>
    #define msleep(x) usleep(x * 1000)
#endif

#define LIFE_ 4
#define DEATH_ 3

template<typename T>
std::vector<T> parse_stream(std::istream &stream) {
    std::vector<T> v;
    std::istream_iterator<T> input(stream);
    std::copy(input, std::istream_iterator<T>(), std::back_inserter(v));
    return v;
}

std::vector<std::vector<int>> init_vector() {
    std::ifstream input("file.txt");

    std::vector<int> v = parse_stream<int>(input);

    std::vector< int > tmp(v[1]);
    std::vector<std::vector<int>> vv(v[0]);

    for (int i = 2; i < v.size(); i++) {
        vv[(i-2)/v[0]].push_back(v[i]);
    }
    input.close();
    return vv;
}


int get_size() {
    std::ifstream input("file.txt");
    std::vector<int> vv = parse_stream<int>(input);
    input.close();
    return vv[0];
}

void print_world(std::vector<std::vector<int>> vec) {
     for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            std::cout << vec[i][j] << ' ';
        }
        std::cout << std::endl;
    }
     std::cout << std::endl;
}

int get_live_count(std::vector<std::vector<int>> vv) {
    int count = 0;
    for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            if (vv[i][j] == 1) count++;
        }
    }
    return count;
}

int count_live_neighbors(std::vector<std::vector<int>> vv, int i, int j) {
    int count = 0;
    if (!((i-1) < 0) && !((i-1) > get_size()-1) && !((j-1) < 0) && !((j-1) >get_size()-1)) {
        if (vv[i-1][j-1] == 1) count++;
        }
    if (!(i < 0) && !(i > get_size()-1) && !((j-1) < 0) && !((j-1) >get_size()-1)) {
        if (vv[i][j-1] == 1) count++;
        }
    if (!((i+1) < 0) && !((i+1) > get_size()-1) && !((j-1) < 0) && !((j-1) >get_size()-1)) {
        if (vv[i+1][j-1] == 1) count++;
        }
    if (!((i-1) < 0) && !((i-1) > get_size()-1) && !(j < 0) && !(j >get_size()-1)) {
        if (vv[i-1][j] == 1) count++;
        }
    if (!((i+1) < 0) && !((i+1) > get_size()-1) && !(j < 0) && !(j >get_size()-1)) {
        if (vv[i+1][j] == 1) count++;
        }
    if (!((i-1) < 0) && !((i-1) > get_size()-1) && !((j+1) < 0) && !((j+1) >get_size()-1)) {
        if (vv[i-1][j+1] == 1) count++;
        }
    if (!((i) < 0) && !((i) > get_size()-1) && !((j+1) < 0) && !((j+1) >get_size()-1)) {
        if (vv[i][j+1] == 1) count++;
        }
    if (!((i+1) < 0) && !((i+1) > get_size()-1) && !((j+1) < 0) && !((j+1) >get_size()-1)) {
        if (vv[i+1][j+1] == 1) count++;
    }
    return count;
}



std::vector<std::vector<int>> check_neighbors(std::vector<std::vector<int>> vv) {
     for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            if (vv[i][j] == 1) {
                if (count_live_neighbors(vv, i, j) < DEATH_) {
                    vv[i][j] = 0;
                    }
                 }
            if (vv[i][j] == 0) {
                if (count_live_neighbors(vv, i, j) > LIFE_) {
                    vv[i][j] = 1;
                        }
                    }
                }
            }
     return vv;
}


int main() {
    int count = 0;
    bool is_optimal = false;
    std::vector<std::vector<int>> v1 = init_vector();
    std::vector<std::vector<int>> temp = v1;
    do {
        std::vector<std::vector<int>> v2 = check_neighbors(temp);
        count = get_live_count(v2);
        is_optimal = (temp == v2);
        print_world(v2);
        msleep(500);
    } while(!is_optimal && (count != 0));
return 0;
}
