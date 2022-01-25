#include<stdlib.h>
#include<vector>
#include<array>
#include<iostream>
#include<algorithm>
using namespace std;

#define V 8

void toInfinite(array <array<int, V>, V>& minKnownDist);

int main() {

	int graph[V][V] = {

		//		A	   B	  C		 D		E	   F	  G		 H
		/*A*/ {	0,	   10,	  9999,  12,	9999,  9999,  11,	 4		},
		/*B*/ { 9999,  0,	  9999,  8,		9999,  9999,  9999,  20		},
		/*C*/ { 9999,  9999,  0,	 17,	8,	   9999,  13,	 9999	},
		/*D*/ { 9999,  9999,  9999,  0,		9999,  16,	  24,	 14		},
		/*E*/ { 9999,  9999,  9999,  9999,  0,	   8,	  9999,  9999	},
		/*F*/ { 9999,  9999,  9999,  9999,  9999,  0,	  18,	 2		},
		/*G*/ { 9999,  9999,  9999,  9999,	11,	   9999,  0,	 3		},
		/*H*/ { 9999,  9999,  10,	 9999,  5,	   9999,  9999,  0		}
	};

	vector <pair<int, int>>		currPath;		// Vector of pairs to store the current pathway.
	vector <pair<int, int>>		fullyExpl;		// Vector of pairs to store the dead end nodes ( Nodes that have already been fully explored. )
	array  <array<int, 8>, 8>	minKnownDist;	// Array to store the current minimum known distance between nodes.

	int sourceNode  = 0;	// A
	int destNode    = 1;	// B

	int currNode	= sourceNode;

	toInfinite(minKnownDist);


	
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			// Still need to check if the node is dead. Are there any child elements or links? when to perform this cehck?
			if (i == currNode && j == destNode) {	// If the current node has a link to the destination.
				cout << "FOUND NODE PATH" << endl;
				cout << graph[i][j] << " Miles away" << endl;
				currPath.push_back(make_pair(i, j));			// Adds the currently selected node to the current pathway.
				minKnownDist[i][j] = graph[i][j];				// Sets the index of the new minimum known distance to the discovered distance.
				// exit from loop or continue running until complete. 
			}
			else {
				if (minKnownDist[i][j] != 9999) {
					// If the node has already been explored.
				}
				//if (find(fullyExpl.begin(), fullyExpl.end(), make_pair(i, j)) {	// Searches through the dead nodes for the current index.
				//	currPath.push_back(make_pair(i, j));	// Adds current node to current path.
				//}
				// check next node // explore children // does node have any children

			}
		}
	}

	// Program plan
	/*
	
		Take the source / starting node.
		Add this to current pathway

		Check if a direct path from the starting / current node to the goal node exists.
			
		If it doesn't then:
			ITERATOR - Iterate through all given indexes of the graph (nodes) {

				check nearest link / next node with the shortest distance from the current node.
				add this node to the current path
				check for links to other nodes.

				If no links to other nodes:
					add index to dead path / fullyExpl vector
				If there are links to other nodes:
			}

		Else if it does then:
			Add to currPath vector and return complete path to be output.


	
	*/

}

void toInfinite(array <array<int, V>, V> & minKnownDist) {
	// Loop to set all minKnownDistances to 9999.

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			minKnownDist[i][j] = 9999;
		}
	}

	// ==========================================
}