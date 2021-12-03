void setup(){
  size(640,480);
}
int r=10;

void draw(){
  stroke(255,0,0);
  ellipseMode(RADIUS);
  background(255);
  int step = 20;
  //for (int i=0; i <= 640; i=i+step){
 //   for (int j=0; j<= 480;j=j+step){
   noFill();
  for (int i=0; i <= 640; i=i+step){
    for (int j=0; j<= 480;j=j+step){
    ellipse(i,j,r,r);
    }
  }
  
}
void keyPressed(){
  if (key == 'w')
   r++;
}