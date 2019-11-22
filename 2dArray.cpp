/*
 * Demo of 2D Array
 */
#include <iostream>

/*
 * To understand different ways a 2D array can be created and used.
 */

// Global constants
const int ROW = 3;
const int COLUMN = 4;

/*
 * One important thing for passing multidimensional arrays is, 
 * first array dimension does not have to be specified. 
 * The second (and any subsequent) dimensions must be given.
 */
void print1(int arr[][COLUMN]) {
   for (unsigned i=0; i<ROW; i++) {
      for (unsigned j=0; j<COLUMN; j++) {
         std::cout << arr[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

/*
 * This function is required when the array elements are
 * stored in heap and not in stack.
 */
void print2(int **arr) {
   for (unsigned i=0; i<ROW; i++) {
      for (unsigned j=0; j<COLUMN; j++) {
         std::cout << arr[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

int main() {

   // First method
   int array1[ROW][COLUMN] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
   std::cout << "Printing array1 elements: " << std::endl;
   print1(array1);
   
   // Second method
   int *array2[ROW];
   for (unsigned i=0; i<ROW; i++)
      array2[i] = new int[COLUMN];

   for (unsigned i=0; i<ROW; i++)
      for (unsigned j=0; j<COLUMN; j++)
         array2[i][j] = i+j;
   
   std::cout << "Printing array2 elements: " << std::endl;
   print2(array2);
   // Deallocate the memory
   for (unsigned i=0; i<ROW; i++)
      delete []array2[i];

   // Third Method
   int** array3 = new int*[ROW];
   for (unsigned i=0; i<ROW; i++)
      array3[i] = new int[COLUMN];

   for (unsigned i=0; i<ROW; i++)  
      for (unsigned j=0; j<COLUMN; j++)
         array3[i][j] = i+j;

   std::cout << "Printing array3 elements: " << std::endl;
   print2(array3);
   // Deallocate memory
   for (unsigned i=0; i<ROW; i++)
      delete []array3[i];
   delete []array3;

   return 0;
} 
