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
public class Book2 {
    private String titleofbook;
    private String Authorofbook;
    private int Yearofpublishing;
    
   /* public void getTitleofbook(String title){
        this.titleofbook =title;
    }*/

    /**
     *
     * @param Authorofbook
     * @param titleofbook
     * @param Yearofpublishing
     */
    

    public Book2( String Authorofbook,String titleofbook, int Yearofpublishing) {
        this.titleofbook = titleofbook;
        this.Authorofbook = Authorofbook;
        this.Yearofpublishing = Yearofpublishing;
    }

    public Book2() {
    }

    
    public String getTitleofbook() {
        return titleofbook;
    }

    public void setTitleofbook(String titleofbook) {
        this.titleofbook = titleofbook;
    }

    public String getAuthorofbook() {
        return Authorofbook;
    }

    public void setAuthorofbook(String Authorofbook) {
        this.Authorofbook = Authorofbook;
    }

    public int getYearofpublishing() {
        return Yearofpublishing;
    }

    public void setYearofpublishing(int Yearofpublishing) {
        this.Yearofpublishing = Yearofpublishing;
    }
    
}
