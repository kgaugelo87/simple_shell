#include "main.h"

/**
 * _curenviron – displays the current environment
 * @details: our arguments information
*
 * Return: Always return the value of (0)
 */

int _curenviron(info_t *details)
{
        print_list_str(details->env);
        return (0);
}
