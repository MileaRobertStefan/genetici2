#include "Euristic.h"
bool Euristic::alegem_un_fraier(double T, double a, double b)
{
	//	std::cout << a << " " << b;
	return (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX))) < exp((double(-1 * abs(b - a)) / T));
}