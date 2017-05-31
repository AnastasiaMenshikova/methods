typedef void(*FCallback)(int);
class bst
{
	struct Node {
		int info;
		Node *left, *right;
	};

	Node *Top;
	void Push(Node *root, int info);
	void Del(Node *&root, int info);
	int Depth(Node *root, int depth);
	void Straight(FCallback callback, Node *root);
	void Symmetric(FCallback callback, Node *root);
	void Back(FCallback callback, Node *root);
	int minimum(Node *root);  
public:
	bst();
	~bst();
	void PushWrapper(int info); 
	void DelWrapper(int info); 
	int DepthWrapper(); 
	void DelTree();
	void StraightWrapper(FCallback callback); 
	void SymmetricWrapper(FCallback callback); 
	void BackWrapper(FCallback callback); 
	void Width(FCallback callback);
	bool IsEmptyTree();
	bool IsExistElem(int info);
};
