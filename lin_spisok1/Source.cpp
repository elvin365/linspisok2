#include "stdio.h"
#include "stdlib.h"

struct Node {
	int Data;
	Node* next;
};

Node* add(Node *head, int Value)
{
	Node *New = (Node*)malloc(sizeof(Node));
	New->Data = Value;
	New->next = head;
	return New;
}
 Node* add1(Node* head,Node* del)
{
	Node *New = (Node*)malloc(sizeof(Node));
	New->Data = 777;
	New->next = del->next;
	del->next = New;
	
	return head;
}
 Node* add2(Node* head, Node* del)
 {
	 Node *New = (Node*)malloc(sizeof(Node));
	 New->Data = 888;
	 New->next = del;
	 Node *Pcur=head;
	 while (Pcur->next != del)
	 {
		 Pcur = Pcur->next;
	 }
	 Pcur->next = New;
	 return head;
 }

void Show(Node* head)
{
	while (head)
	{
		printf("%d\n", head->Data);
		head = head->next;
	}
}

Node* Find(Node *head, int Value)
{
	while (head)
	{
		if (head->Data == Value)
			return head;
		head = head->next;
	}
	return NULL;
}
Node* Find2(Node* head, Node* del)
{
	while (head)
	{
		if (head->next != del)
		{
			head = head->next;
		}
		return head;
	}
}

Node* Delete(Node* head, Node* removable)
{
	if (head == removable)
	{
		head = head->next;
		free(removable);
	}
	else
	{
		Node *prev = head;
		while (prev->next != removable)
		{
			prev = prev->next;
		}

		prev->next = removable->next;
		free(removable);
	}
	return head;
}

int main()
{
	Node *a = NULL;

	for (int i = 0; i < 5; i++)
		a = add(a, i);

	Show(a);
	putchar('\n');
	Node *del = Find(a, 2);
	Node* a1 = NULL;
	getchar();
	a=add1(a,del);
	//a = Delete(a, del);
	getchar();
	Show(a);
	getchar();
	a = add2(a, del);
	putchar('\n');
	Show(a);
	a = Delete(a, del->next);
	putchar('\n');
	Show(a);

	system("PAUSE");
	return 0;
}