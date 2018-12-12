#pragma once
#include <string>
#include <fstream>
#include <iostream>


class KnapsackProblem
{
public:
	KnapsackProblem();
	KnapsackProblem(std::string wFile, std::string vFile, int weight, int number);
	~KnapsackProblem();
private:
	int max_weight;
	int* weights;
	int* values;


};

