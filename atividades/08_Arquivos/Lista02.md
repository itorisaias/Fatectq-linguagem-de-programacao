# Lista de Exercícios sobre Manipulação de Arquivos em C

## Prazos

- Primeiro prazo: 14/06/2024
- Segundo prazo: 21/06/2024

---

# 1 - Escrita Simples em Arquivo Binário

Crie um programa em C que receba 5 números inteiros do usuário e os salve em um arquivo binário chamado `numeros.bin`.

## Entrada
```md
10 20 30 40 50
```

# 2 - Leitura Simples em Arquivo Binário

Escreva um programa em C que leia e exiba o conteúdo de um arquivo binário chamado `numeros.bin` que contém uma sequência de inteiros. Utilize a função `fread` para ler os dados.

## Saida
```
10 20 30 40 50
```

# 3 - Escrita de Estrutura em Arquivo Binário

Escreva um programa que receba uma estrutura contendo um nome e uma idade, e a salve em um arquivo binário chamado `pessoa.bin`.

## Entrada
```md
Nome: João
Idade: 30
```

# 4 - Escrita e Leitura de Arquivo Binário

Escreva um programa que leia o arquivo `pessoa.bin`, modifique a idade da pessoa, e salve novamente no arquivo.

# 5 - Sistema de Locadora de Veículos

Desenvolva um sistema em C para gerenciar uma lista de veículos e suas respectivas viagens. O sistema deve permitir as seguintes operações:

**Operações:**

- Cadastrar novo veículo: 
    - Permite ao usuário adicionar um novo veículo ao catálogo.
    - Informações a serem cadastradas: placa, marca e modelo.
    - Cada veículo pode ter no máximo 4 viagens associadas (data, distância).

- Listar veículos cadastrados:
    - Exibe todos os veículos atualmente cadastrados no sistema.
    - Mostra a posição, placa, marca, modelo e total de KM de cada veículo.

- Atualizar informações do veículo:
    - Permite ao usuário modificar as informações de um veículo existente.
    - A seleção é feita com base na posição do veículo na lista.

- Remover veículo:
    - Remove um veículo do catálogo com base na posição selecionada.
    - A lista é ajustada para preencher a lacuna deixada pelo veículo removido.

- Gerenciar viagens:
    - Permite adicionar, listar e remover viagens de um veículo específico.
    - Cada viagem inclui informações como data e distância.

- Exportar catálogo para CSV:
    - Exporta o catálogo de veículos e suas viagens para um arquivo CSV.
    - Cada veículo e suas viagens são listados de forma legível
    - Exemplo de linha do registro: `AAADEF2G45,Chevrolet,Onix,12000KM`.

**Observações:**
- **Salvar o estado ao sair:** O sistema deve salvar o catálogo de veículos em um arquivo binário (veiculos.bin) ao sair, para garantir a persistência dos dados.
- **Restaurar o estado ao iniciar:** Ao iniciar, o sistema deve carregar o catálogo de veículos a partir do arquivo binário previamente salvo, restaurando o estado anterior.
- **Dica:** Realize a operação de abertura e fechamento de arquivos em cada função para evitar problemas com o cursor do arquivo, pois ainda não abordamos essa manipulação em detalhes.

**Nota**
Utilize o exemplo do código `netflix.c` discutido em sala como base para entender como salvar e carregar o estado do sistema utilizando arquivos binários. Adapte conforme necessário para lidar com os detalhes específicos dos veículos e viagens.
