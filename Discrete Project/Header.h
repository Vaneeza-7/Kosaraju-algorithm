#pragma once
#include<iostream>
#include<fstream>
#include<list>
#include<stack>
#include<vector>
#include<string>
#include<iterator>

using namespace std;

//class edge {
//	int dest_id;
//public:
//	edge() {
//		dest_id = 0;
//	}
//	edge(int to_id) {
//		dest_id = to_id;
//	}
//	int getedgeid()
//	{
//		return dest_id;
//	}
//	void setedgeid(int to_id)
//	{
//		dest_id=to_id;
//	}
//};

class Node {
	int value;
public:
	list<Node> adjlist;

	Node()
	{
		value = 0;
	}

	Node(int src)
	{
		value = src;
	}
	void setNodeid(int src)
	{
		value = src;
	}
	int getNodeid()
	{
		return value;
	}

	list<Node> getadjlist()
	{
		return adjlist;
	}

	//Node operator()(edge& e )
	//{
	//	Node n;
	//	n.setNodeid(e.getedgeid());
	//	return n;
	//}

	void addedgeTolist(int tovertex)
	{
		//edge e(tovertex);
		//adjlist.push_back(e);
		Node n(tovertex);
		adjlist.push_back(n);

	}

	bool operator==(const Node& n)
	{
		if (value == n.value)
			return true;

	}

	//bool operator==(edge& e)
	//{
	//	if (value == e.getedgeid())
	//		return true;

	//}
	
	void printadList()
	{
		for (auto i = adjlist.begin(); i != adjlist.end(); i++)
		{
			cout << i->getNodeid()<<" ";
		}

	}
};

class Graph {
	
	vector<Node> vertices;
public:
	static int count;
	void addNode(Node newnode)
	{
		vertices.push_back(newnode);
	}

	
	bool contains(int vertex)
	{
		bool found=false;
		for (int i = 0; i < vertices.size(); i++)
		{
			if (vertices.at(i).getNodeid() == vertex)
			{
				found = true;
				break;
			}

		}

		return found;
	}

	Node retNode(int v)
	{
		Node placeholder;
		placeholder.setNodeid(-1);
		for (int i = 0; i < vertices.size(); i++)
		{
				if (vertices.at(i).getNodeid() == v)
				{
					return vertices.at(i);
					break;
				}
	    }
		return placeholder;
	}

