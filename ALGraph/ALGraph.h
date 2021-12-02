#pragma once
#include <iostream>
#include <queue>
using namespace std;

const int MAX_VERTEX = 10;

//�߱�:�붥����еĶ����������߱��е�ÿ���ڵ�ṹ�붥��vertex��ͬ�������ýڵ����ţ���ָ����һ���ڵ��ָ��next
struct ArcNode
{
	int adjVex;
	ArcNode* next;
};

//�����:���ڴ���һ���������ж�������飬�������е�ÿ���������vertexNode��vertexNode�а���vertex��ֵ��һ��ָ���vertex���ڱߵ�ָ��firstEdge
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