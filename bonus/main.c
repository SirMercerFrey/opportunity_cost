#include "push_swap.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_head	*pile_a;
	t_head	*pile_b;
	char	*line;

	pile_a = create_pile();
	pile_b = create_pile();
	if (argc < 2)
		return (printf("\n"));
	preambule(argc, argv, pile_a);
	if (check_doublons(pile_a))
		return (printf("Error\n"));
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		execute_instruction(line, pile_a, pile_b);
		free(line);
	}
	if (is_sorted(pile_a) && !pile_b->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}
