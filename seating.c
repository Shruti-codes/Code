//seating arrangement in train

//please, switch to switch case. I didn't have time!
#include <stdio.h>

int main(){
	int T, N, r;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		r = N%12;

		if(r==0)
			printf("%d WS \n", N-11);
		else if(r==6)
			printf("%d WS\n", N+1);
		else if(r==1)
			printf("%d WS\n", N+11);
		else if(r==7)
			printf("%d WS\n", N-1);
		else if(r==2)
			printf("%d MS\n", N+9);
		else if(r==4)
			printf("%d AS\n", N+5);	
		else if(r==3)
			printf("%d AS\n", N+7);			
		else if(r==5)
			printf("%d MS\n", N+3);
		else if(r==8)
			printf("%d MS\n", N-3);
		else if(r==9)
			printf("%d AS\n", N-5);
		else if(r==10)
			printf("%d AS\n", N-7);
		else if(r==11)
			printf("%d MS\n", N-9);
	}
}

