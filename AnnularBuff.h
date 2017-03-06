#pragma once

#ifndef		__ANNULAR_BUFF__
#define		__ANNULAR_BUFF__

#ifndef		MAX_ANNULAR_BUFF_SIZE
#define		MAX_ANNULAR_BUFF_SIZE	512	
#endif // !MAX_ANNULAR_BUFF_SIZE

typedef unsigned int UINT;

template <typename _BuffType>
class  CAnnularBuff
{
public:
	CAnnularBuff();
	CAnnularBuff(UINT nCapacity);
	virtual ~CAnnularBuff();

	bool IsEmpty();
	
	bool IsFull();

	UINT getLength();

	bool push_back(_BuffType nElement);
	_BuffType pop_front();

	UINT getElement(UINT iPos);

private:
	UINT	m_UnHead;
	UINT	m_UnTail;
	UINT	m_nSize;
	UINT	m_nCapacity;
	_BuffType*   m_pBuff;

};


template<typename _BuffType>
CAnnularBuff<_BuffType>::CAnnularBuff()
	: m_nCapacity(0),
	m_nSize(0),
	m_UnHead(0),
	m_UnTail(0),
	m_pBuff(nullptr)
{
	m_pBuff = new _BuffType[MAX_ANNULAR_BUFF_SIZE];
	m_nCapacity = MAX_ANNULAR_BUFF_SIZE;
}

template <typename _BuffType>
CAnnularBuff<_BuffType>::CAnnularBuff(UINT nCapacity)
	: m_nCapacity(nCapacity),
	m_nSize(0),
	m_UnHead(0),
	m_UnTail(0),
	m_pBuff(nullptr)

{
	if (nCapacity > MAX_ANNULAR_BUFF_SIZE || nCapacity <= 0)
	{
		m_pBuff = new _BuffType[MAX_ANNULAR_BUFF_SIZE];
		m_nCapacity = MAX_ANNULAR_BUFF_SIZE;
	}
	else
	{
		m_pBuff = new _BuffType[nCapacity];
		m_nCapacity = nCapacity;
	}
}

template<typename _BuffType>
CAnnularBuff<_BuffType>::~CAnnularBuff()
{
	delete[]	m_pBuff;
	m_nCapacity = 0;
	m_nSize = 0;
	m_UnHead = 0;
	m_UnTail = 0;
}

template <typename _BuffType>
bool CAnnularBuff<_BuffType>::push_back(_BuffType oElement)
{
	// 事先判断 缓冲区是否满
	if (IsFull())
	{
		return false;
	}

	m_pBuff[m_UnTail] = oElement;
	m_UnTail = (m_UnTail + 1) % m_nCapacity;
	++m_nSize;

	return true;
}

template <typename _BuffType>
_BuffType CAnnularBuff<_BuffType>::pop_front()
{
	// 判断缓冲区是否为空
	if (IsEmpty())
	{
		return -1;
	}

	_BuffType oElement = m_pBuff[m_UnHead];
	m_UnHead = (m_UnHead + 1) % m_nCapacity;
	--m_nSize;

	return oElement;
}


template <typename _BuffType>
UINT CAnnularBuff<_BuffType>::getElement(UINT iPos)
{
	// 跟数组遍历类似，从0位置开始，位置大小不能超过实际大小
	if ((iPos + 1) > m_nSize)
	{
		return -1;
	}

	return m_pBuff[iPos];
}

template <typename _BuffType>
bool CAnnularBuff<_BuffType>::IsEmpty()
{
	return m_nSize == 0;
}

template <typename _BuffType>
UINT CAnnularBuff<_BuffType>::getLength()
{
	return m_nSize;
}

template <typename _BuffType>
bool CAnnularBuff<_BuffType>::IsFull()
{
	return m_nSize >= m_nCapacity;
}


#endif