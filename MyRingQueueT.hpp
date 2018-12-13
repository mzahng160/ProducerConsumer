#pragma once
#pragma once

template   <class T>
class MyRingQueueT
{
public:
	MyRingQueueT()
	{
	}

	MyRingQueueT(T queueCapacity)
	{
		m_iQueueCapacity = queueCapacity;
		m_pQueue = new T[m_iQueueCapacity];
		ClearQueue();
	}

	~MyRingQueueT()
	{
	
	}

	void ClearQueue()
	{
	
	}
	bool QueueEmpty() const
	{
	
	}

	int QueueLength() const
	{
	
	}

	bool QueueFull() const
	{
	
	}

	bool EnQueue(int element)
	{
	
	}

	bool DeQueue(int &element)
	{
	
	}

	void QueueTraverse()
	{
	
	}
private:
	int *m_pQueue;
	int m_iQueueLen;
	int m_iQueueCapacity;
	int m_iHead;
	int m_iTail;
};

