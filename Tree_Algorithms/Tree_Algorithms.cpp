// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include "Tree_Algorithms.h"

using namespace std;

int main()
{
   Tx splay_test = Tx();
    
   // Set 1 Splay on 35

   BST<int> test = BST<int>();
   test.insert(39);
   test.insert(17);
   test.insert(13);
   test.insert(11);
   test.insert(15);
   test.insert(31);
   test.insert(35);
   test.insert(33);
   test.insert(37);
   test.insert(21);
   test.insert(19);
   test.insert(27);
   test.insert(23);
   test.insert(29);
   test.insert(25);

   try {
      cout << splay_test.splay_find(test, 35) << endl;
   }
   catch (BST<int>::Not_found_exception e) {
      cout << e.to_string() << endl;
   }

   //---------------
   // Set 2 Splay on 36

   BST<int> test2 = BST<int>();
   test2.insert(40);
   test2.insert(18);
   test2.insert(14);
   test2.insert(12);
   test2.insert(16);
   test2.insert(32);
   test2.insert(36);
   test2.insert(38);
   test2.insert(34);
   test2.insert(22);
   test2.insert(20);
   test2.insert(28);
   test2.insert(30);
   test2.insert(24);
   test2.insert(26);

   try {
      cout << splay_test.splay_find(test2, 36) << endl;
   }
   catch (BST<int>::Not_found_exception e) {
      cout << e.to_string() << endl;
   }

   //---------------
   // Set 3 Splay on 36

   BST<int> test3 = BST<int>();
   test3.insert(126);
   test3.insert(38);
   test3.insert(22);
   test3.insert(14);
   test3.insert(30);
   test3.insert(94);
   test3.insert(54);
   test3.insert(110);
   test3.insert(102);
   test3.insert(118);
   test3.insert(46);
   test3.insert(78);
   test3.insert(62);
   test3.insert(86);
   test3.insert(70);

   try {
      cout << splay_test.splay_find(test3, 54) << endl;
   }
   catch (BST<int>::Not_found_exception e) {
      cout << e.to_string() << endl;
   }

   //---------------
// Set 4 Splay on 3

   BST<int> test4 = BST<int>();
   //test4.insert(7);
   //test4.insert(1);
   //test4.insert(10);
   //test3.insert(14);
   //test3.insert(30);
   //test3.insert(94);
   //test3.insert(54);
   //test3.insert(110);
   //test3.insert(102);
   //test3.insert(118);
   //test3.insert(46);
   //test3.insert(78);
   //test3.insert(62);
   //test3.insert(86);
   //test3.insert(70);

   try {
      //splay_test.splay_insert(test4, 2);
      //splay_test.splay_insert(test4, 1);
      //splay_test.splay_insert(test4, 7);
      //splay_test.splay_insert(test4, 10);
      //splay_test.splay_insert(test4, 3);
      //splay_test.splay_insert(test4, 2);
      cout << splay_test.splay_contains(test4, 9) << endl;
   }
   catch (BST<int>::Not_found_exception e) {
      cout << e.to_string() << endl;
   }

}
