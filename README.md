# random number generator in C++
Manual de utilização.
Conforme sugerido no artigo: "New state-of-the-art random number generator - simple strong and fast",
criamos uma aplicação amigável ao usuário de forma que ele possui inicialmente um menu com as seguintes opções.

1) Gerar e imprimir o seed
2) Modificar parametros do seed.
3) Gerar um número aleatório.
4) Testar aleatoridade da funcao.

Na opção 1 é utilizada a fórmula constante no artigo e gerado uma dízima com 58 casas decimais. Através de uma janela deslizante são escolhidos 10 números em sequencia para que se possa tornar a primeira parte da semente geradora de números aleatórios. Após isso, uma função que gera o tempo do sistema em milisegundas eh executada e esta é a segunda parte da semente. Por fim, mutiplica-se ambas sub-sementes e obtém-se a semente para geração de números.

Na opção 2 realiza-se uma operação semelhante a opção 1, porém é dada ao usuário a opção de determinar os 4 coeficientes inteiros da fração afim de se gerar uma dizima completamente diferente. Ressalta-se a possibilidade de fatores positivos e negativos. Após a escolha a semente é gerada da mesma forma.

Na opção 3, é chamado de fato a função geradora de números aleatórios e retorna-se para o usuário um número entre 0 e 4.294.967.295 (unsigned int).

Por fim, implementou-se um função afim de realizar a geração de 1.000.000 numeros aleatorios verificar o percentual destes abaixo de 1000. Além disso, criou-se um mapeamento de cada numero criado para se verificar a criação de ciclos e repetições.
