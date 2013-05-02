/* 
* Graph container class.
*/

#pragma once

#include <vector>
#include <queue>
#include "Vertex.h"

template <class T>
class Graph {
public:
	// constructors
	Graph(std::vector<T>& nodes)
	{
		for (unsigned i = 0; i < nodes.size(); i++)
		{
			Vertex<T> vertex(nodes[i]);
			_vertices.push_back(vertex);
		}

	}

	// information
	unsigned size() const { return _vertices.size(); }
	bool empty() const { return !_vertices.size(); }

	// operations
	bool addEdge(unsigned i, unsigned j) 
	{
		// check validity of parameters
		if (!(i < size() && j < size()))
			return false;

		// add edges
		if (_vertices[i].addNeighbor(j))
			return _vertices[j].addNeighbor(i);

		return false;
	}

	bool remEdge(unsigned i, unsigned j) 
	{
		// check validity of parameters
		if (!(i < size() && j < size()))
			return false;

		// remove edges
		if (_vertices[i].remNeighbor(j))
			return _vertices[j].remNeighbor(i);

		return false;
	}
	
	T& operator[](int i)
	{
		return _vertices[i].getNode();
	}


	class Iterator;
	class BFS_Iterator;
	friend class BFS_Iterator;

	Iterator begin() { return Iterator(*this, 0); }
	Iterator end() { return Iterator(*this, _vertices.size()); }

	
private:
	std::vector<Vertex<T>> _vertices;
};



template <class T>
class Graph<T>::Iterator {
public:
	Iterator(Graph<T>& graph, unsigned i) : _graph(graph), _index(i) { }

	T& operator* () { return _graph[_index]; }

	Iterator operator++() //prefix
	{
		++_index;
		return (*this);
	}

	Iterator operator++(int) //postfix
	{
		Iterator copy(*this);
		++_index;
		return copy;
	}

	bool operator ==(Iterator& other)
	{
		if (&_graph != &(other._graph))
			return false;
		return _index == other._index;
	}

	bool operator !=(Iterator& other)
	{
		return !(*this == other);
	}

	bool isEnd() const
	{
		return _index >= _graph.size();
	}

	unsigned get_index() const { return _index; }

private:
	Graph<T>& _graph;
	unsigned int _index;
};


// this iterator gets a source index and makes it able to iterate on the bfs order from the source
template <class T>
class Graph<T>::BFS_Iterator {
public:
	// the Constructor creates a 
	BFS_Iterator(Graph<T>& graph, unsigned source) : _graph(graph), _index(0) { if (source < _graph.size()) runBFS(source); }

	T& operator* () { return _graph[_index]; }

	// next
	BFS_Iterator operator++() //prefix
	{
		_index = _order.front();
		_order.pop();
		return (*this);
	}
	// next
	BFS_Iterator operator++(int) //postfix
	{
		Iterator copy(*this);

		_index = _order.front();
		_order.pop();
		return copy;
	}

	// operator ==
	bool operator ==(Iterator& other)
	{
		if (&_graph != &(other._graph))
			return false;
		return _index == other._index;
	}
	// operator !=
	bool operator !=(Iterator& other)
	{
		return !(*this == other);
	}
	// end
	bool isEnd() const
	{
		return _order.empty();
	}

private:
	Graph<T>& _graph;
	std::queue<unsigned> _order;
	unsigned int _index;

	// ------------------------------------------------------------------------------


	// creates the _order on which the iterator iterates
	void runBFS(unsigned source)
	{
		// declare all vertices as not visited
		for (unsigned i = 0; i < _graph.size(); ++i)
			_graph._vertices[i].visited = false;

		// create queue and push the source and mark it as visited
		std::queue<unsigned> queue;
		queue.push(source);
		_graph._vertices[source].visited = true;

		// run while the queue is not empty
		while (!queue.empty())
		{
			// get the next vertex from queue
			unsigned current = queue.front();
			queue.pop();

			_order.push(current);

			// push all neighbors that have not been visited to the queue
			// mark them as visited, and push them to the order
			for (Vertex<T>::neighborsIterator it = _graph._vertices[current].begin(); !it.isEnd(); ++it)
			{
				if (_graph._vertices[*it].visited)
					continue;

				_graph._vertices[*it].visited = true;
				queue.push(*it);
			}
		}

		// dummy for isEnd(). when this will be in _index the _order will be empty
		_order.push(0);

		operator++();
	}
};