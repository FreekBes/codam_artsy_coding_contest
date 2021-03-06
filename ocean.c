#include "headers.h"

void	free_waves(int **waves)
{
	int		i;

	i = 0;
	while (waves[i])
	{
		free(waves[i]);
		i++;
	}
	free(waves);
}

int		**draw_ocean(int ended)
{
	static int	frame;
	static int	seconds;
	static int	wave_amount;
	static int	**waves;
	int			i;
	int			j;

	if (wave_amount == 0)
	{
		wave_amount = COLS / 4;
		if (waves)
			free_waves(waves);
		waves = (int **)malloc(sizeof(int *) * (wave_amount + 1));
		i = 0;
		while (i < wave_amount)
		{
			waves[i] = (int *)malloc(sizeof(int) * 2);
			waves[i][0] = 0;
			waves[i][1] = 0;
			i++;
		}
		waves[i] = NULL;
	}
	if (frame == 0)
	{
		i = 0;
		while (i < wave_amount)
		{
			waves[i][0] = (rand() % (LINES) + 1);
			if (!ended)
				waves[i][1] = (rand() % (COLS + 30 + seconds * 2 + 1) + 5 + seconds * 2);
			else
				waves[i][1] = (rand() % (COLS - 5) + 5);
			i += 2;
		}
	}
	if (frame == 20)
	{
		i = 1;
		while (i < wave_amount)
		{
			waves[i][0] = (rand() % (LINES) + 1);
			if (!ended)
				waves[i][1] = (rand() % (COLS + 30 + seconds * 2) + 5 + seconds * 2);
			else
				waves[i][1] = (rand() % (COLS - 5) + 5);
			i += 2;
		}
	}

	i = 0;
	while (i < wave_amount)
	{
		if (seconds > 3)
			attron(COLOR_PAIR((rand() % (-14) + 1)));
		if (i % 2 || i == 0)
		{
			if (waves[i][0] > 0)
			{
				if (frame >= 0 && frame < 15)
					mvprintw(waves[i][0], waves[i][1], "_");
				else if (frame >= 15 && frame < 23)
					mvprintw(waves[i][0], waves[i][1], "~");
				else if (frame >= 23 && frame < 30)
					mvprintw(waves[i][0], waves[i][1], "=");
				else
					mvprintw(waves[i][0], waves[i][1], ".");
			}
		}
		else
		{
			if (waves[i][0] > 0)
			{
				if (frame >= 20 && frame < 30)
					mvprintw(waves[i][0], waves[i][1], "_");
				else if (frame >= 30 || frame < 7)
					mvprintw(waves[i][0], waves[i][1], "~");
				else if (frame >= 7 && frame < 10)
					mvprintw(waves[i][0], waves[i][1], "=");
				else if (frame >= 10 && frame < 20)
					mvprintw(waves[i][0], waves[i][1], ".");
			}
		}
		if (!ended)
			waves[i][1] = waves[i][1] - 1 - seconds / 4;
		i++;
	}
	//printw("seconds: %d, frame: %d", seconds, frame);
	frame++;
	if (frame > FRAMERATE * 2)
	{
		frame = 0;
		seconds++;
	}
	return (waves);
}
