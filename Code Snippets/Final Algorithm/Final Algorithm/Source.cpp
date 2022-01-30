#include<iostream>
#include<climits>
#include<string>
#include <chrono>
#include <ctime> 
using namespace std;

#define v 80
int amount = 0; // used for simulation


int miniDist(int dist[], bool visited[]) // finding minimum distance
{
    int min = 10000, ind;              // sets the min value to infinite & Initialises index var.

    for (int k = 0; k < v; k++)          // iterates through the verticies.
    {
        amount++;

        if (visited[k] == false && dist[k] <= min)  // Checks if the node hasn't been visited yet and if the current path is shorter than the minimum known path ( which is infinite on the initial iteration ).
                                                    // This is used to find path length to each vertex.
        {
            amount++;
            min = dist[k];              // Sets the min value to the current index of min known distance. ( ready for comparison in the next iteration of the for loop )
            ind = k;                    // Sets the index value to the current index of the iterator / for loop so this can be returned back as the shortest path index for this node/edge.
        }
    }
    return ind;                         // Returns index for shortest identified path.
}

void RunAlgorithm(int graph[v][v], int src) // adjacency matrix     // Outputs all of the shortest paths from the source node to every other node.
{
    //auto start = chrono::system_clock::now();         // Used to test time taken to execute.
    int dist[v]; // array to store the minimum path length for each node.                           
    bool visited[v];// Boolean array to store visited or unvisited for each node.


    for (int k = 0; k < v; k++) // Iterator to run through each index of the arrays.
    {
        dist[k] = 10000;  // Assumes the distance is infinite and assigns value to each index.      ( Initialisation )
        visited[k] = false;        // False values assigned to all indexes to store unvisited for each node. ( Initialisation )
    }

    dist[src] = 0;   // Sets the distance of the source node to 0 as this is the only known path length.

    for (int k = 0; k < v; k++) // Iterates through all of the indexes of the arrays.
    {
        amount++;
        int m = miniDist(dist, visited);   // Sets m to the calculated minimum distance from each node
        visited[m] = true;                     // Sets the current node to explored
        for (int k = 0; k < v; k++)
        {
            amount++;
            // updating the distance of neighbouring vertex
            if (!visited[k] && graph[m][k] && dist[m] != 10000 && dist[m] + graph[m][k] < dist[k])   // Checks if the the current node has not yet been visited. Checks if the cost for this edge is less than the currently known shortest path
                dist[k] = dist[m] + graph[m][k];                                                       // Updates the shortest known path from the source to the goal node, Adds previous total pathlength to newly discovered node.
        }
    }
    //auto end = std::chrono::system_clock::now();
    //chrono::duration<double> elapsed_seconds = end - start;       // Used for testing time to execute algorithm.
    //time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "Vertex\t\t\tDistance from source\n" << endl;   // Titles for output
    for (int k = 0; k < v; k++)                             // Iterate through saved list.
    {
        char str = 65 + k;                                  // Translates numerical values into letters
        if (dist[k] != 10000) {                             // Checks if the path exists.
            cout << str << "\t\t\t" << dist[k] << endl;     // Outputs results.( Shortest Path Length)
        }
        else {
            cout << str << "\t\t\tPATH DOESN'T EXIST" << endl;
        }
    }
    cout << to_string(amount) << " number of checks performed";
    //cout << "\nfinished computation at " << time(&end_time) << "\nelapsed time: " << elapsed_seconds.count() << "s\n";    // Used for testing time of completion.
}

int main()
{
    int graph[v][v] = {

        // Cost matrix showing edge cost from vertex [LEFT V] to - [TOP V]
        //		A	B	C	D	 E	 F	 G	 H
        /*A*/ {	0,  10, 0,  12,  0,	 0,  11, 4	},
        /*B*/ { 0,  0,  0,	8,	 0,	 0,	 0,	 20	},
        /*C*/ { 0,  0,  0,  17,	 8,  0,  13, 0	},
        /*D*/ { 0,  0,  0,  0,	 0,  16, 24, 14	},
        /*E*/ { 0,  0,  0,  0,   0,	 8,	 0,  0	},
        /*F*/ { 0,  0,  0,  0,   0,  0,	 18, 2	},
        /*G*/ { 0,  0,  0,  0,   11, 0,  0,	 30	},
        /*H*/ { 0,  0,  10, 0,   5,	 0,  0,  0	}

    };

    int src;
    cout << "Max = " << v << ", Min = 0" << endl;
    cout << "Please enter the source node (1=A, 2=B etc):\t" << endl;
    cin >> src;
    RunAlgorithm(graph, src);         // Calls the algorithm funciton with the source node as a parameter.
    return 0;
}