
#include "libraries.h"

/* TODO : UNIFY INTERFACE (Y,X) */
void init_person_at(Person *p, int x, int y, int d)
{
    p->alive = TRUE;
    p->viral_charge = 0;
    p->pos.y = y;
    p->pos.x = x;
    p->direction = d;
    p->healing = FALSE;
}

void init_doctor_at(Person *p, int x, int y, int d)
{
    p->alive = TRUE;
    p->viral_charge = 0;
    p->pos.x = x;
    p->pos.y = y;
    p->direction = d;
    p->healing = TRUE;
}