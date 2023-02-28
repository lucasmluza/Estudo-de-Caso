# Buffer Circular : C++

## Estrutura do projeto

A classe CircularBuffer está implementada como uma classe tempatle e seu arquivos ficam no ```diretório circular_buffer```. Para teste unitário, a ferramenta escolhida foi o framework ```gtest``` da Google. Dentro do diretório tests, os testes unitário são implementados pelo arquivo unity_test.cpp.

## Teste Unitário

### Dependências

- g++
- make
- cmake

### Compilar e executar

```
$ cd Estudo-de-Caso/q2/cpp/tests/

$ cmake -S . -B build

$ cmake --build buid/

$ cd build && ctest
```

### Recompilar o test

$ cd Estudo-de-Caso/q2/cpp/tests/build
$ make

### Somente executar o test

$ cd Estudo-de-Caso/q2/cpp/tests/build
$ ctest