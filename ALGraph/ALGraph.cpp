#include "ALGraph.h";

ALGraph::ALGraph(char c[], int v, int e)
{
	this->vertexNum = v;
	this->arcNum = e;

	//为顶点表赋值：将参数c[]中的数据放入adjList[]中
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->adjList[i].vertex = c[i];
		this->adjList[i].firstEdge = NULL;
	}

	//根据edge的情况构造邻边表
	buildList();
}

ALGraph::~ALGraph()
{
	ArcNode* p, * q;
	for (int i = 0; i < vertexNum; i++)
	{
		p = adjList[i].firstEdge;
		q = p;
		while (p != NULL)
		{
			p = p->next;
			delete q;
			q = p;
		}
	}
}

void ALGraph::buildList()
{
	int vex1, vex2;

	for (int i = 0; i < this->arcNum; i++)
	{
		cout << "请输入相连的两个顶点的编号：" << endl;
		cin >> vex1 >> vex2;

		//新建节点
		ArcNode* newVertex = new ArcNode();
		newVertex->adjVex = vex2;//如果位置在vex1与vex2节点相连接，则将vex2作为新节点的编号

		//头插法
		newVertex->next = adjList[vex1].firstEdge;//将新节点放在原有的邻边表的最前方，组成新的邻边表
		this->adjList[vex1].firstEdge = newVertex;//将顶点与新的邻边表相连接
		
	}
	
}

void ALGraph::display()
{
	ArcNode* p;
	cout << "打印邻接表：" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		cout << adjList[i].vertex;
		p = adjList[i].firstEdge;
		while (p != NULL)
		{
			cout << "->" << p->adjVex;
			p = p->next;
		}
		cout << endl;
	}
}

int main()
{
	int vNum, aNum;
	char c[MAX_VERTEX];
	cout << "请输入顶点数量：" << endl;
	cin >> vNum;
	for (int i = 0; i < vNum; i++)
	{
		cout << "请输入节点：" << endl;
		cin >> c[i];
	}

	cout << "请输入邻边数量：" << endl;
	cin >> aNum;

	ALGraph alg(c, vNum, aNum);
	alg.display();

	system("pause");
	return 0;
}