#include "reservoir.h"

double get_east_storage(std::string date){
  
  //opens an input file stream 
  std::ifstream fin("Current_Reservoir_levels.tsv");
  
  //exit if opening the file fails
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

    //for the first line of the columns
    string junk;
    //reads one line
    std::getline(fin, junk);

    //loop reads the file line by line for 5 different values
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){

      fin.ignore(INT_MAX, "\n"); //skips to end of the line and ignores other data

      //to print a line of data
      std::cout << date << " " << eastSt << std::endl;
		 
    }

    //to close the stream
    fin.close();
}
