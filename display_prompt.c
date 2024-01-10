#include "main.h"

/**
 * displayprompt - Fuction display prompt
 *
 * Description: the function return $
 * Returns: Nothing
 */
void displayprompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
		printf("$ ");
}
