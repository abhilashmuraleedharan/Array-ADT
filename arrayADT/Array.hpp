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

   size_ = size;
   length_ = length;
   arr_ = new T[size];
   for (unsigned i=0; i<length; i++) {
      arr_[i] = arr[i];
   }
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T> & other) {
   size_ = other.size_;
   length_ = other.length_;
   arr_ = new T[other.size_];
   for (unsigned i=0; i<other.length_; i++) 
      arr_[i] = other.arr_[i];
}

// Overloaded Assignment operator
template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & other) {
   size_ = other.size_;
   length_ = other.length_;
   arr_ = new T[other.size_];
   for (unsigned i=0; i<other.length_; i++)
      arr_[i] = other.arr_[i];

   return (*this);
}

template <typename T>
void Array<T>::display() const{
   for (unsigned i=0; i<length_; i++)
      std::cout << arr_[i] << " ";
   std::cout << std::endl;
}

template <typename T>
inline int Array<T>::length() const {
   return length_;
}

template <typename T>
inline int Array<T>::size() const {
   return size_;
}  
