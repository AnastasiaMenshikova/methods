class Matrix
{
	struct Node {
		int line, column, info;
		Node *right, *down;
	};

	Node *headcolumn, *headline;

public:
	Matrix();
	~Matrix();
	void Push(int line, int column, int info); 
	void Del(int line, int column); 
	int Search(int line, int column); 
	void DelMatrix();

	typedef Node* iterater;
	iterater GetLineHead();
	iterater GetColumnHead();
	iterater GetRight(iterater a);
	iterater GetDown(iterater a);
	int GetLine(iterater a);
	int GetColumn(iterater a);
	int GetInfo(iterater a);
	bool IsEmptyMatrix();
	bool IsExistVector(int line, int column);
	int SumLine(int line);
	int SumColumn(int column);
};
