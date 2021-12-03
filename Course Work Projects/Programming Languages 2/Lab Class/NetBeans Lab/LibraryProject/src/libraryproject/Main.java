/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package libraryproject;

/**
 *
 * @author Tboy Simple
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Book b = new Book();
        b.Authorofbook = "Thomas Harris";
        b.Yearofpublishing = 1988;
        b.titleofbook = "The silence of the lambs";
        System.out.println(b.Authorofbook + " - " + b.titleofbook + " - " + b.Yearofpublishing);
        Book2 b2 = new Book2();
        b2.setAuthorofbook("Thomas Harris");
        b2.setTitleofbook("Red Dragon");
        b2.setYearofpublishing(1981);
        System.out.println(b2.getAuthorofbook() + " - " + b2.getTitleofbook() + " - " + b2.getYearofpublishing());
        Book2 b1 = new Book2("Thomas Harris", "Hannibal", 1999);
        System.out.println(b1.getAuthorofbook() + " - " + b1.getTitleofbook() + " - " + b1.getYearofpublishing());

    }

}
