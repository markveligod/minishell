#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int fd[2], result;
    size_t size;
    char resstring[14]; 
    /* Попытаемся создать pipe */
    if(pipe(fd) < 0){
        /* Если создать pipe не удалось, печатаем об этом сообщение
        и прекращаем работу */
        printf("Can\'t create pipe\n");
        exit(-1); 
    } 
    /* Порождаем новый процесс */ 
    result = fork();
    char *mass[] = {"/bin/ls", "-l", NULL};

    if(result < 0){ 
        /* Если создать процесс не удалось, сообщаем об этом и 
        завершаем работу */
        printf("Can\'t fork child\n");
        exit(-1);
    } else if (result > 0) {
        /* Мы находимся в родительском процессе, который будет 
        передавать информацию процессу-ребенку. В этом процессе
        выходной поток данных нам не понадобится, поэтому 
        закрываем его.*/
        close(fd[0]);
        execve(mass[0], mass, NULL);
        dup2(fd[0], STDIN_FILENO);
        /* Закрываем входной поток данных, на этом 
        родитель прекращает работу */
        close(fd[1]);
        printf("WRITE: Parent exit\n");
    } else {
        /* Мы находимся в порожденном процессе, который будет 
        получать информацию от процесса-родителя. Он унаследовал
        от родителя таблицу открытых файлов и, зная файловые 
        дескрипторы, соответствующие pip, иможет его использовать.
        В этом процессе входной поток данных нам не 
        ипонадобится, поэтому закрываем его.*/
        close(fd[1]);
        /* Пробуем прочитать из pip'а 14 байт в массив, т.е. всю
        записанную строку */
        size = read(fd[0], resstring, 140);
        if(size < 0){

            /* Если прочитать не смогли, сообщаем об ошибке и
            завершаем работу */

            printf("Can\'t read string\n"); 
            exit(-1); 
        } 
        /* Печатаем прочитанную строку */
        printf("READ: %s\n",resstring);
        /* Закрываем входной поток и завершаем работу */
        close(fd[0]);
    }    
    return 0; 
}