#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>

int main(int ac, char **av);
int main(void);
int main(int ac, char **av, char **env);

/** 
 * Getenv
 */
char *_getenv(const char *name);

/**
 * setenv
 */
int _setenv(const char *name, const char *value, int overwrite);

/**
 * unsetenv
 */
int _unsetenv(const char *name);
/**
 * Betty checker
 */
int bfree(void **ptr)
#endif
