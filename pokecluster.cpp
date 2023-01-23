#include "mpi.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
//#include <math.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
//Readings the PokeCluster.csv file and grabs its approximately 800 dataset
string readFile()
{
  //Variables
  ifstream fin;
  string line;
  string pokeColumns;
  vector <string> pokeData;
  string tempID;
  string currentPokemon;
  int randomID;
  srand(time(NULL)+randomID);

  //Categories
  string id;
  string name;
  string totalStat;
  string hpStat;
  string attackStat;
  string defenseStat;
  string spaStat;
  string spdStat;
  string speedStat;
  string genNum;

  //srand(time(NULL)+randomID); //randomizer

  //Open PokedexCluster
  fin.open("PokedexCluster.csv");

   //Parsing data into vector
   while(getline(fin,line))
   {
     getline(fin,line);
     stringstream ss(line);

     /*while(getline(ss,pokeColumns, ','))
      {
        pokeData.push_back(pokeColumns);
        //Displaying data for testing purposes
        //cout<<pokeColumns<<endl;
      }*/

      //Checking data in the right categories
      while(fin.good())
      {

        getline(fin,id,',');
        getline(fin,name,',');
        getline(fin,totalStat,',');
        getline(fin,hpStat,',');
        getline(fin,attackStat,',');
        getline(fin,defenseStat,',');
        getline(fin,spaStat,',');
        getline(fin,spdStat,',');
        getline(fin,speedStat,',');
        getline(fin,genNum,'\n');


        //TRandom ID generator to pick a centroid for each process
        randomID = rand()%791;
        tempID = to_string(randomID);

        //Testing correspondance
        if(tempID == id)
        {
          //cout<<"The ID is: "<<tempID<<endl;

          //cout<<"The Pokemon is: "<<name<<endl;
          currentPokemon = name;
        }

      }

   //Checks if the data got filled into the vector
   /*if(pokeData.empty() == true)
   {
     cout<<"Vector is empty."<<endl;
   } else
   {
     cout<<"Vector is filled with data! Yay!"<<endl;
   }*/

   //Close File
   //fin.close();
 }

  return currentPokemon;
}

int main(int argc, char ** argv)
{
  //Variables
  int n = 0; //number of points
  int dim = 2; //dimensions
  int K = 4; //number of clusters
  int randomID;
  string processPokemon;

  srand(time(NULL)+randomID);
  string pokeFile = readFile();

  //MPI Variables
  int rank, size;
  double clusters[K][dim]; //clusters


  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  //Checking what current process we are in
  for(int i = 0; i < size; ++i)
  {
    if(i == rank){
        //Display current Process
        cout<<"Current Process: "<<rank<<endl;
        //Display pokeFile
        cout<<pokeFile;
        cout<<endl;
    }

    MPI_Barrier(MPI_COMM_WORLD);

  }


  MPI_Finalize();
  return 0;
}


//Kmeans Clustering
/*void kmeansClustering(vector<int> *pokePoints, int K, int rank)
{
  vector<int> pokePoint = readFile();
  vector<int> centroids;
  for(int i = 0; i < K; i++)
  {
    centroids.push_back(pokeStrings->at(rand()%n));
    cout<<centroids<<endl;
  }
}
*/

//Calculating Eucledian distance
double eucledian_distance(const double **pointA, const double **pointB, int dim)
{
  double totalDistance = 0.0;
  double tempDistance;

  for(int i = 0; i < dim; i++)
  {
    tempDistance = pointA[i] - pointB[i];
    totalDistance = pow(tempDistance,2);
  }

  return sqrt(totalDistance);
}
