//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Andrea M. House
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//=====================================================
// Course Structure
//=====================================================

struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

//=====================================================
// Node Structure
//=====================================================

struct Node {
    Course course;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(Course aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }
};

//=====================================================
// Binary Search Tree
//=====================================================

class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Course course);
    void inOrder(Node* node);

public:
    BinarySearchTree();
    void Insert(Course course);
    Course Search(string courseNumber);
    void InOrder();
};

//=====================================================
// Constructor
//=====================================================

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

//=====================================================
// Insert
//=====================================================

void BinarySearchTree::Insert(Course course) {

    if (root == nullptr) {
        root = new Node(course);
    }
    else {
        addNode(root, course);
    }
}

//=====================================================
// Add Node
//=====================================================

void BinarySearchTree::addNode(Node* node, Course course) {

    if (course.courseNumber < node->course.courseNumber) {

        if (node->left == nullptr) {
            node->left = new Node(course);
        }
        else {
            addNode(node->left, course);
        }
    }
    else {

        if (node->right == nullptr) {
            node->right = new Node(course);
        }
        else {
            addNode(node->right, course);
        }
    }
}

//=====================================================
// Search
//=====================================================

Course BinarySearchTree::Search(string courseNumber) {

    Node* current = root;

    while (current != nullptr) {

        if (current->course.courseNumber == courseNumber) {
            return current->course;
        }

        if (courseNumber < current->course.courseNumber) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return Course();
}

//=====================================================
// InOrder Traversal
//=====================================================

void BinarySearchTree::inOrder(Node* node) {

    if (node != nullptr) {

        inOrder(node->left);

        cout << node->course.courseNumber
            << ", "
            << node->course.courseTitle
            << endl;

        inOrder(node->right);
    }
}

void BinarySearchTree::InOrder() {
    inOrder(root);
}

//=====================================================
// Display Course
//=====================================================

void displayCourse(Course course) {

    cout << "\n"
        << course.courseNumber
        << ", "
        << course.courseTitle
        << endl;

    if (!course.prerequisites.empty()) {

        cout << "Prerequisites: ";

        for (size_t i = 0; i < course.prerequisites.size(); i++) {

            cout << course.prerequisites[i];

            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
        }

        cout << endl;
    }
}

//=====================================================
// Main
//=====================================================

int main() {

    BinarySearchTree bst;

    // Test Data

    Course c1;
    c1.courseNumber = "CSCI100";
    c1.courseTitle = "Introduction to Computer Science";

    Course c2;
    c2.courseNumber = "CSCI101";
    c2.courseTitle = "Introduction to Programming in C++";
    c2.prerequisites.push_back("CSCI100");

    Course c3;
    c3.courseNumber = "CSCI200";
    c3.courseTitle = "Data Structures";
    c3.prerequisites.push_back("CSCI101");

    Course c4;
    c4.courseNumber = "MATH201";
    c4.courseTitle = "Discrete Mathematics";

    Course c5;
    c5.courseNumber = "CSCI300";
    c5.courseTitle = "Introduction to Algorithms";
    c5.prerequisites.push_back("CSCI200");
    c5.prerequisites.push_back("MATH201");

    Course c6;
    c6.courseNumber = "CSCI301";
    c6.courseTitle = "Advanced Programming in C++";
    c6.prerequisites.push_back("CSCI101");

    Course c7;
    c7.courseNumber = "CSCI350";
    c7.courseTitle = "Operating Systems";
    c7.prerequisites.push_back("CSCI300");

    Course c8;
    c8.courseNumber = "CSCI400";
    c8.courseTitle = "Large Software Development";
    c8.prerequisites.push_back("CSCI301");
    c8.prerequisites.push_back("CSCI350");


    bst.Insert(c1);
    bst.Insert(c2);
    bst.Insert(c3);
    bst.Insert(c4);
    bst.Insert(c5);
    bst.Insert(c6);
    bst.Insert(c7);
    bst.Insert(c8);

    int choice = 0;

    while (choice != 9) {

        cout << "\nMenu\n";
        cout << "1. Print Course List\n";
        cout << "2. Print Course\n";
        cout << "9. Exit\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice) {

        case 1:
            bst.InOrder();
            break;

        case 2:
        {
            string courseNumber;

            cout << "Enter course number: ";
            cin >> courseNumber;

            Course course =
                bst.Search(courseNumber);

            displayCourse(course);

            break;
        }

        case 9:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
