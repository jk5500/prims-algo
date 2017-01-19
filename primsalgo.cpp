#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <list>

using namespace std;
#define max 10000
#define INF 99999999
#define pii pair<int,int>
#define p(x) push_back(x)

struct compare
{
	bool operator () (const pii& a,const pii&b)
	{
		return a.second>b.second;
	}
};

priority_queue<pii,vector<pii>,compare> Q;
int D[max];
bool F[max];
int P[max];

class Graph
{
	int V;
	list<pii> *adj;
public:
	Graph(int V);
	void addEdge(int u,int v,int w);
	void printvalue(int start,int edge);
};
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<pii> [V]();
}

void Graph::addEdge(int u,int v,int w)

{
	adj[u].p(pii(v,w));
	adj[v].p(pii(u,w));
}

void Graph::printvalue(int start,int edge)
{
	int u,v,w;
	for (int i=1;i<=V;i++)
	{
		D[i]=INF;
	}
	for (int k=1;k<=V;k++)
	{
		P[k]=-1;
	}
	D[start]=0;
	Q.push(pii(start,D[start]));
	list<pii>::iterator it;
	while (!Q.empty())
	{
		u=Q.top().first;
		Q.pop();
		if (F[u])
		{
			continue;
		}
		for (it=adj[u].begin();it!=adj[u].end();it++)
		{
			v=(*it).first;
			w=(*it).second;
			if (F[v]==false && D[v]>w)
			{
				D[v]=w;
				Q.push(pii(v,D[v]));
				P[v]=u;

			}
		}
		F[u]=1;


	}
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", P[i], i);
}

 
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.printvalue(0,14);
 
    return 0;
}