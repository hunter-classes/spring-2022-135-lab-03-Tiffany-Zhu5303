#include "reverseorder.h"
#include <iostream>

void reverse_oreder(std::string date1, std::string date2){
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }
  
  std::string junk, day, eastSt, eastEl, westSt, westEl, comparison; 
  getline(fin, junk);

  double west_basin_el [365];
  std::string days [365];
  int count = 0;
  int start, end;
  
  while(fin >> day >> eastSt >> eastEl >> westSt >> westEl){
    fin.ignore(INT_MAX, '\n');
    
    west_basin_el[count] = std::stod(westEl);
    days[count] = day;
    
    if(day == date1){
      start = count;
    }else if (day == date2){
      end = count;
    }
    
    //count of line number
    count++;

  }

  //prints west basin elevation in reverse chronological order
  for(int i = end; i >= start; i--){
    if(west_basin_el[i] > 0){
    std::cout << days[i] << " " << west_basin_el[i] << std::endl;
    }
    }
  
}
