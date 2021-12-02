#pragma once
#include <iostream>
#include <queue>
using namespace std;

const int MAX_VERTEX = 10;

//边表:与顶点表中的顶点相连。边表中的每个节点结构与顶点vertex相同。包含该节点的序号，与指向下一个节点的指针next
struct ArcNode
{
	int adjVex;
	ArcNode* next;
};

//顶点表:用于创建一个储存所有顶点的数组，该数组中的每个顶点就是vertexNode。vertexNode中包含vertex的值与一条指向该vertex的邻边的指针firstEdge
struct VertexNode 
{
	int vertex;
	ArcNode* firstEdge;
};

class ALGraph
{
private:
	VertexNode adjList[MAX_VERTEX];
	int visited[MAX_VERTEX];
	int vertexNum, arcNum; 
	queue<int> myQueue;

	void buildList();

	void DFS(int v);

	void BFS(int v);

public:
	ALGraph(int c[], int v, int e);

	~ALGraph();

	void DFSTraverse(int v);

	void BFSTraverse(int v);

	void display();

	void visitedClean();
};