/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package diaryproject;

import java.util.Scanner;

/**
 *
 * @author kocsisg
 */
public final class Entry {

    private int day;
    private int month;
    private int year;
    private String text;

    @Override
    public boolean equals(Object o){//Ex. 8. Override the equals method
        if (o.getClass()!=this.getClass()) return false;
        Entry e = (Entry)o;
        if (year==e.getYear() && month==e.getMonth() && day==e.getDay()) return true;
        return false;
    }//equals
    
    @Override
    public String toString(){ // Ex. 3 Override the toString method
        return month + "-" + day + "-" + year + "\n" + text;
    }//toString
    
    public void setDate(String date) throws WrongDateException { // Ex. 4. Add the setDate method
        Scanner sc = new Scanner(date);
        sc.useDelimiter("-"); // tell that the numbers are separated by "-" characters
        this.month=sc.nextInt();
        this.day=sc.nextInt();
        this.year=sc.nextInt();
        //Ex. 6. Add Wrongdate exception to the project and throw it from here
        if (day<1 || day>31 || month<1 || month>12) throw new WrongDateException();
    }//setDate
    
    public Entry(String date, String text) throws WrongDateException{//Ex. 5. Add the constructor
        this.text=text;
        setDate(date);//set the date using a String instead of 3 int values
    }//constructor
    
    /**
     * @return the text
     */
    public String getText() {
        return text;
    }

    /**
     * @param text the text to set
     */
    public void setText(String text) {
        this.text = text;
    }

    /**
     * @return the day
     */
    public int getDay() {
        return day;
    }

    /**
     * @param day the day to set
     */
    public void setDay(int day) {
        this.day = day;
    }

    /**
     * @return the month
     */
    public int getMonth() {
        return month;
    }

    /**
     * @param month the month to set
     */
    public void setMonth(int month) {
        this.month = month;
    }

    /**
     * @return the year
     */
    public int getYear() {
        return year;
    }

    /**
     * @param year the year to set
     */
    public void setYear(int year) {
        this.year = year;
    }

}//class Entry
