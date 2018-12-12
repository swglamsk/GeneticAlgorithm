#include "stdafx.h"
#include "KnapsackProblem.h"


KnapsackProblem::KnapsackProblem()
{
}

KnapsackProblem::KnapsackProblem(std::string wFile, std::string vFile, int weight, int number)	
{
	max_weight = weight;
	std::fstream fileW(wFile, std::ios_base::in);
	std::fstream fileV(vFile, std::ios_base::in);

	weights = new int[number];
	values = new int[number];

	for (int i = 0; i < number; i++)
	{
		fileW >> weights[i];
		fileV >> values[i];
		std::cout << i << ". Waga: " << weights[i] << " Wartosc: " << values[i] << std::endl;
	}


}


KnapsackProblem::~KnapsackProblem()
{
	delete[] values;
	delete[] weights;
}

void KnapsackProblem::convertAnswer(Individual& individual)
{
	std::string genotype = individual.getGenotype();
	int length = genotype.length();
	std::cout << "Najlepszy wybor: " << std::endl;
	for (int i = 0; i < length; i++) {
		if (genotype[i] == '1') {
			std::cout << weights[i] << " " << values[i] << std::endl;
		}
	}
}