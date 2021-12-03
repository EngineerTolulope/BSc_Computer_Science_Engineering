#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main()
{
    int n, h=0, t=0;
    float x;
    //srand(7364);//how to set the initial value of the starting point to a number
    int number= time(NULL);//stores the time as a number
    srand(number);//we use time because it changes everytime, it sets where rand() starts from in it internal calculations
    //printf("%d\n", RAND_MAX);
    /* n = rand();//0<=n<=RAND_MAX
       n = rand();//0<=n<=RAND_MAX
       n = rand();//0<=n<=RAND_MAX*/
    //RAND_MAX
    //n=rand()%(max-min +1) + min
    n=rand()%(90-1+1) + 1; // e.g between 1 and 90
    x=(float)rand()/RAND_MAX;//gives a floating number
    //x=((float)rand()/RAND_MAX) * (max - min)+min;//gives a floating number
    //printf("%f\n", x);
    x=/*gives a 0..... no at first*/((float)rand()/RAND_MAX) * (110.5-10.8)+10.8;//gives a float number btw 10.8 and 110.5
    //printf("%f\n", x);
    printf("%d\n",n); // prints a random number between 1 and 90
    for (n=0;n<1000000;n++){
        x=(float)rand()/RAND_MAX;
    if (x<=0.75) h++; //head+=1
    else t++;//tail+=1
    }



    printf("%f",(float)h/(h+t));//gives the probability of getting head



    return 0;
}
