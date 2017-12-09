// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tipos de Triângulos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1045

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A v[ 0 ]
#define B v[ 1 ]
#define C v[ 2 ]
#define vSize sizeof v / sizeof( double )

int cmp( const void* a, const void* b )
{
	if ( *( double* ) a > *( double* ) b ) return -1;
	if ( *( double* ) a < *( double* ) b ) return 1;
	return 0;
}

int main( void )
{
	int i;
	double v[ 3 ];

	for ( i = 0; i < vSize; ++i )
		scanf( "%lf", v + i );

	qsort( v, vSize, sizeof( double ), cmp );

	if ( v[ 0 ] >= v[ 1 ] + v[ 2 ] )
		goto hell;

	for ( i = 0; i < vSize; ++i )
		v[ i ] = pow( v[ i ], 2 );

	if ( A == B + C )
		puts( "TRIANGULO RETANGULO" );
	else if ( A > B + C )
		puts( "TRIANGULO OBTUSANGULO" );
	else if ( A < B + C )
		puts( "TRIANGULO ACUTANGULO" );

	if ( A == C )
		puts( "TRIANGULO EQUILATERO" );
	else if ( A == B || B == C )
		puts( "TRIANGULO ISOSCELES" );

	return EXIT_SUCCESS;

hell:
	puts( "NAO FORMA TRIANGULO" );
}
