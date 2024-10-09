#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

node* allocNode(int data)
{
	node* item = (node*)malloc(sizeof(node));
	item->data = data;
	item->next = NULL;
	return item;
}

node* createList(int n)
{
	int i;
	node* head = NULL;
	node* tail = NULL;

	for (i = 1; i <= n; i++)
		if (head == NULL)
			head = tail = allocNode(i);
		else
		{
			tail->next = allocNode(i);
			tail = tail->next;
		}

	if (head != NULL)
		tail->next = head;

	return head;
}

void printList(node* head)
{
	while (head != NULL)
	{
		printf("[%d]-> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

node* JosephusPermutation(node* head, int m)
{
	node* jHead = NULL;
	node* jTail = NULL;

	//if (head == NULL) not needed, we don't enter the while, and return NULL.
	//	return head;

	//if (head->next == head) not needed, loop handle one element.
	//{
	//	head->next = NULL;
	//	return head;
	//}

	while (head != NULL)
	{
		int i;
		for (i = 0; i < m - 2; i++)
			head = head->next;

		if (jHead == NULL)
			jHead = jTail = head->next;
		else
		{
			jTail->next = head->next;
			jTail = jTail->next;
		}

		head->next = head->next->next;
		jTail->next = NULL;
		head = head->next;
	}

	return jHead;
}

void freeList(node** head)
{
	node* temp = *head;
	while (*head != NULL)
	{
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
}

int main()
{
	node* head = createList(8);

	head = JosephusPermutation(head, 3);

	printList(head);

	freeList(&head);

	printList(head);

	return 0;
}