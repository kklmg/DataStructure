#pragma once
#include<Windows.h>
#include"LinkList.h"
#include"Stack.h"
#include"queue.h"

#include<stdio.h>

class CGraph 
{
public:
	CGraph(DWORD NumVertex) :m_dwNumVertex(NumVertex),m_dwNumEdge(0),m_plist(NULL), m_fptrDoSome(NULL)
	{
		m_plist = new CLinkList<DWORD>[NumVertex];
		m_pbVisitInfo = new bool[NumVertex];

		memset(m_pbVisitInfo, FALSE, sizeof(bool)*NumVertex);
	}
	~CGraph() 
	{
		if (m_plist != NULL) 
		{
			delete[] m_plist;
			m_plist = NULL;
		}
		if (m_pbVisitInfo != NULL)
		{
			delete[] m_pbVisitInfo;
			m_pbVisitInfo = NULL;
		}
	}

	void AddEdge(DWORD from,DWORD to) 
	{
		m_plist[from].Insert(to);
		m_plist[to].Insert(from);

		++m_dwNumEdge;
	}
	
	bool VisitVertex(DWORD visit) 
	{
		if (m_pbVisitInfo[visit])return FALSE;
		else 
		{
			m_pbVisitInfo[visit] = TRUE;

			
			printf("%c\n",visit+65);

			return TRUE;
		} 
	}

	void SetFptr(void(*fptr)(DWORD))
	{
		m_fptrDoSome = fptr;
	}

	void DFS(DWORD StartVertex) 
	{
		CStack_List<DWORD> l_Stack;	//stack

		DWORD l_Visit = StartVertex;	//visit Vertex
		DWORD l_Next;					//Next Vertex

		VisitVertex(l_Visit);
		l_Stack.Push(l_Visit);			//push start Vertex to stack

		//
		while (m_plist[l_Visit].First(l_Next))
		{
			bool VisitFlag = FALSE;

			if (VisitVertex(l_Next)) 
			{
				l_Stack.Push(l_Visit);

				l_Visit = l_Next;
			
				VisitFlag = TRUE;
			}
			else
			{
				while (m_plist[l_Visit].Next(l_Next)) 
				{
					if (VisitVertex(l_Next)) 
					{
						l_Stack.Push(l_Visit);
						l_Visit = l_Next;
					
						VisitFlag = TRUE;
						break;
					}	
				}
			}

			if (!VisitFlag) 
			{
				if (l_Stack.IsEmpty())break;
			
				else l_Stack.Pop(l_Visit);
			}
		}
		memset(m_pbVisitInfo, FALSE, sizeof(bool)*m_dwNumVertex);
	}

	void BFS(DWORD StartVertex)
	{
		CListQueue<DWORD> l_queue;		//queue

		DWORD l_Visit = StartVertex;	//visit Vertex
		DWORD l_Next;					//Next Vertex

		VisitVertex(l_Visit);
		l_queue.Enque(l_Visit);			//push start Vertex to stack

		while (m_plist[l_Visit].First(l_Next))
		{
			if (VisitVertex(l_Next))
			{
				l_queue.Enque(l_Next);
			}

			while (m_plist[l_Visit].Next(l_Next))
			{
				if (VisitVertex(l_Next))
				{
					l_queue.Enque(l_Next);
				}
			}
			
		
			if (l_queue.IsEmpty())break;
			else l_queue.Deque(l_Visit);		
		}
		memset(m_pbVisitInfo, FALSE, sizeof(bool)*m_dwNumVertex);
	}

	DWORD m_dwNumEdge;
	DWORD m_dwNumVertex;

	bool *m_pbVisitInfo;

	void(*m_fptrDoSome)(DWORD);

	CLinkList<DWORD>*m_plist;
};