/*
PROGRAM TO FIND THE LONGEST PATH IN A TREE (diameter) IT RETURS WHAT WILL BE THE LONGEST PATH IN A TREE
ALSO CONTAINS FUNCTION TO FIND THE HEIGHT OF A TREE

PROGRAM CONATIS BOTH  BRUTE FORCE AND OPTIMAL SOLUTION WITH THEIR TIEM COMPLEXCITIES
USIG PAIR CONCEPT A SINGLE FUNCTION IS WRITTEN TO FIND THE BOTH HEIGHT AND DIAMETER OF A TREE WITH SINGLE RECUSRRION PROGRAM
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *leftNode;
    Node *rightNode;

    Node(int data)
    {
        this->data = data;
        this->leftNode = this->rightNode = NULL;
    }
};

class Tree
{
public:
    // function to find the height of a given tree
    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = height(root->leftNode);
        int rightHeight = height(root->rightNode);

        return max(leftHeight, rightHeight) + 1;
    }

    // function to find the longest path or diameter of a tree
    // TIME COMPLEXCITY -- O(N1*N2) -- N1--> to find the height ,N2-->to find the diameter
    int treeDiameter(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = height(root->leftNode);
        int rightHeight = height(root->rightNode);

        int leftDiameter = treeDiameter(root->leftNode);
        int rightDiameter = treeDiameter(root->rightNode);

        int selfDiameter = leftHeight + rightHeight + 1;

        return max(selfDiameter, max(leftDiameter, rightDiameter));
    }

    // single function using pair concept to find the both hight and diameter of a tree
    // TIME COMPLEXCITY -- O(N)
    pair<int, int> heightAndDiameter(Node *root)
    {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = heightAndDiameter(root->leftNode);
        pair<int, int> right = heightAndDiameter(root->rightNode);

        int height = max(left.first, right.first) + 1;
        int diameter = max({left.second, right.second, left.first + right.first + 1});

        return {height, diameter};
    }
};

int main()
{
    Node *root = new Node(1);
    root->leftNode = new Node(2);
    root->rightNode = new Node(3);
    root->rightNode->leftNode = new Node(4);
    root->rightNode->rightNode = new Node(7);
    root->rightNode->leftNode->leftNode = new Node(5);
    root->rightNode->leftNode->leftNode->leftNode = new Node(6);
    root->rightNode->rightNode = new Node(8);
    root->rightNode->rightNode->rightNode = new Node(9);
    Tree t;
    // cout << "The height of a tree : " << t.height(root) << endl;
    // cout << "The diameter of a tree : " << t.treeDiameter(root) << endl;

    // calling of pair method in a main function
    pair<int, int> result = t.heightAndDiameter(root);

    cout << "The height of a tree : " << result.first << endl;
    cout << "The diameter of a tree : " << result.second << endl;
    return 0;
}