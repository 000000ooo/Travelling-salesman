#include "matrix.h"
#include "infDouble.h"
#include <algorithm>
#include <vector>

bool sortCriteria(std::pair<infDouble, int> term1, std::pair<infDouble, int> term2)
{
	return term1.first < term2.first;
}


//takes in a matrix and does preprocessing procedures to it
class deltaMatrix
{
	matrix<infDouble>& _graph;

public:
	matrix<std::vector<std::pair<infDouble, int>>>* body_deltaMatrix = NULL;

private:

	//calculates all the change values from node x to node y
	void deriveDelta(int x, int y) {
		if (x == y) {
			body_deltaMatrix->body_matrix[x][y].push_back(std::make_pair(infDouble::OMEGA, -1));
			return;
		}

		static int a;
		static infDouble length;

		length = _graph.body_matrix[x][y];

		for (a = 0; a < body_deltaMatrix->getM_horizontalLength(); a++) {
			if (a == x || a == y) { continue; }

			body_deltaMatrix->body_matrix[x][y].push_back({ _graph.body_matrix[x][a] + _graph.body_matrix[a][y] - length, a });
		}

		std::sort(body_deltaMatrix->body_matrix[x][y].begin(), body_deltaMatrix->body_matrix[x][y].end(), sortCriteria);
	}

	void deriveAllDelta() {
		int y;
		infDouble minVal, temp;

		for (int x = 0; x < _graph.getM_horizontalLength(); x++)
		{
			for (y = 0; y < _graph.getN_verticalLength(); y++)
			{
				deriveDelta(x, y);
			}
		}
	}

public:

	deltaMatrix(matrix<infDouble>& in_graph);

};

deltaMatrix::deltaMatrix(matrix<infDouble>& in_graph) : _graph(in_graph) {
	body_deltaMatrix = new matrix<std::vector<std::pair<infDouble, int>>>(_graph.getM_horizontalLength(), _graph.getN_verticalLength());

	deriveAllDelta();
}
