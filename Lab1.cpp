// Opis
// Program generuje losowo pionki ze wspolrzednymi ograniczonymi przez uzytkownika
// nastepnie uzytkownik wybiera wsporzedne swojego pionka, po czym program liczy
// odleglosci wszystkich pionkow od tego jednego i wybiera najwieksza wartosc




#include <iostream>
#include <random>
#include <math.h>

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& point);

public:
	int x = 0;
	int y = 0;

	Point()
	{}

	Point(int cX, int cY) // c -> constructor
		: x(cX), y(cY)
	{}
};

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
	stream << "(" << point.x << ", " << point.y << ")";
	return stream;
}

float calculateDistance(Point p1, Point p2)
{
	int xDif = (p1.x - p2.x);
	int yDif = (p1.y - p2.y);

	return sqrt( (float)(xDif*xDif + yDif*yDif) );
}

int findMaxIndex(float* arrayPtr, int size)
{
	float max = *arrayPtr;
	int index = -1;

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

int main()
{
	int columnsCount = 0;
	int rowsCount = 0;
	int pawnNumber = 0;

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

	std::cout << "How many pawns?\n";
	std::cin >> pawnNumber;

	if (pawnNumber < 0 || pawnNumber > rowsCount*columnsCount)
	{
		std::cout << "Error: Unapropriate number of pawns\n";
		return -1;
	}

	int userX = 0;
	int userY = 0;

	std::cout << "What are coordinates of Your pawn?\n";
	
	std::cout << "x = ";
	std::cin >> userX;

	if (userX < 0 || userX > columnsCount)
	{
		std::cout << "Error: Unapropriate pawn coordinates\n";
		return -1;
	}

	std::cout << "y = ";
	std::cin >> userY;

	if (userY < 0 || userY > rowsCount)
	{
		std::cout << "Error: Unapropriate pawn coordinates\n";
		return -1;
	}

	Point userPawn(userX, userY);

	std::random_device randomDevice; // get random seed from hardware
	std::mt19937 gen(randomDevice()); // generate random number with Merenne Twister engine
	std::uniform_int_distribution<> distribution(0, columnsCount-1); // set limits for random number
	std::uniform_int_distribution<> distribution2(0, rowsCount-1); // second distribution because limits of rows and columns are different

	Point* pawnList = new Point[pawnNumber];

	for (int i = 0; i < pawnNumber; i++)
	{
		pawnList[i].x = distribution(gen);
		pawnList[i].y = distribution2(gen);
		std::cout << i << " Pair: (" << pawnList[i].x << ", " << pawnList[i].y << ")";
		std::cout << " Distance: " << calculateDistance(userPawn, pawnList[i]) << "\n";
	}

	float* distanceList = new float[pawnNumber];

	Point solution(0, 0);

	for (int i = 0; i < pawnNumber; i++)
	{
		distanceList[i] = calculateDistance(userPawn, pawnList[i]);
	}

	solution = pawnList[ findMaxIndex(distanceList, pawnNumber) ];

	std::cout << "Solution= " << solution << "\n";

	delete[] pawnList;
	delete[] distanceList;

}