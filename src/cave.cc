//#include <iterator>
//#include <algorithm>
//#include <vector>
//#include <iostream>
//#include <fstream>
//
//#ifdef _WIN32
//    #include <windows.h>
//    #define msleep(x) Sleep(x)
//#else
//    #include <unistd.h>
//    #define msleep(x) usleep(x * 1000)
//#endif
//
//#define LIFE_ 4
//#define DEATH_ 3
//
//template<typename T>
//std::vector<T> parse_stream(std::istream &stream) {
//    std::vector<T> v;
//    std::istream_iterator<T> input(stream);
//    std::copy(input, std::istream_iterator<T>(), std::back_inserter(v));
//    return v;
//}
//
//std::vector<std::vector<int>> init_world() {
//    std::ifstream input("file.txt");
//
//    std::vector<int> v = parse_stream<int>(input);
//
//    std::vector< int > tmp(v[1]);
//    std::vector<std::vector<int>> vv(v[0]);
//
//    for (int i = 2; i < v.size(); i++) {
//        vv[(i-2)/v[0]].push_back(v[i]);
//    }
//    input.close();
//    return vv;
//}
//
//
//int get_size() {
//    std::ifstream input("file.txt");
//    std::vector<int> vv = parse_stream<int>(input);
//    input.close();
//    return vv[0];
//}
//
//void print_world(std::vector<std::vector<int>> vec) {
//     for (int i = 0; i < get_size(); i++) {
//        for (int j = 0; j < get_size(); j++) {
//            std::cout << vec[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }
//     std::cout << std::endl;
//}
//
//int get_live_count(std::vector<std::vector<int>> vv) {
//    int count = 0;
//    for (int i = 0; i < get_size(); i++) {
//        for (int j = 0; j < get_size(); j++) {
//            if (vv[i][j] == 1) count++;
//        }
//    }
//    return count;
//}
//
//int count_live_neighbors(std::vector<std::vector<int>> vv, int i, int j) {
//    int count = 0;
//    if ((i - 1) >= 0 && (i - 1) <= get_size() - 1 && (j - 1) >= 0 && (j - 1) <= get_size() - 1) {
//        if (vv[i-1][j-1] == 1) count++;
//        }
//    if (i >= 0 && i <= get_size() - 1 && (j - 1) >= 0 && (j - 1) <= get_size() - 1) {
//        if (vv[i][j-1] == 1) count++;
//        }
//    if ((i + 1) >= 0 && (i + 1) <= get_size() - 1 && (j - 1) >= 0 && (j - 1) <= get_size() - 1) {
//        if (vv[i+1][j-1] == 1) count++;
//        }
//    if ((i - 1) >= 0 && (i - 1) <= get_size() - 1 && j >= 0 && j <= get_size() - 1) {
//        if (vv[i-1][j] == 1) count++;
//        }
//    if ((i + 1) >= 0 && (i + 1) <= get_size() - 1 && j >= 0 && j <= get_size() - 1) {
//        if (vv[i+1][j] == 1) count++;
//        }
//    if ((i - 1) >= 0 && (i - 1) <= get_size() - 1 && (j + 1) >= 0 && (j + 1) <= get_size() - 1) {
//        if (vv[i-1][j+1] == 1) count++;
//        }
//    if ((i) >= 0 && (i) <= get_size() - 1 && (j + 1) >= 0 && (j + 1) <= get_size() - 1) {
//        if (vv[i][j+1] == 1) count++;
//        }
//    if ((i + 1) >= 0 && (i + 1) <= get_size() - 1 && (j + 1) >= 0 && (j + 1) <= get_size() - 1) {
//        if (vv[i+1][j+1] == 1) count++;
//    }
//    return count;
//}
//
//
//
//void next_generation(std::vector<std::vector<int>> &v1, std::vector<std::vector<int>> &v2) {
//     for (int i = 0; i < get_size(); i++) {
//        for (int j = 0; j < get_size(); j++) {
//            if (v1[i][j] == 1) {
//                if (count_live_neighbors(v1, i, j) < DEATH_) {
//                    v2[i][j] = 0;
//                    } else {
//                    v2[i][j] = 1;
//                }
//                 } else {
//                    if (count_live_neighbors(v1, i, j) > LIFE_) {
//                    v2[i][j] = 1;
//                        } else {
//                        v2[i][j] = 0;
//                    }
//                }
//            }
//        }
//}
//
//int main() {
//    std::vector<std::vector<int>> world = init_world();
//    std::vector<std::vector<int>> prev_world;
//    unsigned int live_points = 0;
//    bool is_optimal = false;
//
//    do {
//        print_world(world);
//        prev_world = world;
//        next_generation(world, prev_world);
//
//        is_optimal = (world == prev_world);
//        live_points = get_live_count(world);
//
//        if (is_optimal) {
//            std::cout << "Optimal configuration detected" << std::endl;
//        }
//
//        if (live_points == 0) {
//            std::cout << "All points died" << std::endl;
//        }
//        msleep(1000);
//    } while (live_points != 0 && !is_optimal);
//
//    return 0;
//return 0;
//}

#include "s21_cave.h"

int main() {
    s21::Cave cave1 = s21::Cave("file.txt", 3, 4);
//    cave1.update_cave();
//    cave1.print_world();
//    s21::Cave cave2 = s21::Cave("file.txt", 3, 4);
//    cave1.next_generation(cave1.get_vec(), cave2.get_vec());
//    cave1.print_world(cave2.get_vec());
//    std::cout << cave.get_live_count(cave.get_vec());
}