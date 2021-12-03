#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h> //In order to use low level file handling
#include<malloc.h> //In order to use the malloc function


int main(){
int size; // to store the size
char sig[2] = "BM"; // to store the signature
int g = open("tina5.bmp",O_WRONLY|O_CREAT|O_TRUNC/*|O_BINARY*/,S_IRUSR|S_IWUSR); //(Read https://linux.die.net/man/3/open)
write (g, sig, 2); // BM
size = 256*(256*3 + 256*(256%4)) + 54; //(256*3 + 256*(256%4)) reps the row size + the multiplication of padding
                                        //for each row
write (g, &size, 4);//size
//printf("%d",size);
int temp;
temp = 0;
write (g, &temp, 4);//Unused
temp = 54;
write (g, &temp, 4);//Pixel Array Offset
temp = 40;
write (g, &temp, 4);//DIB header size
int W= 256, H = 256;
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

int i;
int RowSize = 3*W + W%4;

unsigned char *p = (unsigned char*)malloc(RowSize); //Array to store the row
int n=0;
unsigned char R,G,B;
R=0; //Red
G=0; //Green
B=0; //Blue


while (n<H){
    for (i=0;i<3*W;i+=3){
        p[i]= B;
        p[i+1] =G;
        p[i+2] = R;
        //printf("%d",R);

    }
write (g , p, RowSize);
R++;
n++;
}

free(p);
close(g);
return 0;
}
