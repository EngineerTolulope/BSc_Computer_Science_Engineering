class inhom2d {
  
  float x, y;
 
  inhom2d(float x, float y ) {
    this.x=x;
    this.y=y;
  }  
}

inhom2d circlePoint(inhom2d o, float r, float t){
  return new inhom2d (o.x + r*cos(t), o.y + r*sin(t) );
  //returns the coordinates of the point on the circle at angle t
}
void setup(){
  size(800,600);
  ellipseMode(RADIUS);
}

void draw( ){
 background(255);
 
 inhom2d o = new inhom2d (400,300);//stores the mid point of the circle to be tested
 float radius =200;//declares the radius of the tested circle
 stroke(255,0,0);
 ellipse (o.x,o.y,radius,radius);//draws the tested big circle, o.x,o.y = X0,Y0
 //inhom2d P = circlePoint(o,radius,PI/2);//stores the coordinates of the point 
                                        //of the tested circle in p
 //ellipse (P.x,P.y,5,5);//draws a circle around that point
  //inhom2d P;
  int n=17;//n represents the number of points on the circle
  float angle=(2*PI) /n;//The angle between n points is the total angle/no. of points
  /*for (int i=0;i<n;i++){
  P = circlePoint(o, radius, i * angle);//look below for comment
  //as we draw the points, the first is alpha, next point becomes 2*alpha, and so on
  stroke(0,255,0);
  ellipse(P.x,P.y,5,5);//draws a circle around that point
  }*/
  inhom2d[] points = new inhom2d[n];//declaring an array named points
  for (int i=0;i<n;i++){
  points[i] = circlePoint(o, radius, i * angle); 
  //the points stores all the x and y coordinates of points in it's array
  }
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){//we use j=i+1, so a point doesn't try drawing
                            //a line with itself
      line(points[i].x,points[i].y,points[j].x,points[j].y);
      //takes the points stored in the array and starts drawing a point to each other
      //point using a line
    }
  }
  float stepx = 800.0/n;
  float stepy = 600.0/n;
  
  for (int i=0;i<=n;i++){
    line(i*stepx,0,0,(n-i) * stepy);
  }
}