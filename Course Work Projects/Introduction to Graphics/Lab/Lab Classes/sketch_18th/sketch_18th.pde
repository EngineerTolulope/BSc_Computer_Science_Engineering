int n=1;
float anglex = PI / 6;//the angle of rotation around x axis
float angley = PI / 7;//the angle of rotation around y axis
inhom3d C1 = new inhom3d(  0.5,  0.5, -0.5 );//stores the initial values of the vertices
inhom3d C2 = new inhom3d( -0.5,  0.5, -0.5 );
inhom3d C3 = new inhom3d( -0.5, -0.5, -0.5 );
inhom3d C4 = new inhom3d(  0.5, -0.5, -0.5 );
inhom3d C5 = new inhom3d( 0.5,  0.5,  0.5 );
inhom3d C6 = new inhom3d( -0.5, 0.5,  0.5 );
inhom3d C7 = new inhom3d(  -0.5, -0.5,  0.5 );
inhom3d C8 = new inhom3d(  0.5,  -0.5,  0.5 );
class hom3d {
  float x1, x2, x3, x4;
  
  hom3d(float x1, float x2, float x3, float x4) {
    this.x1=x1;
    this.x2=x2;
    this.x3=x3;
    this.x4=x4;
  }
  
  hom3d appMatrix( float A[][] ) {
    return new hom3d( A[0][0]*this.x1 + A[0][1]*this.x2 + A[0][2]*this.x3 + A[0][3]*this.x4,
                      A[1][0]*this.x1 + A[1][1]*this.x2 + A[1][2]*this.x3 + A[1][3]*this.x4,
                      A[2][0]*this.x1 + A[2][1]*this.x2 + A[2][2]*this.x3 + A[2][3]*this.x4,
                      A[3][0]*this.x1 + A[3][1]*this.x2 + A[3][2]*this.x3 + A[3][3]*this.x4 );
  }
  
  inhom3d toInhom3d( ) {//converts to inhomogenous
    return new inhom3d( this.x1 / this.x4, this.x2 / this.x4, this.x3 / this.x4 );
  }
}
  
class inhom3d {
  float x, y, z;
 
  inhom3d(float x, float y, float z ) {
    this.x=x;
    this.y=y;
    this.z=z;
  }  
  
