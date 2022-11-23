#pragma once
#include<iostream>
#include<fstream>
#include<list>
#include<stack>
#include<vector>
#include<string>
#include<iterator>

using namespace std;

//Resources used:
//GeekForGeeks
//Simple Snippets
//Programiz


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

	void addedgeTolist(int tovertex)
	{
		Node n(tovertex);
		adjlist.push_back(n);

	}

	bool operator==(const Node& n)
	{
		if (value == n.value)
			return true;

	}

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

	void addEdge(int fromVertex, int toVertex)//called in main to make graph
	{
		if (contains(fromVertex)) {
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
		vector<bool> visited(length, false);   //to track the visited vertices
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

