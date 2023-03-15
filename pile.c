#include"pile.h"
#include<assert.h>
#define N 100
struct pile
{
    int cle[N];
    int sommet;
};
static struct pile p;
void creer_pile()
{
    p.sommet=-1;
}
unsigned vide()
{
    return (p.sommet==-1);
}
int dernier()
{
    assert(!vide());
    return(p.cle[p.sommet]);
}
void empiler(int data)
{
    p.sommet++;
    p.cle[p.sommet]=data;
}
void depiler()
{
    assert(!vide());
    p.sommet--;
}
