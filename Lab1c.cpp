// Opis
// Program wpierw okresla limity danych wejsciowych, nastepnie towrzy siatke
// po czym wypelnia ja liczbami naturalnymi od 0 do 9 (losowe liczy naturalne)
// gdy juz wypelni plansze po kolei dzielimy wszystkie jej wartosci i dodaje
// do TripletVector'a (na wzor <vector>) zestawy danych Triplet zawierajacych
// w tym przypadku wsporzedna x, wsporzedna y, wartosc iloczynu pol sasiadujacych
// po czym wybierany jest Triplet z najmniejszym iloczynem, oraz rysowana jest siatka (x rosna w prawo, y rosn¹ w dol)


#include <iostream>
#include <random>
#include "MyAddon.h"

int main()
{
	int columnsCount = 0;
	int rowsCount = 0;
	int n = 0;

	std::cout << "Enter columns number:\n";
	std::cin >> columnsCount;

	if (columnsCount < 0)
	{
		std::cout << "Error: Columns count less than 0\n";
		return -1;
	}

	std::cout << "Enter rows number:\n";
	std::cin >> rowsCount;

	if (rowsCount < 0)
	{
		std::cout << "Error: Rows count less than 0\n";
		return -1;
	}

	std::cout << "Enter the n number (range is from 1 to " << columnsCount+rowsCount << "):\n";
	std::cin >> n;

	if (n <= 0 || n >= columnsCount + rowsCount)
	{
		std::cout << "Error: n is out of range\n";
		return -1;
	}

	std::cout << "\n";

	Grid grid(columnsCount, rowsCount);

	std::random_device randomDevice; // get random seed from hardware
	std::mt19937 gen(randomDevice()); // generate random number with Merenne Twister engine
	std::uniform_int_distribution<> distribution(0, 9); // set limits for random number

	for (int i = 0; i < columnsCount; i++)
	{
		for (int j = 0; j < rowsCount; j++)
		{
			grid.setGridValueAtIndex(i, j, distribution(gen));
		}
	}

	TripletVector vector;

	for (int i = 0; i < columnsCount; i++)
	{
		for (int j = 0; j < rowsCount; j++)
		{
			if ((i + j) % n == 0)
			{
				vector.addToBack(Triplet(i, j, grid.productAtIndex(i, j)));
			}
		}
	}

	Triplet solution = vector.findMinValue();

	std::cout << "Solution  x: " << solution.getX() << " y: " << solution.getY() << " z: " << solution.getZ() << "\n\n";

	for (int j = 0; j < grid.getRows(); j++)
	{
		for (int i = 0; i < grid.getColumns(); i++)
		{
			std::cout << grid.getGridValueAtIndex(i, j) << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
