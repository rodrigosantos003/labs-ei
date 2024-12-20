/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pt.pa.adts;



/**
 *
 * @author patricia.macedo
 */
public class TADTreeMain {

    public static void main(String[] args) {
        TreeLinked<String> myTree = new TreeLinked("Animal");
        Position<String> root = myTree.root();
        Position<String> posMamifero = myTree.insert(root, "Mamifero");
        Position<String> posAve = myTree.insert(root, "Ave");
        myTree.insert(posMamifero, "Cao");
        Position<String> posGato = myTree.insert(posMamifero, "Gato");
        myTree.insert(posMamifero, "Vaca");
        myTree.insert(posAve, "Papagaio");
        Position<String> posAguia = myTree.insert(posAve, "Aguia");
        myTree.insert(posAguia, "Aguia Real");
        System.out.println("TREE " + myTree);
        System.out.println(myTree);

        String removedMamifero = myTree.remove(posMamifero);
        System.out.println("Removed Mamiferos");

        System.out.println("TREE:");
        System.out.println(myTree);
    }
}