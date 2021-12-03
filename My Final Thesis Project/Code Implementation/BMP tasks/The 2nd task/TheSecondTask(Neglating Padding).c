#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h> //In order to use low level file handling
#include<malloc.h> //In order to use the malloc function


int main(){
int size; // to store the size
char sig[2]; // to store the signature
int f=open("proc2.bmp", O_RDONLY); //(Read https://linux.die.net/man/3/open)
int g= open("tina2.bmp",O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,S_IRUSR|S_IWUSR); //(Read https://linux.die.net/man/3/open)

read(f, sig, 2); // read the first two bytes, the signature, �BM� as a string
write(g, sig, 2);
read(f,&size,4); // read the second field, the size, as integer, so we use 4 bytes
write(g, &size, 4);

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
write(g, &W, 4);
read(f,&H,4); // height in pixel (as binary integer)
write(g, &H, 4);
//printf("H:- %d\n W:- %d",H,W);

//Then the next two fields are just 2 bytes long, so we need �short� variables:
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

//Neglating Padding
//int SizeOfBytesUsed = W*H*3;//The width * Height * 3 (Because of The RGB, one byte for each, every row *3)
//unsigned char *p=(unsigned char*/* The type is Unsigned char */)malloc(SizeOfBytesUsed);//Allocate memory for p, as large as to store every pixel
//read(f,p/* *p is the value, while p is the address, we needed the address*/,SizeOfBytesUsed);//it reads all elements
//for(i=0;i<SizeOfBytesUsed;i+=3){ //A loop to change all RGB colors in p //Making the picture grayscale
//    temp=p[i] + p[i+1] + p[i+2];
//    temp/=3;
//    p[i] = temp;
//    p[i+1] = temp;
//    p[i+2] = temp;
//
//}
//write(g,p,SizeOfBytesUsed);





free(p); //Deallocating

//printf(" Red: %d, Green: %d\n Blue: %d\n", R,G,B);

close(f);
close (g);

return 0;
}
