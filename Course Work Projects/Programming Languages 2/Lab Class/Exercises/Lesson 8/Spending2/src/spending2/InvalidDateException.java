/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spending2;

/**
 *
 * @author student
 */
public class InvalidDateException extends Exception {

    /**
     * Creates a new instance of <code>InvalidDateException</code> without
     * detail message.
     */
    public InvalidDateException() {
    }

    /**
     * Constructs an instance of <code>InvalidDateException</code> with the
     * specified detail message.
     *
     * @param msg the detail message.
     */
    public InvalidDateException(String msg) {
        super(msg);
    }
}
