#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <stdarg.h>
using namespace std;

void addRd(int d, int &k)
{
	k = 10 * k + d;

}

int sumNumber(int num, ...);

void  up_and_down(int n)
{
	cout << " level: " << n << endl;
	if (n < 4)
	{
		up_and_down(n + 1);
		cout << "level: " << n << endl;
	}
}

long fact(int n)
{
	long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;

	return ans;
}

long rfact(int n)
{
	long ans;
	if (n > 0)
		ans = n*rfact(n - 1);
	else
		ans = 1;

	return ans;
}



int sum(char* ch, int r);

void rand(char *mas, int r);

int Rsum(char* ch, int r, int * s);





void main()
{

	/*#pragma region

	  int k, d;
	  cout << "k: ";
	  cin >> k;

	  for (int i = 0; i < 2; i++)
	  {
		  while (1)
		  {
			  cout << "d: ";
			  cin >> d;
			  if (d >= 0 && d <= 9)
			  {
				  addRd(d, k);
				  break;
			  }

			  else
			  {
				  cout << " !!! \n";
			  }
		  }
		  cout << "k = " << k << endl;
	  }

  #pragma endregion*/


  /*#pragma region

	  int sum = sumNumber(3, 2, 6, 3, 1, 1, 1, 4, 3, 2);
	  cout << sum;
	  cout << endl;
	  #pragma endregion*/

	  //up_and_down(4);
	  /*#pragma region

		  int num;
		  while (scanf("%d", &num) == 1)
		  {
			  if (num < 0)
			  {
				  cout << "please do not enter negative number\n";
			  }

			  else if (num > 12)
			  {
				  cout << "the input type mast be less than 13\n";
			  }

			  else
			  {
				  long result = fact(num);
				  cout << "num = " << num << "  result = " << result << endl;

				  long resultR = rfact(num);
				  cout << "num = " << num << "  resultR = " << resultR << endl;
			  }
		  }
		  #pragma endregion*/

	int nz;

	cout << "¬ведите номер задани€: ";
	cin >> nz;

	switch (nz)
	{
	case 11:
	{
		char ch[5];
		int s = 0;
		
		rand(ch, 5);
		s = Rsum(ch, 5, &s);

	}break;

	}

}


int sumNumber(int num, ...)
{
	int sum = 0;

	va_list arg;
	//инициализируем указатель arg

	va_start(arg, num);


	//суммируем р€дов
	int t;
	for (; num; num--)
	{
		t = va_arg(arg, int);
		sum += t;
	}


	//корректное завершение
	va_end(arg);

	return sum;
}


int sum(char* ch, int r)
{
	int s;

	for (int i = 0; i < r; i++)
	{
		s += (int)*ch;
		ch++;
	}

	return s;
}


int Rsum(char* ch, int r, int * s)
{

	if (r >= 0)
	{
		r--;
		s += Rsum(ch + r, r, s);
	}
	else
		r = *ch + r;

	return r;

}


void rand(char *mas, int r)
{
	srand(time(NULL));

	for (int i = 0; i < r; i++)
	{
		*mas = 1 + rand() % 9 + '0';
		mas++;
	}
}
