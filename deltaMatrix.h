#pragma once

#include "matrix.h"
#include "infDouble.h"
#include <vector>

inline std::ostream& operator<< (std::ostream& output, std::vector<std::pair<infDouble, int>>& target) {
	std::cout << "{ ";
	for (std::pair<infDouble, int>& temp : target)
	{
		std::cout << temp.second << ' ';
	}
	std::cout << '}';

	return output;
}

class deltaMatrix
{
	matrix<infDouble>& _graph;
	void deriveDelta(int x, int y);

	void deriveAllDelta();

public:

	matrix<std::vector<std::pair<infDouble, int>>>* body_deltaMatrix;

	deltaMatrix(matrix<infDouble>& in_graph);
};
