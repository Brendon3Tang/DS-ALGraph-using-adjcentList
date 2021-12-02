#include "ALGraph.h";

ALGraph::ALGraph(int c[], int v, int e)
{
	this->vertexNum = v;
	this->arcNum = e;

	//��ʼ��visited[]������DFS/BFS
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		visited[i] = 0;
	}

	//Ϊ�����ֵ��������c[]�е����ݷ���adjList[]��
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		this->adjList[i].vertex = c[i];
		//this->adjList[i].firstEdge->adjVex = -1;
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

void ALGraph::BFSTraverse(int v)
{
	//��ʼ��visited[]
	visitedClean();

	//��v�ڵ㿪ʼ����ͼ
	BFS(v);

	//�������ͼ�е����ж��㣬�������δ�������Ķ��㣬��Ӹö��㿪ʼ����
	for (int i = 0; i < vertexNum; i++)
	{
		if (visited[i] == 0)
		{
			//cout << "visited�ǣ�" << visited[i] << endl;
			BFS(i);
		}
	}
}

void ALGraph::BFS(int v)
{
	ArcNode* p;
	cout << adjList[v].vertex << " ";//�������Ҫ��Ķ���
	visited[v] = 1;//���ö����visited״̬����Ϊ1
	myQueue.push(adjList[v].vertex);//���ö������
	
	//ֱ�����п�֮ǰ������ѭ�����߼��������Ĳ��������
	while (!myQueue.empty())
	{
		//ȡ�õ�ǰ�������ţ�����ָ��pָ��ö�������ڶ���
		v = myQueue.front();
		myQueue.pop();
		p = adjList[v].firstEdge;//ָ��pָ��ö�������ڶ��㣨ָ���ڱ߱�

		//ѭ���ö���������ڱ߱��ҵ�δ��visited�����ڶ���
		while (p != NULL)
		{
			//����ҵ���δvisited�����ڶ��㣬����������ڶ��㣬����visited״̬����Ϊ1���������ڶ�����ӣ���ʹָ��ָ���ڱ߱��е���һ���ڵ�
			if (visited[p->adjVex] == 0)
			{
				cout << p->adjVex << " ";//��������ڶ���
				visited[p->adjVex] = 1;//��visited״̬����Ϊ1
				myQueue.push(p->adjVex);//ʹ�����ڶ������
				p = p->next;//ʹָ��ָ���ڱ߱��е���һ���ڵ�
			}
			//����ö�����������ڶ���ȫ�������ʹ�����ֱ���˳����ڱ߱��ѭ��
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
	cout << "������ȱ�������ѡ����ʼvertex����ţ�";
	cin >> start;
	alg.DFSTraverse(start);
	cout << endl;

	cout << "���й�ȱ�������ѡ����ʼvertex����ţ�";
	cin >> start;
	alg.BFSTraverse(start);
	cout << endl;
	

	system("pause");
	return 0;
}