#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> // macros va_start, va_arg, va_end, fonctions variadiques

float	float_somme(int n, ...)
{
	float somme = 0.0; // innitialisation var somme a 0
	va_list args; // declara var type va_list appelee args
	va_start (args, n); 
	/* appel de la maccro va_start en envoynt 2 parametres : 
						// la var args et le nom du dernier parametre 
						// obligatoire de la fonction (cf parametres fonction
						// float_somme) */
	for (int i = 0 ; i < n ; i++)
		somme += (float)va_arg(args, double);	
	/* lectur des valeurs associees a n pour va_arg, params = var args ET typr 
	 * de donnee qu'on veut lire
	 *
	 * ATENTION = addition de float + dire a arg "lit un double" (par rapport
	 * au main et au cast
	 *
	 * */
	va_end(args); // fin utilisation args
	return (somme);
}

int main(void)
{
	float f = float_sum (3, 2.5, -12.62, 37.0); // 3 float a additionner

	printf ("SOMME = %f.\n", (double) f); // cast
	return EXIT_SUCCESS;
}
