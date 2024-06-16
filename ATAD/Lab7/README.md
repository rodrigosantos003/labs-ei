# Algoritmos e Tipos Abstratos de Dados

## Lab 7 | Exercícios + Template  

:gb: [English version](README_en.md)

**Objetivos**:

- Utilização de ADT;

- Gestão de memória dinâmica (heap).

**Referências**:

- “Tipos Abstratos de Dados – Linguagem C. Bruno Silva”, disponível no Moodle.

---

:exclamation: **As funções solicitadas deverão ser definidas e implementadas no módulo `operations`**, salvo indicação em contrário. Deve utilizar o *valgrind* para verificar a correta gestão de memória no final de cada nível.

### Nível 1 (Duração estimada: < 20min)

1. Analise a estrutura do código, compile e execute o programa, verificando a execução do mesmo.

2. Implemente a função `bool fortniteItemBuy(const char* name, PtList shop)` que marca o item com o nome `name` como *comprado* (campo `owned = true`).

3. Implemente no `main` um excerto de código que solicite ao utilizador o nome do item a comprar. Imprima novamente a loja; o item, se encontrado, deverá aparecer como comprado; caso contrário, deverá apresentar uma mensagem de erro. Teste o programa.

### Nível 2 (Duração estimada: ~ 15min)

4. Implemente a função `int fortniteItemSearch(const char* name, PtList shop)` que devolve o *índice* do item com o nome `name`; devolve `-1` se não existir. Teste esta função no `main`, mostrando a informação completa do item pesquisado.

### Nível 3 (Duração estimada: ~ 15min)

5. Implemente a função `PtList fortniteShopCopy(PtList shop)` que devolve uma *cópia* da loja, i.e., uma nova lista que contém uma cópia dos items em `shop`.

6. Adicione ao `main` o código para testar esta função; crie a cópia, imprima essa lista e não se esqueça de libertar a memória antes do programa terminar.

### Nível 4 (Duração estimada: ~ 20min)

7. Implemente a função `PtList fortniteFindItemsPriceRange(PtList shop, int min, int max)` que:

	- Devolve por retorno uma nova lista contendo uma cópia dos items cujo preço se encontra em `[min, max]`; devolve `NULL` se `shop == NULL`. Se não houver nenhum item dentro do intervalo, devolve uma lista sem elementos (vazia).
	
8. No `main` solicite ao utilizador um intervalo de preços e proceda à compra dos items encontrados nesse intervalo. Os items devem ser marcados como comprados na lista/loja inicial (não a cópia).

### Nível 5 (Duração estimada: ~ 20min)

9. Implemente e teste a função `void forniteSortByName(PtList shop, bool ascending)` que ordena os items em `shop` ascendentemente/descendentemente (consoante parâmetro) pelo seu nome. Teste esta função sobre a cópia da loja criada no passo 6.

10. Forneça a documentação *doxygen* de todas as funções solicitadas neste enunciado.

---

```markdown
@bruno.silva
(EOF)
``` 