#include "./benchmark.hpp"

int main(void) {
  std::cout << "\033[1;94m" <<
    "# ****************************************************************************** #\n"
    "#                                                                                #\n"
    "#                              containers bench test1                            #\n"
    "#                                                                                #\n"
    "# ****************************************************************************** #\n"
            << "\033[0m" << std::endl;
  benchmark_vector();
  benchmark_stack();
  benchmark_map();
  system("leaks ft_container");

  return 0;
}