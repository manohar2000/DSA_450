# DSA_450
List of 450 Questions for Data Structures and Algorithms Preparation

Link to the YouTube video for motivation : [view](https://youtu.be/4iFALQ1ACdA) <br>

Link to Placement Series : [view](https://www.youtube.com/playlist?list=PL4PCksYQGLJM2mKe1n8LnFgcm3FRLhxZ9) <br>
Link to Competitive Programming Series : [view](https://www.youtube.com/playlist?list=PL4PCksYQGLJOcaPLgeMFaxaHigPFjBuTG)

## Arrays

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|------------------------|
1| Reverse array | [view](Arrays/reverse%20array.cpp) | One index from start another from the last and swap continuously | 13th Dec |
2 | Find max/min | [view](Arrays/minmax%20element%20with%20divide%20and%20conquer.cpp)| Divide and conquer | 13th Dec | 
3 | Find max/min | [view](Arrays/minmax%20element%20using%20pairs.cpp) | Pairs | 13th Dec |
4 | Kth max/min | [view](Arrays/kth%20smallest%20element.cpp) | In-built merge sort  | 13th Dec|
5 | Trapping Rain water | [view](Arrays/rainwater_trapping.cpp) | min_of_height(building_in_left,buildings_in_right) - curr_height | 16th Dec |
6 | Sort array of 0,1 and 2 | [view](Arrays/Sort012.cpp) | Count and replace | 1st March |
7 | Sort such that all neg elements come before pos elements | [view](Arrays/sortnegpos.cpp) | Partitioning of quick sort | 1st March | 
8 | Power of N(large N) | [view](Arrays/powerofN.cpp) | Right shift and bitwise AND operator | 3rd March |
9 | Rotate array by K positions | [view](Arrays/rotationofarrByk.cpp) | GCD; juggling algo | 5th March |
10 | Min Heights | [view](Arrays/MinHeights.cpp) | Sorting; iterating and updating small and large vars | 6th March | 
11 | Next Permutation | [view](Arrays/NextPermutation.cpp) | Finding the break in decreasing seq from last, swapping with next greatest element and reversing the array | 7th March | 
12 | find duplicate elements in array | [view](Arrays/findDuplicate.cpp) | Floyd cycle detection algo | 7th March |
13 | Rotation of array by K | [view](Arrays/rotationofarrByk.cpp) | Juggling algorithm | 7th March | 
14 | Jump Game 2 | [view](Arrays/JumpGame2.cpp) | Top-down dp; 3 vars that keep a count of jumps, steps and maxReach | 8th March |
15 | Merge 2 sorted arrays without extra space | [view](Arrays/mergeArrays.cpp)| Step algorithm |8th March | 
16 | Merge Intervals | [view](Arrays/mergeIntervals.cpp) | Consecutively comparing the end interval of curr and start interval of next set | 9th March |
17 | Count Inversions | [view](Arrays/countInversions.cpp) | Enhanced merge sort | 10th March |
18 | Buy Sell Stock | [view](Arrays/BuySellStocks.cpp) | 2 variables to keep a track of the min element and max diff | 11th March |
19 | Count Pairs sum equal to K | [view](Arrays/countpairs.cpp) | Hashing | 11th March |
20 | Common Elements in 3 sorted arrays | [view](Arrays/CommonElements.cpp) | Variable to keep a track of the previous common element and 3 pointers for each of the array | 11th March | 
21 | Rearrange array in alternating pos/neg elements | [view](Arrays/rearrange.cpp) | Partitioning followed by swapping | 13th March |
22 | Factorial of a large number | [view](Arrays/largeFactorial.cpp) | Storing results in array rather a interger | 14th March | 
23 | len of longest consecutive numbers in an array | [view](Arrays/longestConsSeq.cpp) | storing all numbers in a set and referencing from it | 16th March | 
24 | Max product subarray | [view](Arrays/maxProduct.cpp) | storing min and max element and iterating through the array | 16th March |
25 | Triplet in array with sum K exists or not | [view](Arrays/triplet.cpp) | sort array and 2 pointer approach | 17th March | 
26 | Majority Element | [view](Arrays/majorityelementII.cpp) | creating a array of k-1 elements and using a tetris like approach to store and replace elements. Lastly checking the occurences of the elements in the temp array | 17th March |
27 | Max Circular Subarray Sum | [view](Arrays/maxCircularSum.cpp) | max(kadane's algo, (sumofArray + maxsubrray sum of inverted array)) | 18th March |
28 | Smallest subarray with sum greater than x | [view](Arrays/smallestSubArr.cpp) | two pointer approach | 18th April | 
29 | Three way partition | [view](Arrays/threeWayPartition.cpp) | Dutch National Flag algo(two pointer approach) | 18th April |
30 | Median of 2 sorted arrays | [view](Arrays/Medianof2Arr.cpp) | min1,max1 and min2,max2 such max1<=min2 and max2<=min1 | 19th April |

## Matrix

Sno | Topic Name | My Solution | Logic Used | Other better approaches|All approaches| Date Completed |
----|------------|-------------|------------|------------------------|--------------|----------------|
 1 | Spiral traversal | [@spiral_print](https://github.com/manohar2000/DSA_450/blob/main/Matrix/spiralprint.cpp) | 4 indices in 4 corners of the matrix | DFS recurisve | [@spiralPrint](https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/) | 14th Dec |
 2 | Search an element | [@staircase](https://github.com/manohar2000/CB-Algorithms/blob/main/arrays/2d-array/staircase_search.cpp) | start top right, if curr>k j-=1 else i+=1 | - | [@searching](https://www.geeksforgeeks.org/search-element-sorted-matrix/?ref=lbp) | 14th Dec |
 3 | Rotate matrix by 90 degrees | [@rotation](https://github.com/manohar2000/CB-Algorithms/blob/main/arrays/2d-array/rotate_array.cpp) | Reverse rows/columns then transpose | - | [@rotation](https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/?ref=lbp) | 14th Dec |

## Strings

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Searching and Sorting

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Linked List

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Binary Trees

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|
1 | Level Order Traversal | [view](Trees/levelOrder.cpp) | queue | 13th March |
2 | Reverse Level Order Traversal | [view](Trees/ReverseLevelOrder.cpp) | queue and stack | 20th Feb |
3 | Height of a Tree | [view](Trees/height.cpp) |  recursion | 13th March |
4 | Diameter of a Tree | [view](Trees/diameter.cpp) | diameter can lie in 3 places | 13th March | 
5 | Mirror of a Tree | [view](Trees/mirrorTree.cpp) | recursion | 20th Feb |
6 | Inorder Iterative | [view](Trees/inorderIterative.cpp) | 
7 | Preorder Iterative | [view](Trees/PreOrderIterative.cpp) |
8 | Postorder Iterative | [view](Trees/PostOrderIterative.cpp) |
9 | Left View | [view](Trees/leftView.cpp) | 
10 | Top View | [view](Trees/topView.cpp) |
11 | Bottom View | [view](Trees/topView.cpp) |
12 | Zig-Zag Traversal | [view](Trees/zigzagTraversal.cpp) |
13 | Tree balanced or not | [view](Trees/balanced.cpp) |
14 | Diagonal Traversal | [view](Trees/diagonalTravesal.cpp) |  
15 | Binary Tree into DLL | [view](Trees/FlattenBSTtoLL.cpp) |
16 | Find LCA | [view](Trees/closestleaf.cpp) | 


## Binary Search Trees

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Greedy Algorithms

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Backtracking

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Stacks and Queues

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Heap

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|


## Graph

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|
1 | Creating a graph with weighted edges | [view](Graphs/CreatingaGraph.cpp) | map<vector<T,int>> | 22nd April |
2 | BFS traversal | [view](Graphs/bfsTraversal.cpp) | queue and a map for visited nodes | 22nd April | 
3 | DFS traversal | [view](Graphs/dfsTraversal.cpp) | recursion and map for visited nodes | 23rd April |
4 | Cyclce Detection using DFS | [view](Graphs/cycledetectionDFS.cpp) |  instack and visited map | 24th April | 
5 | Cycle Detection using BFS | [view](Graphs/cycleDetectionBFS.cpp) | counting the incoming edges and queue | 24th April |

## Trie

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|

## Dynamic Programming

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|

## Bit Manipulation

Sno | Topic Name | My Solution | Logic Used | Date Completed |
----|------------|-------------|------------|----------------|
