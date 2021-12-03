#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h> //In order to use low level file handling
#include<malloc.h> //In order to use the malloc function


int main(){
int size; // to store the size
char sig[2] = "BM"; // to store the signature
int g = open("tina4.bmp",O_WRONLY|O_CREAT|O_TRUNC/*|O_BINARY*/,S_IRUSR|S_IWUSR); //(Read https://linux.die.net/man/3/open)
write (g, sig, 2); // BM
size = 200*200*3 + 54;
write (g, &size, 4);//size
int temp;
temp = 0;
write (g, &temp, 4);//Unused
temp = 54;
write (g, &temp, 4);//Pixel Array Offset
temp = 40;
write (g, &temp, 4);//DIB header size
int W= 200, H = 200;
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
int d; //eachpixelonly
while (n<H){
    d=0; //counts number of pixels written

    for (i=0;i<3*W;i+=3){
        if ((d<100) && (n<100)){ //lower left
            p[i] = 0; //Pixels are written as BGR in bmp
            p[i+1] = 255; //Green
            p[i+2] = 0;
            d++; //after writing one pixel increase d
        }else if ((d>=100) && (n<100)){ //lower right
            p[i] = 255; //Blue
            p[i+1] = 0;
            p[i+2] = 0;
            d++;

        }else if ((d>=100) && (n>=100)){ //upper right
            p[i] = 0;
            p[i+1] = 255; //Green +
            p[i+2] = 255; //Red
            d++;

        }else if ((d<100) && (n>=100)){ //upper left
            p[i] = 0;
            p[i+1] = 0;
            p[i+2] = 255; //Red
            d++;

        }

    }
write (g , p, RowSize);

n++;
}


free(p);
close(g);
return 0;
}
