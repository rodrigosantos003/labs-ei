# Algoritmos e Tipos Abstratos de Dados

## Lab 4 | Exercícios + Template  

:gb: [English version](README_en.md)

Este repositório foi criado a partir de:

- <https://github.com/estsetubal-atad/CProgram_Template> 

Consulte o README se tiver dúvidas sobre a sua utilização.

----

**Objetivos**:

- Definição e tipos de dados;

- Pesquisa, seleção e ordenação sobre tipos de dados compostos;

- Passagem de argumentos por referência (vs. passagem por cópia);

**Referências**:

- Organização ATAD, documentação do software utilizado: <https://github.com/estsetubal-atad/Docs>

- *"Linguagem C"*, *e-book* disponível no Moodle.

---

:exclamation: As funções solicitadas deverão ser definidas e implementadas no módulo `fortnite`, salvo indicação em contrário.

### Nível 1 (Duração estimada: < 10min)

1. Defina um tipo de dados composto `FortniteItem` que permita guardar a informação de um item da loja Fortnite. Consulte o ficheiro `fortniteshop.csv` para inferir o tipo de dados e dimensão de cada campo da estrutura.

2. Defina e implemente a função `fortniteItemCreate` que devolve uma estrutura do tipo `FortniteItem` e que recebe por parâmetro os valores necessários para inicializar a estrutura criada.

3. Siga os seguintes passos:

    - Complete o código em falta na função `fortniteLoadShop`;

    - No `main` declare um array do tipo `FortniteItem` com dimensão de `100` posições.

    - Invoque a função `fortniteLoadShop` sobre este array; utilize o argumento `howMany = 100`.	

4. Edite o *makefile*, compile e execute o programa, verificando a correta compilação do mesmo.

### Nível 2 (Duração estimada: ~ 25min)

5. Defina o tipo de dados `PtFortniteItem` como sendo um ponteiro para o tipo `FortniteItem`.

6. Defina e implemente a função `void fortniteItemPrint(PtFortniteItem item)` - que imprime os detalhes de um item de forma tabular (veja o excerto de *output* abaixo).

7. Defina e implemente a função `void fortniteArrayPrint(FortniteItem arr[], int arrLength)`, cujo propósito deve ser óbvio.

    :bulb: Utilize a função anterior `fortniteItemPrint` para imprimir cada um dos elementos do array.

8. No `main` invoque esta função, compile e execute o programa. O *output* esperado é o seguinte:

    ```markdown
    Imported 81 fortnite items: 
    Lovely                         | Rare                 | 1200 
    Hearty                         | Rare                 | 500 
    Hooked On You                  | Rare                 | 200 
    Cuddle King                    | Rare                 | 1200 
    ...
    ```

### Nível 3 (Duração estimada: ~ 25min)

9. Defina e implemente a função `int findMostExpensiveItemIndex(FortniteItem arr[], int arrLength)` que aplica o algoritmo de seleção para encontrar o índice do item mais caro no array `arr`.

10. No `main` invoque esta função e imprima o respetivo item utilizando a função `fortniteItemPrint`.

### Nível 4 (Duração estimada: ~ 20min)

:bulb: Para as ordenações, utilize o algoritmo *bubble sort*.

11. Defina e implemente a função `void fortniteArraySortByRarity(FortniteItem arr[], int arrLength)` que deve ordenar `arr` por raridade (alfabeticamente de A-Z)

12. Defina e implemente a função `void fortniteArraySortByCost(FortniteItem arr[], int arrLength)` que deve ordenar `arr` decrescentemente por custo.

13. Teste ambas as funções anteriores, fazendo *output* do array ordenado e verificando a correção do resultado.

### Nível 5 (Duração estimada: < 15min)

14. No `main` faça o output do tamanho necessário para guardar uma instância de `FortniteItem`, i.e., uso de `sizeof`;

15. Nos algoritmos de ordenação do nível anterior, nas operações de "troca", defina, implemente e utilize a função `void swap(PtFortniteItem item1, PtFortniteItem item2)` que troca o conteúdo de dois endereços.

16. Adapte o código em `fortniteArrayPrint` para varrer o array utilizando *aritmética de ponteiros* ao invés de indexação.

---

```markdown
@bruno.silva
(EOF)
``` 
