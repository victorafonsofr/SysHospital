# SysHospital
<center>
<pre>
                       _ _ _ _ _
                      |         |
                      |         |
                 _ _ _|         |_ _ _
                |                     |
                |     @SysHospital    |
                |_ _ _           _ _ _|
                      |         |
                      |         |
                      |_ _ _ _ _|
</pre>
</center> 
Como rodar o programa?

No powershell ou terminal linux
cd /SysHospital/assets/ <br>
(windows)
gcc -I interfaces main.c .\functions\*.c -o SysHospital

(linux)
gcc -I interfaces main.c functions/*.c -o SysHospital


# Quais módulos implementam as listas?
 Lista dinâmica simples-> pacientes.c
 Lista dinâmica duplamente encadeada -> historico_atendimento.c
 Lista dinâmica circular -> medicos.c
 Fila dinâmica -> atendimentos.c
 Pilha dinâmica -> acoes.c
