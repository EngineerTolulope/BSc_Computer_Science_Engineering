
int ax = 100;
int ay = 200;
int bx=400, by=100;
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

void setup( ) {
  size( 640, 480 );
}

void draw() {
  inhom2d A = new inhom2d( ax, ay );
  //inhom2d B = new inhom2d( 400.0, 100.0 );
  inhom2d B = new inhom2d( bx, by );
  inhom2d C = new inhom2d( 100.0, 50.0 );
  inhom2d D = new inhom2d( 500.0, 400.0 );
  
  hom2d a, b, c, d, i;
  
  inhom2d I;
  
  a = toHom2d( A );
  b = toHom2d( B );
  c = toHom2d( C );
  d = toHom2d( D );
  
  i = fitInt( fitInt( a, b ), fitInt ( c, d ) );
  
  background( 128 );
  
  ellipseMode( RADIUS );
  
  line( A.x, A.y, B.x, B.y );
  line( C.x, C.y, D.x, D.y );
  
  if ( i.x3 != 0 ) {
    I = toInhom2d( i );
    if (((A.x < I.x && I.x<B.x) || (B.x < I.x && I.x<A.x)) && ((C.x < I.x && I.x<D.x) || (D.x < I.x && I.x<C.x) ))
      ellipse ( I.x, I.y, 3, 3 );
  }
}

 
void keyPressed( ) {
  if ( key == 'w')
    ay -= 1;
  if (key == 's')
    ay++;
  if (key == 'a')
    ax--;
  if (key == 'd')
    ax++;
  if ( key == 't')
    by -= 1;
  if (key == 'g')
    by++;
  if (key == 'f')
    bx--;
  if (key == 'h')
    bx++;  
}