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
	Graph g, rev_g;

	fstream input;
		string v1, v2;
		int node1, node2;
		input.open("data3.txt");
		while (input >> v1 >> v2)
		{
			node1 = stoi(v1);
			node2 = stoi(v2);
			//cout << node1 << " " << node2 << endl;
			g.addEdge(node1, node2);
			rev_g.addEdge(node2, node1);
		}
	    input.close();

	int size = g.LargestSCC(rev_g);
	cout << "Size of largest strongly connected components in "
		"given graph is "<<size<<endl;
	return 0;
}
