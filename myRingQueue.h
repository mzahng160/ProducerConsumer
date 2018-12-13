#pragma once
class myRingQueue
{
public:
	myRingQueue();
	myRingQueue(int queueCapacity);
	~myRingQueue();

	void ClearQueue();
	bool QueueEmpty() const;
	int QueueLength() const; 
	bool QueueFull() const;
	bool EnQueue(int element);
	bool DeQueue(int &element);
	void QueueTraverse(); 
private:
	int *m_pQueue; 
	int m_iQueueLen; 
	int m_iQueueCapacity; 
	int m_iHead; 
	int m_iTail;
};

