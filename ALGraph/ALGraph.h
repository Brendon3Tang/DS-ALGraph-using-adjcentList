#pragma once
#include <iostream>
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
	char vertex;
	ArcNode* firstEdge;
};

class ALGraph
{
private:
	VertexNode adjList[MAX_VERTEX];
	int vertexNum, arcNum; 

	void buildList();

public:
	ALGraph(char c[], int v, int e);

	~ALGraph();

	void DFSTraverse(int v);

	void BFSTraverse(int v);

	void display();
};