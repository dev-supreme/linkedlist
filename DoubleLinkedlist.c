//Double linkedlist ����
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


typedef enum {
	false = 0,
	true = 1
} bool;

typedef struct Node
{
	int nData;
	struct Node* pPrev;
	struct Node* pNext;
}Node;



Node* head = NULL;
Node* tail = NULL;

int insertNode(int data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //��� ���� ���� head�޸𸮿� �Ҵ� (malloc)

	pNewNode->nData = data;
	pNewNode->pNext = NULL;   //pnewNode �� ������ ����
	pNewNode->pPrev = NULL;

	if (NULL == head)
	{
		head = pNewNode;
	}
	else
	{
		Node* pNode = head;
		//���� �������� ������ ��
		if (pNewNode->nData <= pNode->nData)
		{
			pNewNode->pNext = head;
			head = pNewNode;
			pNewNode->pPrev = NULL;
			pNode->pPrev = pNewNode;

		}
		else
		{//�߰����� ���� ������ ��
			while (pNode->pNext != NULL)	//��������!!
			{
				if (pNewNode->nData <= pNode->pNext->nData)
				{
					pNewNode->pNext = pNode->pNext;   //NewNode�� Next�� �����ʰ����� ����
					pNewNode->pPrev = pNode;          //NewNode�� Prev�� ���ʰ����� ����
					pNode->pNext->pPrev = pNewNode;   //�����ʰ����� Prev�� NewNode�� ����
					pNode->pNext = pNewNode;          //���ʰ����� Next�� NewNode�� ����
					break;
				}

				pNode = pNode->pNext;
			}
		}
		if (pNode->pNext == NULL)
		{
			pNode->pNext = pNewNode;
			tail = pNewNode;
			pNewNode->pPrev = pNode;
		}
	}
}

void PrintList()
{
	Node* pNode = head;
	while (pNode)
	{
		printf("%d -> ", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
	pNode = tail;
	while (pNode)
	{
		printf("%d -> ", pNode->nData);
		pNode = pNode->pPrev;
	}
	printf("NULL\n");

}

int FindNode(int data, int avg)
{
	Node *pNode = head;
	pNode->nData = data;

	bool bFound;
	if (data <= avg) //�Է��� ���� ��պ��� ������ head�������� Ž��
	{
		while (pNode)
		{
			if (pNode->nData != data)         //ã�����Ͽ�����
			{
				bFound = false;
			}
			else                 //ã������ break�ϰ� while�� ��������
			{
				bFound = true;
				break;
			}
			pNode = pNode->pNext;
		}
	}
	else if (avg < data) //�Է��� ���� ��պ��� ũ�� tail�������� Ž��
	{
		pNode = tail;
		while (pNode)
		{
			if (pNode->nData != data)         //ã�����Ͽ�����
			{
				bFound = false;
			}
			else                 //ã������ break�ϰ� while�� ��������
			{
				bFound = true;
				break;
			}
			pNode = pNode->pPrev;
		}
	}

	if (bFound == false)
		return 0;
	else
		return pNode->nData;
}

/*
void DisposeList()
{
	node *p = head;
	while (p)
	{
		node *tmp = p;
		p = p->pNext;
		free(tmp);
		tmp = NULL;
	}
}
*/
int main(void)
{
	int data;
	int count = 0;
	int sum = 0;
	int Avg = 0; //�տ������� Ž���Ұ��� �ڿ������� Ž���Ұ��� �Ǵ����ִ� ���flag

	//Ordered Insert
	printf("���� ������ �������� '0'�� �Է��ϼ���\n");
	printf("Put Insert number\n");
	while (true)
	{
		scanf_s("%d", &data);
		// ���� ���� Ȯ�� �� ��ȿ�� �˻� 

		if (data == 0)
		{
			printf("\nEnd InsertNode\n");
			break;
		}

		insertNode(data);

		sum += data; //����ڰ� �Է��� ���� ��ü��
		count++; //����ڰ� �Է��� �� ����
	}

	PrintList();
	//Average
	Avg = sum / count;
	//Find Node
	printf("\n/////���Ե� ���ã��/////\n");
	printf("ã����� Data���� �Է��ϼ��� : ");
	scanf_s("%d", &data);

	data = FindNode(data, Avg);
	if (data == false)
	{
		printf("ã���� ���� ���� ��忡 �����ϴ�.\n");
	}
	else if(data)
		printf("%d", data);
	puts("");


	system("pause");
	return 0;
}