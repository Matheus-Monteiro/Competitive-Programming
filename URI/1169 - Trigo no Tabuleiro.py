# Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
# Nome: Trigo no Tabuleiro
# Nível: 1
# Categoria: MATEMÁTICA
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1169

import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args)
	{
		Scanner entrada = new Scanner(System.in);
		BigInteger n;
		int t, m;
		
		t = entrada.nextInt();	

		while(t != 0)
		{
			n = BigInteger.valueOf(2);
			m = entrada.nextInt();
			n = n.pow(m);
			n = n.divide(BigInteger.valueOf(12000));
			System.out.println(n + " kg");		
			t--;
		}
	}
}
