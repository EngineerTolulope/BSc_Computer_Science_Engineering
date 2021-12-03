#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include <dirent.h>
#include<fcntl.h> //In order to use low level file handling
#include<malloc.h> //In order to use the malloc function
//
int L =256;
int pixelsize;
int i,j,t;
//unsigned char *Head; //To store header fields
unsigned char *PA ;//For the pixel array
float rnum; //random number
float P_up=0.23,P_down=0.28,P_left=0.26,P_right=0.23;
int tmpx, tmpy;
int bon;//if 1 don't break, Break if 0
//
void createBmp(){ //Function to write the 1st 54 bytes //PA here is different from the global variable
int size; // to store the size
char sig[2] = "BM"; // to store the signature
char name[100];
t=0;
sprintf(name,"RW%04d.bmp",t);//printing it for each timeline
int g = open(name,O_RDWR|O_CREAT|O_TRUNC/*|O_BINARY*/,S_IRUSR|S_IWUSR); //(Read https://linux.die.net/man/3/open)
write (g, sig, 2); // BM
size = L*(L*3 + L%4) + 54;
write (g, &size, 4);//size
//printf("%d",size);
int temp;
temp = 0;
write (g, &temp, 4);//Unused
temp = 54;
write (g, &temp, 4);//Pixel Array Offset
temp = 40;
write (g, &temp, 4);//DIB header size
int W= L, H = L;
write (g, &W, 4);
write (g, &H, 4);
short int tmp; //for 2 bytes  char
tmp = 1;
write (g, &tmp, 2); //Planes
tmp = 24;
write (g, &tmp, 2); //Bits per Pixel
temp =0;
write (g, &temp, 4);//Compression
write (g, &temp, 4); //Image size
temp = 5900;
write (g, &temp, 4); //Horizontal pixel/meter
write (g, &temp, 4); //Vertical pixel/ meter
temp = 0;
write (g, &temp, 4); //Colors in palette
write (g, &temp, 4); //Used palette colors
//
write(g,PA,pixelsize);
//
close(g); free(PA); //free(Head);
return;
}
//
struct particle{
    int x;
    int y;
};
//
int main(){
    pixelsize = L*(L*3+L%4);//Changing the value of the global variable;//Total number of pixels
    PA = (unsigned char*) calloc(pixelsize, sizeof(unsigned char));//Initiallizing the pixel array to zero
    //
    srand(time(NULL));//we use time because it changes everytime, it sets where rand() starts from in it internal calculations
    int N=L*10;//Random number //Making sure N is a very large number than L
    struct particle part[N];//An array of N structures, To store all particles, 0,1,2, until N
    int hmax=0; //We are at the zero height in the y coordinate
    //
    for (i=0;i<N;i++){
      bon=1;                        //Making sure bon is one at the start of the do while
      if (i<L){                     //Storing the bottom pixels as the landmark
        part[i].x = i; part[i].y=0; //The y coordnate remains 0
      }//If
      else{
        part[i].x = rand()%L; part[i].y= hmax + 1; // y is a number on present hmax + 10
        tmpy=hmax+1+2; //The maximum height a pariticle can reach before dying
        do{//Loop was created for the movement of a particle
            rnum=(float)rand()/RAND_MAX; // 0 <= x <=1 //Gets random number
            if (rnum < P_up) part[i].y+=1;
            else if (rnum >= P_up && rnum < P_up+P_down) part[i].y-=1;
            else if (rnum >= P_up+P_down && rnum < P_up+P_down+P_left ) part[i].x-=1;
            else part[i].x+=1;
            //
            if (part[i].y >= tmpy || part[i].y<=0 || part[i].x<=0){//If it has reached the upper limit ////Don't continue when it is <= zero
               part[i].x = rand()%L; part[i].y= hmax+1; //New Particle
               continue;                                              //Start moving again //Starts do while loop again
            }
            //
            for (j=0;j<i;j++){//Checking if they are neighbors
               if ((part[i].x + 1 == part[j].x  && part[i].y==part[j].y)|| //Neighbours with the right
                   (part[i].x - 1 == part[j].x  && part[i].y==part[j].y)||  //Left
                   (part[i].y + 1 == part[j].y  && part[i].x==part[j].x)||  //Up
                   (part[i].y - 1 == part[j].y  && part[i].x==part[j].x)){  //Down //Check if neighbors with previous elements
                   if (part[i].y > hmax) hmax=part[i].y; //Checking if height of part. > former height
                   bon=0;
                   break; //Leave present for loop
                }//If
            }

        }while(bon); //bon is 0 so loop stops //We stop loop if we found neighbour of previous particles
        }//Else
        //
        //Store the new neighbour in the pixel array //And the first L elements as well
        PA[part[i].y*(L*3 + L%4) + part[i].x *3 + 0 ] = 128; //Blue Pixel
        PA[part[i].y*(L*3 + L%4) + part[i].x *3 + 1 ] = 0;  //Green Pixel
        PA[part[i].y*(L*3 + L%4) + part[i].x *3 + 2 ] = (i/(float)N) * 255; //Red Pixel
        //
        //if ((i%1000==0) || i==N-1) createBmp();
    }//For
   //
    createBmp();//Printing the final product after all manipulation on a picture
    return 0;
    }


