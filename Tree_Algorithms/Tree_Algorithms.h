// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include "BST.h"

using namespace std;

#ifndef Tree_Algorithms_h
#define Tree_Algorithms_h

class Tx {
private:

   template <typename T> static void insert(typename BST<T>::Node*& current, typename BST<T>::Node*& p) {
      if (p == nullptr) {
         return;
      }
      else if (current == nullptr) {
         current = p;
         return;
      }
      else {
         if (current->_data > p->_data) {
            return insert<T>(current->_left, p);
         }
         else {
            return insert<T>(current->_right, p);
         }
      }
   }

   template <typename T> static void _splay(typename BST<T>::Node*& p, const T& x) {
      if (p == nullptr || !x) {
         return;
      }
      
      typename BST<T>::Node* left_tree_root = nullptr;
      typename BST<T>::Node* right_tree_root = nullptr;

      typename BST<T>::Node* top_node;

      while (p->_data != x) {
         if (p->_data > x) {
            if (p->_left == nullptr) {
               break;
            }
            else if (p->_left->_data > x) {
               _rotate_with_left_child<T>(p);
               if (p->_left != nullptr) {
                  top_node = p;
                  p = p->_left;

                  top_node->_left = nullptr;

                  insert<T>(right_tree_root, top_node);
               }
            } 
            else if (p->_left->_data < x) {
               top_node = p;

               p = p->_left;

               top_node->_left = nullptr;
               insert<T>(right_tree_root, top_node);

            }
            else {
               // p->_left is equal to x
               top_node = p;
               p = p->_left;
               top_node->_left = nullptr;
               insert<T>(right_tree_root, top_node);
            }
         }
         else {
            if (p->_right == nullptr) {
               break;
            }
            else if (p->_right->_data < x) {
               _rotate_with_right_child<T>(p);
               if (p->_right != nullptr) {
                  top_node = p;
                  p = p->_right;

                  top_node->_right = nullptr;

                  insert<T>(left_tree_root, top_node);
               }
            }
            else if (p->_right->_data > x) {
               top_node = p;

               p = p->_right;

               top_node->_right = nullptr;
               insert<T>(left_tree_root, top_node);
            }
            else {
                //p->_right is equal to x
               top_node = p;
               p = p->_right;
               top_node->_right = nullptr;
               insert<T>(left_tree_root, top_node);
            }
         }
      }

      typename BST<T>::Node* left_child = p->_left;
      typename BST<T>::Node* right_child = p->_right;

      p->_left = nullptr;
      p->_right = nullptr;

      insert<T>(left_tree_root, left_child);
      insert<T>(right_tree_root, right_child);
      
      p->_left = left_tree_root;
      p->_right = right_tree_root;

      return;

   }

   template <typename T> static void _rotate_with_left_child(typename BST<T>::Node*& p) {
      if (p == nullptr || p->_left == nullptr) {
         return;
      }
      typename BST<T>::Node* right_grandchild = p->_left->_right;
      typename BST<T>::Node* left_child = p->_left;
      p->_left = right_grandchild;
      left_child->_right = p;
      p = left_child;
      return;
   }

   template <typename T> static void _rotate_with_right_child(typename BST<T>::Node*& p) {
      if (p == nullptr || p->_right == nullptr) {
         return;
      }
      typename BST<T>::Node* left_grandchild = p->_right->_left;
      typename BST<T>::Node* right_child = p->_right;
      p->_right = left_grandchild;
      right_child->_left = p;
      p = right_child;
      return;
   }

public:
   template <typename T> static const T& splay_find(BST<T>& tree, const T& x) {
      _splay(tree._root, x);
      if (tree._root == nullptr) {
         throw typename BST<T>::Not_found_exception();
      }
      else if (tree._root->_data == x) {
         return tree._root->_data;
      }
      else {
         throw typename BST<T>::Not_found_exception();
      }
   }

   template <typename T> static bool splay_contains(BST<T>& tree, const T& x) {
      if (tree._root == nullptr) {
         return false;
      }
      
      try {
         splay_find(tree, x);
      }
      catch (typename BST<T>::Not_found_exception e) {
         cout << e.to_string() << endl;
      }

      if (tree._root->_data == x) {
         return true;
      }
      return false;
   }

   template <typename T> static bool splay_insert(BST<T>& tree, const T& x) {
      
      if (!x) {
         return false;
      }
      if (tree._root == nullptr) {
         tree.insert(x);
         return true;
      }
      _splay(tree._root, x);
      if (tree._root->_data == x) {
         return false;
      }
      else if (tree._root->_data < x) {
         tree._root = new typename BST<T>::Node(x, tree._root, tree._root->_right);
         tree._root->_left->_right = nullptr;
         tree._size++;
         return true;
      }
      else {
         tree._root = new typename BST<T>::Node(x, tree._root->_left, tree._root);
         tree._root->_right->_left = nullptr;
         tree._size++;
         return true;
      }
   }

   template <typename T> static bool splay_remove(BST<T>& tree, const T& x) {
      _splay(tree._root, x);
      if (tree._root == nullptr || tree._root->_data != x) {
         return false;
      }
      else {
         typename BST<T>::Node* delete_node = tree._root;
         if (tree._root->_left != nullptr) {
            _splay(tree._root->_left, tree._find_max(tree._root->_left)->_data);
            tree._root->_left->_right = tree._root->_right;
            tree._root = tree._root->_left;
         }
         else {
            tree._root = tree._root->_right;
         }

         delete delete_node;
         tree._size--;
         return true;
      }
   }

   // beginning of Testing functions

   //template <typename T> static void _rotate_left_child(BST<T>& tree) {
   //   _rotate_with_left_child<int>(tree.get_root());
   //}

   //template <typename T> static void _rotate_right_child(BST<T>& tree) {
   //   _rotate_with_right_child<int>(tree.get_root());
   //}

   // end of Testing functions

   friend class Tests; // Don't remove
};

#endif