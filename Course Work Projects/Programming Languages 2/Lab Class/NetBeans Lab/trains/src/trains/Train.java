/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trains;

import java.util.Scanner;

/**
 *
 * @author Tboy Simple
 */
public class Train {
    private String startsFrom;
    private String destination;
    private int depHour;
    private int depMin;
    private boolean IC;
    
    /**
     *
     * @param trainData
     */
    public Train (String trainData){
        Scanner ssc = new Scanner(trainData);
        ssc.useDelimiter("@");
        startsFrom = ssc.next();
        destination = ssc.next();
        String dt= ssc.next();
        setDepTime(dt);//setDepTime(ssc.next())
       /* if (ssc.hasNext()) IC =true;
        else IC = false;*/
       IC = ssc.hasNext();
    }

    @Override
    public String toString() {
        return  startsFrom +" - "+destination+ "\t"+ getDepTime()+(IC?" IC":"") ;
    }
    
    public void setDepTime(String depTime){
        String hourstr;
        hourstr = depTime.substring(0, 2);
        depHour = Integer.valueOf(hourstr);
        
        depMin= Integer.valueOf(depTime.substring(3));
    }
    
    
 /**
  * getter that return the departure time
  * @return A string in the format hh:mm
  */
    public String getDepTime(){
        return depHour +":"+depMin;
    }
    public String getStartsFrom() {
        return startsFrom;
    }

    public void setStartsFrom(String startsFrom) {
        this.startsFrom = startsFrom;
    }

    public String getDestination() {
        return destination;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public int getDepHour() {
        return depHour;
    }

    public void setDepHour(int depHour) {
        this.depHour = depHour;
    }

    public int getDepMin() {
        return depMin;
    }

    public void setDepMin(int depMin) {
        this.depMin = depMin;
    }

    public boolean isIC() {
        return IC;
    }

    public void setIC(boolean IC) {
        this.IC = IC;
    }
    
    
}
