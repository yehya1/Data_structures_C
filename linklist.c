#include <iostream>
struct node
{
	int data;
	struct node *next;
};
void print_list(node* head)
{
	node* tmp = head;
	while (tmp != NULL)
	{
		printf("%d  ", tmp->data);
		tmp = tmp->next;
	}
	printf("%s", "\n");
}
void print_listR(node* head)
{
	node* tmp = head;

	while (tmp != NULL)
	{
		printf("%d  ", tmp->data);
		tmp = tmp->next;
	}
	printf("%s", "\n");
}
void add_node_in_start(int n, node*& head, node*& tail)
{
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;

	if (head == NULL)
	{
		tail = tmp;
		head = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;

	}
}
void add_node_in_end(int n, node*& head, node*& tail )
{
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	if (tail == NULL) {
		tail = tmp;
		head = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}
}
void print_in_index(int index, node*& haed) {
	node *temp = haed;
	int i;
	for (i = 1;i != index && temp->next != NULL;i++)
		temp = temp->next;
	printf("%d\n",temp->data);

}
void add_node_in_index(int index,int n,node*& head, node*& tail) {
	node *temp = head;
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	
	if (head == NULL) {
		tail = tmp;
		head = tmp;
	}
	else {
		if (index == 1) {
			add_node_in_start(n, head, tail);
			return;
		}
		for (int i = 2;i != index&&temp->next!=NULL;i++)
			temp = temp->next;
		if (temp->next == NULL)
			add_node_in_end(n, head, tail);
		else {
			tmp->next = temp->next;
			temp->next = tmp;
		}

	}

}

int main()
{
	node *head = NULL;
	node *tail = NULL;
	for (int i = 0; i < 8; i++) {
		add_node_in_start(i + 1, head, tail);
		add_node_in_end(i + 1, head, tail);
	}
	add_node_in_index(2, 100, head, tail);
	print_list(head);
}