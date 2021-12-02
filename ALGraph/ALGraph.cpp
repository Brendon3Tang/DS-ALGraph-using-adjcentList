#include "ALGraph.h";

ALGraph::ALGraph(int c[], int v, int e)
{
	this->vertexNum = v;
	this->arcNum = e;

	//初始化visited[]，用于DFS/BFS
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		visited[i] = 0;
	}

	//为顶点表赋值：将参数c[]中的数据放入adjList[]中
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		this->adjList[i].vertex = c[i];
		//this->adjList[i].firstEdge->adjVex = -1;
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

void ALGraph::DFSTraverse(int v)
{
	//初始化visited[]
	visitedClean();

	//从v节点开始遍历图
	DFS(v);

	//检查整个图中的所有顶点，如果还有未遍历过的顶点，则从该顶点开始遍历
	for (int i = 0; i < vertexNum; i++)
	{
		if (visited[i] == 0)
		{
			//cout << "visited是：" << visited[i] << endl;
			DFS(i);
		}
	}
}

void ALGraph::DFS(int v)
{
	//输出节点
	cout << adjList[v].vertex << " ";
	visited[v] = 1;

	//创建指针p指向当前节点的下一个节点
	ArcNode* p;
	p = adjList[v].firstEdge;
	//如果下一个节点不会空
	while (p != NULL)
	{
		//如果下一个节点还未被访问输出过
		if (visited[p->adjVex] == 0)
			DFS(p->adjVex);//用递归继续访问下一个节点
		p = p->next;//将指针p继续移动到再下一个节点
	}
}

void ALGraph::BFSTraverse(int v)
{
	//初始化visited[]
	visitedClean();

	//从v节点开始遍历图
	BFS(v);

	//检查整个图中的所有顶点，如果还有未遍历过的顶点，则从该顶点开始遍历
	for (int i = 0; i < vertexNum; i++)
	{
		if (visited[i] == 0)
		{
			//cout << "visited是：" << visited[i] << endl;
			BFS(i);
		}
	}
}

void ALGraph::BFS(int v)
{
	ArcNode* p;
	cout << adjList[v].vertex << " ";//输出参数要求的顶点
	visited[v] = 1;//将该顶点的visited状态设置为1
	myQueue.push(adjList[v].vertex);//将该顶点入队
	
	//直到队列空之前都保持循环（逻辑类似树的层序遍历）
	while (!myQueue.empty())
	{
		//取得当前顶点的序号，并将指针p指向该顶点的相邻顶点
		v = myQueue.front();
		myQueue.pop();
		p = adjList[v].firstEdge;//指针p指向该顶点的相邻顶点（指向邻边表）

		//循环该顶点的所有邻边表，找到未被visited的相邻顶点
		while (p != NULL)
		{
			//如果找到了未visited的相邻顶点，则输出该相邻顶点，并将visited状态设置为1，将该相邻顶点入队，再使指针指向邻边表中的下一个节点
			if (visited[p->adjVex] == 0)
			{
				cout << p->adjVex << " ";//输出该相邻顶点
				visited[p->adjVex] = 1;//将visited状态设置为1
				myQueue.push(p->adjVex);//使该相邻顶点入队
				p = p->next;//使指针指向邻边表中的下一个节点
			}
			//如果该顶点的所有相邻顶点全部被访问过，则直接退出该邻边表的循环
			else
				break;
		}
	}


}

void ALGraph::visitedClean()
{
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		visited[i] = 0;
	}
}

int main()
{
	int vNum, aNum;
	int c[MAX_VERTEX];
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

	int start;
	cout << "进行深度遍历，请选择起始vertex的序号：";
	cin >> start;
	alg.DFSTraverse(start);
	cout << endl;

	cout << "进行广度遍历，请选择起始vertex的序号：";
	cin >> start;
	alg.BFSTraverse(start);
	cout << endl;
	

	system("pause");
	return 0;
}