  hom3d toHom3d( ) {//converts to homogenous
    return new hom3d( this.x, this.y, this.z, 1 );
  }
}
void mult( float A[][], float B[][], float C[][] )//function multiplies matrix A and B , then stores the result in C
{
  float sum;
  for (int i = 0; i <= 3; i++) {
      for (int j = 0; j <= 3; j++) {
         sum = 0;
         for (int k = 0; k <= 3; k++) {
            sum = sum + A[i][k] * B[k][j];
         }
         C[i][j] = sum;
      }
   }
}
void setup()
{
  size( 640, 480 );
  ellipseMode( RADIUS );
}
void draw ( ) {
  
  background( 255,0,255 );//sets background to white
 
  float [][] matrixT =  { { 1,   0,   0,  320 }, //translation matrix
                        {   0,   1,   0,  240 },
                        {   0,   0,   1,   0  },
                        {   0,   0,   0,   1  }  };
                        
  float [][] matrixS =  { { 100,   0,    0,    0  }, //scaling matrix
                        {    0,   100,   0,    0  },
                        {    0,    0,   100,   0  },
                        {    0,    0,    0,    1  }  };
                       
  float [][] matrixRx = { {       1,              0,            0,          0  }, //rotation matrix around x axis
                        {         0,        cos( anglex ), -sin( anglex ),  0  },
                        {         0,        sin( anglex ),  cos( anglex ),  0  },
                        {         0,              0,            0,          1  }     }; 
                        
                        
  float [][] matrixRy = { {  cos( angley ),        0,        sin( angley ),   0  }, //rotation matrix around y axis
                        {         0,               1,             0,          0  },
                        {   -sin( angley ),        0,        cos( angley ),   0  },
                        {         0,               0,             0,          1  }     }; 
                        
  float [][] matrixOp =  { {  1,    0,    0,    0  },//orthongonal projection matrix, 
                         {    0,    1,    0,    0  },
                         {    0,    0,    0,    0  },// 3 row 3 column is zero because we want the z plane not to be represented, only want x and y
                         {    0,    0,    0,    1  }  };
  
  float [][] matrixCp =  { {  1,    0,    0,    0  }, 
                         {    0,    1,    0,    0  },
                         {    0,    0,    0,    0  },// 3 row 3 column is zero because we want the z plane not to be represented, only want x and y
                         {    0,    0, (float)-1/400,    1  }  };
  //temporary matrices
  float [][] temp1    = new float [4][4];// it is a 4 by 4 matrix
  float [][] temp2    = new float [4][4];
  float [][] temp3    = new float [4][4]; 
  
  // the final transformation matrix
  float [][]    M     = new float [4][4];
  
  /*mult( matrixRy, matrixS, temp1 ); //stores Ry * S in temp1
  mult( matrixRx,  temp1, temp2 );// and so on
  mult( matrixT,  temp2, temp3 );
  mult( matrixOp, temp3,   M   );*/// stores final matrix in M
  
  // T*Op*Rx*Ry*S
  mult( matrixRy, matrixS, temp1 ); //stores Ry * S in temp1
  mult( matrixRx,  temp1, temp2 );// and so on
  mult( matrixOp,  temp2, temp3 );
  mult( matrixT, temp3,   M   );// stores final matrix in M
  
  
  /*// T*Cp*Rx*Ry*S
  mult( matrixRy, matrixS, temp1 ); //stores Ry * S in temp1
  mult( matrixRx,  temp1, temp2 );// and so on
  mult( matrixCp,  temp2, temp3 );
  mult( matrixT, temp3,   M   );// stores final matrix in M */
  
  hom3d   C1h  = C1.toHom3d( );//converts initial vertices to homogenous coordinates
  hom3d   C2h  = C2.toHom3d( );
  hom3d   C3h  = C3.toHom3d( );
  hom3d   C4h  = C4.toHom3d( );
  hom3d   C5h  = C5.toHom3d( );
  hom3d   C6h  = C6.toHom3d( );
  hom3d   C7h  = C7.toHom3d( );
  hom3d   C8h  = C8.toHom3d( );
  
  hom3d   C1h_ = C1h.appMatrix( M );//takes each vertex of the cube and transform it using the M matrix calculated above
  hom3d   C2h_ = C2h.appMatrix( M );
  hom3d   C3h_ = C3h.appMatrix( M );
  hom3d   C4h_ = C4h.appMatrix( M );
  hom3d   C5h_ = C5h.appMatrix( M );
  hom3d   C6h_ = C6h.appMatrix( M );
  hom3d   C7h_ = C7h.appMatrix( M );
  hom3d   C8h_ = C8h.appMatrix( M );
  
  inhom3d C1_  = C1h_.toInhom3d( );//converts each vertices back to inhomogenous coordinates, so enable us to use them in drawing, e.t.c
  inhom3d C2_  = C2h_.toInhom3d( );
  inhom3d C3_  = C3h_.toInhom3d( );
  inhom3d C4_  = C4h_.toInhom3d( );
  inhom3d C5_  = C5h_.toInhom3d( );
  inhom3d C6_  = C6h_.toInhom3d( );
  inhom3d C7_  = C7h_.toInhom3d( );
  inhom3d C8_  = C8h_.toInhom3d( );
  
  fill(255,0,0);
  //draws a circle or radius 4 around each vertice of the cube
  ellipse( C1_.x, C1_.y, 4, 4 );
  ellipse( C2_.x, C2_.y, 4, 4 );
  ellipse( C3_.x, C3_.y, 4, 4 );
  ellipse( C4_.x, C4_.y, 4, 4 );
  ellipse( C5_.x, C5_.y, 4, 4 );
  ellipse( C6_.x, C6_.y, 4, 4 );
  ellipse( C7_.x, C7_.y, 4, 4 );
  ellipse( C8_.x, C8_.y, 4, 4 );
  
  //connects the lines of the cube vertices together
  stroke(0,0,255);//makes lines blue
  line(C1_.x,C1_.y,C2_.x,C2_.y);
  line(C2_.x,C2_.y,C3_.x,C3_.y);
  line(C3_.x,C3_.y,C4_.x,C4_.y);
  line(C4_.x,C4_.y,C1_.x,C1_.y);
  line(C1_.x,C1_.y,C5_.x,C5_.y);
  line(C5_.x,C5_.y,C6_.x,C6_.y);
  line(C6_.x,C6_.y,C2_.x,C2_.y);
  line(C6_.x,C6_.y,C7_.x,C7_.y);
  line(C7_.x,C7_.y,C8_.x,C8_.y);
  line(C8_.x,C8_.y,C5_.x,C5_.y);
  line(C8_.x,C8_.y,C4_.x,C4_.y);
  line(C7_.x,C7_.y,C3_.x,C3_.y);

 
  stroke(255);
  strokeWeight(n);
  line(C1_.x,C1_.y,0,0);//blessings from Heaven
  line(C2_.x,C2_.y,0,0);
  line(C3_.x,C3_.y,0,0);
  line(C4_.x,C4_.y,0,0);
  line(C1_.x,C1_.y,0,0);
  line(C5_.x,C5_.y,0,0);
  line(C6_.x,C6_.y,0,0);
  line(C6_.x,C6_.y,0,0);
  line(C7_.x,C7_.y,0,0);
  line(C8_.x,C8_.y,0,0);
  line(C8_.x,C8_.y,0,0);
  line(C7_.x,C7_.y,0,0);

}

void keyPressed(){
  if (key=='w')
    anglex+= PI/6;
  else if (key=='s')
    angley+= PI/7;
  else if (key == 'e')
    n++;
  else if (key == 'd')
   if (n!=0)
      n--;

}