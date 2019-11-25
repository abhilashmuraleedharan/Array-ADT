/*
 * Class implementing an array ADT
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#pragma once

#include <iostream>
#include <stdexcept>

#include "enumerations.h"

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

      // Available data operations
      void display() const;
      void append(T item);
      void insertItem(int index, T item); 
      T deleteItem(int index);
      int linearSearch(T item, LinearSearchStrategy strategy=DEFAULT) const;
      int binarySearch(T item) const;
      T getItem(int index) const;
      T getMax() const;
      T getMin() const;
      Array & reverse() const;
      Array & rotate() const;

      // Available information operations
      inline int length() const; // Returns the length of the Array
      inline int size() const;  // Returns the size of the Array

      // Returns TRUE if the Array is full
      inline bool isFull() const {
         return length_ == size_;
      }

   private:
      T *arr_;      // Points to the array allocated in heap memory.
      int size_;    // Holds the size of the array.
      int length_;  // Holds the length of the array.

      // Private helper methods
      void _expand();  // Increase the size of the array to accomodate
                       // new items.
      void _initialize();  // Initialize the array
};

// Finish including the rest of the header from the additional header file.
#include "Array.hpp"
