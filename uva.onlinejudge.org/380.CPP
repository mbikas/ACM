#define SIZE 100		 //Increase '100' to a higher value when submit.
#define FAIL 9999

#include<stdio.h>

int forwarding[SIZE][4], used[SIZE], time, call, dest, num;

int  find_destination_call(int index, int call);
void print_result(void);

int main(void)
{
	int i, j, test_case;

	scanf(" %d", &test_case);

	printf("CALL FORWARDING OUTPUT\n");

	for(i = 0; i < test_case; i++)
	{
		for(num = 0;	; num++)
		{
			scanf(" %d", &forwarding[num][0]);

			if (forwarding[num][0] == 0) break;

			for(j = 1; j < 4; j++) scanf(" %d", &forwarding[num][j]);
		}

		printf("SYSTEM %d\n", i + 1);

		while(1)
		{
			scanf(" %d", &time);

			if (time == 9000) break;

			scanf(" %d", &call);			

			dest = find_destination_call(0, call);

			print_result();
		}
	}

	printf("END OF OUTPUT\n");

	return(0);
}

int find_destination_call(int index, int call)
{
	int i, status;

	//If there created a infinity loop, then send the call to '9999'.
	for(i = 0; i < index; i++)
	{
		if (used[i] == call) return(FAIL);
	}

	for(i = 0; i < num; i++)
	{
		//If the requested call found.
		if (call == forwarding[i][0])
		{
			//If the call is in the correct time.
			if (time >= forwarding[i][1] && time <= (forwarding[i][1] + forwarding[i][2]))
			{
				//This number has been traversed.
				used[index] = call;
				return(find_destination_call(index + 1, forwarding[i][3]));
			}
		}
	}

	return(call);
}

void print_result(void)
{
	printf("AT ");
	printf("%d%d%d%d ", time / 1000, (time / 100) % 10, (time / 10) % 10, time % 10);
	printf("CALL TO ");
	printf("%d%d%d%d ", call / 1000, (call / 100) % 10, (call / 10) % 10, call % 10);
	printf("RINGS ");
	printf("%d%d%d%d",  dest / 1000, (dest / 100) % 10, (dest / 10) % 10, dest % 10);
	printf("\n");

   return;
}