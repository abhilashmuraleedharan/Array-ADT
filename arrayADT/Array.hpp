/*
 * Header Extension of a class implementing Array ADT
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */

#pragma once

#include "Array.h"

// Default Constructor
template <typename T>
Array<T>::Array() {
   std::cout << "Enter the size of the array" << std::endl;
   std::cin >> size_;
   
   if (size_ <= 0)
      throw std::runtime_error("Invalid size");
   arr_ = new T[size_];
   _initialize();
   
   std::cout << "Enter the number of items you wish to add into the array" << std::endl;
   std::cin >> length_;
   if (length_ <= 0 || length_ > size_)
      throw std::runtime_error("Invalid length");
   
   std::cout << "Enter the " << length_ << " items you wish to add into the array" << std::endl;
   for (unsigned i=0; i<length_; i++)
      std::cin >> arr_[i];
}

// Argument constructor
template <typename T>
Array<T>::Array(T arr[], int size, int length) {
   if (size <= 0)
      throw std::runtime_error("Invalid size");

   if (length <= 0 || length > size)
      throw std::runtime_error("Invalid length");

   arr_ = new T[size];
   _initialize();

   for (unsigned i=0; i<length; i++) {
      arr_[i] = arr[i];
   }
   size_ = size;
   length_ = length;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T> & other) {
   size_ = other.size_;
   length_ = other.length_;
   arr_ = new T[other.size_];
   _initialize();
   // Copy the elements one by one
   for (unsigned i=0; i<other.length_; i++) 
      arr_[i] = other.arr_[i];
}

// Overloaded Assignment operator
template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & other) {
   size_ = other.size_;
   length_ = other.length_;
   arr_ = new T[other.size_];
   _initialize();
   // Copy the elements one by one
   for (unsigned i=0; i<other.length_; i++)
      arr_[i] = other.arr_[i];

   return (*this);
}

// Prints on console all the items of the Array
template <typename T>
void Array<T>::display() const{
   for (unsigned i=0; i<length_; i++)
      std::cout << arr_[i] << " ";
   std::cout << std::endl;
}

// Returns length of the array;
template <typename T>
inline int Array<T>::length() const {
   return length_;
}

// Returns size of the array
template <typename T>
inline int Array<T>::size() const {
   return size_;
}

// Adds an item to the end of the array
template <typename T>
void Array<T>::append(T item) {
   if (isFull()) {
      // Array is full. Need to make space for the new element
      _expand();
   }
   // Add the element to the end of the array
   arr_[length_] = item;
   // Update length
   length_++;
}

// Inserts a new item at the given index of the Array
template <typename T>
void Array<T>::insertItem(int index, T item) {
   if (index < 0 || index >= size_)
      throw std::runtime_error("Index out of bounds");

   if (isFull()) {
      // Increase the size of the array
      _expand();
   }

   // Shift existing items starting 
   // from index to the right by 1 position.
   for (unsigned i=length_; i>index; i--) 
      arr_[i] = arr_[i-1];
   
   arr_[index] = item;
   // Update length
   length_++;
}

/*
 * Deletes the item at the given index.
 * Returns the item that was deleted
 */
template <typename T>
T Array<T>::deleteItem(int index) {
   if (index < 0 || index >= size_)
      throw std::runtime_error("Index out of bounds");

   T itemToBeDeleted = arr_[index];
   // Shift all items present after index 
   // by 1 position to the left. 
   for (unsigned i=index; i<length_-1; i++)
      arr_[i] = arr_[i+1];
   // Overwrite the last duplicate item with null
   // just to be on the safer side.
   arr_[length_-1] = '\0';
   // Update length
   length_--;
   
   return itemToBeDeleted; 
}

/*
 * Performs Linear Search for the key item as per given strategy.
 * Returns the index of the key if found. Else returns -1.
 */
template <typename T>
int Array<T>::linearSearch(T keyItem, LinearSearchStrategy strategy) const {
   for (unsigned i=0; i<length_; i++) {
      if (arr_[i] == keyItem) {
         switch (strategy) {
            case TRANSPOSITION:
               // Swap the key position with its left neighbour
               // to bring the key item closer in next search
               {  // Adding braces to limit scope of T 
                  T temp = arr_[i-1];
                  arr_[i-1] = arr_[i];
                  arr_[i] = temp;
                  return i-1;
               }
            case MOVE_TO_FRONT:
               // Swap the key position with the first item so
               // that the same key is found only in 1 comparison
               // in next search
               {
                  T temp = arr_[0];
                  arr_[0] = arr_[i];
                  arr_[i] = temp;
                  return 0;
               }
            default:
               // Just return the key index
               return i;
         }
      }
   }
   // Item was not found
   return -1;
}

// Private Helper methods

// Doubles the size of the Array
template <typename T>
void Array<T>::_expand() {
   T *temp = arr_;
   /*
    * Doubling the array size each time it becomes full
    * results in an amortized runtime of O(1)
    */  
   arr_ = new T[size_*2];
   _initialize();
   // Copy the values from old array to new array
   for (unsigned i=0; i<length_; i++) 
      arr_[i] = temp[i];
   // Update size
   size_ = size_ * 2;
   // delete the old shorter array
   delete []temp;
}

// Initializes the Array
template <typename T>
void Array<T>::_initialize() {
   for (unsigned i=0; i<size_; i++)
      arr_[i] = '\0';
}  
