#include "ALGraph.h";

ALGraph::ALGraph(char c[], int v, int e)
{
	this->vertexNum = v;
	this->arcNum = e;

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

	system("pause");
	return 0;
}