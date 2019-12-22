#pragma once
#include "Individ.h"
class Euristic
{
	bool alegem_un_fraier(double T, double a, double b);
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

	void simulated_annealing(Graf *g)
	{
		double* raspuns = new double[g->graf.size()];
		double minim_global = 10000000, minim_local;
		Individ vecin(g);
		double temperatura = 1000.0;
		Individ candidat(g);
		const unsigned int dimensiuni= g->graf.size();
		
		candidat.trasaturi.initiere_random();

		double minim_curent;// calculeaza_functie(candidat);

		bool stop = false;
		for (int ii = 0; ii < 120; ++ii)
			do {
				int set = 12000;
				do
				{
					vecin = candidat;
					int length = rand() % (candidat.trasaturi.ADN.size()) + 1;
					for (int i2 = 0; i2 < length; ++i2)
					{
						const int pos = rand() % candidat.trasaturi.ADN.size();
						vecin.trasaturi.ADN[pos] = !vecin.trasaturi.ADN[pos];
					}
					//minim_local = calculeaza_functie(vecin);
					if (minim_curent > minim_local)
					{
						minim_curent = minim_local;
						candidat = vecin;
					}
					else
						if (alegem_un_fraier(temperatura, minim_curent, minim_local))
						{
							minim_curent = minim_local;
							candidat = vecin;
						}
					set--;
				} while (set);
				temperatura *= 0.9;
				if (minim_global > minim_curent)
				{
					minim_global = minim_curent;
					cobai = candidat;
				}
			} while (temperatura > 1);
			delete[] raspuns;
	}
	Euristic(Individ a) : cobai(a) {};


};

