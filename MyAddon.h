#pragma once

class Grid
{
	int columns;
	int rows;
	int** gridField = nullptr;


public:

	Grid(int _columns, int _rows);

	int getColumns();

	int getRows();

	int*** getGridPtr();

	int getGridValueAtIndex(int i, int j);

	void setGridValueAtIndex(int i, int j, int value);

	int productAtIndex(int i, int j);

	~Grid();
};



class Triplet
{
	int x;
	int y;
	int z;

public:

	Triplet();

	Triplet(int X, int Y);

	Triplet(int X, int Y, int Z);

	int getX();

	void setX(int X);

	int getY();

	void setY(int Y);

	int getZ();

	void setZ(int Z);
};

class TripletVector
{
	int maxElements;
	int numberOfElements;
	Triplet* vector;

public:

	TripletVector();

	int getMaxElement();

	int getnumberOfElements();

	void addToBack(Triplet newElement);

	Triplet getValueAtIndex(int index);

	void setValueAtIndex(int index, Triplet value);

	Triplet findMinValue();

	~TripletVector();
};











