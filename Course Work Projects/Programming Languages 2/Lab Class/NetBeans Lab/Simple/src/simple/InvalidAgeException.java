/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simple;

/**
 *
 * @author Tboy Simple
 */
public class InvalidAgeException extends Exception {

    /**
     * Creates a new instance of <code>InvalidAgeException</code> without detail
     * message.
     */
    public InvalidAgeException() {
    }

    /**
     * Constructs an instance of <code>InvalidAgeException</code> with the
     * specified detail message.
     *
     * @param msg the detail message.
     */
    public InvalidAgeException(String msg) {
        super(msg);
    }
}
