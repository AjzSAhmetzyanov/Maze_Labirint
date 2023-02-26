#include "s21_cave.h"
using namespace s21;
Cave::Cave(int rows, int cols, int birth_limits, int death_limits) {

}

Cave::Cave(std::string path_to_file, int birth_limits, int death_limits) {
    birth_limits_ = birth_limits;
    death_limits_ = death_limits;
    path_to_file_ = path_to_file;
    std::ifstream input(path_to_file);
    std::vector<int> v = parse_stream<int>(input);
    std::vector<int> tmp(v[1]);
    new_cave.resize(v[1]*v[1]);
    old_cave.resize(v[1]*v[1]);
    for (int i = 2; i < v.size(); i++) {
        new_cave[(i-2)/v[0]].push_back(v[i]);
    }
    input.close();
}

int Cave::get_size(std::string path_to_file) {
    std::ifstream input(path_to_file);
    std::vector<int> vv = parse_stream<int>(input);
    input.close();
    return vv[0];
}

void Cave::print_world() {
    for (int i = 0; i < get_size(path_to_file_); i++) {
        for (int j = 0; j < get_size(path_to_file_); j++) {
            std::cout << old_cave[i][j] << ' ';
        }
        std::cout << std::endl;
    }
     std::cout << std::endl;
}

int Cave::get_live_count(std::vector<std::vector<int>> vv) {
    int count = 0;
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv.size(); j++) {
            if (vv[i][j] == 1) count++;
        }
    }
    return count;
}

int Cave::count_live_neighbors(std::vector<std::vector<int>> vv, int i, int j) {
    int count = 0;
    if ((i - 1) >= 0 && (i - 1) <= vv.size() - 1 && (j - 1) >= 0 && (j - 1) <= vv.size() - 1) {
        if (vv[i-1][j-1] == 1) count++;
        }
    if (i >= 0 && i <= vv.size() - 1 && (j - 1) >= 0 && (j - 1) <= vv.size() - 1) {
        if (vv[i][j-1] == 1) count++;
        }
    if ((i + 1) >= 0 && (i + 1) <= vv.size() - 1 && (j - 1) >= 0 && (j - 1) <= vv.size() - 1) {
        if (vv[i+1][j-1] == 1) count++;
        }
    if ((i - 1) >= 0 && (i - 1) <= vv.size() - 1 && j >= 0 && j <= vv.size() - 1) {
        if (vv[i-1][j] == 1) count++;
        }
    if ((i + 1) >= 0 && (i + 1) <= vv.size() - 1 && j >= 0 && j <= vv.size() - 1) {
        if (vv[i+1][j] == 1) count++;
        }
    if ((i - 1) >= 0 && (i - 1) <= vv.size() - 1 && (j + 1) >= 0 && (j + 1) <= vv.size() - 1) {
        if (vv[i-1][j+1] == 1) count++;
        }
    if ((i) >= 0 && (i) <= vv.size() - 1 && (j + 1) >= 0 && (j + 1) <= vv.size() - 1) {
        if (vv[i][j+1] == 1) count++;
        }
    if ((i + 1) >= 0 && (i + 1) <= vv.size() - 1 && (j + 1) >= 0 && (j + 1) <= vv.size() - 1) {
        if (vv[i+1][j+1] == 1) count++;
    }
    return count;
}

void Cave::next_generation(std::vector<std::vector<int>> v1, std::vector<std::vector<int>> v2) {
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1.size(); j++) {
            if (v1[i][j] == 1) {
                if (count_live_neighbors(v1, i, j) < death_limits_) {
                    v2[i][j] = 0;
                    } else {
                    v2[i][j] = 1;
                }
                 } else {
                    if (count_live_neighbors(v1, i, j) > birth_limits_) {
                    v2[i][j] = 1;
                        } else {
                        v2[i][j] = 0;
                    }
                }
            }
        }
}

bool Cave::get_end_gen() {
    return end_gen_;
}

bool Cave::get_error() {
    return error_;
}


void Cave::update_cave() {
    if (!end_gen_) {
        std::vector<std::vector<int>> tmp_cave_(get_size(path_to_file_));
        for (int i = 0; i < get_size(path_to_file_); ++i) {
            for (int j = 0; j < get_size(path_to_file_); ++j) {
                int nbs = count_live_neighbors(tmp_cave_, i, j);
                if (tmp_cave_[i][j])
                    new_cave[i][j] = (nbs < death_limits_);
                else
                    new_cave[i][j] = (nbs <= birth_limits_);
            }
        }
        if (tmp_cave_ == new_cave || new_cave == old_cave)
            end_gen_ = true;
        old_cave = tmp_cave_;
    }
}
