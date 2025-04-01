# include "tr.h"

int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *func(void *arg)
{
    int i;
    int sum;

    i = *(int *)arg;
    sum = 0;

    for (int j = 0; j < 5; j++)
        sum += arr[i + j];
    *(int *)arg = sum;
    return arg;
}


int main (int ac, char **av)
{
    pthread_t tr[2];

    for (int i = 0; i < 2 ; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&tr[i], NULL, &func, a))
            return 1;
    }

    int a = 0;

    for (int j = 0; j < 2 ; j++)
    {
        int *x;
        if (pthread_join(tr[j], (void **)&x))
            return 1;
        a += *x;
    }

    printf("%d\n", a);

}