// Vertex class. container for values in Graph container.

#pragma once

#include <vector>

template <class T>
class Vertex {
public:
	Vertex(const T& node) : _node(node) { }	    // c-tor 
	
	bool addNeighbor(unsigned vertex) 
	{
		// check for duplicates
		for (unsigned i = 0; i < _neighbors.size(); i++)
			if (_neighbors[i] == vertex)
				return false;

		// if no duplicates: add
		_neighbors.push_back(vertex);
		return true;
	}

	bool remNeighbor(unsigned vertex) 
	{
		// search for neighbor
		for (unsigned i = 0; i < _neighbors.size(); i++)
		{
			// if found: erase
			if (_neighbors[i] == vertex)
			{
				_neighbors.erase(_neighbors.begin()+i);
				return true;
			}
		}

		return false;
	}

	T& getNode() { return _node; }

	class neighborsIterator;
	friend class neighborsIterator;

	neighborsIterator begin() { return neighborsIterator(*this, 0); }
	neighborsIterator end()   { return neighborsIterator(*this, _neighbors.size()); }

	bool visited;				  // useful for different algorithms

private:
	T _node;
	std::vector<unsigned> _neighbors; // neighbors list.
};


                                                                     
                                                                     
                                                                     
                                             

template<class T>
class Vertex<T> ::neighborsIterator {

public:	
	neighborsIterator(Vertex<T> &vtx, unsigned i): _vtx(vtx), _index(i) { }

	unsigned operator*() { return _vtx._neighbors[_index]; }
	
	neighborsIterator operator ++() { 
		++_index; 
		return *this;
	}

	neighborsIterator operator ++(int) {
		neighborsIterator copy(*this);
		++_index;
		return copy;
	}

	bool operator == ( neighborsIterator& other )
	{
		if ( &_vtx == & (other._vtx) )
			return false;
		return _index == other._vtx;
	}

	bool isEnd() { return _index >= _vtx._neighbors.size(); }


private:
	Vertex<T>& _vtx;
	unsigned _index;

};