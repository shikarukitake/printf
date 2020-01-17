//
// Created by Aletha Yellin on 17/01/2020.
//

#include "put_bch.h"

int main()
{
    put_bch('y');
    put_bch('e');
    put_bch('a');
    put_bch('h');

    flush_buffer();

    int i = 0;
    while (i < 100)
    {
        put_bch('0' + i % 10);
        i++;
    }
    flush_buffer();
}