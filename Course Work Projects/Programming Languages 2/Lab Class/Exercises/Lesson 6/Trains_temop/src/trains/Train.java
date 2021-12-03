/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trains;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class Train {
    private String startsFrom;
    private String destination;
    private int depHour;
    private int depMin;
    private boolean IC;
    
    public Train(String trainData){
        Scanner ssc = new Scanner(trainData);
        ssc.useDelimiter("@");
        startsFrom = ssc.next();
        destination = ssc.next();
        String depTime;
        depTime = ssc.next();
        setDepTime(depTime);
        IC = ssc.hasNext();
    }

    @Override
    public String toString() {
        return startsFrom + " - " + destination + "\t" + getDepTime() + (IC?" IC":"");
    }
    
    /**
     * Returns the departure time of the train in hh:mm format as a String
     * @return The departure time as a String (hh:mm)
     */
    public String getDepTime(){
        return depHour + ":" + depMin;
    }
    
    /**
     * Sets the departure time of a train given by a String
     * @param depTime The departure time in hh:mm format
     */
    public void setDepTime(String depTime){
        depHour = Integer.valueOf(depTime.substring(0, 2));
        depMin = Integer.valueOf(depTime.substring(3));
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
