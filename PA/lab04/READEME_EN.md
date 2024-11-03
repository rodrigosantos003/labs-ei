# Programação avançada | Lab4

PT: [Versão em Português](README.md)

## Objectives:

- ADT Map;
- Interface `Map<K, V>`;
- ADT Map - Implementation using a BST (binary search tree).

## 0 – Introduction

The ADT Map consists of a container for mappings *key → value*, commonly referred to as a *dictionary*.

**Characteristics:**

- Does not allow duplicate keys;
- The same value can be associated with multiple keys.

![](images/adt-map.png)

### Interface `Map<K, V>`

The specification of the ADT Map in Java is done with an *interface*:

<small>

```java
package pt.pa.adts;

/**
 * An object that maps keys to values.
 * A map cannot contain duplicate keys; each key can map to at most one value.
 * @param <K> the type of keys maintained by this map
 * @param <V> the type of mapped values
 */
public interface Map<K, V> {
    V put(K key, V value) throws NullPointerException;
    V get(K key) throws NullPointerException;
    V remove(K key) throws NullPointerException;
    boolean containsKey(K key) throws NullPointerException;
    Collection<K> keys();
    Collection<V> values();
    int size();
    boolean isEmpty();
    void clear();
}

```





## Exercises

1.	Clone this base project lab04_template_24_25 (IntelliJ project) from GitHub.

<p align="center">
	<a href="https://github.com/estsetubal-pa-2024-25/lab04_template_24_25">https://github.com/estsetubal-pa-2024-25/lab04_template_24_25</a>
</p>

2.	Complete the missing code in `main()`, using Map operations.



2.	In order to test the implementation of the `MapBST` class, provide the implementation of the following two auxiliary methods:

- 3.1. Given the root of a (sub-)tree, search for the node containing that key; Returns `null` if it doesn't exist. **Provide a recursive implementation**.
          **`private BSTNode searchNodeWithKey(K key, BSTNode treeRoot)`**

- 3.2\. Given the root of a (sub-)tree, searches its leftmost node (*contains the “minimum” key*); Returns `null` if it doesn't exist. **Provide a recursive or iterative implementation**.

  ​          **` private BSTNode getLeftmostNode(BSTNode treeRoot)`**

  

4. Run the `main()` method using the full `MapBST` implementation;

   

5. Use the `MapBST.toString()` method which will display a textual representation of the underlying tree:

```bash
MapBST of size = 8:
│ ┌── {key=9, value=3
│ ┌── {key=8, value=2
│ ┌── {key=7, value=2
│ │ └── {key=6, value=4
└── {key=5, value=2
    │ ┌── {key=4, value=5
    │ │ └── {key=3, value=2
    └── {key=1, value=2
```



6. Test the removal of mappings by checking the resulting trees.

   

7. Change the implementation so that the `keys()` and `values()` methods use an **in-order** traversal of the tree.

**NOTE**: In the case of `keys()`, since they are the keys of the tree, the collection will contain these elements sorted.



8. Add information about the **height of the tree** to the *output* of the `toString()` method, e.g.:

```bash
MapBST of size = 8 and height = 3:
│ ┌── {key=9, value=3
│ ┌── {key=8, value=2
│ ┌── {key=7, value=2
│ │ └── {key=6, value=4
└── {key=5, value=2
    │ ┌── {key=4, value=5
    │ │ └── {key=3, value=2
    └── {key=1, value=2
```

**Tip**: Implement/use a recursive helper method:

​	**`private int height(BSTNode treeRoot)`**

