/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carproject;

/**
 *
 * @author Tboy Simple
 */
public class Car {

    private String brand;
    private String type;
    private int Regyear;
    private int colorCode;

    private static String[] colorNameArray = {"black", "red", "green", "blue", "yellow", "orange", "gray", "white", "brown", "purple", "pionk"};

    public Car(String brand, String type, int Regyear, int colorcode) {
        this.brand = brand;
        this.type = type;
        this.Regyear = Regyear;
        this.colorCode = colorcode;
    }

    @Override
    public String toString() {
        String colorName;
        /*switch (colorcode){
         case 3: colorname = "green";break;
         default : colorname ="Undefined";
         }*/
      colorName = colorNameArray[colorCode];
        return brand + "," + type + "," + colorName + "(" + Regyear + ")";
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getRegyear() {
        return Regyear;
    }

    public void setRegyear(int Regyear) {
        this.Regyear = Regyear;
    }

    public int getColorcode() {
        return colorCode;
    }

    public void setColorcode(int colorcode) {
        this.colorCode = colorcode;
    }

    public void setColorcode(String colorName) {
        /*    if (colorName.equals("black")) colorCode=0;
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
