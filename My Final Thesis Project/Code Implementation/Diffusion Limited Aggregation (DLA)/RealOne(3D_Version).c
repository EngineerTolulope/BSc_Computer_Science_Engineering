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
unsigned char *Head; //To store header fields
unsigned char *PA ;//For the pixel array
char name[100];
float rnum; //random number
float P_up,P_down,P_left,P_right,P_forward,P_backward; //Sum must be equal to 1
int tmpx, tmpy,count=0;
int bon;//if 1 don't break, Break if 0
//
/*void createBmp(){ //Function to write the 1st 54 bytes //PA here is different from the global variable
int size; // to store the size
char sig[2] = "BM"; // to store the signature
t=0;
sprintf(name,"Pictures Folder\\RW%d.bmp",i);//printing it for each timeline
//sprintf(name, "RW%04d.bmp", i);
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
write(g,PA,pixelsize);
//
close(g);
return;
} */
//
struct particle{
    int x;
    int y;
    int z;
};
//
int main(){
    FILE *fp;//The pov file to store the simulation //we use Pov-ray application to open
    //
    pixelsize = L*(L*3+L%4);//Changing the value of the global variable;//Total number of pixels
    PA = (unsigned char*) calloc(pixelsize, sizeof(unsigned char));//Initiallizing the pixel array to zero
    //
    srand(time(NULL));//we use time because it changes everytime, it sets where rand() starts from in it internal calculations
    int N=L*5;//Random number //Making sure N is a very large number than L
    struct particle part[N];//An array of N structures, To store all particles, 0,1,2, until N
    int hmax=0; //We are at the zero height in the y coordinate
    //
    int SL=20; //The side length of the buttom square
    for (i=0;i<SL;i++){ //The square bottom layer in 2D 20x20 (0 still 19), We index from zero
        for (j=0;j<SL;j++){
            part[count].x=j; part[count].y=hmax=0; part[count].z=i;
            /*PA[part[count].y*(L*3 + L%4) + part[count].x *3 + 0 ] = 128; //Blue Pixel
            PA[part[count].y*(L*3 + L%4) + part[count].x *3 + 1 ] = 0;  //Green Pixel
            PA[part[count].y*(L*3 + L%4) + part[count].x *3 + 2 ] = (i/(float)N) * 255; //Red Pixel
            */
            count++;
        }
    }
    //
    P_up=P_down=P_left=P_right=P_forward=P_backward= 1.0/6.0; //Sum must be equal to 1
    for (i=count;i<N;i++){
        bon=1;                        //Making sure bon is one at the start of the do while
        part[i].x = rand()%SL; part[i].y= hmax + 5; part[i].z= rand()%SL;// y is a number on present hmax + 10
        tmpy=hmax+5+4; //The maximum height a pariticle can reach before dying
        do{//Loop was created for the movement of a particle
            rnum=(float)rand()/RAND_MAX; // 0 <= x <=1 //Gets random number
            if (rnum < P_up) part[i].y+=1;
            else if (rnum >= P_up && rnum < P_up+P_down) part[i].y-=1;
            else if (rnum >= P_up+P_down && rnum < P_up+P_down+P_left ) part[i].x-=1;
            else if (rnum >= P_up+P_down+P_left && rnum < P_up+P_down+P_left+P_right) part[i].x+=1;
            else if (rnum >= P_up+P_down+P_left+P_right && rnum < P_up+P_down+P_left+P_right+P_forward) part[i].z+=1;
            else if (rnum >= P_up+P_down+P_left+P_right+P_forward && rnum<P_up+P_down+P_left+P_right+P_forward+P_backward) part[i].z-=1;
            //
            if (part[i].y >= tmpy || part[i].y<0){//If it has reached the upper limit ////Don't continue when it is <= zero
               part[i].x = rand()%SL; part[i].y= hmax+5; part[i].z= rand()%SL; //New Particle
               continue;                                              //Start moving again //Starts do while loop again
            }
            //x and z coordinate are periodical
            if (part[i].x >= SL) part[i].x=0;
            else if (part[i].x < 0) part[i].x=SL-1;
            if (part[i].z >= SL) part[i].z=0;
            else if (part[i].z < 0) part[i].z=SL-1;
            //
            for (j=0;j<i;j++){//Checking if they are neighbors
               if ((part[i].x + 1 == part[j].x  && part[i].y==part[j].y && part[i].z==part[j].z)|| //Neighbours with the right
                   (part[i].x - 1 == part[j].x  && part[i].y==part[j].y && part[i].z==part[j].z)||  //Left
                   (part[i].y + 1 == part[j].y  && part[i].x==part[j].x && part[i].z==part[j].z)||  //Up
                   (part[i].y - 1 == part[j].y  && part[i].x==part[j].x && part[i].z==part[j].z)||  //Down
                   (part[i].z + 1 == part[j].z  && part[i].x==part[j].x && part[i].y==part[j].y)||  //Forward
                   (part[i].z - 1 == part[j].z  && part[i].x==part[j].x && part[i].y==part[j].y)){  //Backward //Check if neighbors with previous elements
                   if (part[i].y > hmax) hmax=part[i].y; //Checking if height of part. > former height
                   //printf("%d %d %d\n",part[i].x,part[i].y,part[i].z);
                   bon=0;
                   break; //Leave present for loop
                }//If
            }//for
        }while(bon); //bon is 0 so loop stops //We stop loop if we found neighbour of previous particles
        //
        /*//Store the new neighbour in the pixel array //And the first L elements as well
        PA[part[i].y*(L*3 + L%4) + part[i].x *3 + 0 ] = 128; //Blue Pixel
        PA[part[i].y*(L*3 + L%4) + part[i].x *3 + 1 ] = 0;  //Green Pixel
        PA[part[i].y*(L*3 + L%4) + part[i].x *3 + 2 ] = (i/(float)N) * 255; //Red Pixel
        *///
      //  if (i%200==0){
            //createBmp(); //Create a picture after every 25th particle
            sprintf(name,"Pictures Folder(3d)\\Sim%d.pov",i);//Creating pov files after every 25th simulation as well
            fp=fopen(name, "w");
            fprintf(fp, "#include \"colors.inc\"\n#include \"shapes.inc\"\n#include \"textures.inc\"\n#include \"metals.inc\"\n");
            fprintf(fp, "background{White}\n");
            fprintf(fp, "union{light_source{<28.94,28.94,-61.38> color White shadowless}\n");

            for (j=0;j<=SL*SL;j++) fprintf(fp, "sphere { <%d,%d,%d>,0.600\ntexture{ pigment{ color rgb<0.0,0.2,0.0>}\nfinish{ phong 1 metallic}}}\n",part[j].x,part[j].y,part[j].z);
            for (   ;j<=i    ;j++) fprintf(fp, "sphere { <%d,%d,%d>,0.700\ntexture{ pigment{ color rgb<%f,0.0,0.5>}\nfinish{ phong 1 metallic}}}\n",part[j].x,part[j].y,part[j].z,1.0-(j-SL*SL)/((float)N-SL*SL));

            fprintf(fp,"rotate y*0\ntranslate <0,0,0>\n}\n");
            fprintf(fp,"camera{\nlocation <%d,%d,%d>\nlook_at  <%d,%d,%d>}\n" ,2*SL,hmax,-(2*SL+10) ,SL/2 -2,hmax/2 -2,SL/2 -2);
            fclose(fp);
     //   }//If

    }//For
    //free(Head);free(PA);
    return 0;
    }


