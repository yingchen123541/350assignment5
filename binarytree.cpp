#include "binarytree.h"

//constructor
template <class T>
BST<T>::BST(){
  root = NULL;
}

//destructor
template <class T>
BST<T>::~BST(){
  //figure it out
  // build character
  delete root;
}
//core functions
//////////////////////////

//inserts an object into the tree and assigns it a key
template <class T>
void BST<T>::insert(T node, int k){
  TreeNode<T> *temp = new TreeNode<T>(node, k);
//key is the value
//empty tree
  if(root == NULL){
    root = temp;
  }else{
    //tree not empty, we need to find the insert location
    TreeNode<T> *curr = root;
    TreeNode<T> *parent = NULL; // empty TreeNode

    while(curr != NULL){
      parent = curr;

      if(temp->key < curr->key){
        // go left
        curr = curr->left;
        if(curr == NULL){
          parent->left = temp;
          break;
        }
      }else{
        //go right
        curr = curr->right;
        if(curr == NULL){
          //found nodes home
          parent->right = temp;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::search(int k){
  if(isEmpty()){
    return false;
  }else{
    //the tree is not empty
    TreeNode<T> *curr = root;

    while(curr->key != k){
      if(k < curr->key){
        //go left
        curr = curr->left;
      }else{
        //go right
        curr = curr->right;
      }
      if(curr == NULL){
        return false;
      }
    }
  }
  return true;
}

//returns the value of a node if given the key
template <class T>
T BST<T>::returnT(int k){
  TreeNode<T> *curr = root;

  while(curr->key != k){
    if(k < curr->key){//go left
      curr = curr->left;
    }else{//go right
      curr = curr->right;
    }
  }
  cout << curr->data << endl;
 return curr->data;
}


template <class T>
bool BST<T>::deleteNode(int k){
  //successor is the node that takes the place of the deleted nodes
  // node that replaces has to replace the integrity of the Tree
  if(isEmpty()){
    return false;
  }else{
    // tree is not empty and value exists
    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;
    //usual code to find nodes
    while(curr->key != k){
      parent = curr;
      if(k < curr->key){
        //go left
        isLeft = true;
        curr = curr->left;
      }else{
        //go right
        isLeft = false;
        curr = curr->right;
      }
      if(curr == NULL){//we did not find the value
        return false;
      }
      //if we made if here, then we have ofund the node to deleted
    }
    //no childern clause
    if(curr->left == NULL && curr->right == NULL){
      //case 1, is a leaf
      if(curr == root){
        root = NULL;

      }else if(isLeft){
        parent->left = NULL;
      }else{
        parent->right = NULL;
      }
      cout << "deleted." << endl;
      delete curr;
    }
    //the node has 1 child
    //first determine if left or right
    else if(curr->right == NULL){
      //has left child and not a right child
      if(curr == root){
        root = curr->left;
      }else if(isLeft){
        parent->left = curr->left;
      }else{
        parent->right = curr->left;
      }
      delete curr;
    }else if(curr->left == NULL){
      //has right child
      if(curr == root){
        root = curr->right;
      }else if(isLeft){
        parent->left = curr->right;
      }else{
        parent->right = curr->right;
      }
      cout << "deleted." << endl;
      delete curr;
    }else{
      //the node has 2 children :((
      TreeNode<T> *successor = getSuccessor(curr);

      if(curr == root){
        root = successor;
      }else if(isLeft){
        parent->left = successor;
      }else{
        parent->right = successor;
      }

      successor->left = curr->left;
      cout << "deleted." << endl;
      delete curr;
    }
  }
  return true;
}

//We find the successor of the node by going to the right child
// and finding the min
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  //d is the node to be deleted
  TreeNode<T> *sp = d;
  //successor's parent
  TreeNode<T> *successor = d;
  TreeNode<T> *curr = d->right;

  while(curr !=NULL){
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

////////helper functions///////////////

template <class T>
bool BST<T>::isEmpty(){
  return(root == NULL);
  //or size = 0;
}

//prints the tree inorder
template <class T>
void BST<T>::printTree(TreeNode<T> *node){
  if(node == NULL){
    return;
  }

  printTree(node->left);
  cout << node->data << endl;
  printTree(node->right);
}

//calls the recPrint function on the root
template <class T>
void BST<T>::printRoot(){
  printTree(root);
}

//prints the tree preorder
template <class T>
void BST<T>::printPreorder(TreeNode<T> *node){
  if(node == NULL){
    return;
  }
  cout << node->data << endl;
  printPreorder(node->left);
  printPreorder(node->right);
}

//prints the tree to a file for student data base
template <class T>
void BST<T>::printToFile(TreeNode<T> *node, ofstream& out){
  if(node == NULL){
    return;
  }
  out << node->data << endl;
  printToFile(node->left, out);
  printToFile(node->right, out);
}

//calls the print on the root
template <class T>
void BST<T>::PrintFileR(ofstream& out){
  printToFile(root, out);
}

//returns the id with the lowest key value
template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *curr = root;
//if tree is empty
  if(curr == NULL){
    return NULL;
  }
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

//returns the id with the highest key value
template <class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T> *curr = root;
//if tree empty return null
  if(curr == NULL){
    return NULL;
  }
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}





//old code ignore delete later
// class BST{
// public:
// //fill in code
// private:
//   TreeNode *root;
//
// };
//
// BST::BST(){
//   root = NULL;
// }
//
// //deconstructor
// BST::~BST(){
//   // build character
// }
//
// void BST::printTree(TreeNode *node){
//   // must be recursive
//   if(node == NULL){
//     return;
//   }
//
//   printTree(node -> left);
//   cout << node -> key << endl;
//   printTree(node -> right);
// }
//
// TreeNode* BST::getMax(){
//   TreeNode *curr = root;
//
//   if(root == NULL){
//     return NULL; // tree is empty
//   }
//   while(curr -> right != NULL){
//     curr = curr -> right;
//   }
//   return curr; // curr -> key
//   // if a tree consisted of numeric type
// }
//
// bool BST::isEmpty(){
//   return(root == NULL); // or size = 0
// }
// //fill in code
// void BST::insert(int value){
//   TreeNode *node = new TreeNode(value);
//   // value is also the key
//   if(root == NULL){
//     root =node;
//   }else{
//     //tree is not empty, we need to find the location
//     TreeNode *curr = root;
//     TreeNode *parent; // empty TreeNode
//
//     if(value < curr -> key){
//       // go left
//       curr = curr -> left;
//     }
//     if(curr == NULL){
//       parent -> left = node;
//       break;
//     }
//   }else{
//     // go right
//     curr = curr -> right;
//     // found the nodes home
//     parent ->right = node;
//     break;
//   }
// }
//
// bool BST::search(int value){
//   if(isEmpty()){
//     return false;
//   }else{
//   //tree is not isEmpty
//   TreeNode *current = root;
//
//   while(current -> key!=value){
//     if(value < current ->key){
//       current = current ->left;
//     }else{
//       current = current -> right;
//     }
//
//     if(current == NULL){
//       return false;
//     }
//     return true;
//   }
// }
// }
//
// bool BST::deleteNode(int K){
// //successor is the node that takes the place of the deleted nodes
// // node that replaces has to replace the integrity of the Tree
//   if(isEmpty()){
//     return false;
//   }else if(!search(k)){
//     return false;
//   }//can leverage search here
// // tree is not empty and value exists
//
//   TreeNode *current = root;
//   TreeNode *parent = root;
//   bool isLeft = true;
//   //usual code to find nodes
//   while(current -> key!=k){
//     parent = current;
//     if(k < current -> key){
//       isLeft = true;
//       current = current -> left;
//     }else{
//       isLeft = false;
//       current = current ->right;
//     }
//     if(current == NULL){
//       return false;
//     }
//     //if we made if here, then we have ofund the node to deleted
//   }
//
// // no childern classe
//   if(current -> left == NULL && current -> right == NULL){
//     // is a leaf
//     if(current == root){
//       root = NULL;
//     }else if(isLeft){
//       parent -> left = NULL;
//     }else{
//       parent -> right = NULL;
//     }
//     // one child and the child is left
//   }else if (current -> right == NULL){
//     //does not have a right child
//     if(current == root){
//       root = current -> left;
//     }else if(isLeft){
//       parent -> left = current -> left;
//     }else{
//       parent -> right = current -> left;
//     }
//   }else if (current -> left == NULL){
//   //does not have a right child
//   if(current == root){
//     root = current -> right;
//   }else if(isLeft){
//     parent -> left = current -> right;
//   }else{
//     parent -> right = current -> right;
//   }
// }else{
//   //the node has 2 childern :(((
//   TreeNode *successor = getSuccessor(current);
//   if(current == root){
//     root = successor;
//   }else if(isLeft){
//     parent -> left = successor;
//   }
//   else
//     parent ->right = successor'
//
// //}
// successor -> left = current -> left;
// return true;
// }
// }
//
// TreeNode* BST::getSuccessor(TreeNode *d){
//   // d is the node to b delete
//   TreeNode *sp = d;
//   TreeNode *successor = d;
//   TreeNode *current = d -> right;
//
//   while(current != NULL){
//     sp = successor;
//     successor = current;
//     current = current -> left;
//   }
//   if(successor != d -> right){
//     sp -> left = successor -> right;
//     successor -> right = d -> right;
//   }
//   return successor;
// }
//
//
//
// /////
