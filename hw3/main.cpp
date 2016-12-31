#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <climits>
#include <iomanip>
int V;
double probability(){
   return 1.0*rand()/RAND_MAX;}


using namespace std;
//class that has make_graph as constructor
//use adjacency matrix as Graph representation
class Graph{
   public:
      Graph(int s, double density);
      void print_graph();
	 vector<vector<bool>> g1;
   private:
      int size;
      double density;

};


//make_graph altered to work in c++; compute min distance;
Graph::Graph(int s, double density){
   this->size = s;
   V = s;
   this->density = density;
   for (int i = 0; i < s; ++i){
        // We push a new vector of bool onto the initial vector s times
        // The * is there to dereference the new vector that we insert
        this->g1.push_back( *( new vector<bool>() ) );
        for (int j = 0; j < s; ++j){
            //then, on each of those vectors, we push a default "false" s times
            this->g1.at(i).push_back(false);
        }
   }
   //If this edge exists, set g1[i][j] to true;
   for (int i = 0; i < s; ++i){
      for (int j = 0; j < s; ++j){
        if (probability()< density) this->g1[i][j] = true;
      }
   }
}

//simple conversion, just needed 'this'
void Graph::print_graph(){
cout << "graph size: " << this->size << endl;
cout << "graph density: " << this->density << endl;
   for(int i = 0; i < this->size; ++i){
      for (int j = 0; j < this->size; ++j){
         cout << this->g1[i][j] << " ";
      }
      cout << "\n";
   }
}
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
	cout << "Vertex     Distance from Source:"<< endl;
	double sum = 0;
	int count = 0;
	for (int i = 1; i < V; i++)
	{
        if (dist[i] != INT_MAX)
		{
			sum += dist[i];
			count++;
		}
		cout << setw(5);
		cout << i << "   " << dist[i] << endl;
	}
	cout << "average distance is: " << sum / count << endl;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(Graph graph, int src)
{

     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V - 1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; ++v)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph.g1.at(u).at(v)&& dist[u] != INT_MAX
                                       && dist[u]+graph.g1.at(u).at(v) < dist[v])
            dist[v] = dist[u] + graph.g1.at(u).at(v);
     }

     // print the constructed distance array
     printSolution(dist, V);
}
int main(){
    srand(time(0));
    cout << "Test simple graph generation\n";
    Graph* test1 = new Graph(50, 0.3);
    test1->print_graph();

    dijkstra(*test1, 0);
    cout << "\nEND of TEST\n\n";

    return 0;
}
