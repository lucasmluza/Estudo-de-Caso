# Enigma

Você recebeu um arquivo chamado "enigma" junto com a prova, este é uma biblioteca. Escreva uma aplicação que utilize as funções desta biblioteca, compile está aplicação utilizando somente linha de comando, descreva os comandos utilizados e os passos que foram utilizados para resover este problema. 

Explique a diferença em linkagem estática e dinámica. 


Verifique se o arquivo que você recebeu está integro. 

```
$ md5sum enigma 
81808a8ff591865c488f2ca93eb3090f  enigma
```

## Diferença entre linkagem estática e dinámica

### Estática

Uma biblioteca estática é um conjunto de objetos pré-compilados que podem ser incorporados a um programa através da ligação estática. Durante o processo de ligação estática, o código da biblioteca é copiado para o arquivo executável final, fazendo com que o arquivo contenha todo o código necessário para ser executado, incluindo o código da biblioteca. Esse metodo tem como vantagem permitir que o arquivo executável seja executado em qualquer máquina sem a necessidade de instalar a biblioteca separadamente.

### Dinámica

A ligação dinâmica é o processo de linkar as bibliotecas com o arquivo executável durante a execução. Quando se utiliza a ligação dinâmica, o código da biblioteca não é copiado para o arquivo executável final. Em vez disso, o programa carrega o código da biblioteca necessário a partir de um arquivo de biblioteca compartilhada quando o programa é executado. Isso significa que vários programas podem compartilhar o mesmo código de biblioteca, reduzindo o tamanho do executável. E as bibliotecas podem ser atualizadas independentemente.

## Steps

To have a list of symbols from the library:

```
nm -C enigma
```

