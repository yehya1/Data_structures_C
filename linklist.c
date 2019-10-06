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

int main()
{
	node *head = NULL;
	node *tail = NULL;
	for (int i = 0; i < 8; i++) {
		add_node_in_start(i + 1, head, tail);
		add_node_in_end(i + 1, head, tail);
	}
	print_list(head);

}