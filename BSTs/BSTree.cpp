#include "BSTree.h"
#include <iostream>
#include <assert.h>
#include<string>
#include<fstream>
#include<list>
using namespace std;
template <class T>

Node<T>::Node()
{
	//load from file
	left=right=NULL;
}

template <class T>
Node<T>::Node(T val1,T val2)
{
	//load from file
	value1=val1;
	value2 = val2;
	left=right=NULL;
	
}

template <class T>
BSTree<T>::BSTree(void)
{
	root=NULL;

	
}
template<class T>
bool BSTree<T>::contain(T val)
{
		Node<T>*tmp = root;
		while (tmp != NULL)
		{
			if (tmp->value1 == val)
			{
				return true;
			}
			if (tmp->value1 > val)
				tmp = tmp->left;

			else
				tmp = tmp->right;
		}
		return false;
	}

template <class T>
T BSTree<T>::findNode(T val1)
{
	Node<T>* tmp=root;

	while((tmp!=NULL)&&(tmp->value1!=val1))
		if(tmp->value1>val1)
			tmp=tmp->left;
		else
			tmp=tmp->right;
	return tmp->value2;
}
template<class T>
T BSTree<T>::edit(T val1,T val2)
{
	Node<T>* tmp = root;

	while ((tmp != NULL) && (tmp->value1 != val1))
		if (tmp->value1 > val1)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	return tmp->value2=val2;

}
template <class T>
void BSTree<T>::insert(T val1,T val2)
{
		Node<T>* newNode = new Node<T>(val1, val2);
		Node<T>* tmp = root;

		if (root == NULL)
			root = newNode;
		else
		{
			while (true)
			{
				if (tmp->value1 > val1)
					if (tmp->left == NULL)
					{
						tmp->left = newNode;
						break;
					}
					else
						tmp = tmp->left;
				else
					if (tmp->right == NULL)
					{
						tmp->right = newNode;
						break;
					}
					else
						tmp = tmp->right;
			}
		}

}


template <class T>
void BSTree<T>::traverse()
{

	//ofstream out;
	//out.Open("file1.txt",ios::trunc);
		inOrder(root);
	//out.Close();
}
template <class T>
void BSTree<T>::inOrder(Node<T>* start)
{
	
	
	if (start != NULL)
     {
		inOrder(start->left);
		cout << start->value1 << "\n";
		cout << start->value2 << endl;
	  // out << start->value1 << "\n" << start->value2;
		inOrder(start->right); 
     }
	
}

template<class T>

void BSTree<T>::write(Node<T>* start)
{

	ofstream out;
	out.open("file1.txt", ios::app);
	if (start != NULL)
	{
		write(start->left);
	    out << start->value1 << "\n" << start->value2<<"\n";
		write(start->right);
	}
	out.close();
}
template<class T>
void BSTree<T>::traversee()
{ 
	ofstream out;
	out.open("file1.txt", ios::trunc);
	
	write(root);

}

template <class T>
Node<T>* BSTree<T>::findMin(Node<T>* start)
{
	Node<T>* minNode = start;
	while (minNode->left != NULL)
		minNode = minNode->left;
	return minNode;
}

template <class T>
Node<T>* BSTree<T>::findParent(T val)
{
	Node<T>* a, *b;
	a = root;
	b = NULL;
	while ((a != NULL) && (a->value1 != val))
	{
		b = a;
		if (a->value1 > val)
			a = a->left;
		else
			a = a->right;
	}
	return b;
}
template <class T>
void BSTree<T>::remove(T val)
{
	assert(contain(val));
	Node<T>* m = findNodee(val);
	if ((m->left == NULL) && (m->right == NULL)) //deleting a leaf node
	{
		if (m == root)
			root = NULL;
		else
		{
			Node<T>* parent = findParent(val);
			if (val < parent->value1)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		delete m;
	}
	else if ((m->left == NULL) && (m->right != NULL))
	{
		Node<T>* parent = findParent(val);
		if (m == root)
			root = m->right;
		else
		{
			if (val < parent->value1)
				parent->left = m->right;
			else
				parent->right = m->right;
		}
		delete m;
	}
	else if ((m->left != NULL) && (m->right == NULL))
	{
		Node<T>* parent = findParent(val);
		if (m == root)
			root = m->left;
		else
		{
			if (val < parent->value1)
				parent->left = m->left;
			else
				parent->right = m->left;
		}
		delete m;
	}
	else
	{
		Node<T>* minNode = findMin(m->right);
		Node<T>* parent = findParent(minNode->value1);
		m->value1 = minNode->value1;

		if (parent == m)
			parent->right = minNode->right;
		else
			parent->left = minNode->right;
		delete minNode;
	}
}
template <class T>
Node<T>* BSTree<T>::findNodee(T val)
{
	Node<T>* tmp = root;

	while ((tmp != NULL) && (tmp->value1 != val))
		if (tmp->value1 > val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	return tmp;
}


template <class T>
BSTree<T>::~BSTree(void)
{
	
}
