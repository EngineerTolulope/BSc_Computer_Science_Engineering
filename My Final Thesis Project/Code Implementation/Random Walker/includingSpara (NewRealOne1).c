#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
//#include <dirent.h>
#include<fcntl.h> //In order to use low level file handling
#include<malloc.h> //In order to use the malloc function
//
FILE *fp;       //Parameter File //Variables are defined respective to file
int lenofs;      //length and height is 44 squares long
int S;           //Side length of each square is 2*S + 1 //If S=2 side is 5x5
int cm;          //Coloring Method e.g 1
int hmax;       //The length of the head of the snake
int snakenum;   //How many snakes in the garden
int tmax;      //Time Of Simulation
char fileID[10];//So we can change the file id in every run instead of just "RW...."
//
int L;          //each square is 2S+1 long
int pixelsize;  //Changing the value of the global variable;
int moveby;     //for to get to the center of the next square, if S=1 , moveby is 3
//Other Variables
char name[100]; //To store the name of the file
int i,j,k,t,g;
unsigned char *Head; //To store header fields
unsigned char *PA ;//For the pixel array
float rnum; //random number
float P_up=0.26,P_down=0.25,P_left=0.26,P_right=0.23;
int tmpx, tmpy;
//
void createBmp(){ //Function to write the 1st 54 bytes
int t=0;
int size; // to store the size
char sig[2] = "BM"; // to store the signature
char name[100];
sprintf(name,"%s%04d.bmp", fileID,t);//printing it for each timeline
int g = open(name,O_RDWR|O_CREAT|O_TRUNC|O_BINARY,S_IRUSR|S_IWUSR); //(Read https://linux.die.net/man/3/open)
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
unsigned char *p = (unsigned char*)calloc(pixelsize, sizeof(unsigned char)); //pixel array initialized to store 0 chars, all through
write(g,p,pixelsize);
//
free(p);
close(g);
return;
}
//
int main(){
    fp=fopen("param.txt", "rw");//Opening the Parameter file for reading
    fscanf(fp,"%d %d %d %d %d %d %s",&lenofs,&S,&cm,&hmax,&snakenum,&tmax,fileID); //Reading from the parameter file
    close(fp); //Close the parameter file
    //
    if (lenofs%2==1) lenofs--; //It works better if it is an even number so we get exactly the middle e.g L/2
    L= (2*S+1)*lenofs; //each square is 2S+1 long//Number of squares * the side length of each square
    pixelsize = L*(L*3+L%4);//Changing the value of the global variable;
    moveby = 2*S+1; //for it to the lower left corner of the next square, if S=1 , moveby is 3
    //
    int x[snakenum][hmax], y[snakenum][hmax];
    memset(x, 0, sizeof (x)); memset(y, 0, sizeof (y));//initialize all elements of x and y array to zero
    srand(time(NULL));//we use time because it changes everytime, it sets where rand() starts from in it internal calculations
    for (i=0;i<snakenum;i++){//Setting the first element of the snakes to a random number
        rnum= rand()%(lenofs); //Choose a random number between 0 and the number of square on a row and column
        x[i][0]=(2*S+1)*rnum;    //Got a random square, now we store it precise location in x[i][0]
        rnum= rand()%(lenofs);
        y[i][0]=(2*S+1)*rnum;
    }
    //
    Head = (unsigned char*) malloc(54);//allocate memory to Head
    createBmp(); //To create the black file that we read from and continue amendment
    //t=0;
    sprintf(name,"%s%04d.bmp", fileID,t);//Same name with the one created by createBmp() function
    g = open(name, O_RDWR);
    read(g,Head,54); //read only the head
    close(g);
    //
    float c[hmax];  //to store color shades
    c[0]=255;
    for (i=1;i<hmax;i++){//change the values of the remaining
        if(cm==1)
            c[i]= c[i-1] - 255/(float)hmax; //So the value is always decreasing
        if(cm==2)
            c[i]= c[i-1]; //So the value is constant
    }
    //
    t=1;
    while (t<=tmax){//Until we reach the maximum time of simulation
        PA = (unsigned char*) calloc(pixelsize, sizeof(unsigned char));//Initiallizing the pixel array to zero over and over again
        //
       for (i=0;i<snakenum;i++){//representing the particular snake
        for (j=hmax-1;j>=0;j--){//The snakes head and body//we start printing from the back so the head of the snake is always visible
         // if (x[i][j]!=0 &&y[i][j]!=0){//So it doesn't print when we have zero coordinate, because we initialized all to zero
            tmpx=x[i][j];tmpy=y[i][j];
            while (1){//for the column
             while(1){//for the row
                PA[tmpy*(L*3 + L%4) + tmpx *3 + 0 ] = c[j]; //255*(20-t)/20 ;//Blue Pixel
                PA[tmpy*(L*3 + L%4) + tmpx *3 + 1 ] = c[j];  //Green Pixel
                PA[tmpy*(L*3 + L%4) + tmpx *3 + 2 ] = c[j]; //Red Pixel
                if (tmpx == (x[i][j] + moveby -1)){ //If we have reached the right edge of the square //x[0],y[0] are still unchanged
                    tmpx = x[i][j];
                    break;
                }//If
                tmpx++;//increment by 1, because it is just a coordinate, not the 3 pixel length of row//If we are not at the edge we increment
                }//While
             if (tmpy == (y[i][j] + moveby -1)) break;//if we reach the upper edge of the square
             tmpy++; //If we are not at the edge we increment
            }//While
       // }//If
        }//for
        }//for
        //
        sprintf(name,"%s%04d.bmp", fileID,t); //To create a new file with the amendment
        g = open(name,O_RDWR|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
        write(g,Head,54);
        write(g, PA, pixelsize);
        close(g);
        //
        for (i=0;i<snakenum;i++){
          for(j=hmax-1;j>0;j--){//To shift every element to the right by one step, Starting with the position of the one on the first picture
            x[i][j]=x[i][j-1];// x[i][1]=x[i][0]
            y[i][j]=y[i][j-1];
        }}
        //
    for (i=0;i<snakenum;i++){ //Amend the zeroth coordinate of all snakes
      rnum=(float)rand()/RAND_MAX; // 0 <= x <=1
      if( rnum < P_up) {
        y[i][0]+= moveby; //Move Up
        if(y[i][0] ==L){////Not affected the same way as left or down
           y[i][0]=0;
          }}//if
      else if(rnum >= P_up && rnum <P_up+P_down) {
        y[i][0]-= moveby; //Move down
        if(y[i][0] == 0-moveby){ //if the new lowerleft coordinate to start drawing from is a square distance behind 0
           y[i][0]=L-moveby;//we start from  L, since we start from lowerleft corner L-moveby
        }}//else if
      else if(rnum >= P_up+P_down && rnum <P_up+P_down+P_left){
        x[i][0]-= moveby; //Move left
        if(x[i][0] == 0-moveby){//Same as the statement for down
           x[i][0]=L-moveby;
        }}//else if
      else if(rnum >=P_up+P_down+P_left /*&& x<P_up+P_down+P_left+P_right*/) {
        x[i][0]+= moveby; //Move Right
        if(x[i][0] ==L){ //Not affected the same way as left or down
           x[i][0]=0;
        }}//else if
     }//For
        //
     t++;
     }//While
    return 0;
    }



