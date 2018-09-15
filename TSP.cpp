/*********************************************************************
** Program name: TSP (final project)
** Authors: Ann Kostecki, Charles Ledbetter, Matthew Northey
** Date: 3/9/2018
** Description: A heuristic solution for the traveling salesman
problem. This is the main function that parses an input file and
passes the data to the solveTSP algorithm. It then outputs the results
to a .tour file.
*********************************************************************/
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<string>

#include "solveTSP.hpp"

using std::ifstream;
using std::ofstream;
using std::vector;
using std::cout;
using std::endl;
using std::string;

// parses file into CityGraph object
CityGraph inputToGraph(ifstream &in){
  // the object to be returned
  CityGraph cRet;

  //for parsing in ints
  int tempInt;

  //load the graph struct from file
  while(in){
    in >> tempInt;
    cRet.left.push_back(tempInt);
    in >> tempInt;
    cRet.x.push_back(tempInt);
    in >> tempInt;
    cRet.y.push_back(tempInt);
  }

  //used to correct for blank last line
  cRet.left.pop_back();
  cRet.x.pop_back();
  cRet.y.pop_back();

  return cRet;
}

//main
int main(int argc, char* argv[]){
  // for file handling
  ifstream inputFile;
  ofstream outputFile;

  //used to name output file
  string outName(argv[1]);
  outName += ".tour";

  // holds the graph
  CityGraph cGraph;
  cGraph.sum = 0;

  // open the file if it exists
  inputFile.open(argv[1]);

  // check that the file properly opened if not tell user
  if(!inputFile){
    cout << "There was an error opening the file.\n" << endl;
  }

  // if the file exists and opened correctly
  // continue rest of program
  else{
    // make the graph
    cGraph = inputToGraph(inputFile);

    // close the input file
    inputFile.close();

    solveTSP(cGraph);

    // print solution
    if(cGraph.left.size() == cGraph.visited.size()){
      outputFile.open(outName);
      outputFile << cGraph.sum << "\n";
      for(int i = 0; i < cGraph.visited.size(); i++){
        outputFile << cGraph.visited[i] << "\n";
      }
      outputFile.close();
    }
    else{
      cout << "No Route Found." << endl;
    }
  }

  return 0;
}
