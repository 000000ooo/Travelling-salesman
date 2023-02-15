#pragma once

//#include <vector>
#include <iostream>
#include <utility>
#include <iomanip>

template <class matrixBodyType>

//origin point at top left, format in [from][to]
class matrix
{

	int M_horizontalLength;
	int N_verticalLength;

	bool active = false;

	void destroy()
	{
		if (!active)
		{
			return;
		}

		for (int x = 0; x < M_horizontalLength; x++)
		{
			delete[] body_matrix[x];
		}

		delete[] body_matrix;

		body_matrix = NULL;

		active = false;
	}
	void reconstruct(int m, int n)
	{
		destroy();

		body_matrix = new matrixBodyType * [m];

		for (int x = 0; x < m; x++)
		{
			body_matrix[x] = new matrixBodyType[n];
		}

		active = true;
	}

public:
	matrixBodyType** body_matrix = NULL;

	matrix() = delete;
	matrix(int m) : M_horizontalLength(m), N_verticalLength(m) { reconstruct(m, m); }
	matrix(int m, int n) : M_horizontalLength(m), N_verticalLength(n) { reconstruct(m, n); }

	~matrix() { destroy(); }

	void resize(int m, int n)
	{
		destroy();

		M_horizontalLength = m;
		N_verticalLength = n;

		reconstruct(m, n);
	}

	void fullInput()
	{
		int y;
		for (int x = 0; x < M_horizontalLength; x++)
		{
			for (y = 0; y < N_verticalLength; y++)
			{
				std::cin >> body_matrix[x][y];
			}
		}
	}


	void fullOutput()
	{

		int y;
		for (int x = 0; x < M_horizontalLength; x++)
		{
			for (y = 0; y < N_verticalLength; y++)
			{
				std::cout << body_matrix[x][y] << " ";
			}

			std::cout << '\n';
		}
	}

	const int getM_horizontalLength() const
	{
		return M_horizontalLength;
	}

	const int getN_verticalLength() const
	{
		return N_verticalLength;
	}

};
