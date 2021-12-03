void setup( ) {
 size(640,480);
}

void draw(){
  background(255,255,255);//Or background(255)
  ellipseMode(RADIUS);
  stroke(255,0,0);
  fill(255,255,0);
  noStroke();
  ellipse(100,100,50,50);
}