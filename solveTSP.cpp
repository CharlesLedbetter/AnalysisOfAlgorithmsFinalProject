/*********************************************************************
** Program name: TSP (final project)
** Author: Ann Kostecki, Charles Ledbetter, Matthew Northey
** Date: 3/9/2018
** Description: Implementation for the greedy algorithm nearest
neighbor algorithm that finds a reasonable solution for the TSP
problem.
*********************************************************************/
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

#include "solveTSP.hpp"

using std::vector;
using std::sort;

//used to sort city in order to find nearest neighbor
bool sortCities(City l,City r){
  return (l.dist < r.dist && l.name != -1);
}

//the function that solves TSP
void solveTSP(CityGraph& cg){
  //used for holding temp values
  int temp = 0;
  City tempCity;

  //used to hold cities nearest current node
  vector<City> cities;

  //used to copy cg and find best solution
  CityGraph tg;
  tg.sum = 0;
  CityGraph sg;
  sg.sum = INT_MAX;

  //used for loop control
  int k = 0;
  int bound = 0;

  //this is meant to limit execution time
  //of problems with larger values of n
  if(cg.left.size() > 5001){
    bound = 1;
  }
  else if(cg.left.size() > 2001){
    bound = 10;
  }
  else if(cg.left.size() > 1001){
    bound = 100;
  }
  else{
    bound = cg.left.size();
  }

  //find the best starting point that works with nearest neighbor
  for(int i = 0; i < bound; i++){
    tg = cg;
    tg.sum = 0;

    //set first
    tg.visited.push_back(tg.left[i]);
    tg.left[i] = -1;
    k = i;

    //loop until all cities are visited
    while(tg.left.size() != tg.visited.size()){

      //find nearest neighbor
      for(int j = 0; j < tg.left.size(); j++){
        if(i != j && tg.left[j] != -1){
          temp = nearbyint(sqrt(((tg.x[j] - tg.x[k])*(tg.x[j] - tg.x[k]))+((tg.y[j] - tg.y[k])*(tg.y[j] - tg.y[k]))));

          tempCity.name = j;
          tempCity.dist = temp;

          cities.push_back(tempCity);
        }
      }

      //sort the cities into nearest to i and select that one
      sort(cities.begin(), cities.end(), sortCities);
      tg.visited.push_back(tg.left[cities.front().name]);
      tg.left[cities.front().name] = -1;
      tg.sum += cities.front().dist;
      k = cities.front().name;
      cities.clear();
    }

    //add first city as last city and adjust sum
    tg.sum += nearbyint(sqrt(((tg.x[tg.visited.front()] - tg.x[tg.visited.back()])*
    (tg.x[tg.visited.front()] - tg.x[tg.visited.back()])) +
    ((tg.y[tg.visited.front()] - tg.y[tg.visited.back()])*
    (tg.y[tg.visited.front()] - tg.y[tg.visited.back()]))));


    //if the new solution is better than the old replace
    if(tg.sum < sg.sum){
      sg = tg;
    }
  }

  //adjust the input CityGraph
  cg = sg;
}
