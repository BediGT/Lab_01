#include "MyAddon.h"
#include <iostream>


// Grid Class

Grid::Grid(int _columns, int _rows)
	: columns(_columns), rows(_rows)
{
	gridField = new int*[columns];

	for (int i = 0; i < columns; i++)
	{
		gridField[i] = new int[rows];
	}
}

int Grid::getColumns() {
	return columns;
}

int Grid::getRows() {
	return rows;
}

int*** Grid::getGridPtr()
{
	return &gridField;
}

int Grid::getGridValueAtIndex(int i, int j)
{
	return gridField[i][j];
}

void Grid::setGridValueAtIndex(int i, int j, int value) {
	gridField[i][j] = value;
}

int Grid::productAtIndex(int i, int j)
{
	int product = 1;

	for (int iter = -1; iter < 2; iter++)
	{
		for (int jter = -1; jter < 2; jter++)
		{
			if (i + iter >= 0 && j + jter >= 0 && i + iter < columns && j + jter < rows)
			{
				if (!(iter == 0 && jter == 0))
				{
					product *= gridField[i+iter][j+jter];
				}
			}
		}
	}

	return product;
}


Grid::~Grid()
{
	if (gridField != nullptr)
	{
		for (int i = 0; i < columns; i++)
		{
			delete[] gridField[i];
		}

		delete[] gridField;
	}
}




// Triplet Class

Triplet::Triplet()
	:x(0), y(0), z(0)
{}

Triplet::Triplet(int X, int Y)
	:x(X), y(Y), z(0)
{}

Triplet::Triplet(int X, int Y, int Z)
	:x(X), y(Y), z(Z)
{}

int Triplet::getX()
{
	return x;
}

void Triplet::setX(int X)
{
	x = X;
}

int Triplet::getY()
{
	return y;
}

void Triplet::setY(int Y)
{
	y = Y;
}

int Triplet::getZ()
{
	return z;
}

void Triplet::setZ(int Z)
{
	z = Z;
}

TripletVector::TripletVector()
{
	vector = new Triplet[2];
	maxElements = 2;
	numberOfElements = 0;
}

int TripletVector::getMaxElement()
{
	return maxElements;
}

int TripletVector::getnumberOfElements()
{
	return numberOfElements;
}

void TripletVector::addToBack(Triplet newElement)
{
	if (numberOfElements >= maxElements)
	{
		maxElements *= 2;

		Triplet* expandList = new Triplet[maxElements];

		for (int i = 0; i < numberOfElements; i++)
		{
			expandList[i] = vector[i];
		}

		delete[] vector;

		vector = expandList;
	}

	vector[numberOfElements] = newElement;

	numberOfElements++;
}

Triplet TripletVector::getValueAtIndex(int index)
{
	if (index < maxElements && index >= 0)
	{
		return vector[index];
	}
	else
	{
		return Triplet(-1,-1);
	}
}

void TripletVector::setValueAtIndex(int index, Triplet value)
{
	if (index < maxElements && index >= 0)
	{
		vector[index] = value;
	}
	else
	{
		std::cout << "Error: index out of range\n";
	}
}

Triplet TripletVector::findMinValue()
{
	Triplet min = vector[0];

	for (int i = 1; i < numberOfElements; i++)
	{
		if (vector[i].getZ() < min.getZ())
		{
			min = vector[i];
		}
	}

	return min;
}

TripletVector::~TripletVector()
{
	delete[] vector;
}


