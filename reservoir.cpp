#include "reservoir.h"
#include <iostream>

double get_east_storage(std::string date){

  //opens an input file stream 
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  //exit if opening the file fails
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

    //for the first line of the columns
    std::string junk, day, eastSt, eastEl, westSt, westEl;
    //reads one line
    getline(fin, junk);

    //loop reads the file line by line for 5 different values
    while(fin >> day >> eastSt >> eastEl >> westSt >> westEl){

      fin.ignore(INT_MAX, '\n'); //skips to end of the line and ignores other data
      if(day == date){
	std::cout << date << " ";
	break;
      }
    }

    //to close the stream
    fin.close();

    return std::stod(eastSt);
}

double get_min_east(){
   
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }
  
  std::string junk, day, eastSt; 
  getline(fin, junk);

  double min;
  
  while(fin >> day >> eastSt){
    fin.ignore(INT_MAX, '\n');
    //to get the first value
    min = std::stod(eastSt);
    break;
  }
  
  while(fin >> day >> eastSt){

    fin.ignore(INT_MAX, '\n');
 
    if(std::stod(eastSt) < min){
      min = std::stod(eastSt);
    }
    
  }

  std::cout << "The minimum storage in East basin during 2018: ";
  
  return min;
}

double get_max_east(){

  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

  std::string junk, day, eastSt; 
  getline(fin, junk);

  double max;
  
  while(fin >> day >> eastSt){
    fin.ignore(INT_MAX, '\n');
    //to get the first value
    max = std::stod(eastSt);
    break;
  }
  
  while(fin >> day >> eastSt){

    fin.ignore(INT_MAX, '\n');
 
    if(std::stod(eastSt) > max){
      max = std::stod(eastSt);
    }
  }

  std::cout << "The maximum storage in East basin during 2018: ";
    
  return max;
}
