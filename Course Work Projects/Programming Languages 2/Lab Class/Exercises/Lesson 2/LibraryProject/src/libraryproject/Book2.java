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
public class Book2 {

    private String title;
    private String author;
    private int yearOfPublishing;

    public Book2(String author, String title, int yearOfPublishing){
        this.author=author;
        this.title=title;
        this.yearOfPublishing=yearOfPublishing;
    }
    
    public Book2(){
    }
    
    /**
     * @param author the author to set
     */
    public void setAuthor(String author) {
        this.author = author;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String t) {
        title = t;
    }

    /**
     * @return the author
     */
    public String getAuthor() {
        return author;
    }

    /**
     * @return the yearOfPublishing
     */
    public int getYearOfPublishing() {
        return yearOfPublishing;
    }

    /**
     * @param yearOfPublishing the yearOfPublishing to set
     */
    public void setYearOfPublishing(int yearOfPublishing) {
        this.yearOfPublishing = yearOfPublishing;
    }

}
