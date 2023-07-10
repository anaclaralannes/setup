#!/bin/bash

# Caminho para o executável
EXEC=/scratch/CAMINHO/PARA/O/EXECUTAVEL

# Caminho para o arquivo de benchmark
BENCHMARK=/scratch/CAMINHO/PARA/O/ARQUIVO/BENCHMARK.txt

# Loop para variar o número de threads de 1 a 24 com incremento de 4
for i in $(seq 1 4 24)
do
  # Cria um novo arquivo de script Slurm para cada job
  echo "#!/bin/bash

#SBATCH --ntasks-per-node=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=$i
#SBATCH -p FILA
#SBATCH -J JOB
#SBATCH --exclusive

echo \$SLURM_JOB_NODELIST
nodeset -e \$SLURM_JOB_NODELIST

cd \$SLURM_SUBMIT_DIR

source /scratch/app/modulos/intel-psxe-2016.sh
# ou
# module load gcc/6.5

/usr/bin/ldd $EXEC

export OMP_NUM_THREADS=\$SLURM_CPUS_PER_TASK

# O comando 'time' é utilizado para medir o tempo de execução e o resultado é anexado ao arquivo de benchmark
(time srun  -N 1 -c \$SLURM_CPUS_PER_TASK $EXEC) 2>> $BENCHMARK" > job_$i.sh

  # Submete o job
  sbatch job_$i.sh
done