/*
 * Reese Myers
 * CPSC 1070: 010
 * 04/09/2023 */

// Purpose: This file defines all of the functions for the Queue class. The Queue class
// utilizes linked lists to create Queues of int-containing nodes.

#include "Queue.h"
#include <iostream> // To print error messages

using namespace std;

// The default constructor initializes numNodes to 0 and assignes
// nullptr to both front and rear.
Queue::Queue() {
	numNodes = 0;
	front = nullptr;
	rear = nullptr;
}

// The Queue class destructor clears out the queue. It iterates
// through the entire linked list and frees the memory held by each node.
Queue::~Queue() {
	// The garbage pointer is used to move from one node to the next.
	// The memory address of the front pointer is initially assigned to garbage.
	QueueNode *garbage = front;
	
	// The loop iterates while garbage is not pointing to nullptr
	// During each iteration, the pointer to the front node is set to the address 
	// of pointer to the next node. The initial pointer to the next node is set to nullptr,
	// and the node pointed to by garbage is cleared.
	// The memory address of the front pointer is assigned to garbage.
	while (garbage != nullptr) {
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = front;
	}
}

// This function is used to enqueue an int passed in as a parameter.
// It is used to add new nodes to the queue.
void Queue::enqueue(int num) {
	// If the queue is empty, memory is dynamically allocated for a QueueNode.
	// The int passed in as a parameter is passed to the QueueNode constructor.
	// The address of the queueNode is assigned to both front and rear,
	// and numNodes is incremented.
	// Else if the Queue is full, an error message is printed out.
	// Otherwise, a new QueueNode is created and added to the rear of the Queue.
	if (isEmpty()) {
		front = new QueueNode(num);
		rear = front;
		numNodes++;
	}
	else if (isFull()) {
		cout << "The queue is full.\n";
	}
	else {
		rear->next = new QueueNode(num);
		rear = rear->next;
		numNodes++;
	}
}

// This function is sued to remove a node from the Queue.
// The address of an int is passed in as a parameter, and this is how the function
// is able to "return" a value.
void Queue::dequeue(int &num) {
	QueueNode *temp = nullptr; // A temporary pointer to a QueueNode is created

	// If the Queue is empty, an error message is printed out.
	// Otherwise, the front node's value is assiged the int at the address of num.
	// The temp pointer is assigned to the address of the front node, then the
	// address of the front pointer is set to the address of the next node.
	// The memory of the original front node is freed, and numNdoes is decremented. 
	if (isEmpty()) {
		cout << "The queue is empty.\n";
	}
	else {
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
		numNodes--;
	}
}

// This function returns a boolean value representing whether or not the queue is empty.
// If the front pointer is pointing to nullptr, true is returned.
// Otherwise, the function returns false.
bool Queue::isEmpty() const {
	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

// This function returns a boolean value representing whether or not the queue is full.
// If the number of nodes is equal to 100, true is returned.
// Otherwise, the function returns false.
bool Queue::isFull() const {
	if (numNodes == 100) {
		return true;
	}
	else {
		return false;
	}
}

// This function is used to clear the queue.
// It dequeues nodes until the queue is empty.
void Queue::clear() {
	int tempToClear; // The actual value stored by this int is never used.

	while (!isEmpty()) {
		dequeue(tempToClear);
	}
}
