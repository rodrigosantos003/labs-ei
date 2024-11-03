package pt.pa;

import pt.pa.adts.Position;
import pt.pa.adts.Tree;
import pt.pa.adts.TreeLinked;

/**
 *
 * @author amfs
 */
public class Main {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Tree<String> ecosystemTree = new TreeLinked<>("Ecosystem");

        // Tree rooot
        Position<String> treeRoot = ecosystemTree.root();

        // Level 1 nodes
        ecosystemTree.insert(treeRoot, "Anchovy");
        Position<String> tunaPosition = ecosystemTree.insert(treeRoot, "Tuna");
        Position<String> sharkPosition = ecosystemTree.insert(treeRoot, "Shark");
        Position<String> eaglesPosition = ecosystemTree.insert(treeRoot, "Eagles");

        // Level 2 nodes
        ecosystemTree.insert(tunaPosition, "Mackerel");
        Position<String> barracudaPosition = ecosystemTree.insert(tunaPosition, "Barracuda");
        ecosystemTree.insert(sharkPosition, "Dolphin");
        ecosystemTree.insert(eaglesPosition, "Snakes");
        ecosystemTree.insert(eaglesPosition, "Rabbits");

        // Level 3 nodes
        ecosystemTree.insert(barracudaPosition, "Sardine");

        System.out.println(ecosystemTree);
    }
}
