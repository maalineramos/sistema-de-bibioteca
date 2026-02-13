# 📚 Sistema de Biblioteca em C

Este projeto foi desenvolvido como parte de um exercício do curso de **Análise e Desenvolvimento de Sistemas (ADS)**, em uma fase inicial da disciplina, quando eu estava tendo um dos meus primeiros contatos com **linguagem C** e com **programação em geral**.

A proposta do exercício foi praticar lógica de programação e estruturação de código com um problema simples do mundo real: o gerenciamento básico de uma biblioteca.

## 🎯 Intuito do exercício

O principal objetivo foi aprender, na prática, como transformar uma ideia em um programa funcional, passando pelos fundamentos que normalmente aparecem no começo do curso:

- organização de dados
- entrada e saída de informações
- criação de menus
- uso de repetição e decisões
- cuidado com memória e strings

Mais do que criar um sistema completo, a atividade buscava consolidar a base de programação para desafios futuros.

## ✅ O que foi implementado no programa

O sistema simula rotinas essenciais de uma biblioteca:

- **Cadastro de livros**
  - registro de nome, autor, editora e edição
- **Listagem de livros cadastrados**
  - visualização dos dados já inseridos
- **Registro de empréstimos**
  - associação de um empréstimo a um livro
- **Listagem de empréstimos**
  - consulta dos empréstimos realizados

## 🧠 Conteúdos de programação praticados

Durante o desenvolvimento, foram trabalhados conceitos importantes para iniciantes em C:

- **Structs** para modelar dados (`Livro` e `Emprestimo`)
- **Alocação dinâmica de memória** com `calloc`
- **Liberação de memória** com `free`
- **Manipulação de texto** com `fgets`
- **Estruturas de controle** com menus, condicionais e laços

## 📘 Aprendizado deste projeto

Este exercício representou um passo importante na minha formação, pois ajudou a:

- entender como dividir um problema em partes menores
- organizar melhor as informações dentro do programa
- ganhar confiança com a sintaxe de C
- praticar boas bases para evoluir em programação

Mesmo sendo um projeto simples, ele marcou o início da minha jornada prática no desenvolvimento de software.

## ▶️ Como executar

Compile e rode o programa no terminal:

```bash
gcc pratica-biblioteca.c -o pratica-biblioteca
./pratica-biblioteca
```
