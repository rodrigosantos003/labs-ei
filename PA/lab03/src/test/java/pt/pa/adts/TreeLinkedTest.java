package pt.pa.adts;

import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.*;

class TreeLinkedTest {
    protected Tree<String> ecosystemTree = new TreeLinked<>("Ecosystem");

    @BeforeEach
    void setUp(){
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
    }

    @Test
    void testSize() {
        assertEquals(11, ecosystemTree.size());
        ecosystemTree.insert(ecosystemTree.root(), "Birds");
        assertEquals(12, ecosystemTree.size());
    }

    @Test
    void testIsEmpty() {
        ecosystemTree.remove(ecosystemTree.root());
        assertTrue(ecosystemTree.isEmpty());
    }

    @Test
    void testIsExternal() {
        Position<String> newNode = ecosystemTree.insert(ecosystemTree.root(), "Cats");
        assertTrue(ecosystemTree.isExternal(newNode));

        ecosystemTree.insert(newNode, "Birds");
        assertFalse(ecosystemTree.isExternal(newNode));
    }

    @Test
    void testIsRoot() {
        Position<String> newNode = ecosystemTree.insert(ecosystemTree.root(), "Cats");
        assertFalse(ecosystemTree.isRoot(newNode));
        assertTrue(ecosystemTree.isRoot(ecosystemTree.root()));
    }

    @Test
    void testInsertShouldReturnCorrectPosition(){
        Position<String> childPos = ecosystemTree.insert(ecosystemTree.root(), "Cats");
        assertEquals("Cats", childPos.element());

        Position<String> secondChildPos = ecosystemTree.insert(ecosystemTree.root(), "Birds");
        assertEquals("Birds", secondChildPos.element());

        assertEquals(ecosystemTree.root(), ecosystemTree.parent(childPos));
        assertEquals(ecosystemTree.root(), ecosystemTree.parent(secondChildPos));
    }

    @Test
    void testRemoveShouldReturnCorrectPosition(){
        Position<String> childPos = ecosystemTree.insert(ecosystemTree.root(), "Cats");

        String removedElem = ecosystemTree.remove(childPos);
        assertEquals("Cats", removedElem);
    }

    @Test
    void testInsertThrowsInvalidPositionException(){
        assertThrows(InvalidPositionException.class, ()->{
            ecosystemTree.insert(null, "InvalidInsert");
        });

        Position<String> invalidPosition = () -> "Invalid";
        assertThrows(InvalidPositionException.class, () -> {
            ecosystemTree.insert(invalidPosition, "ChildWithInvalidParent");
        });
    }

    @Test
    void testDegree() {
        assertEquals(4, ecosystemTree.degree(ecosystemTree.root()));
    }
}