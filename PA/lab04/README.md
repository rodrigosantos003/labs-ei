# Programação Avançada | Lab4

:gb: [English version](README_EN.md)

## Objetivos:

- ADT Map;
- Interface `Map<K,V>`;
- Implementação do ADT Map com recurso a uma BST (árvore binária de pesquisa).



## 0 – Introdução

O ADT Map consiste num contentor de mapeamentos *chave &rarr; valor*, também vulgarmente chamado de *dicionário*.

**Características:**

- Não permite chaves duplicadas;
- O mesmo valor pode estar associado a múltiplas chaves.

![](images/adt-map.png)


### Interface `Map<K, V>`

A especificação do ADT Map na linguagem Java é feito numa *interface*:

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

</small>



## Exercícios

1. Faça *clone* deste projeto base **lab04_template_24_25** (projeto **IntelliJ**) do *GitHub*.

<p align="center">
	<a href="https://github.com/estsetubal-pa-2024-25/lab04_template_24_25">https://github.com/estsetubal-pa-2024-25/lab04_template_24_25</a>
</p>

2. Complete o código em falta no `main()`, utilizando as operações de `Map`.

   

3. Por forma a poder testar a implementação da classe `MapBST` forneça a implementação dos seguintes dois métodos auxiliares:

* 3.1\. Dada a raiz de uma (sub-)árvore, pesquisa o nó que contém essa chave; Devolve `null` se não existir. **Forneça uma implementação <u>recursiva</u>**.

  ​        **`private BSTNode searchNodeWithKey(K key, BSTNode treeRoot)`**

  

- 3.2\. Dada a raiz de uma (sub-)árvore, pesquisa o seu nó mais à esquerda (*contém a chave "mínima"*); Devolve `null` se não existir. **Forneça uma implementação <u>recursiva</u> ou <u>iterativa</u>**.

  **`    private BSTNode getLeftmostNode(BSTNode treeRoot)`**

  

4. Execute o método `main()` utilizando a implementação completa de `MapBST`;

   

5. Utilize o método `MapBST.toString()` que irá mostrar uma representação textual da árvore subjacente:

```bash
MapBST of size = 8:
│           ┌── {key=9, value=3
│       ┌── {key=8, value=2
│   ┌── {key=7, value=2
│   │   └── {key=6, value=4
└── {key=5, value=2
    │   ┌── {key=4, value=5
    │   │   └── {key=3, value=2
    └── {key=1, value=2
```



6. Teste a remoção de mapeamentos, verificando as árvores resultantes.

   

7. Altere a implementação por forma a que os métodos `keys()` e `values()` utilizem uma *travessia* **em-ordem** da árvore.

**NOTA:** No caso de `keys()`, dado que são as chaves da árvore, a coleção irá conter esses elementos ordenados.



8. Adicione ao *output* do método `toString()` informação sobre a **altura da árvore**, e.g.:

```bash
MapBST of size = 8 and height = 3:
│           ┌── {key=9, value=3
│       ┌── {key=8, value=2
│   ┌── {key=7, value=2
│   │   └── {key=6, value=4
└── {key=5, value=2
    │   ┌── {key=4, value=5
    │   │   └── {key=3, value=2
    └── {key=1, value=2
```

**Sugestão:** Implemente/utilize um método auxiliar recursivo:

​		`private int height(BSTNode treeRoot)`

