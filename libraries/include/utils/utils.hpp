#pragma once

#include <cassert>

#include <atomic>
#include <string>

namespace Utils
{
	template<typename T>
	class Node
	{
	private:

	public:
		Node() = default;
		Node(const T& t);

		T			data;
		Node<T>* next = nullptr;
	};

	template<typename T>
	class Queue
	{
	private:
		Node<T>* head = nullptr;
		unsigned int	size = 0;	//queue size, number of elements

	public:
		~Queue();					//not trivially copyable

		T& frontData(const int iterator = 0);		//get front node's data or else

		void			pushBackNode(const T& t);				//add node at end of queue
		void			popFrontNode(const int iterator = 0);	//erase front node or else

		bool			emptyQueue();
		unsigned int	sizeQueue() const;
	};

	class SpinLock
	{
	private:
		std::atomic_flag flag = ATOMIC_FLAG_INIT;

	public:
		void lock();
		void unlock();
	};

	class RawText
	{
	private:
		std::string raw;
		int			length = 0;
		int			cursor = 0;	//which line is the cursor pointing at

	public:
		RawText() = default;
		RawText(const std::string& str);

		void			setCursor(const int pos);
		bool			getline(std::string& out);
		std::string&	getRawText();
	};
}

using namespace Utils;

template<typename T>
Utils::Node<T>::Node(const T& t)
{
	data = t;
}

template<typename T>
inline Utils::Queue<T>::~Queue()
{
	while (!emptyQueue())
		popFrontNode();
}

template<typename T>
inline T& Utils::Queue<T>::frontData(const int iterator)
{
	Node<T>* node = head;

	if (node)
	{
		for (int i = 0; i < iterator; ++i)
		{
			if (node->next)
				node = node->next;
			else
				break;
		}

		return node->data;
	}

	std::abort();
}

template<typename T>
void Utils::Queue<T>::pushBackNode(const T& t)
{
	Node<T>* node = new Node<T>(t);

	if (!head)
		head = node;
	else
	{
		Node<T>* temp = head;

		for (;;)
		{
			if (temp->next)
				temp = temp->next;
			else
				break;
		}

		temp->next = node;
	}

	++size;
}

template<typename T>
void Utils::Queue<T>::popFrontNode(const int iterator)
{
	if (emptyQueue())
		return;

	Node<T>* node = head;
	Node<T>* prev = nullptr;

	if (node)
	{
		for (int i = 0; i < iterator; ++i)
		{
			if (node->next)
			{
				prev = node;
				node = node->next;
			}
			else
				break;
		}
	}
	else
		return;

	if (prev)
		prev->next = node->next;
	else
		head = node->next;

	delete node;

	--size;
}

template<typename T>
bool Utils::Queue<T>::emptyQueue()
{
	return size == 0;
}

template<typename T>
unsigned int Utils::Queue<T>::sizeQueue() const
{
	return size;
}