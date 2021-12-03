#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h> //In order to use low level file handling
#include<malloc.h> //In order to use the malloc function


int main(){
int size; // to store the size
char sig[2]; // to store the signature
int f=open("proc1.bmp", O_RDONLY); //(Read https://linux.die.net/man/3/open)
int g= open("tina.bmp",O_WRONLY|O_CREAT|O_TRUNC/*|O_BINARY*/,S_IRUSR|S_IWUSR); //(Read https://linux.die.net/man/3/open)

read(f, sig, 2); // read the first two bytes, the signature, “BM” as a string
write(g, sig, 2);
read(f,&size,4); // read the second field, the size, as integer
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

//Then the next two fields are just 2 bytes long, so we need ‘short’ variables:
short int tmp;
short int Color;
short int i=2;
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
//int SizeOfBytesUsed = W*H*3;//The width * Height * 3 (Because of The RGB, one byte for each)
//unsigned char *p=(unsigned char*/*The type is Unsigned char*/)malloc(SizeOfBytesUsed);//Allocate memory for p, as large as to store every pixel
//read(f,p /* *p is the value, while p is the address, we needed the address*/,SizeOfBytesUsed);//it reads all elements
//for(i=0;i<SizeOfBytesUsed;i++){ //A loop to change all RGB colors in p
//    p[i]=p[i]/2; //Divides the colours into two
//}
//write(g,p,SizeOfBytesUsed);


//Including Padding
int RowSize = 3*W + (W%4);
int n=0;
unsigned char *p=(unsigned char*/*The type is Unsigned char*/)malloc(RowSize);//Allocate memory for p, as large as to store every pixel
while (n<H){
    read(f,p,RowSize);
    for (i=0;i<(3*W);i++){
        p[i]/=2;
    }
    write(g,p,RowSize);
    n++;
}


free(p);

//printf(" Red: %d, Green: %d\n Blue: %d\n", R,G,B);

close(f);
close (g);

return 0;
}
