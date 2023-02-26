#include "s21_cave.h"

int main() {
  s21::Cave cave1 = s21::Cave("file.txt", 6, 2);
  while (!cave1.get_end_gen()) {
    cave1.update_cave();
    cave1.print_world();
  }
  std::cout << cave1.get_end_gen();
}