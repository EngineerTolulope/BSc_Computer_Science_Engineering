/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carsproject;

/**
 *
 * @author student
 */
public class Car {

    private static String[] colorNameArray = {"black", "red", "green", "blue", "yellow", "orange", "gray", "white", "brown", "purple", "pionk"};
    
    private String brand;
    private String type;
    private int regYear;
    private int colorCode;

    public Car(String brand, String type, int regYear, int colorCode) {
        this.brand = brand;
        this.type = type;
        this.regYear = regYear;
        this.colorCode = colorCode;
    }

    public Car() {
    }

    
    @Override
    public String toString() {
        String colorName;
     /*   switch (colorCode) {
            case 0:
                colorName = "black";
                break;
            case 1:
                colorName = "red";
                break;
            case 2:
                colorName = "green";
                break;
            case 3:
                colorName = "blue";
                break;
            case 4:
                colorName = "yellow";
                break;
            case 5:
                colorName = "orange";
                break;
            case 6:
                colorName = "gray";
                break;
            case 7:
                colorName = "white";
                break;
            case 8:
                colorName = "brown";
                break;
            case 9:
                colorName = "purple";
                break;
            case 10:
                colorName = "pink";
                break;
            default:
                colorName = "undefined";
        }*/
        colorName = colorNameArray[colorCode];
        return brand + ", " + type + ", " + colorName + " (" + regYear + ")";
    }

    /**
     * @return the brand
     */
    public String getBrand() {
        return brand;
    }

    /**
     * @param brand the brand to set
     */
    public void setBrand(String brand) {
        this.brand = brand;
    }

    /**
     * @return the type
     */
    public String getType() {
        return type;
    }

    /**
     * @param type the type to set
     */
    public void setType(String type) {
        this.type = type;
    }

    /**
     * @return the regYear
     */
    public int getRegYear() {
        return regYear;
    }

    /**
     * @param regYear the regYear to set
     */
    public void setRegYear(int regYear) {
        this.regYear = regYear;
    }

    /**
     * @return the colorCode
     */
    public int getColorCode() {
        return colorCode;
    }

    /**
     * @param colorCode the colorCode to set
     */
    public void setColorCode(int colorCode) {
        this.colorCode = colorCode;
    }
    /**
     * Sets the color code by name
     * @param colorName the name of the color
     */
    public void setColorCode(String colorName) {
      /*  if (colorName.equals("black")) colorCode=0;
        if (colorName.equals("red")) colorCode=1;
        if (colorName.equals("green")) colorCode=2;
        if (colorName.equals("blue")) colorCode=3;
        if (colorName.equals("yellow")) colorCode=4;
        if (colorName.equals("orange")) colorCode=5;
        if (colorName.equals("gray")) colorCode=6;
        if (colorName.equals("white")) colorCode=7;
        if (colorName.equals("brown")) colorCode=8;
        if (colorName.equals("purple")) colorCode=9;
        if (colorName.equals("pink")) colorCode=10;*/
        for (int i = 0; i < colorNameArray.length; i++) {
            if (colorNameArray[i].equals(colorName)) colorCode=i;
        }
    }

}
