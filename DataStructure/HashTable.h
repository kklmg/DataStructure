#pragma once
#include"LinkList.h"

//size_t
template<typename TValue=int>
struct STSlot
{
	STSlot() :m_nKey(0) {}

	STSlot(int key, TValue value) :m_nKey(key), m_Value(value) {}

	void operator=(STSlot &slot)
	{
		m_nKey = slot.m_nKey;
		m_Value = slot.m_Value;
	}

	unsigned int m_nKey;
	TValue m_Value;
};



template<typename TValue,int size>
class CHashTable
{
public:
	CHashTable() :m_fptrHashFun(__DefaultHashFun) {}

	CHashTable(unsigned int(*HashFun)(unsigned int)):m_fptrHashFun(HashFun)
	{
		m_Table = new CLinkList<STSlot<TValue>>[Volume];
	}
	~CHashTable() {}
	//template <>
	bool Insert(unsigned int key, TValue value) 
	{
		if (Search(key)) return FALSE;	//key duplicated

		int HashKey= m_fptrHashFun(key);
		
		STSlot<TValue> slot(HashKey, value);

		m_pTable[HashKey].Insert(slot);


		return true;

	

	//		m_pTable[1].
	//	a[1].m_nKey;
		//aaa[1]
		//m_pTable[1]
		

	}

	bool Delete(unsigned int key, TValue &GetValue)
	{
		STSlot<TValue> slot;
		int HashKey = m_fptrHashFun(key);//calculate hash key

		if (m_pTable[HashKey].RemoveIf<int>(IsSameKey, key, slot)) 
		{
			GetValue = slot.m_Value;
			return TRUE;
		}
		else return FALSE;
	}

	bool Search(unsigned int key)
	{
		STSlot<TValue> slot;

		int HashKey = m_fptrHashFun(key);//calculate hash key

		if (m_pTable[HashKey].First(slot))
		{
			if (slot.m_nKey == key)
			{
				return TRUE;
			}
			while (m_pTable[HashKey].Next(slot))
			{
				if (slot.m_nKey == key)
				{
					return TRUE;
				}
			}
		}
		return FALSE;
	}
	bool Search(unsigned int key,TValue &GetValue)
	{
		STSlot<TValue> slot;

		int HashKey = m_fptrHashFun(key);//calculate hash key
		
		if (m_pTable[HashKey].First(slot))
		{
			if (slot.m_nKey == key)
			{
				GetValue = slot.m_Value;
				return TRUE;
			}
			while (m_pTable[HashKey].Next(slot))
			{
				if (slot.m_nKey == key)
				{
					GetValue = slot.m_Value;
					return TRUE;
				}
			}
		}
		return FALSE;
	}


	static unsigned int  __DefaultHashFun(unsigned int key)
	{
		return key % size;
	}

	static bool IsSameKey(STSlot<TValue> slot,int key)
	{
		if (slot.m_nKey == key)return TRUE;
		else return FALSE;
	}

private:
	unsigned int GetHK(int key) 
	{
		return m_fptrHashFun(key);
	}

	//STSlot<int> a[10];
	CLinkList<STSlot<TValue>> m_pTable[size];
	CLinkList<STSlot<int>> m_pTable1[10];

	unsigned int (*m_fptrHashFun)(unsigned int key);
};

