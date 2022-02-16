#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

#include "reservoir.h"

double get_east_storage(std::string date);

int main()
{
  std::string date;
  cout << "Enter a date in the format mmddyyyy: " << std::endl;
  cin >> date;

  data = get_east_storage(date);

  
  return 0;
}
