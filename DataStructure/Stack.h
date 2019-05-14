#pragma once
#include<Windows.h>
#include"MyNode.h"

template<typename T>
class CStack 
{
public:
	CStack() :m_dwNumData(0) {}

	virtual bool IsEmpty() = 0;

	virtual void Push(T data) = 0;

	virtual bool Pop(T &GetData) = 0;

	virtual bool Seek(T &GetData) = 0;
protected:
	DWORD m_dwNumData;
};

template<typename T>
class CStack_Array :public CStack<T>
{
public:
	CStack_Array(DWORD dataCount) :m_pArrData(NULL), m_nTopID(-1), m_dwVolume(dataCount)
	{
		m_pArrData = new T[dataCount];	
	}
	~CStack_Array() 
	{
		if (m_pArrData != NULL) 
		{
			delete[] m_pArrData;
			m_pArrData = NULL;
		}
	}

	virtual bool IsEmpty() 
	{
		if (m_nTopID==-1)return true;
		else return false;
	}

	virtual void Push(T data) 
	{
		if (m_dwNumData >= m_dwVolume)return;

		++m_nTopID;

		m_pArrData[m_nTopID] = data;

		++m_dwNumData;
	}

	virtual bool Pop(T &GetData) 
	{
		if (IsEmpty())return false;

		GetData = m_parr[m_nTopID];
	
		--m_nTopID;
		--m_dwNumData;

		return true;
	}

	virtual bool Seek(T &GetData) 
	{
		if (IsEmpty())return false;

		GetData = m_parr[m_nTopID];

		return true;
	}

private:
	DWORD m_dwVolume;
	T *m_pArrData;
	int m_nTopID;
};

template<typename T>
class CStack_List :public CStack<T>
{
public:
	CStack_List() :m_pHead(NULL) {}

	~CStack_List()
	{
		while (Pop()) {}
	}

	virtual bool IsEmpty()
	{
		if (!m_pHead)return true;
		else return false;
	}

	virtual void Push(T data)
	{
		STNode_OC<T> *NewNode = new STNode_OC<T>(data);
		NewNode->m_pChild = m_pHead;
		m_pHead = NewNode;
		++m_dwNumData;
	}

	bool Pop()
	{
		if (IsEmpty())return false;

		STNode_OC<T> *DeleteNode = m_pHead;

		m_pHead = m_pHead->m_pChild;

		delete DeleteNode;

		--m_dwNumData;

		return true;
	}

	virtual bool Pop(T &GetData)
	{
		if (IsEmpty())return false;

		GetData = m_pHead->GetData();

		STNode_OC<T> *DeleteNode = m_pHead;

		m_pHead = m_pHead->m_pChild;

		delete DeleteNode;

		--m_dwNumData;

		return true;
	}

	virtual bool Seek(T &GetData)
	{
		if (IsEmpty())return false;

		GetData = m_pHead->GetData();

		return true;
	}

private:
	STNode_OC<T> *m_pHead;
};
