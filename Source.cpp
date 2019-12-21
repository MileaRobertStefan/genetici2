#include <iostream>
#include "Graf.h"
#include  "Gena.h"
#include "Individ.h"
#include "Euristic.h"
int Gena::default_size = 1;
int main()
{
	srand((int)time(0));
	Graf input(std::string("D:\\Facultate\\Anul2\\AlgoritmiGemetici\\Tema3\\genetici\\instances\\le450_5a.col"));
	input.Sortate_dupa_grad_Si_eliminare_noduri_izolate();
	Individ Jonut(&input);
	Euristic he(Jonut);

	he.main();

	return 0;
}