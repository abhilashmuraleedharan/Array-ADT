/*
 * Demo of Array ADT
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */

#include "Array.h"
#include "enumerations.h"

int main() {
   std::cout << "Program demonstrating Array ADT" << std::endl;
   // Enabling conversion from bool to strings "true" and "false" for the std::cout stream. 
   std::cout << std::boolalpha;
 {
#if 0
   try {
      char input_array[] = { 'A', 'b', 'h', 'i', 'l', 'a', 's', 'h'};
      Array<char> array = {input_array, 8, 8};
      std::cout << "array: " << std::endl;
      array.display();
      std::cout << "size: " << array.size() << " length: " << array.length() << std::endl;
      std::cout << "Is array full?: " << array.isFull() << std::endl;
      std::cout << "Inserting a new element \'a\' at 6th index" << std::endl;
      array.insertItem(6, 'a');
      array.display();
      std::cout << "size: " << array.size() << " length: " << array.length() << std::endl;
      std::cout << "Appending a new element \'M\' to the array" << std::endl;
      array.append('M');
      array.display();
      std::cout << "size: " << array.size() << " length: " << array.length() << std::endl;
      std::cout << "Inserting a new element \'.\' at 9th index" << std::endl;
      array.insertItem(9, '.');
      array.display();
      std::cout << "size: " << array.size() << " length: " << array.length() << std::endl;
      std::cout << "Delete item at index 5" << std::endl;
      std::cout << "Deleted item: " << array.deleteItem(5) << std::endl;
      array.display();
      std::cout << "size: " << array.size() << " length: " << array.length() << std::endl;
      std::cout << "Is array full?: " << array.isFull() << std::endl;

   } catch (const std::runtime_error & e) {
      std::cerr << "Exception: " << e.what() << std::endl;
   }
#endif
 }

 {
#if 1
   try { 
      int input_array[] = {24, 56, 77, 92, 1, 33, 63, 45, 81, 100};
      Array<int> array(input_array, 20, 10);
      std::cout << "array: " << std::endl;
      array.display();
      std::cout << "size: " << array.size() << " length: " << array.length() << std::endl;
      std::cout << "Is array full?: " << array.isFull() << std::endl;
      std::cout << "Check if item 92 is present in the Array" << std::endl;
      int index = array.linearSearch(92);
      if (index == -1) 
         std::cout << "Item 92 not found" << std::endl;
      else
         std::cout << "Item 92 found at index: " << index << std::endl;
      
      std::cout << "Check if element 63 is present in the Array using Transposition strategy" << std::endl;
      index = array.linearSearch(63, TRANSPOSITION);
      if (index == -1) 
         std::cout << "Item 63 not found" << std::endl;
      else
         std::cout << "Item 63 found at index: " << index << std::endl;
      array.display();

      std::cout << "Check if element 100 is present in the Array using Move to Front strategy" << std::endl;
      index = array.linearSearch(100, MOVE_TO_FRONT);
      if (index == -1) 
         std::cout << "Item 100 not found" << std::endl;
      else
         std::cout << "Item 100 found at index: " << index << std::endl;
      array.display();

   } catch (const std::runtime_error & e) {
      std::cerr << "Exception: " << e.what() << std::endl;
   }
#endif
 }
   return 0;
}
