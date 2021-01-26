#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>


//*************************************DELAY**********************************

void delay(int milliseconds) // taking argument in seconds
{
    clock_t start_time = clock();

    while (clock() < (start_time + milliseconds));
}


//***************************************CURSOR POSITION***********************
COORD coord = {0, 0}; //cursor related
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//*************************************BLINKING TEXT*****************************
void blink(char *message, int x_coord, int y_coord,int blink_freq)
{
    int i,j = 0;
    for (i=0;i<blink_freq;i++)
    {
        gotoxy(x_coord, y_coord);
        for (j = 0; j < strlen(message); j++)
        {
            printf(" ");
        }
        delay(200);
        gotoxy(x_coord, y_coord);
        printf(message);
        delay(200);
    }
}

void blink_(char *message, int x_coord, int y_coord)
{
    int j = 0;
    for (;;)
    {
        gotoxy(x_coord, y_coord);
        for (j = 0; j < strlen(message); j++)
        {
            printf(" ");
        }
        delay(200);
        gotoxy(x_coord, y_coord);
        printf(message);
        delay(200);
    }
}
char getinput(void)
{
    int i=0;
    char ch,*input;
    do
    {   
        ch = getch();
        if (i > 0 && ch == 8)
        {
             input[--i] = '\0';
             printf("\b \b");
        }
        if (ch != 8 && ch != 13)
        {
            printf("%c", ch);
            input[i] = ch;
            i++;
        }
    } while (ch != 13);
    input[i] = '\0';
    
    return(*input);
}

//threading
/*void* threadFunction(void* args)
{
    int j;
    while(1)
    {
    blink_("invalid", 40, 14);
    }
    }

int main()
{
    /*creating thread id*/
 //   pthread_t id;
   // int ret;
    
    /*creating thread*/
    /*ret=pthread_create(&id,NULL,&threadFunction,NULL);
    if(ret==0)
    {
        sleep(2);
        gotoxy(40, 15);
        printf("Press Enter to continue");
        gotoxy(40, 16);
        printf("Else press other keys to exit the application.");
    }
    else
    {
        printf("Thread not created.\n");
        exit(ERROR); /*return from main*/
//    }
      
  //  getch();
    //printf("Thread not created.\n");
   // getch();
    //return 0;
//}