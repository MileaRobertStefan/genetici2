#pragma once
#include "Librarii.h"
#include "Gena.h"
#include "Graf.h"
class Individ
{
	Graf* graf;
public:
	std::vector<int> id_culori; // id_culoare[i] =trasaturi[graf->graf[i]].decodificare

	Gena trasaturi;
	bool exista_culori_adiacente();
	bool exista_culori_adiacente(int);
	void elimina_culori_adiacente();
private:
	void mutatie() {};
	void crossOver() {};

	void hill_cb() {};
	void simulate_anealing() {};
	void print_culori();

public:
	Individ(Graf* GRAF);

};

