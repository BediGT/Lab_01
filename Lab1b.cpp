// Opis
// Program zapelnia szachownice (siatke) liczbami oznaczajacymi kolory, ktorych ilosc
// okresla uzytkownik, nastepnie funckcja okresla ktory kolor ma najwiecej sasiadow,
// poprzez stworzenie listy kolorow gdzie kazdy indeks to kolor, a wartosc na indeksie
// to ilosc sasiadow, nastepnie szuka maksymalnej wartosci w liscie i zwracany jest
// indeks tej wartosci 

#include <iostream>
#include <random>

class Grid
{
	int columns = 0;
	int rows = 0;
	int** gridList = nullptr;


public:

	Grid(int _columns, int _rows)
		: columns(_columns), rows(_rows)
	{
		gridList = new int* [columns];

		for (int i = 0; i < columns; i++)
		{
			gridList[i] = new int[rows];
		}
	}

	int getColumns() {
		return columns;
	}

	int getRows() {
		return rows;
	}

	int*** getGridListPtr()
	{
		return &gridList;
	}

	int getGridListIndex(int i, int j) {
		return gridList[i][j];
	}

	void setGridListIndex(int i, int j, int value) {
		gridList[i][j] = value;
	}

	~Grid()
	{
		for (int i = 0; i < columns; i++)
		{
			delete[] gridList[i];
		}

		delete[] gridList;
	}
};



int findMaxIndex(int* arrayPtr, int size)
{
	int max = *arrayPtr;
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (*(arrayPtr + i) > max)
		{
			max = *(arrayPtr + i);
			index = i;

		}
	}

	return index;
}



int colorNeighbours(Grid grid, int colors)
{
	int* colorList = new int[colors];

	for (int i = 0; i < colors; i++)
	{
		colorList[i] = 0;
	}

	for (int i = 0; i < grid.getColumns(); i++)
	{
		for (int j = 0; j < grid.getRows(); j++)
		{
			if (i == 0)
			{
				if (grid.getGridListIndex(i, j) == grid.getGridListIndex(i + 1, j))
				{
					colorList[grid.getGridListIndex(i, j)]++;
				}
			}
			else if (i == grid.getColumns() - 1)
			{
				if (grid.getGridListIndex(i, j) == grid.getGridListIndex(i - 1, j))
				{
					colorList[grid.getGridListIndex(i, j)]++;
				}
			}
			else
			{
				if (grid.getGridListIndex(i, j) == grid.getGridListIndex(i + 1, j))
				{
					colorList[grid.getGridListIndex(i, j)]++;
				}
				if (grid.getGridListIndex(i, j) == grid.getGridListIndex(i - 1, j))
				{
					colorList[grid.getGridListIndex(i, j)]++;
				}
			}
		}
	}

	for (int i = 0; i < colors; i++)
	{
		std::cout << "Color " << i << ": " << colorList[i] << "\n";
	}

	std::cout << "\n";

	return findMaxIndex(colorList, colors);
}



int main()
{
	int columnsCount = 0;
	int rowsCount = 0;
	int colorsCount = 0;



	std::cout << "How many columns?\n";
	std::cin >> columnsCount;

	if (columnsCount < 0)
	{
		std::cout << "Error: Columns count less than 0\n";
		return -1;
	}

	std::cout << "How many rows?\n";
	std::cin >> rowsCount;

	if (rowsCount < 0)
	{
		std::cout << "Error: Rows count less than 0\n";
		return -1;
	}

	std::cout << "How many colors?\n";
	std::cin >> colorsCount;
	

	if (colorsCount < 0)
	{
		std::cout << "Error: Unapropriate color number\n";
		return -1;
	}

	std::cout << "\n";



	Grid grid(columnsCount, rowsCount);

	std::random_device randomDevice; // get random seed from hardware
	std::mt19937 gen(randomDevice()); // generate random number with Merenne Twister engine
	std::uniform_int_distribution<> distribution(0, colorsCount - 1); // set limits for random color
	
	for (int i = 0; i < columnsCount; i++)
	{
		for (int j = 0; j < rowsCount; j++)
		{
			grid.setGridListIndex(i, j, distribution(gen));
		}
	}

	std::cout << "Color with the highest amount of neighbours: " << colorNeighbours(grid, colorsCount) << "\n";

	return 0;
}
