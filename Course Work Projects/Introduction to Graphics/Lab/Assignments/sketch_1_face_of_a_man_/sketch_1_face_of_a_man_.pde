void setup( ) {
   size(1000,1000);
}

void draw( ){
  ellipseMode(RADIUS);
  //noFill();
  ellipse(500,500,250,250);//big circle
  ellipse(375,375,35,35);//left eye
  ellipse(375,375,20,20);//left eye
  ellipse(625,375,35,35);//right eye
  ellipse(625,375,20,20);//right eye
  triangle(425,425,575,425,500,550);
  line(340,560,375,650);
  line(375,650,625,650);
  line(625,650,660,560);
  rect(250,100,500,235,30,30,0,0);//for the rectangle
  line(0,335,1000,335);
  
}