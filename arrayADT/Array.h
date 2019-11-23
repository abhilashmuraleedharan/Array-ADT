/*
 * Class implementing an array ADT
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
   public:
      Array(); // Default Constructor
 
      Array(T arr[], int size, int length); // Argument constructor

      // Copy constructor to ensure deep copy
      Array(const Array & other);

      ~Array() {
         delete []arr_;
      }

      // Overloaded Assignment operator to ensure deep copy
      Array & operator=(const Array & other);

      // Available Operations
      void display() const;
      bool append(T item);
      T deleteItem(int index);
      int search(T item) const;
      T getItem(int index) const;
      bool setItem(int index, T value); 
      T getMax() const;
      T getMin() const;
      Array & reverse() const;
      Array & rotate() const;
      inline int length() const;
      inline int size() const;

   private:
      T *arr_;      // Points to the array allocated in heap memory.
      int size_;    // Holds the size of the array.
      int length_;  // Holds the length of the array.
};

// Finish including the rest of the header from the additional header file.
#include "Array.hpp"
