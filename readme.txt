Primeiramente, abra a pasta onde se encontram os arquivos para o projeto utilizando no Console o comando "cd anaclara_lannes";

Em seguida, compile o programa utilizando o comando "make" no terminal;

Após compilar o programa, execute-o utilizando o comando "time ./diffusion" e ao final da execução, também lhe será informado o tempo desta realização;

Tal execução permitirá a visualização dos arquivos.txt que informam os valores de x, y, u em forma de tabela ao decorrer do tempo;

Através do comando "./visualize_diffusion.sh" é possível executar o script responsável por gerar, através dos resultados em cada arquivo.txt do passo anterior, seus respectivos gráficos de evolução ao longo do tempo. 
(Caso não tenha instalado o gnuplot em seu terminal Linux, é necessário o fazer, digitando "sudo apt install gnuplot", e em seguida, "chmode +x visualize_diffusion.sh" para gerar os gráficos aqui comentados).
Recomenda-se o teste destes com malha e tempo menores, podendo ser ajustados no arquivo constants.h, uma boa sugetão para acompanhar o resultado nos gráficos é: Malha 200x200 e Tempo 1000.

Por fim, caso você queira limpar o output do programa e seu executável, utilize o comando "make clean".