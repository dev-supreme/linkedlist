//Double linkedlist 구현
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

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
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //노드 담을 공간 head메모리에 할당 (malloc)

	pNewNode->nData = data;
	pNewNode->pNext = NULL;   //pnewNode 는 독립적 공간
	pNewNode->pPrev = NULL;

	if (NULL == head)
	{
		head = pNewNode;
		tail = pNewNode;
	}
	else
	{
		Node* pNode = head;
		//제일 작은수가 들어왔을 때
		if (pNewNode->nData <= pNode->nData)
		{
			pNewNode->pNext = head;
			head = pNewNode;
			pNewNode->pPrev = NULL;
			pNode->pPrev = pNewNode;
			
		}
		else
		{//중간값인 수가 들어왔을 때
			while (pNode->pNext != NULL)	
			{
				tail = pNode;
				if (pNewNode->nData <= pNode->pNext->nData)
				{
					pNewNode->pNext = pNode;
					pNode->pNext = pNewNode;
					pNewNode->pPrev = pNewNode->pNext->pPrev;
					pNode->pPrev = pNewNode;
					break;
				}

				pNode = pNode->pNext;
			}

			if (pNode->pNext == NULL)
			{
				pNode->pNext = pNewNode;
				tail = pNewNode;
				pNewNode->pPrev = pNode;
			}
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
	printf("숫자 삽입을 끝내려면 '0'을 입력하세요\n");
	printf("Put Insert number\n");
	while (1)
	{
		scanf_s("%d", &data);
		// 종료 조건 확인 및 유효성 검사 

		if (data == 0)
		{
			printf("\nEnd InsertNode\n");
			break;
		}

		insertNode(data);
	}
	PrintList();

	system("pause");
	return 0;
}