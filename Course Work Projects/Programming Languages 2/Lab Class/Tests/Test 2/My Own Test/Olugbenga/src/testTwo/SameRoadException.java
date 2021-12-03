/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testTwo;

/**
 *
 * @author student
 */
public class SameRoadException extends Exception {

    /**
     * Creates a new instance of <code>SameRoadException</code> without detail
     * message.
     */
    public SameRoadException() {
    }

    /**
     * Constructs an instance of <code>SameRoadException</code> with the
     * specified detail message.
     *
     * @param msg the detail message.
     */
    public SameRoadException(String msg) {
        super(msg);
    }
}
