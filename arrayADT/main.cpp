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
      int input_array[] = {24, 56, 77, 92, 100, 253, 478, 512, 777, 1024};
      Array<int> array(input_array, 10, 10);
      std::cout << "array: " << std::endl;
      array.display();
      std::cout << "size: " << array.size() << " length: " << array.length() << std::endl;
      std::cout << "Is array full?: " << array.isFull() << std::endl;
      std::cout << "Check if item 92 is present in the Array" << std::endl;
      int index = array.binarySearch(92);
      if (index == -1)
         std::cout << "92 is not present in the array" << std::endl;
      else
         std::cout << "92 found at index " << index << std::endl;
      array.display();
      std::cout << "Check if item 777 is present in the Array" << std::endl;
      index = array.binarySearch(777);
      if (index == -1)
         std::cout << "777 is not present in the array" << std::endl;
      else
         std::cout << "777 found at index " << index << std::endl;
      array.display();
      std::cout << "Check if item 500 is present in the Array" << std::endl;
      index = array.binarySearch(500);      
      if (index == -1)
         std::cout << "500 is not present in the array" << std::endl;
      else
         std::cout << "500 found at index " << index << std::endl;
   } catch (const std::runtime_error & e) {
      std::cerr << "Exception: " << e.what() << std::endl;
   }

   return 0;
}
