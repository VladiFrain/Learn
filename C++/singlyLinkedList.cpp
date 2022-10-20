#include "header.h"
using namespace std;
//односвязный список
template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data);
	void clear();
	void push_front(T data);
	void pop_back();
	void insert(T value, int index);
	void removeAt(int index);
	int GetSize() { return size; }
	T &operator[](const int index);
private:

	template<typename T>
	class Node
	{
	public:
		//адрес следующего элемента
		Node *pNext;
		//данные в элементе списка
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T> *head;
};
template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}
//удаление первого элекента списка
template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
//добавление элекента в конец списка
template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}
//очистка списка
template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}
//добавление элекента в начало списка
template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}
//удаление последнего элемента
template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}
//вставить элемент по указанному индексу
template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);;
		size++;
	}

}
//удалить элемент по указанному индексу
template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
//перегрузка оператора [] для обращения к элементам списка
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

void SinglyLinkedList()//команда консоли: -sl
{
	List<int> lst;
	int numbersCount = 3;
	for (int i = 0; i < numbersCount; i++)
	{
		lst.push_back(i + 15);
	}
	for (int  i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	lst.pop_front();
	lst.push_front(3);
	cout << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl; 
	}
	lst.insert(99, 2);
	cout << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	lst.removeAt(1);
	cout << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	lst.pop_back();
	cout << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
}