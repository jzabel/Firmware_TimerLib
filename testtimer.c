/* test Timer, a simple program to test the adition of the Timer functions
   to the introl library
*/
#include <stdio.h>
#include <dbprintf.h>
#include <me218_912.h>
#include <timer.h>

#define TIME_OUT_DELAY 1280 /* TIME_OUT_DELAY = 10 S w/ 8mS interval */
#define SHORT_DELAY 128

static unsigned int delta = 1;

void main(void)
{
   unsigned int i;
   
   /* test GetTime() */
   DB_printf("\nGetTime() reports %u\n", GetTime());
   if (GetTime())
     puts("returned non-zero\n");
   else
     puts("yup, returned zero\n");
     
   puts("\nStarting Timer Test (TestTimer.c), will delay for 10 Sec.\n");
   DB_printf("GetTime() Now reports %u\n", GetTime());
   
   TMR_Init(TMR_RATE_8MS);
   TMR_InitTimer(0, TIME_OUT_DELAY);
   TMR_InitTimer(1, TIME_OUT_DELAY);
   TMR_InitTimer(2, TIME_OUT_DELAY);
   TMR_InitTimer(3, TIME_OUT_DELAY);
   TMR_InitTimer(4, TIME_OUT_DELAY);
   TMR_InitTimer(5, TIME_OUT_DELAY);
   TMR_InitTimer(6, TIME_OUT_DELAY);
   TMR_InitTimer(7, TIME_OUT_DELAY);
   while(TMR_IsTimerExpired(0) != TMR_EXPIRED)
      ;
   puts("Timed Out\a\n");
   TMR_InitTimer(7, SHORT_DELAY);
   for (i=0;i<10,000 ;i++ )
   {/* kill some time */
   }
   TMR_StopTimer(7);
   if (TMR_IsTimerActive(7) != TMR_NOT_ACTIVE)
      puts("Timer Stop Failed\n");
   else
      puts("Timer Stop Succeded\n");
   puts("Restarting Timer for short delay \n");
   TMR_StartTimer(7);
   while(TMR_IsTimerExpired(7) != TMR_EXPIRED)
      ;

   puts("Timed Out Again\a\n");

   disable();
//DB_printf("response time = %u\n", delta);
}
/*------------------------------ End of file ------------------------------*/


