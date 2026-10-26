Project One: Runtime Analysis of Data Structures
Overview
The purpose of the advising application is to load course data, validate course prerequisites, store course information, and provide the ability to search for a specific course or print all courses in alphanumeric order. Three data structures were evaluated for this project: a vector, a hash table, and a binary search tree.

Runtime Analysis
Operation	Vector	Hash Table	Binary Search Tree
Load File	O(n)	O(n)	O(n log n)
Validate Prerequisites	O(n²)	O(n)	O(n log n)
Search Course	O(n)	O(1) average	O(log n) average
Print Sorted List	O(n log n)	O(n log n)	O(n)
Advantages and Disadvantages
Vector
Advantages
Simple and easy to implement
Easy to sort
Works well for small datasets
Disadvantages
Linear search performance O(n)
Prerequisite validation requires O(n²) comparisons
Hash Table
Advantages
Fast average lookup time O(1)
Efficient searching for individual courses
Disadvantages
Data is not stored in sorted order
Additional sorting is required before printing courses alphabetically
Binary Search Tree
Advantages
Maintains courses in sorted order
Efficient course searching with O(log n) average performance
Supports in-order traversal for printing courses alphabetically
Disadvantages
Performance can decrease if the tree becomes unbalanced
More complex implementation than a vector
Recommendation
The Binary Search Tree is the recommended data structure for the advising application. While a hash table provides faster average search performance, the Binary Search Tree maintains sorted order while still allowing efficient searches. Because the application requires displaying courses in alphanumeric order, the Binary Search Tree provides the best balance between efficiency and functionality.

Sample Course Data
CSCI100 - Introduction to Computer Science
CSCI101 - Introduction to Programming in C++
CSCI200 - Data Structures
MATH201 - Discrete Mathematics
CSCI300 - Introduction to Algorithms
CSCI301 - Advanced Programming in C++
CSCI350 - Operating Systems
CSCI400 - Large Software Development
