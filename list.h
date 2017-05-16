class list
{
	struct node
	{
		int value;
		node *next;
		node *prev;
	};

	node *head;	//указатель на начало списка
	node *tail;	//указатель на конец списка
	void Del(); //функция удаляет первый элемент в списке, используется в void Clear(); для очистки списка

public:

	list();
	~list();
	void PushHead(int a);  
	void PushTail(int a);  
	void PushBefore(int key, int a);
	void PushAfter(int key, int a); 
	int PopHead(); 
	int PopTail(); 
	bool Search(int key); 
	void DelKey(int key);
	void RandPush(int amount, int range); 
	void Sort(); 
	void Clear(); 
	typedef node* iterater; 
	iterater getHead();
	iterater getTail();
	iterater getNext(iterater a);
	iterater getPrev(iterater a); 
	int getInf(iterater a); 
	bool IsEmpty(); 
};
