# Questão 1

O FreeRTOS é um sistema operacional embarcado largamente utilizado em aplicações que necessitam de muitas tarefas sendo executadas ao mesmo tempo no microcontrolador e em aplicações com tempo real. 

Utilizando a versão do FreeRTOS para computadores (Windows ou Linux) implente uma aplicação com às seguintes características: 

- Tenha uma variável do tipo inteiro que várias tarefas possam acessar; 
- Tarefa 1, Leia a variável compartilhada incremente o valor 1 e imprima o seu valor na serial e salve a variável com o seu novo valor; 
- Tarefa 2, Leia a variável compartilhada decremente o valor 1 e imprima o seu valor na serial e salve a variável com o seu novo valor;

## Dependências

- gcc
- make

## Build

```
$ make
```

## Executar

```
$ ./build/app
```