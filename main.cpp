#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

#include "reservoir.h"
#include "reverseorder.h" 

int main(){
  
  std::string date = "04/18/2018";

  double storage = get_east_storage(date);
  std::cout << storage << "\n";

  double min_storage = get_min_east();
  std::cout << min_storage << "\n";

  double max_storage = get_max_east();
  std::cout << max_storage << "\n";

  std::string compare = compare_basins(date);
  std::cout << compare << "\n";

  std::string date1 = "05/03/18";
  std::string date2 = "11/15/18";

  reverse_oreder(date1, date2);
  return 0;
}
