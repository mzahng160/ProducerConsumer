#include "stdafx.h"
#include "myRingQueue.h"
#include <iostream>
using namespace std;

myRingQueue::myRingQueue()
{

}

myRingQueue::myRingQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new int[m_iQueueCapacity];
	ClearQueue();
}

myRingQueue::~myRingQueue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
}

void myRingQueue::ClearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}
bool myRingQueue::QueueEmpty() const
{
	if (m_iQueueLen == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
int myRingQueue::QueueLength() const
{
	return m_iQueueLen;
}
bool myRingQueue::QueueFull() const
{
	if (m_iQueueLen == m_iQueueCapacity) {
		return true;
	}
	else {
		return false;
	}
}
bool myRingQueue::EnQueue(int element)
{
	if (QueueFull()) 
	{
		return false;
	}
	else 
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail % m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
}
bool myRingQueue::DeQueue(int &element)
{
	if (QueueEmpty()) 
	{
		return false;
	}
	else 
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead % m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
}
void myRingQueue::QueueTraverse()
{
	for (int i = m_iHead; i < m_iQueueLen; i++) 
	{
		cout << m_pQueue[i%m_iQueueLen] << endl;
	}
}