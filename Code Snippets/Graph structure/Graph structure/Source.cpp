#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

#define V 8

int minimumDist(int dist[], bool visited[])	// Function to check each path for a given vertex and return the 
{
	int min = INT_MAX, index;	// Sets the min value to infinite and the current index.

	for (int i = 0; i < V; i++)		// Iterates through the array
	{
		if (visited[i] == false && dist[i] <= min)	// Checks if a node is not visited and if the current path is shorter.
		{
			min = dist[i];			// sets min to the current distance.
			index = i;				// Stores the current index in index.
		}
	}
	return index;					// Returns the index of the shortest path.
}

void Dijkstra(int graph[V][V], int startNode)
{
	int dist[V]; // calculates minimum distance for a node. Array used for outputting values.                            
	bool visited[V];// Stores true if the index has already been visited.


	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;	// Uses integer max value as a kind of 'Infinite' value.
		visited[i] = false;	// Sets all of the indexes to false, ready to check visited values.
	}

	dist[startNode] = 0;   // Sets the source vertex distance to A.             

	for (int i = 0; i < V; i++)
	{
		int min = minimumDist(dist, visited); // vertex not yet included.
		visited[min] = true;// min with minimum distance included in visited.
		for (int i = 0; i < V; i++)
		{
			// Updating the minimum distance for the particular node.
			if (!visited[i] && graph[min][i] && dist[min] != INT_MAX && dist[min] + graph[min][i] < dist[i])
				dist[i] = dist[min] + graph[min][i];
		}
	}
	cout << "Vertex\t\tDistance from source" << endl;
	for (int i = 0; i < V; i++)
	{ // Output results
		char str = 65 + i; // Ascii values for pritning A,B,C..
		cout << str << "\t\t\t" << dist[i] << endl;
	}
}

int main() {

	int graph[V][V] = {
		//      A   B   C   D   E   F   G   H
		/*A*/ { 0,  10, 0,  12, 0,  0,  11, 4},
		/*B*/ { 0,  0,  0,  8,  0,  0,  0,  20},
		/*C*/ { 0,  0,  0,  17, 8,  0,  13, 0},
		/*D*/ { 0,  0,  0,  0,  0,  16, 24, 14},
		/*E*/ { 0,  0,  0,  0,  0,  8,  0,  0},
		/*F*/ { 0,  0,  0,  0,  0,  0,  18, 2},
		/*G*/ { 0,  0,  0,  0,  11, 0,  0,  3},
		/*H*/ { 0,  0,  10,  0,  5, 0,  0,  0} };

	Dijkstra(graph, 0);

	return 0;
}