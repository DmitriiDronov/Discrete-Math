#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "menuUtils.hpp"

class BaseMatrix
{
private:
	std::vector<std::vector<int>> matrix;
	int cols;
	int rows;

public:
	inline BaseMatrix();
	BaseMatrix(const unsigned int cols, const unsigned int rows);
	void edit();
	friend std::ostream& operator<<(std::ostream& os, const BaseMatrix mx);
	inline BaseMatrix(const BaseMatrix& mx)
	{
		cols = mx.cols;
		rows = mx.rows;
		matrix = mx.matrix;
	}
};


class IncidenceMatrix : public BaseMatrix
{
public:
	IncidenceMatrix();
	IncidenceMatrix(const int edges, const int nodes);
	int convertToOther();
};

class AdjencyMatrix
{
public:
	AdjencyMatrix();
	~AdjencyMatrix();
private:

};

std::vector<IncidenceMatrix>& incidentMartixes();