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

   return 0;
}
