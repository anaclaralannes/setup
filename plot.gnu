# Arquivo plot.gnu
set terminal png size 800,600
set output 'benchmark.png'

set title "Benchmarking Results"
set ylabel "Time (s)"
set xlabel "Number of Threads"

set key outside

set xtics rotate by -45

# Assumindo que a primeira linha do arquivo 'times.txt' contém o tempo de execução com uma thread
first_line = system("head -n 1 times.txt | awk '{print $2}'")
# Plotar o tempo de execução, speedup, eficiência e escalabilidade
set multiplot layout 2,2 title "Benchmarking Results"
    # Tempo de execução
    set title "Execution Time"
    plot 'times.txt' using 1:2 title 'Execution Time' with linespoints
    # Speedup
    set title "Speedup"
    plot 'times.txt' using 1:(first_line/\$2) title 'Speedup' with linespoints
    # Eficiência
    set title "Efficiency"
    plot 'times.txt' using 1:(first_line/\$2/\$1) title 'Efficiency' with linespoints
    # Escalabilidade
    set title "Scalability"
    plot 'times.txt' using 1:(first_line/\$2/\$1) title 'Scalability' with linespoints
unset multiplot
