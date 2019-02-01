//Double linkedlist 구현
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
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //노드 담을 공간 head메모리에 할당 (malloc)

	pNewNode->nData = data;
	pNewNode->pNext = NULL;   //pnewNode 는 독립적 공간
	pNewNode->pPrev = NULL;

	if (NULL == head)
	{
		head = pNewNode;
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
			while (pNode->pNext != NULL)	//순서주의!!
			{
				if (pNewNode->nData <= pNode->pNext->nData)
				{
					pNewNode->pNext = pNode->pNext;   //NewNode의 Next를 오른쪽공간에 연결
					pNewNode->pPrev = pNode;          //NewNode의 Prev를 왼쪽공간에 연결
					pNode->pNext->pPrev = pNewNode;   //오른쪽공간의 Prev를 NewNode에 연결
					pNode->pNext = pNewNode;          //왼쪽공간의 Next를 NewNode에 연결
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
	if (data <= avg) //입력한 값이 평균보다 작으면 head에서부터 탐색
	{
		while (pNode)
		{
			if (pNode->nData != data)         //찾지못하였을때
			{
				bFound = false;
			}
			else                 //찾았을때 break하고 while문 빠져나옴
			{
				bFound = true;
				break;
			}
			pNode = pNode->pNext;
		}
	}
	else if (avg < data) //입력한 값이 평균보다 크면 tail에서부터 탐색
	{
		pNode = tail;
		while (pNode)
		{
			if (pNode->nData != data)         //찾지못하였을때
			{
				bFound = false;
			}
			else                 //찾았을때 break하고 while문 빠져나옴
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
	int Avg = 0; //앞에서부터 탐색할건지 뒤에서부터 탐색할건지 판단해주는 평균flag

	//Ordered Insert
	printf("숫자 삽입을 끝내려면 '0'을 입력하세요\n");
	printf("Put Insert number\n");
	while (true)
	{
		scanf_s("%d", &data);
		// 종료 조건 확인 및 유효성 검사 

		if (data == 0)
		{
			printf("\nEnd InsertNode\n");
			break;
		}

		insertNode(data);

		sum += data; //사용자가 입력한 값의 전체합
		count++; //사용자가 입력한 값 개수
	}

	PrintList();
	//Average
	Avg = sum / count;
	//Find Node
	printf("\n/////삽입된 노드찾기/////\n");
	printf("찾고싶은 Data값을 입력하세요 : ");
	scanf_s("%d", &data);

	data = FindNode(data, Avg);
	if (data == false)
	{
		printf("찾으신 노드는 현재 노드에 없습니다.\n");
	}
	else if(data)
		printf("%d", data);
	puts("");


	system("pause");
	return 0;
}