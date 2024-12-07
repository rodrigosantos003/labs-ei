/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pt.pa.patterns.memento.model;

import java.util.*;

public class Caretaker {
    private Memento memento;
    private Originator originator;

    public Caretaker(Originator originator) {
        this.originator = originator;
    }

    public void saveState(){
        this.memento = originator.createMemento();
    }

    public void restoreState() throws NoMementoException{
        if(memento == null) throw new NoMementoException();

        originator.setMemento(memento);
    }
}
