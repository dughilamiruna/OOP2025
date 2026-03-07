#include "Math.h"
#include <cstdio>

int main()
{
	printf("Metodele Add:\n");
	printf("Add(1, 2) = %d\n", Math::Add(1,2));
	printf("Add(1, 2, 3) = %d\n", Math::Add(1, 2, 3));
	printf("Add(1.5, 2.5) = %d\n", Math::Add(1.5, 2.5));
	printf("Add(1.5, 2.5, 3.5) = %d\n", Math::Add(1.5, 2.5, 3.5));
	printf("\n");

	printf("Metodele Mul:\n");
	printf("Mul(1, 2) = %d\n", Math::Mul(1, 2));
	printf("Mul(1, 2, 3) = %d\n", Math::Mul(1, 2, 3));
	printf("Mul(1.5, 2.5) = %d\n", Math::Mul(1.5, 2.5));
	printf("Mul(1.5, 2.5, 3.5) = %d\n", Math::Mul(1.5, 2.5, 3.5));
	printf("\n");

	printf("Metoda Add variadica:\n");
	printf("Add(1, 2, 3, 4, 5, 6) = %d\n", Math::Add(6, 1, 2, 3, 4, 5, 6));
	printf("\n");

	printf("Metoda Add char:\n");
	printf("Add('Hello', ' world!') = %s\n", Math::Add("Hello", " world!"));
	return 0;
}
