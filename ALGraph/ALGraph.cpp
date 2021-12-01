#include "ALGraph.h";

ALGraph::ALGraph(char c[], int v, int e)
{
	this->vertexNum = v;
	this->arcNum = e;

	//��ʼ��visited[]������DFS/BFS
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		visited[i] = 0;
	}

	//Ϊ�����ֵ��������c[]�е����ݷ���adjList[]��
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->adjList[i].vertex = c[i];
		this->adjList[i].firstEdge = NULL;
	}

	//����edge����������ڱ߱�
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
		cout << "��������������������ı�ţ�" << endl;
		cin >> vex1 >> vex2;

		//�½��ڵ�
		ArcNode* newVertex = new ArcNode();
		newVertex->adjVex = vex2;//���λ����vex1��vex2�ڵ������ӣ���vex2��Ϊ�½ڵ�ı��

		//ͷ�巨
		newVertex->next = adjList[vex1].firstEdge;//���½ڵ����ԭ�е��ڱ߱����ǰ��������µ��ڱ߱�
		this->adjList[vex1].firstEdge = newVertex;//���������µ��ڱ߱�������
		
	}
	
}

void ALGraph::display()
{
	ArcNode* p;
	cout << "��ӡ�ڽӱ�" << endl;
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
	//��ʼ��visited[]
	visitedClean();

	//��v�ڵ㿪ʼ����ͼ
	DFS(v);

	//�������ͼ�е����ж��㣬�������δ�������Ķ��㣬��Ӹö��㿪ʼ����
	for (int i = 0; i < vertexNum; i++)
	{
		if (visited[i] == 0)
		{
			//cout << "visited�ǣ�" << visited[i] << endl;
			DFS(i);
		}
	}
}

void ALGraph::DFS(int v)
{
	//����ڵ�
	cout << adjList[v].vertex << " ";
	visited[v] = 1;

	//����ָ��pָ��ǰ�ڵ����һ���ڵ�
	ArcNode* p;
	p = adjList[v].firstEdge;
	//�����һ���ڵ㲻���
	while (p != NULL)
	{
		//�����һ���ڵ㻹δ�����������
		if (visited[p->adjVex] == 0)
			DFS(p->adjVex);//�õݹ����������һ���ڵ�
		p = p->next;//��ָ��p�����ƶ�������һ���ڵ�
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
	char c[MAX_VERTEX];
	cout << "�����붥��������" << endl;
	cin >> vNum;
	for (int i = 0; i < vNum; i++)
	{
		cout << "������ڵ㣺" << endl;
		cin >> c[i];
	}

	cout << "�������ڱ�������" << endl;
	cin >> aNum;

	ALGraph alg(c, vNum, aNum);
	alg.display();

	int start;
	cout << "������ȱ�������ѡ����ʼvertex����ţ�" << endl;
	cin >> start;
	alg.DFSTraverse(start);
	

	system("pause");
	return 0;
}