	bool isVisited(vector<Node> array, Node n)
	{
		bool found = false;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] == n)
			{
				found = true;
				break;
			}
		}
		return found;
	}

	void addEdge(int fromVertex, int toVertex)
	{
		if (contains(fromVertex)) {
			//edge e(toVertex);
			Node n(toVertex);
			for (int i = 0; i < vertices.size(); i++)
			{
				if (vertices.at(i).getNodeid() == fromVertex)
				{
					vertices.at(i).adjlist.push_back(n);
					break;
				}

			}
		}
		else {
			Node n(fromVertex);
			n.addedgeTolist(toVertex);
			vertices.push_back(n);
		}
	}
	
	void printGraph() {
		for (int i = 0; i < vertices.size(); i++) {
			Node temp;
			temp = vertices.at(i);
			cout <<  temp.getNodeid() << ") --> ";
			temp.printadList();
			cout << endl;
		}
	}

	//void DFSUtil(int vv, vector<bool> &visited)
	//{
	//	//vector<Node> visited;
	//	//vector<bool> visited(4, false);
	//	Node temp;
	//	Node v = retNode(vv);
	//	bool found=false;
	//	stack<Node> s;
	//	s.push(v);
	//	while (!s.empty())
	//	{
	//	    temp=s.top();
	//		s.pop();

	//		/*for (int i = 0; i < visited.size(); i++)
	//		{
	//			if (visited.at(i) == temp)
	//			{
	//				found = true;
	//				break;
	//			}

	//		}*/

	//		if (visited[temp.getNodeid()]==false)
	//		{
	//			cout << temp.getNodeid() << " ";
	//			//visited.push_back(temp);
	//			visited[temp.getNodeid()] = true;
	//		}
	//		
	//		for (list<Node>::iterator it=temp.adjlist.begin();it!=temp.adjlist.end(); ++it)
	//		{
	//			if (visited[(*it).getNodeid()] == false)
	//			{
	//				v = retNode((*it).getNodeid());
	//				s.push(v);
	//			}
	//		
	//		}
	//	}

	//}

	//void DFS()
	//{
	//	int length = vertices.size();
	//	vector<bool>visited(length, false);
	//	for (int i = 0; i < vertices.size(); i++)
	//	{
	//		if (!visited[i])
	//		{
	//			DFSUtil(i, visited);
	//		}
	//	}
	//}

	//int getIndex(vector<Node> v, Node K)
	//{
	//	auto it = find(v.begin(), v.end(), K);

	//	// If element was found
	//	if (it != v.end())
	//	{

	//		// calculating the index
	//		// of K
	//		int index = it - v.begin();
	//		return index;
	//	}
	//	else {
	//		// If the element is not
	//		// present in the vector
	//		return -1;
	//	}
	//}


	//Graph reverseGraph(Graph G)
	//{
	//	Graph g;
	//	for (int i = 0; i < G.vertices.size(); i++)
	//	{
	//		list<Node>::iterator it;
	//		for (it = G.vertices.at(i).adjlist.begin(); it != G.vertices.at(i).adjlist.end(); it++)
	//		{
	//			int j = getIndex(g.vertices, *it);
	//			g.vertices.at(j).adjlist.push_back(*it);
	//			

	//		}
	//		
	//	}
	//}

	//void DFSUtil(int vv, vector<bool>& visited, stack<Node>& s)
	//{
	//	Node temp;
	//	Node v = retNode(vv);
	//	if (v.getNodeid() != -1) {
	//		//stack<Node> s;
	//		s.push(v);

	//		temp = s.top();

	//		if (visited[temp.getNodeid()] == false)
	//		{
	//			//cout << temp.getNodeid() << " ";
	//			//visited.push_back(temp);
	//			visited[temp.getNodeid()] = true;
	//		}

	//		for (list<Node>::iterator it = temp.adjlist.begin();it != temp.adjlist.end(); ++it)
	//		{
	//			if (visited[(*it).getNodeid()] == false)
	//			{
	//				v = retNode((*it).getNodeid());
	//				s.push(v);
	//			}

	//		}

	//	}
	//}

void DFSUtil(int vv, vector<bool>& visited, stack<Node>& S)
{
	Node temp;
	Node v = retNode(vv);
	stack<Node>s;
	if (v.getNodeid() != -1) {
		S.push(v);
		s.push(v);
		while (!s.empty()) {
			temp = s.top();
			s.pop();
			if (visited[temp.getNodeid()] == false)
			{
				//cout << temp.getNodeid() << " ";
				//visited.push_back(temp);
				visited[temp.getNodeid()] = true;
			}

			for (list<Node>::iterator it = temp.adjlist.begin();it != temp.adjlist.end(); ++it)
			{
				if (visited[(*it).getNodeid()] == false)
				{
					v = retNode((*it).getNodeid());
					s.push(v);
					S.push(v);
				}

			}

		}
	}
}


	void DFS_without_push(int vv, vector<bool>& visited)
	{
		Node temp;
		Node v = retNode(vv);
		stack<Node> S;
		S.push(v);
		while (!S.empty()) {
			temp = S.top();
			S.pop();
			if (visited[temp.getNodeid()] == false)
			{
				cout << temp.getNodeid() << " ";
				count++;
				//visited.push_back(temp);
				visited[temp.getNodeid()] = true;
			}

			for (list<Node>::iterator it = temp.adjlist.begin();it != temp.adjlist.end(); ++it)
			{
				if (visited[(*it).getNodeid()] == false)
				{
					v = retNode((*it).getNodeid());
					S.push(v);
				}

			}
		}

	}

	void DFS(stack<Node>&Stack, vector<bool> &visited )
	{
		//int length = vertices.size();
		//vector<bool>visited(length, false);
		for (int i = 0; i < vertices.size(); i++)
		{
			if (!visited[i])
			{
				DFSUtil(i, visited, Stack);
			}
		}
	}


	int LargestSCC(Graph reverse)
	{
		stack<Node> s;
		int max=0;
		Node temp;
		int length = vertices.size();
		vector<bool> visited(length, false);
		DFS(s, visited);
		visited.assign(length, false);
		while (!s.empty())
		{
			temp = s.top();
			s.pop();

			if (visited[temp.getNodeid()] == false)
			{
				reverse.DFS_without_push(temp.getNodeid(), visited);
				cout << endl;
				if (count > max)
				{
					max = count;
				}
				count = 0;
			}
			count = 0;
		}
		return max;
	}
};
int Graph::count = 0;

