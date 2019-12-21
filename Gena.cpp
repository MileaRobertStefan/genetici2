#include "Gena.h"

int Gena::decodificare(int poz)
{
	int sum = 0;
	for (int i = 0; i < GENESIZE; ++i)
	{
		sum *= 2;
		sum += ADN[i + poz * GENESIZE];
	}
	return sum;
}

void Gena::initiere_random(int poz)
{
	int random_nr = rand() * rand();
	for (int i = 0; i < GENESIZE; ++i)
		ADN[i + poz * GENESIZE] = (random_nr >> i) & 1;
}

void Gena::print(int poz)
{
	printf("\n %d:\t",poz);
	//int sum = 0;
	for (int i = 0; i < GENESIZE; ++i)
	{
		std::cout << ADN[i + poz * GENESIZE];
		//	sum += ADN[i];
	}
	//	printf(" %d", sum);
}


void Gena::initiere_random()
{
	for (int i = 0; i < size; ++i)
		initiere_random(i);
}

void Gena::print()
{
	for (int i = 0; i < size; ++i)
		print(i);
}

Gena::Gena(int Size) : size(Size)
{
	ADN.resize(GENESIZE * size);
}

Gena::Gena()
{
	ADN.resize(GENESIZE * default_size);
	size = default_size;
}

Gena::~Gena()
{
}
