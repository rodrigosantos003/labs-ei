# Algoritmos e Tipos Abstratos de Dados

## Lab 1 | Exercícios + Template  

:gb: [English version](README_en.md)

Este repositório foi criado a partir de:

- <https://github.com/estsetubal-atad/CProgram_Template> 

Consulte o README se tiver dúvidas sobre a sua utilização.

----

**Objetivos**:

- Utilização de modularidade;

- Manipulação de arrays / strings;

- Documentação Doxygen.

**Referências**:

- Organização ATAD, documentação do software utilizado: <https://github.com/estsetubal-atad/Docs>

- *"Linguagem C"*, *e-book* disponível no Moodle.

---

:computer: Faça o clone **deste** repositório antes de avançar.

### Nível 1 (Duração estimada: < 10min)

1. Crie um módulo "arrays" e adicione-lhe a função `arrayPrint`, que imprime na consola um array no formato `[a, b, c, d, <...>]`:

```cpp
void printArray(int arr[], int arrLength) {
    printf("[ ");
    for(int i=0; i<arrLength; i++) {
        printf("%d%s", arr[i], (i < arrLength - 1 ? ", " : ""));
    }
    printf("]\n");
}
```

2. Exemplifique a utilização desta função no `main`, criando e inicializando um array de inteiros `v` com 5 elementos (2, 3, 6, 4, 7); edite o *makefile*, compile e execute o programa.

### Nível 2 (Duração estimada: ~ 25min)

:exclamation: Sempre que possível, as implementações devem evitar duplicação de código através das outras funções que calculem passsos necessários.

3. Adicione as seguintes funções adicionais para o módulo "arrays":

	- `int sum(int arr[], int arrLength)` – devolve a soma dos elementos de `arr`;

	- `double mean(int arr[], int arrLength)` – devolve a média dos elementos de `arr`;

	- `double variance(int arr[], int arrLength)` – devolve a variância (de
	população) de `arr` - utilizando a seguinte fórmula: 

	<img src="https://latex.codecogs.com/png.image?\dpi{150}&space;S^2&space;=&space;\frac{\sum_i^n&space;(x_i&space;-&space;\bar&space;x)^2}{n&space;-&space;1}" title="S^2 = \frac{\sum (x_i - \bar x)^2}{n - 1}" />

	onde,`x_i` representa cada elemento do array, `\bar(x)` a média de todos os elementos e `n` a quantidade de elementos.

	- `double standardDeviation(int arr[], int arrLength)` – devolve o desvio padrão
	dos elementos de arr. :bulb: O desvio padrão consiste na raiz quadrada da variância.

4. Teste o resultado destas funções sobre o array instanciado no `main`.

	O *output* requerido e resultados esperados são:

	```markdown
	Array: [2, 3, 6, 4, 7]
	Sum = 22
	Mean = 4.40
	Variance = 4.30
	Standard deviation = 2.07
	```

	:exclamation: Apresente valores reais com duas casas decimais.

:question: Qual a complexidade algorítmica da função `variance` que implementou?

### Nível 3 (Duração estimada: ~ 25min)

:exclamation: As seguintes funções devem pertencer a um novo módulo "strings".

:thinking: o modificador `const`, e.g., `const char[]`, é uma "promessa" de que a *string* não será alterada dentro da função.

5. Crie a função `bool equal(const char str1[], const char str2[])` que verifica se duas strings passadas como argumento são iguais (*case-insensitive*).

	* :bulb: Se as duas *strings* tiverem tamanhos diferentes garantidamente não são iguais, caso contrário, utilize a função `tolower(char)/toupper(char)`da biblioteca `<ctype.h>` para comparar caracteres na mesma capitalização.

6. Crie a função `bool isPalindrome(const char str[])` que verifica se a string é um palíndromo (palavra ou frase que tem a mesma sequência de letras em qualquer ordem de leitura).

    * e.g., "ovo", "ana", "sopapos" e "Sator arepo tenet opera rotas".
    * Implemente uma versão que acuse, e.g., "Ana" e "aNA" como palíndromos.

7. Crie a função `bool hasDuplicates(const char str[])` que verifica se existe algum caracter duplicado em `str`.

8. Teste as funções no `main`, solicitando todas as *strings* necessárias ao utilizador.

### Nível 4 (Duração estimada: ~ 20min)

9. Implemente no módulo "strings" a função `void letterFrequency(cons char str[])` que imprime na consola a frequência de ocorrência de cada letra do alfabeto na *string* `str` (em forma tabular) - deve funcionar de forma *case-insensitive* e todos os caracteres que não forem letras devem ser ignorados.

	* Teste a função no `main`, solicitando a *string* ao utilizador.

	
	:mag: Exemplo:

	```markdown
	Introduza string: abracadabra
	Letra	| Freq.
	a	| 5
	b	| 2
	c	| 1
	d	| 1
	...
	r	| 2
	...		
	z	| 0
	```

:question: Qual a complexidade algorítmica da função `letterFrequency` que implementou?

### Nível 5 (Duração estimada: < 15min)

10. Forneça a documentação *doxygen* de todas as funções do módulo "arrays". :bulb: a documentação deve ser adicionada no ficheiro `arrays.h`. 

	* Verifique que, após o efetuar, consegue visualizá-la durante a edição do ficheiro `main.c`, e.g., quando passa o cursor por cima da invocação de uma função documentada.

	* Gere a documentação *doxygen* - deverá obter a pasta `html`. Abra o ficheiro `index.html` e verifique a documentação gerada.

---

```markdown
@bruno.silva
(EOF)
``` 