#ifndef __aw092h__SIMULATION_H
#define __aw092h__SIMULATION_H

    #include "datastructures.h"
    #include "singly_linked_list.h"

    int person_death(
        Person *p, struct singly_linked_list **persons,  
        Case **table,
        int n, int m
    );

#endif