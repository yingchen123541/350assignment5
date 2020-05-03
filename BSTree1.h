class BSTree1{
  public:
    BSTree1();
    ~BSTree1();
    //virtual ~BSTree() , when working with template class
    void insert(int value);//here value is also our key
    bool search(int value);//here value is also our key, return whether certain item is in there or not, return true or false, can change it to return other stuffs like position
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode1* getMin();
    TreeNode1* getMax();

    TreeNode1* getsuccessor(TreeNode1 *d);
    void printTree(TreeNode1 *node);

  private:
    TreeNode1 *root;
};
