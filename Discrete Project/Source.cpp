#include<iostream>
#include"Header.h"
#include<fstream>
#include<list>
//#include<stack>
//#include<vector>
#include<string>
using namespace std;

int main()
{
	Graph g;
	//int size=0;
	// Create a graph given in the above diagram
	//fstream input;
	//	string v1, v2;
	//	int node1, node2;
	//	input.open("data.txt");
	//	while (input >> v1 >> v2)
	//	{
	//		node1 = stoi(v1);
	//		node2 = stoi(v2);
	//		//cout << node1 << " " << node2 << endl;
	//		g.addEdge(node1, node2);

	//	}
	//    input.close();
	/*g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 0);
	g.addEdge(3, 3);
	*///g.addEdge(1, 3);

	cout << "Following are strongly connected components in "
		"given graph \n";
	g.printGraph();
	g.DFS();
	//g.printSCCs();

	return 0;
}
