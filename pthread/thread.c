#include "head.h"
#define THREAD_NUM 3
#define WHILE_TIME 5
#define DELAY_TIME 6

pthread_mutex_t mutex;

void *thread_func(void *arg)
{
    int thread_num = (int)arg;
    int i = 1;
    int res;
    int delaytime;

    res = pthread_mutex_lock(&mutex);
    if(res != 0)
    {
        perror("lock fail\n");
    }
    printf("thread %d starting\n",thread_num);
    while(i < 6)
    {
        i++;
        printf("I am thread %d\n ,and this is %d time runing\n",thread_num,i);
        delaytime = (int)(rand()%DELAY_TIME) + 1;
        sleep(delaytime);
    }
    printf("thread %d finished\n",thread_num);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
int main(int argc, const char *argv[])
{
    int i = 0;
    int res;
    pthread_t thread[3];        
    srand(time(NULL));
    res = pthread_mutex_init(&mutex,NULL);
    //if(pthread_mutex_init(&mutex,NULL) != 0);
    //{
    //    printf("lock init fail\n");
    //    exit(-1);
    //}
    for(i = 0;i < 3;i++)
    {
        res = pthread_create(&thread[i],NULL,thread_func,(void *)i);
        if(res != 0)
        {
            printf("thread create %d fail\n",i);
            exit(-1);
        }
        printf("thread %d creat sucess\n",i);
    }
    for(i = 0;i < 3;i++)
    {
        pthread_join(thread[i],NULL);
        printf("thread %d 被回收\n",i);
    }
    pthread_mutex_destroy(&mutex);


    return 0;
}
