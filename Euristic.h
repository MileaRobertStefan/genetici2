#pragma once
#include "Individ.h"
class Euristic
{
public:
	Individ cobai;
	void (*functie_cu_valoare)(Graf, int);
	int main()
	{
		print_block
		int count = 1 << 30;
		for (int kappa = 0; kappa < 1000; ++kappa) {
			do
			{
				cobai.elimina_culori_adiacente();
				cobai.update_id_culori();
			} while (cobai.exista_culori_adiacente());
			const int rez = cobai.cate_culori_am();
			cobai.trasaturi.initiere_random();
			count = min(count, rez);
		}
		std::cout << count;
		return 0;
	}
	Euristic(Individ a) : cobai(a) {};


};

