#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h> //In order to use low level file handling
#include<malloc.h> //In order to use the malloc function


int main(){
int size; // to store the size
char sig[2]; // to store the signature
int f=open("proc1.bmp", O_RDONLY); //(Read https://linux.die.net/man/3/open)
int g= open("tina3.bmp",O_WRONLY|O_CREAT|O_TRUNC/*|O_BINARY*/,S_IRUSR|S_IWUSR); //(Read https://linux.die.net/man/3/open)

read(f, sig, 2); // read the first two bytes, the signature, “BM” as a string
write(g, sig, 2);
read(f,&size,4); // read the second field, the size, as integer, so we use 4 bytes
int nsize = 2*size; //Have to double the size because of double resolution
write(g, &nsize, 4);

//Then we have to reach the width and the height, but before them there are bytes which is not so important actually,
//so we just skip it (read but not use):

int temp;
int W,H;
read(f,&temp,4); // unused filed
write(g, &temp, 4);
read(f,&temp,4); // Pixel Array offset
write(g, &temp, 4);
read(f,&temp,4); // DIB header size
write(g, &temp, 4);
read(f,&W,4); // width in pixel (as binary integer)
int nW = 2*W; //Double the width
write(g, &nW, 4);
read(f,&H,4); // height in pixel (as binary integer)
int nH = 2*H; //Double the height
write(g, &nH, 4);
//printf("H:- %d\n W:- %d",H,W);

//Then the next two fields are just 2 bytes long, so we need ‘short’ variables:
short int tmp;
short int Color;
int i=2;
read(f,&tmp,2); // planes
write(g, &tmp, 2);
read(f,&Color,2); // colour depth (bits per pixel)
write(g, &Color, 2);

unsigned char R,G,B;
// read intermediate fields temporarily
read(f,&temp,4); //Compression
write(g, &temp, 4);
read(f,&temp,4); //Image Size
write(g, &temp, 4);
//printf("%d",temp); //For the image size including padding
read(f,&temp,4); //Horizontal pixel/meter
write(g, &temp, 4);
read(f,&temp,4); //Vertical pixel/meter
write(g, &temp, 4);
read(f,&temp,4); //Colors in palette
write(g, &temp, 4);
read(f,&temp,4); //Used palette colors
write(g, &temp, 4);

//Reading and Writing
//Taking care of padding as well
   int n=0,k;
   int RowSize = 3*W + W%4; //(in case of 24 bit (3byte) color-depth).  So the size of padding in bytes is W%4
                          //RowSize should be divisible by 4, RowSize contains the padding as well
   int nRowSize = 3*nW + nW%4;
   unsigned char *p=(unsigned char*)malloc(nRowSize);//Array to store the new row of pixels
   unsigned char *l=(unsigned char*)malloc(RowSize); //Array to store the initial row of pixels
   while (n < H){ //repeat the loop until you reach the heigh
      read(f,l,RowSize);
      int j=0;
      for (i=0;i<3*W;i+=3){ //Making p to contain the new row with repeated pixels
        p[j] = l[i]; //One colour is 3 bytes
        p[j+1] = l[i+1];
        p[j+2] = l[i+2];
        //Repeating each pixel
        p[j+3] = l[i]; //One colour is 3 bytes
        p[j+4] = l[i+1];
        p[j+5] = l[i+2];
        j+=6; //start writing again after every 6 bytes


      }
      write(g,p,nRowSize); //repeating the new row twice
      write(g,p,nRowSize);

      n++; //increment n to go to the next row
      }




free(l);
free(p); //Deallocating

//printf(" Red: %d, Green: %d\n Blue: %d\n", R,G,B);

close(f);
close (g);

return 0;
}