//// C++ Implementation of Kosaraju's algorithm to print all SCCs
//#include <iostream>
//#include <list>
//#include <stack>
//using namespace std;
//
//class Graph
//{
//	int V; // No. of vertices
//	list<int>* adj; // An array of adjacency lists
//
//	// Fills Stack with vertices (in increasing order of finishing
//	// times). The top element of stack has the maximum finishing
//	// time
//	void fillOrder(int v, bool visited[], stack<int>& Stack);
//
//	// A recursive function to print DFS starting from v
//	void DFSUtil(int v, bool visited[]);
//public:
//	Graph(int V);
//	void addEdge(int v, int w);
//
//	// The main function that finds and prints strongly connected
//	// components
//	void printSCCs();
//
//	// Function that returns reverse (or transpose) of this graph
//	Graph getTranspose();
//};
//
//Graph::Graph(int V)
//{
//	this->V = V;
//	adj = new list<int>[V];
//}
//
//// A recursive function to print DFS starting from v
//void Graph::DFSUtil(int v, bool visited[])
//{
//	// Mark the current node as visited and print it
//	visited[v] = true;
//	cout << v << " ";
//
//	// Recur for all the vertices adjacent to this vertex
//	list<int>::iterator i;
//	for (i = adj[v].begin(); i != adj[v].end(); ++i)
//		if (!visited[*i])
//			DFSUtil(*i, visited);
//}
//
//Graph Graph::getTranspose()
//{
//	Graph g(V);
//	for (int v = 0; v < V; v++)
//	{
//		// Recur for all the vertices adjacent to this vertex
//		list<int>::iterator i;
//		for (i = adj[v].begin(); i != adj[v].end(); ++i)
//		{
//			g.adj[*i].push_back(v);
//		}
//	}
//	return g;
//}
//
//void Graph::addEdge(int v, int w)
//{
//	adj[v].push_back(w); // Add w to v’s list.
//}
//
//void Graph::fillOrder(int v, bool visited[], stack<int>& Stack)
//{
//	// Mark the current node as visited and print it
//	visited[v] = true;
//
//	// Recur for all the vertices adjacent to this vertex
//	list<int>::iterator i;
//	for (i = adj[v].begin(); i != adj[v].end(); ++i)
//		if (!visited[*i])
//			fillOrder(*i, visited, Stack);
//
//	// All vertices reachable from v are processed by now, push v
//	Stack.push(v);
//}
//
//// The main function that finds and prints all strongly connected
//// components
//void Graph::printSCCs()
//{
//	stack<int> Stack;
//	
//
//	// Mark all the vertices as not visited (For first DFS)
//	bool* visited = new bool[V];
//	for (int i = 0; i < V; i++)
//		visited[i] = false;
//
//	// Fill vertices in stack according to their finishing times
//	for (int i = 0; i < V; i++)
//		if (visited[i] == false)
//			fillOrder(i, visited, Stack);
//
//	// Create a reversed graph
//	Graph gr = getTranspose();
//
//	// Mark all the vertices as not visited (For second DFS)
//	for (int i = 0; i < V; i++)
//		visited[i] = false;
//
//	// Now process all vertices in order defined by Stack
//	while (Stack.empty() == false)
//	{
//		// Pop a vertex from stack
//		int v = Stack.top();
//		Stack.pop();
//
//		// Print Strongly connected component of the popped vertex
//		if (visited[v] == false)
//		{
//			gr.DFSUtil(v, visited);
//			//cout << max;
//			cout << endl;
//		}
//	}
//}

