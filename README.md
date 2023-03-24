# Programa para Gegenciamento de Turmas
Fiz este programa de gerenciamento de turmas como Trabalho Final na Disciplina de Introdução a Programação da minha faculdade.
Ele possui algumans funções básicas. Ultilizei o básico de algumans funções da linguagem C neste programa, como condicionais, vetores, strings, matrizes, arquivo, e laços de repetição.

## Funcionalidades
O programa contém funções básicas de cadastro e listagem de alunos e turmas.

### - Função Menu Principal
A função de menu principal `menuPricipal()`, chama o menu principal pra selecionar as demais funções. Como o próprio nome diz, é o principal menu do programa.
No menu é pedido para selecionar a função que será chamada. Apenas uma função nas opções do menu  principal ficou em desenvolvimento, a função de buscar por aluno. Por eu já ter apresentado este trabalho, não pretendo continua - la.

### - Função de Cadastrar Turma
A função para cadastrar turma `menuCadastroTurma()` serve para fazer o cadastro de uma turma. Deve-se inserir o nome da turma (caso a turma exista, ele irá sobrescrever a turma existente) e a quantidade de alunos que a turma terá.

### - Função de Cadastrar Aluno
A função para fazer o cadastro de um aluno `casdastrarAluno()` serve para realizar o cadastro de um aluno em uma turma. Caso a turma não exista, o programar criará. 
Para cadastrar um aluno deve - se inserir a quantidade de alunos a serem cadastrados, o nome da turma que se deseja fazer o cadastro, e os dados dos alunos a serem cadastrados. 

### - Função de Listar uma Turma
A função para listar uma turma `listarTurma()` serve fazer a listagem de uma turma. A listagem se dá na ordem de cadastro dos alunos.
Ela recebe como parâmetro o nome da turma.

### - Função de Excluir uma Turma
A função para excluir uma turma `excluirTurma()` serve para eliminar uma turma dos arquivos do programa.
Ela recebe como parâmetro o nome da turma que será eliminada.

### - Função que Procede uma Função
A função `menuEncerramento` é o menu que aparece sempre que uma função do programa chega ao fim. Nela você pode selecionar outras funções, como sair do programa ou voltar ao menu principal.