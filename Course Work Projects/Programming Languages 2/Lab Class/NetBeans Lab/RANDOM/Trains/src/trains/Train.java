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

    @Override
    public String toString() {
        return startsFrom + " - " + destination +"\t" +depHour +":" +depMin+" ("+(IC? "IC" : "" )+")";
    }

        
    public Train(String complete) {
        Scanner get = new Scanner(complete);
        get.useDelimiter("@");
        startsFrom = get.next();
        destination = get.next();
        setDepTime(get.next());
        IC =get.hasNext();
   
    }

    
    public void setDepTime (String time){
        depHour= Integer.valueOf(time.substring(0, 2));
        depMin= Integer.valueOf(time.substring(3));
    }
    public String getDepTime(){
        return depHour + ":" + depMin;
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
