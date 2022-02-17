#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

#include "reservoir.h"

int main(){
  
  std::string date = "04/18/2018";

  double storage = get_east_storage(date);
  std::cout << storage;
  
  return 0;
}
