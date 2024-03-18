/*
 * Reese Myers
 * CPSC 1070: 010
 * 04/09/2023 */

// Purpose: This file declares all of the functions and member variables for the Queue class. The Queue class
// utilizes linked lists to create Queues of int-containing nodes.

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
	private:
		// A struct is used to create nodes for the queue.
		// Each QueueNode stores an int value and a pointer to the next node
		struct QueueNode {
			int value;
			QueueNode *next;
			QueueNode(int value1, QueueNode *next1 = nullptr) {
				value = value1; // The value passed in is assigned to value
				next = next1; // nullptr is assigned to next
			}
		};

		QueueNode *front;
		QueueNode *rear;
		int numNodes;
	public:
		Queue();
		~Queue();

		void enqueue(int);
		void dequeue(int &);
		bool isEmpty() const;
		bool isFull() const;
		void clear();
};
#endif
