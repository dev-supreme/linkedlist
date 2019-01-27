//��ũ�� ����Ʈ ordered insert / find / delete ����

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef enum {
	false = 0,
	true = 1
} bool;

struct Node
{
	int nData;
	struct Node *pNext;
}; typedef struct Node node;

node *head = NULL;      //������
int insertNode(int);
void FindNode();
int DeleteNode(int);

int insertNode(int data)
{
	node *pNewnode = (node*)malloc(sizeof(node)); //��� ���� ���� head�޸𸮿� �Ҵ� (malloc)

	pNewnode->nData = data;
	pNewnode->pNext = NULL;   //pnewnode �� ������ ����

	if (NULL == head)
	{
		head = pNewnode;
	}
	else
	{
		node* pNode = head; //�Ǵٸ�����
		//���� �������� ������ ��
		if (pNewnode->nData <= pNode->nData)
		{
			pNewnode->pNext = pNode;
			head = pNewnode;
		}
		else
		{
			//�߰����� ���� ������ ��
			while (pNode->pNext != NULL)
			{
				if (pNewnode->nData <= pNode->pNext->nData)
				{
					pNewnode->pNext = pNode->pNext;
					pNode->pNext = pNewnode;
					break;
				}

				pNode = pNode->pNext;
			}

			if (pNode->pNext == NULL)
			{
				pNode->pNext = pNewnode;
			}
		}
	}
}


void FindNode() //����ڰ� �Է��� ������ ������ ��忡 ����� �� ã��
{
	int count = 0; //���° node���� count++�ϸ鼭 ǥ�����ֱ�
	int data = 0;
	bool bFound;

	node *pFindNode = head; //Findnode�ϱ����� �Ǵٸ� ����
	printf("\n/////���Ե� ���ã��/////\n");
	printf("ã����� Data���� �Է��ϼ��� : ");
	scanf_s("%d", &data);

	while (pFindNode)
	{
		if (pFindNode->nData != data)         //ã�����Ͽ�����
		{
			bFound = false;
			count++;
		}
		else                 //ã������ break�ϰ� while�� ��������
		{
			bFound = true;
			break;
		}
		pFindNode = pFindNode->pNext;
	}
	
	if (bFound = false)
	{
		printf("ã���� ���� ���� ��忡 �����ϴ�.\n");
	}
	else
		printf("ã���� ����� �����ʹ� %d��°�� %d�Դϴ�.\n", count + 1, data);

}

int DeleteNode(int data)
{
	node *p = NULL;
	node *bridgeNode;//delete�� �� ����� ���� ���������ʰ� �������� �ӽó�� �ϳ�����
	node *pNode = head;

	bridgeNode = pNode->pNext;

	while (bridgeNode->nData != data && bridgeNode != p) //�ӽó���� �����Ͱ��� ����ڰ� �Է��� ���� �ƴϰ� p���ƴҶ�
	{
		pNode = pNode->pNext;
		bridgeNode = bridgeNode->pNext;
	}

	if (bridgeNode != p)
	{
		pNode->pNext = bridgeNode->pNext;  //pNode->pNext = NULL
		free(bridgeNode);
		return true;
	}
	else
		return false;
}

void PrintList()
{
	node* pNode = head;
	while (pNode)
	{
		printf("%d -> ", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
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
	//Ordered Insert
	printf("���� ������ �������� '0'�� �Է��ϼ���\n");
	printf("Put Insert number\n");
	while (1)
	{
		scanf_s("%d", &data);
		// ���� ���� Ȯ�� �� ��ȿ�� �˻� 

		if (data == 0)
		{
			printf("\nEnd InsertNode\n");
			break;
		}

		insertNode(data);
	}
	PrintList();

	//Find
	FindNode(); //���ã�� �Լ�ȣ��
	puts("");
	//delete
	int del_num;
	printf("Put Delete number :  ");
	scanf_s("%d", &del_num);
	DeleteNode(del_num);
	PrintList();

	system("pause");
	return 0;
}