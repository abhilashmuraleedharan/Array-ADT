/*
 * Useful Enumerator Collections
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#pragma once
/*
 * Enumerator that defines the strategy 
 * for improving linear search.
 *
 * a) Transposition Strategy
 *    If the key element is found, it's position is moved
 *    one position to the left by swapping with the previous 
 *    element. This way the key element is moved 1 step closer
 *    to the beginning of the list thereby reducing the number 
 *    of comparisions required to locate the same element again 
 *    by 1. With each search of the same key element it gets
 *    closer to the beginning of the array one postion at a time.
 *
 * b) Move to Front/Head
 *    As per this strategy, when the key element is found, 
 *    it's swapped with the very first element of the list. This
 *    way only 1 comparison is required if the same key element is
 *    searched again. However, here unlike transposition strategy,
 *    it's difficult to predict where the swapped elements new 
 *    positions are.
 */
enum LinearSearchStrategy {
   DEFAULT = 0,
   TRANSPOSITION,
   MOVE_TO_FRONT,
};
