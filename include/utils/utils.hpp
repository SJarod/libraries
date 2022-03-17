#pragma once

#include <cassert>

#include <string>
#include <atomic>

#include "math/math.hpp"

namespace Utils
{
	template<typename T>
	class Node
	{
	private:

	public:
		Node() = default;

		/**
		 * Create a node used in the queue.
		 * 
		 * @param t
		 */
		Node(const T& t);

		T			data;
		Node<T>*	next = nullptr;
	};

	template<typename T>
	class Queue
	{
	private:
		Node<T>*	head = nullptr;
		//queue size, number of elements
		uint		size = 0;

	public:
		/**
		 * The queue is not tribially copyable.
		 */
		~Queue();

		/**
		 * Get the front node's data or specify the node's index.
		 */
		T& frontData(const int iterator = 0);

		/**
		 * Add a node at the end of the queue.
		 */
		void pushBackNode(const T& t);

		/**
		 * Erase front node or specify the index of the node to erase.
		 */
		void popFrontNode(const int iterator = 0);

		/**
		 * Is the queue empty?
		 * 
		 * @return 
		 */
		bool isQueueEmpty();

		/**
		 * Get the size of the queue.
		 * 
		 * @return 
		 */
		uint sizeQueue() const;
	};

	class SpinLock
	{
	private:
		std::atomic_flag flag = ATOMIC_FLAG_INIT;

	public:
		/**
		 * Lock the spin lock.
		 * 
		 */
		void lock();

		/**
		 * Unlock the spin lock.
		 * 
		 */
		void unlock();
	};

	class RawText
	{
	private:
		std::string raw;
		int			length = 0;
		//which character is the cursor pointing at?
		int			cursor = 0;

	public:
		RawText() = default;

		/**
		 * Create a raw text from a std::string.
		 * 
		 * @param str
		 */
		RawText(const std::string& str);

		/**
		 * Move the cursor.
		 * 
		 * @param pos
		 */
		void setCursor(const int pos);

		/**
		 * Get the line where the cursor is, then move the cursor to the beginning of the next line.
		 * 
		 * @param out
		 * @return 
		 */
		bool getline(std::string& out);

		/**
		 * Get the entire text.
		 * 
		 * @return 
		 */
		std::string& getRawText();
	};
}

template<typename T>
inline Utils::Node<T>::Node(const T& t)
{
	data = t;
}

template<typename T>
inline Utils::Queue<T>::~Queue()
{
	while (!isQueueEmpty())
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

	//std::abort();
	assert(("out of range", 0));
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
	if (isQueueEmpty())
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
bool Utils::Queue<T>::isQueueEmpty()
{
	return size == 0;
}

template<typename T>
uint Utils::Queue<T>::sizeQueue() const
{
	return size;
}