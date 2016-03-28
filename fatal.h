/* error macros */
#ifdef _FATAL_H_
#define _FATAL_H_

#include <stdio.h>
#include <stdlib.h>

#define Fatal(s)         FatalError(s)
#define FatalError(s)    fprintf(stderr, "%s\n", s), exit(1);
#endif
