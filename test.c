#include<stdio.h>

int main()
{
    char u, v = 'A';
    char *pu, *pv = &v;
    printf("%c %c\n",v,*pv);
    //printf("%p %p %p %p\n", &u, &v, pu, pv);
    *pv = v + 1;
    printf("%c %c\n",v,*pv);
    //printf("%c %c %c %c\n", u, v, *pu, *pv);
    //printf("%p %p %p %p\n", &u, &v, pu, pv);
    u = *pv + 1;
    printf("%c %c %c\n", u, v, *pv);
    //printf("%p %p %p %p\n", &u, &v, pu, pv);
    pu = pv;
    printf("%c %c %c %c\n", u, v, *pu, *pv);
    //printf("%p %p %p %p\n", &u, &v, pu, pv);
    pu = &u;
    printf("%c %c %c %c\n", u, v, *pu, *pv);
    //printf("%p %p %p %p\n", &u, &v, pu, pv);
    return 0;
}
