#pragma once
#include <list>
#include <set>
#include <algorithm>
#include <vector>
#include "infDouble.h"
#include "deltaMatrix.h"

class polygonSet {

	bool activated = false;

	matrix<infDouble>& _graph;
	deltaMatrix* _delta;

	int _size = 0;

public:

	polygonSet(matrix<infDouble>& in_graph);

	deltaMatrix& delta();
	matrix<infDouble>& graph();
	int size();
};

class polygon
{
	std::list<int> body_polygon;
public:
	polygonSet& parent;
private:
	infDouble _length = 0.0;
	int size = 0;
	std::set<int> coveredPoints;

public:
	polygon(polygonSet& in_parent, int vertex1, int vertex2);

	//pushes the node with the lowest delta value into the polygon
	void advance();

	polygon& minTSPCycle();

	infDouble length() const;
};
