#pragma once
#include<string>
#include<fstream>
#include<list>
template <class T>
class Node
{
public:
	T value1, value2;
	Node<T>* left, *right;
	Node();
	Node(T val1,T val2);
};

template <class T>
class BSTree
{
	Node<T>* root;
public:
	BSTree(void); 
	Node<T>* findParent(T val);
	Node<T>* findMin(Node<T>* start);
	void remove(T val);
	bool contain(T val1);
	T findNode(T val1);
	Node<T>* findNodee(T val);
	T edit(T val1,T val2);
	void insert(T val1, T val2);
	void traverse();
	void traversee();
	void inOrder(Node<T>* start);
	void write(Node<T>* start);
	~BSTree(void);
};

