#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float	float_somme(int n, ...)
{
	float somme = 0.0; // innitialisation var somme a 0
	va_list ap; // declar var type va_list appelee ap
	va_start (ap, n); 
	/* appel de la maccro va_start en envoynt 2 parametres : 
	la var ap et le nom du dernier parametre obligatoire de la 
	fonction (cf parametres fonction float_somme) */
	for (int i = 0 ; i < n ; i++)
		somme += (float)va_arg(ap, double);	
	/* lectur des valeurs associees a n pour va_arg, params = var ap ET typr 
	 * de donnee qu'on veut lire
	 * ATENTION = addition de float + dire a arg "lit un double" (par rapport
	 * au main et au cast
	 * */
	va_end(ap); // fin utilisation ap
	return (somme);
}()

int main(void)
{
	float f = float_somme (3, 2.5, -12.62, 37.0); // 3 float a additionner

	printf ("SOMME = %f.\n", (double) f); // cast
	return EXIT_SUCCESS;
}