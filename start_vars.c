#include "main.h"
/**
 * start_vars - Fake rand to jackpoint Giga Millions
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_vars(vars *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->tmp = 0;
	var->dict = create_instru();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}
