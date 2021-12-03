float deg=60;
 float [][] matrixT1 = {{ 1 , 0 , -200 },
                        { 0 , 1 , -150 },
                        { 0 , 0 ,    1}};//The first tranformation T1
 float [][] matrixR= {{ cos(radians(deg)) , -sin(radians(deg)) , 0 },
                      { sin(radians(deg)) , cos(radians(deg)) ,  0 },
                      {        0 ,              0,               1 }};//rotating at an angle of 60 degrees, but being treated as radians, due to processing specs
 float [][] matrixT3= {{ 1 , 0 , 200 },
                       { 0 , 1 , 150 },
                       { 0 , 0 ,   1}};
 float [][] matrixTemp = new float [3][3];//A temprorary matrix used during the calculations like T1*R= Temp then M=Temp*T3
 float [][] matrixM = new float [3][3];
 
class hom2d {
  float x1, x2, x3;
 
  hom2d(float x1, float x2, float x3) {
    this.x1=x1;
    this.x2=x2;
    this.x3=x3;
  }
}
class inhom2d {
  
  float x, y;
 
  inhom2d(float x, float y ) {
    this.x=x;
    this.y=y;
  }  
}

hom2d fitInt( hom2d a, hom2d b ) {

    return new hom2d( a.x2 * b.x3 - a.x3 * b.x2, a.x3 * b.x1 - a.x1 * b.x3, a.x1 * b.x2 - a.x2 * b.x1 );
}

hom2d toHom2d( inhom2d A ) {
  return new hom2d( A.x, A.y, 1 );
}

inhom2d toInhom2d( hom2d a ) {
  return new inhom2d( a.x1 / a.x3, a.x2 / a.x3 );
}

hom2d transform( float M[][], hom2d P ) {//we function we used to do the final transfromation M*Ph

  hom2d P_ = new hom2d(  M[0][0] * P.x1 + M[0][1] * P.x2 + M[0][2] * P.x3,
                         M[1][0] * P.x1 + M[1][1] * P.x2 + M[1][2] * P.x3,
                         M[2][0] * P.x1 + M[2][1] * P.x2 + M[2][2] * P.x3   );
  return P_;
}


 
void mult( float A[][], float B[][], float C[][] )//the function to multiply martix A and B to get C
{
  float sum;
  for (int i = 0; i <= 2; i++) {
      for (int j = 0; j <= 2; j++) {
         sum = 0;
         for (int k = 0; k <= 2; k++) {
            sum = sum + A[i][k] * B[k][j];
         }
         C[i][j] = sum;
      }
   }
}

void setup(){
  size(400,300);
}
 
void draw()
{
  stroke(255,0,0);
  background(255);
  inhom2d P = new inhom2d (250,150);
  mult( matrixR, matrixT1, matrixTemp );//multiplies the matrix R and T1 stores it in Matrix temp
  mult( matrixT3, matrixTemp, matrixM );//does the same but stores it in matrix M
  
  hom2d PH = toHom2d(P);//The parameter M will be times with
  
  hom2d PH_ = transform(matrixM, PH);
  
  inhom2d P_ = toInhom2d(PH_);
  
  ellipseMode(RADIUS);
  
  ellipse(200,150,5,5);//The draws an ellipse around the initial point
  ellipse(250,150,5,5);//draws around the 2nd intial 
  ellipse(P_.x,P_.y,5,5);//this displays the rotated point about the first initial point
}

/*void keyPressed(){
  if (key =='w'){
   deg+=5;
    matrixR[0][0] = cos(radians(deg));
  matrixR[0][1] =-sin(radians(deg));
     matrixR[1][0] = sin(radians(deg));
  matrixR[1][1] =cos(radians(deg));

    }
  else 
    deg-=5;
    
  
}*/