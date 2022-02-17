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
	std::cout << date << " " << eastSt << std::endl;
      }
    }

    //to close the stream
    fin.close();

    return 0;
}
