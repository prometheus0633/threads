# include "tr.h"

int x = 0;
pthread_mutex_t mutex;

void    *func()
{
pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main ()
{
    pthread_t   t1;
    pthread_t   t2;
    

    if (pthread_create(&t1, NULL, func, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, func, NULL) != 0)
        return 2;
    if (pthread_join(t1, NULL) != 0)
        return 3;
    if (pthread_join(t2, NULL) != 0)
        return 4;
    printf("%d\n", x);    

}