# include "tr.h"
# include <time.h>


void *func()
{
    int x;
    int *ptr;

    x = rand() % 6 + 10;
    ptr = malloc(sizeof(int));

    *ptr = x;
    return (void *)(ptr);
}

int main ()
{
    int     *x;
    pthread_t   t;

    if (pthread_create(&t, NULL, func, NULL))
        return (1);
    if (pthread_join(t, (void **)&x))
        return (2);
    printf("%d\n", *x);
    free(x);

}