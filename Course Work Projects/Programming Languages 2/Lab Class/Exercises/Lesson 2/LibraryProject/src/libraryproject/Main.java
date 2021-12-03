/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package libraryproject;

/**
 *
 * @author student
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Book b;
        b = new Book(); 
        b.author = "Thomas Herris";
        b.title = "Silence of the lambs";
        b.yearOfPublishing = 1988;
        
        System.out.println(b.author);
        System.out.println(b.title);
        System.out.println(b.yearOfPublishing);
        
        
        Book2 b2 = new Book2();
        b2.setAuthor("Thomas Harris");
        b2.setTitle("Red Dragon");
        b2.setYearOfPublishing(1981);
        
        System.out.println(b2.getAuthor());
        System.out.println(b2.getTitle());
        System.out.println(b2.getYearOfPublishing());
        
        Book2 b3 = new Book2("Thomas Harris", "Hannibal", 1999);
        System.out.println(b3.getAuthor() + " - " + b3.getTitle() + b3.getYearOfPublishing());
    }
    
}
