#include"stdafx.h"
#include<iostream>


#pragma once
//--------------------------------------
//Head File
//--------------------------------------
#include<Windows.h>
#include<map>
#include<set>
#include <crtdbg.h>

//--------------------------------------
//My Head File
//--------------------------------------
//#include"MyNode.h"
#include"queue.h"
#include"Heap.h"
#include"Sort.h"
#include"BinaryTree.h"
#include"Search.h"
#include"LinkList.h"
#include"HashTable.h"
#include"Graph.h"
#include"Trie.h"


//template<typename T>
using namespace std;



bool Compare(int a, int b) 
{
	return a < b;
}

void DoSomeThing(int data) 
{
	cout << data << endl;
}

unsigned int hashfun(int key) 
{
	///

	return key;
}

struct point 
{
	point() :x(0), y(0) {}
	point(int _x, int _y) :x(_x), y(_y) {}

	void operator=(point &other)
	{
		x = other.x;
		y = other.y;
	}
	int x;
	int y;
};

const int TRIESIZE = 26;




enum enVertex {A,B,C,D,E,F,G,H,I,J,K};

int main() 
{
	STrie::Trie trie;

	trie.Insert("APPLE");
	trie.Insert("AXIS");
	trie.Insert("APP");
	trie.Insert("APPEND");
	trie.Insert("KKLMG");
	trie.Insert("MESSI");

	int count = trie.size();
	bool find0 = trie.Search("APPLE");

	trie.Remove("APPLE");
	trie.Remove("KING");
	trie.Remove("AXIS");

	int count2 = trie.size();
	bool find1= trie.Search("APPLE");


	getchar();

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//CGraph gp(20);


	//gp.AddEdge(A, D);
	//gp.AddEdge(A, G);
	//gp.AddEdge(A, C);
	//gp.AddEdge(A, F);
	//gp.AddEdge(B, F);
	//gp.AddEdge(B, I);
	//gp.AddEdge(B, E);
	//gp.AddEdge(C, A);
	//gp.AddEdge(C, G);
	//gp.AddEdge(D, A);
	//gp.AddEdge(D, G);

	//gp.AddEdge(D, H);
	//gp.AddEdge(E, B);
	//gp.AddEdge(F, A);
	//gp.AddEdge(F, B);
	//gp.AddEdge(G, A);
	//gp.AddEdge(G, C);
	//gp.AddEdge(G, D);
	//gp.AddEdge(H, D);
	//gp.AddEdge(I, B);

	////gp.DFS(D);
	//gp.BFS(A);

	//Sort_Insertion<int>(arr,10);

	//CDeque<int> queue;

	//STMergeSort<int> mergesort;

	//STQuickSort<int> QuickSort;
	
	//CPriorityQueue<int> queue(50,Compare);

	//CBTree<int> Tree;

	//STBTreeNode<int> node1(1);
	//STBTreeNode<int> node2(2);
	//STBTreeNode<int> node3(3);
	//STBTreeNode<int> node4(4);
	//STBTreeNode<int> node5(5);
	//STBTreeNode<int> node6(6);
	//STBTreeNode<int> node7(7);
	//STBTreeNode<int> node8(8);
	//STBTreeNode<int> node9(9);
	//

	//node1.SetLeft(&node2);
	//node1.SetRight(&node3);

	//node2.SetLeft(&node4);
	//node2.SetRight(&node5);

	//node3.SetLeft(&node6);
	//node3.SetRight(&node7);

	//node7.SetLeft(&node8);
	//node7.SetRight(&node9);
	//node9.SetRight(&node7);

	//node1.PostOrderTraverse(DoSomeThing);

	//Tree.SetData()

//	QuickSort(arr, 0, 9);
	//queue.Enque(10);
	//queue.Enque(12);
	//queue.Enque(13);
	//queue.Enque(11);
	//queue.Enque(5);
	//queue.Enque(92);
//
//
////
//	int temp;
//////	int i = 0;
//	//queue.GetFirst(temp);
//	
//	//cout << temp << endl;
//
//
//	while (queue.Deque(temp))
//	{
//		cout << temp << endl;
//		//++i;
//	}
//

	/*int i = 0;

	while (i<10)
	{
		cout << arr[i] << endl;
		++i;
	}*/


	

	//cout << (*iter).nF << endl;

	//bool test1 = (area1 == area2);
	//bool test2 = (area1 == a);


	//getchar();
}