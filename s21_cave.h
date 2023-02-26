#ifndef S21_CAVE_H_
#define S21_CAVE_H_
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>

namespace s21 {
    template<typename T>
    std::vector<T> parse_stream(std::istream &stream) {
        std::vector<T> v;
        std::istream_iterator<T> input(stream);
        std::copy(input, std::istream_iterator<T>(), std::back_inserter(v));
        return v;
    }
    class Cave {
    private:
        std::vector<std::vector<int>> old_cave;
        int birth_limits_ = 0;
        int death_limits_ = 0;
        int rows_ = 0;
        bool end_gen_ = false;
        std::string path_to_file_ = "";

    public:
        int get_size(std::string path_to_file);
        void print_world();
        int get_live_count(std::vector<std::vector<int>> vv);
        int count_live_neighbors(std::vector<std::vector<int>> vv, int i, int j);
        void next_generation(std::vector<std::vector<int>> &v1, std::vector<std::vector<int>> &v2);

    public:
        Cave() = default;
        Cave(std::string path_to_file, int birth_limits, int death_limits);
        Cave(int rows, int cols, int birth_limits, int death_limits);
        ~Cave() = default;

    public:
        bool get_end_gen();
        void update_cave();
    };
}  //namespace s21

#endif // S21_CAVE_H_