# Algoritmos e Tipos Abstratos de Dados

## Lab 0 | Exercícios

:gb: [English version](README_en.md)

**Objetivos**:

- Instalação do ambiente de desenvolvimento (IDE), compilador e ferramentas necessárias.

- Criação de um projeto baseado no template disponibilizado.

- Desenvolvimento e debugging.

**Pré-requisitos**:

- Computador com ambiente Linux (bare ou dual-boot), Windows 10/11 ou MacOS.

- Conta GitHub (email pessoal ou institucional)

### 1 | Instalação (Duração estimada < 30min)

1. Navegue até - e faça bookmark - à organização ATAD do GitHub: <https://github.com/estsetubal-atad>


2. Nos repositórios da organização, abra o repositório “Docs” e siga o tutorial “Software.pdf” - atente nas instruções para o seu sistema operativo.

A documentação de todas as ferramentas a utilizar na unidade curricular está disponível nesse mesmo repositório. Consulte-as sempre que necessário.

### 2 | Criação de novo projeto (Duração estimada ~ 2min)

3. Faça clone do projeto  `CProgram_Template` através do git na linha de comandos:

```console
$> git clone https://github.com/estsetubal-atad/CProgram_Template.git Lab0_Template
```

4. Abra o projeto no VS Code:

```console
$> code Lab0_Template/
```

:warning: Se está a utilizar Windows/WSL deverá garantir (atente no canto inferior esquerdo) que está numa sessão WSL Remota.


### 3 | Programa `BMI` (Índice de Massa Corporal) (Duração estimada ~ 30min)

5. Crie o módulo `bmi` que consiste nos ficheiros `bmi.h` e `bmi.c`.

6. Seguindo as boas práticas de modularidade, adicione *três funções* a este módulo:

    - `double bmiCompute(double height, double weight)` -- que calcula o BMI segundo a seguinte fórmula:

    ```markdown
    BMI = (weight in kg) / (height in meters)^2
    ```

    - `void bmiPrintClassification(double bmi)` -- que imprime (em texto) a classificação de BMI segundo a seguinte tabela:

    Valor do `BMI` | Classificação
    --- | ---
    `BMI < 19` | Abaixo do Peso
    `19 <= BMI < 25` | Peso Normal
    `25 <= BMI < 30` | Sobrepeso
    `30 <= BMI < 40` | Obesidade do Tipo I
    `BMI >= 40` | Obesidade Mórbida


    - `void bmiPrintTable()` -- que imprime a tabela anterior de forma formatada.

7. Forneça a documentação doxygen das funções desenvolvidas e gere-a (deverá obter uma pasta `html` com um ficheiro `index.html`). Verifique o resultado da documentação.

8. Crie um programa na função `main` que, pela ordem apresentada:

    i. Apresente a tabela de BMI ao utilizador;  

    ii. Solicite ao utilizador o seu peso e altura, e;  

    iii. Calcule e mostre a sua classificação BMI.  

### 4 | Debugging (Duração estimada ~ 10min)

Teste a funcionalidade de **debug**: coloque um *breakpoint* na implementação da função `bmiPrintClassification` e execute o programa em modo de *depuração*.


### 5 | Elaboração da Ficha Autómoma | Linguagem C (Duração estimada ~ 90min)

Os objetivos desta ficha são:

- Consolidar o processo de desenvolvimento e compilação de programas na Linguagem C, utilizando a metodologia e ferramentas propostas;
- Ambientar-se à sintaxe básica da Linguagem C, seus tipos de dados e como proceder à entrada e saída de dados.

É altamente recomendado este "esforço" inicial, do qual tirará dividendos rapidamente.

---

```markdown
@bruno.silva
(EOF)
```   
