# cpd_fifa21
Trabalho Final - Classificação e Pesquisa de Dados

# Estruturas de Dados:
## Tabela Hash:
### Jogadores (lab4):
- Tabela para consulta de Jogadores.
- Guarda, para cada jogador, o sofifa_id, nome, posições, rating e quantidade de avaliações.
- Dado um sofifa_id devolve todos seus dados.
### Users (2.2):
- Tabela para consulta de avaliações dos jogadores por um determinado usuáro.
- Guarda, para cada usuário, uma lista com os sofifa_id e as avaliações feitas pelo usuárioo de cada jogador.
- Dado um user_id, encontra o usuário e devolve uma lista em que estão todas as suas avaliações dos jogadores.
### Tags (2.4):
- Tabela para consulta de jogadores com determinada tag.
- Dada uma tag, encontra essa tag na tabela e devolve uma lista de sofifa_id.
- Guarda, para cada tag, uma lista com os sofifa_id dos jogadores que foram avaliados com tal tag.
## Árvore Trie:
### Nome dos Jogadores (2.1):
- Árvore para consulta de jogadores pelo nome.
- Dada uma string, devolve todos os jogadores em que o nome possui tal string como prefixo.
- Guarda o sofifa_id no nodo de final da string para poder consultar na tabela hash.
## Vectors:
### Posições (2.3):
- Vetores para consulta de jogadores que são de determinada posição (um vetor para cada).
- Dada uma posição e um inteiro k, devolve os k jogadores dessa posição com maior rating.
- Guarda em cada vetor o sofifa_id e o rating de cada jogador.
