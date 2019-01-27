//링크드 리스트 ordered insert / find / delete 구현

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

node *head = NULL;      //시작점
int insertNode(int);
void FindNode();
int DeleteNode(int);

int insertNode(int data)
{
	node *pNewnode = (node*)malloc(sizeof(node)); //노드 담을 공간 head메모리에 할당 (malloc)

	pNewnode->nData = data;
	pNewnode->pNext = NULL;   //pnewnode 는 독립적 공간

	if (NULL == head)
	{
		head = pNewnode;
	}
	else
	{
		node* pNode = head; //또다른공간
		//제일 작은수가 들어왔을 때
		if (pNewnode->nData <= pNode->nData)
		{
			pNewnode->pNext = pNode;
			head = pNewnode;
		}
		else
		{
			//중간값인 수가 들어왔을 때
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


void FindNode() //사용자가 입력한 데이터 값으로 노드에 저장된 값 찾기
{
	int count = 0; //몇번째 node인지 count++하면서 표현해주기
	int data = 0;
	bool bFound;

	node *pFindNode = head; //Findnode하기위한 또다른 공간
	printf("\n/////삽입된 노드찾기/////\n");
	printf("찾고싶은 Data값을 입력하세요 : ");
	scanf_s("%d", &data);

	while (pFindNode)
	{
		if (pFindNode->nData != data)         //찾지못하였을때
		{
			bFound = false;
			count++;
		}
		else                 //찾았을때 break하고 while문 빠져나옴
		{
			bFound = true;
			break;
		}
		pFindNode = pFindNode->pNext;
	}
	
	if (bFound = false)
	{
		printf("찾으신 노드는 현재 노드에 없습니다.\n");
	}
	else
		printf("찾으신 노드의 데이터는 %d번째의 %d입니다.\n", count + 1, data);

}

int DeleteNode(int data)
{
	node *p = NULL;
	node *bridgeNode;//delete할 때 노드의 선이 끊어지지않게 연결해줄 임시노드 하나형성
	node *pNode = head;

	bridgeNode = pNode->pNext;

	while (bridgeNode->nData != data && bridgeNode != p) //임시노드의 데이터값이 사용자가 입력한 값이 아니고 p가아닐때
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

	//Find
	FindNode(); //노드찾는 함수호출
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