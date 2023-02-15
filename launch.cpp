#include "polygon.h"

int main() {

	int size;
	std::cin >> size;

	matrix<infDouble> base(size);

	base.fullInput();

	polygonSet test(base);

	infDouble min = infDouble::OMEGA;

	int minX = 0, minY = 0;

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (x == y) { continue; }

			polygon* temp = new polygon(test, x, y);
			if (temp->minTSPCycle().length() < min) {
				min = temp->minTSPCycle().length();

				minX = x;
				minY = y;
			}
			std::cout << temp->minTSPCycle().length() << " ";
            delete temp;
		}
		std::cout << std::endl;
	}

	std::cout << "-------------------------------------\n";
	std::cout << "the minimum value found is: " << min << '\n';
	std::cout << "at: " << minX << ", " << minY;
	return 0;
}
