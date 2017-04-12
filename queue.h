class queue
{
	struct node
	{
		int value; 
		node *next;
	};

	node *head;	//указатель на начало очереди
	node *tail;	//указатель на конец очереди

public:
	queue();
	~queue();

	void push(int);
	int pop();
	bool Search(int key);
	void RandPush(int amount, int range);
	void Del();
	void Clear();
	typedef node* iterater;
	iterater getHead();
	iterater getTail();
	iterater getNext(iterater a);
	int getInf(iterater a);
	bool IsEmpty();
};
