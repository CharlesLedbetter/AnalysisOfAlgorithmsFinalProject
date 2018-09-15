/*********************************************************************
** Program name: TSP (final project)
** Author: Ann Kostecki, Charles Ledbetter, Matthew Northey
** Date: 3/9/2018
** Description: Declarations for the greedy algorithm nearest neighbor
algorithm that finds a reasonable solution for the TSP problem. 
*********************************************************************/
#ifndef TSP_HPP
#define TSP_HPP

#include<vector>
#include<algorithm>

// The graph struct
struct CityGraph {
  std::vector<int> left;
  std::vector<int> visited;
  std::vector<int> x;
  std::vector<int> y;
  int sum;
};

//used for sorting cities into distances
struct City {
  int name;
  int dist;
};

//function that recursively reverses a string and starts a new line
void solveTSP(CityGraph& cg);

//used to sort cities into distances
bool sortCities(City l,City r);

#endif
