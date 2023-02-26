#include "s21_cave.h"

using namespace s21;

Cave::Cave(int rows, int cols, int birth_limits, int death_limits) {
    srand(time(NULL));
    birth_limits_ = birth_limits;
    death_limits_ = death_limits;
    rows_ = rows;
    old_cave.resize(rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            old_cave[i].push_back(rand() % 2);
        }
    }
}

Cave::Cave(std::string path_to_file, int birth_limits, int death_limits) {
    birth_limits_ = birth_limits;
    death_limits_ = death_limits;
    path_to_file_ = path_to_file;
    std::ifstream input(path_to_file);
    std::vector<int> v = parse_stream<int>(input);
    rows_ = v[0];
    old_cave.resize(v[1]);
    for (int i = 2; i < v.size(); i++) {
        old_cave[(i-2)/v[0]].push_back(v[i]);
    }
    input.close();
}

void Cave::print_world() {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < rows_; j++) {
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
    if ((i - 1) >= 0 && (i - 1) <= vv.size() - 1 && (j - 1) >= 0 && (j - 1) <= vv.size() - 1 && (vv[i-1][j-1] == 1)) count++;
    if (i >= 0 && i <= vv.size() - 1 && (j - 1) >= 0 && (j - 1) <= vv.size() - 1 && (vv[i][j-1] == 1)) count++;
    if ((i + 1) >= 0 && (i + 1) <= vv.size() - 1 && (j - 1) >= 0 && (j - 1) <= vv.size() - 1 && (vv[i+1][j-1] == 1)) count++;
    if ((i - 1) >= 0 && (i - 1) <= vv.size() - 1 && j >= 0 && j <= vv.size() - 1 && (vv[i-1][j] == 1)) count++;
    if ((i + 1) >= 0 && (i + 1) <= vv.size() - 1 && j >= 0 && j <= vv.size() - 1 && (vv[i+1][j] == 1)) count++;
    if ((i - 1) >= 0 && (i - 1) <= vv.size() - 1 && (j + 1) >= 0 && (j + 1) <= vv.size() - 1 && (vv[i-1][j+1] == 1)) count++;
    if ((i) >= 0 && (i) <= vv.size() - 1 && (j + 1) >= 0 && (j + 1) <= vv.size() - 1 && (vv[i][j+1] == 1)) count++;
    if ((i + 1) >= 0 && (i + 1) <= vv.size() - 1 && (j + 1) >= 0 && (j + 1) <= vv.size() - 1 && (vv[i+1][j+1] == 1)) count++;
    return count;
}

void Cave::next_generation(std::vector<std::vector<int>> &v1, std::vector<std::vector<int>> &v2) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < rows_; j++) {
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

void Cave::update_cave() {
    if (!end_gen_) {
        std::vector<std::vector<int>> tmp_cave_(old_cave);
        next_generation(old_cave, tmp_cave_);
        if (tmp_cave_ == old_cave) end_gen_ = true;
        old_cave = tmp_cave_;
    }
}
