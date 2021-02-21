#include <iostream>
using namespace std;

struct Linkedlist
{
	int value = 0;
	int line = 0;
	Linkedlist* next = NULL;
};

Linkedlist** edge = new Linkedlist*[20001];
int V, E, K, u, v, w;

void link() {
	Linkedlist* location;

	location = new Linkedlist;
	location->value = w;
	location->line = v;
	location->next = edge[u];
	edge[u] = location;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> V >> E >> K;
	for (int k = 0; k < E; k++) {
		cin >> u >> v >> w;
		link();
	}
}

/*
void link2() {
	Linkedlist* newNode;
	Linkedlist* predLoc;
	Linkedlist* location;
	bool found;

	newNode = new Linkedlist;
	newNode->value = v;
	newNode->line = w;
	newNode->next = NULL;
	if (edge[u].value != 0) {
		newNode->next = predLoc->next;
		predLoc->next = newNode;
	}
	else {
		edge[u] = *newNode;
		newNode->next = newNode;
	}
}
void link1() {
	Linkedlist count = edge[u];
	Linkedlist temp;
	while (count.next != NULL)
		count = *count.next;
	temp.value = w;
	temp.line = v;
	temp.next = NULL;
	count.next = &temp;
}*/