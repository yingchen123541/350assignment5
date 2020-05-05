#include <iostream>

class TreeNode1{
 public:
  TreeNode1();
  //a node consists a key value, so always do int key in overload constructor, also sorting on int
  TreeNode1(int key);
  //or can use this one, if sorting on string not int, k is key
  //TreeNode(int k, <type> value);
  ~TreeNode1();
  //when working with template classes, use this one, search why use virtual keyword
  //virtual ~TreeNode();

  int key;
  TreeNode1 *left;
  TreeNode1 *right;


};
