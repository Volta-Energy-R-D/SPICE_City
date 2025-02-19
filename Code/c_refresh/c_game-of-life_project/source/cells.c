/*
 * cells.c
 *
 *  Created on: May 30, 2020
 *      Author: takis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol_config.h"
#include "cells.h"

/*
 * declare important variables (defined in main file as global variables)
 */
//extern cell_t **env;
//extern cell_t **update_env;
extern cell_t env[config_NE][config_ME];
extern cell_t update_env[config_NE][config_ME];
extern bool reproduction_flag;

/*
 * PRIVATE FUNCTIONS
 */

/*
 * transfer a single community identified by the block-pair (iT,jT) to env and
 * update_env using data_init[][]
 */
void transferCommunity(size_t iT, size_t jT,
		const cell_t data_init[config_NC][config_MC])
{
	size_t i_0 = iT * config_NC;
	size_t j_0 = jT * config_MC;

	printf("     ... transferring block (%d, %d)\n", (int) (iT + 1),
			(int) (jT + 1));
	// copy this community to each community in env to initialize it
	for (size_t i = 0; i != config_NC; ++i)
	{
		for (size_t j = 0; j != config_MC; ++j)
		{
			env[i_0 + i][j_0 + j] = update_env[i_0 + i][j_0 + j] =
					data_init[i][j];
		}
	}
}

/*
 * function counts the number of live neighbours of a cell located
 * at row r and column c of the env array
 *
 * for reference, neighbours are designated as follows:
 *     		a b c
 *              d X e
 *              f g h
 *
 *
 */
size_t countLiveNeighbours(size_t row, size_t col)
{
	size_t cell_count = 0;

	// because we may have negative s & t values, we need to switch to long (opposed to size_t)
	long s, t; // position parameters for referencing neighbour cells
	long r = (long) row;
	long c = (long) col;

	for (neighbour_t i = a_posn; i <= h_posn; ++i)
	{
		switch (i)
		{
		case a_posn:
			s = r - 1;
			t = c - 1;
			break;
		case b_posn:
			s = r - 1;
			t = c;
			break;
		case c_posn:
			s = r - 1;
			t = c + 1;
			break;
		case d_posn:
			s = r;
			t = c - 1;
			break;
		case e_posn:
			s = r;
			t = c + 1;
			break;
		case f_posn:
			s = r + 1;
			t = c - 1;
			break;
		case g_posn:
			s = r + 1;
			t = c;
			break;
		case h_posn:
			s = r + 1;
			t = c + 1;
			break;
		}

		// wrap around if needed
		if (s < 0)
			s = config_NE - 1;
		else if (s == config_NE)
			s = 0;

		if (t < 0)
			t = config_ME - 1;
		else if (t == config_ME)
			t = 0;

		// count the cell if it is living
		if (env[s][t] == live)
			++cell_count;
	}

	return cell_count;
}

/*
 * update cell located at row r and column c in env (indicated by X):
 *
 *		a b c
 *		d X e
 *		f g h
 *
 * with nearest neighbours indicated as shown from a, b, ..., h.
 *
 * this function features Conway's rules:
 * 		- if a cell is dead but surrounded by exactly three live neighbours, it sprouts to life (birth)
 * 		- if a cell is live but has more than 4 live neighbours, it dies (overpopulation)
 * 		- if a cell is live but has fewer than 2 live neighbours, it dies (underpopulation)
 * 		- all other dead or live cells remain the same to the next generation (i.e., a live cell must
 * 		  have exactly three neighbours to survive)
 *
 */
void updateCell(size_t r, size_t c)
{
	cell_t state_cell = env[r][c];
	size_t live_neighbours = countLiveNeighbours(r, c);

	// check if a cell needs updating and perform it.
	if ((state_cell == dead) && (live_neighbours == 3U))
	{
		state_cell = live;
		update_env[r][c] = state_cell;

	}
	else if ((state_cell == live)
			&& ((live_neighbours < 2U) || (live_neighbours >= 4U)))
	{
		state_cell = dead;
		update_env[r][c] = state_cell;

	}

	return;
}

/*
 * PUBLIC FUNCTIONS
 */
/*
 * seed environment on a community-by-community basis,
 * from standard input; we assume that the seed input is exactly
 * the size of a community; 9999 indicates end of file;
 * run this before started ncurses environment;
 */
void initEnvironment(void)
{
	// start by reading in a single community
	int token;
	cell_t datum;
	cell_t community_init[config_NC][config_MC];

	printf("\ninitializing environment...\n");
	printf("     ... loading template community from stdin\n");
	for (size_t i = 0; i != config_NC; ++i)
	{
		for (size_t j = 0; j != config_MC; ++j)
		{
			scanf("%d", &token);
			datum = (cell_t) token;
			community_init[i][j] = datum;
		}
	}
	printf("     ... done.\n");

	printf("     ... creating communities\n");
	// copy this community to each community in env to initialize it
	for (size_t i = 0; i != config_K; ++i)
	{
		for (size_t j = 0; j != config_L; ++j)
		{
			transferCommunity(i, j, community_init);
		}
	}
	printf("     ... done.\n");

}
/*
 * write changes to the environment, env, from update_env
 */
void copyEnvironment(void)
{
	// copy this community to each community in env to initialize it
	for (size_t i = 0; i != config_NE; ++i)
	{
		for (size_t j = 0; j != config_ME; ++j)
		{
			env[i][j] = update_env[i][j];
		}
	}
}

/*
 * this function updates all the cells for a thread (corresponding to one community)
 */
void* updateCommFunc(void *param)
{
	// identify the community corresponding to this thread
	threadID_t index = *((threadID_t*) param);

	// extract the row and column BLOCK position of community within the environment
	const size_t thread_row = index.row;
	const size_t thread_col = index.col;

	// determine the row and column CELL offsets of the community with respect to the environment
	size_t i_0 = thread_row * config_NC;
	size_t j_0 = thread_col * config_MC;

	while (1)
	{
		if (reproduction_flag)
		{
			// update each cell within the community
			for (size_t i = 0; i != config_NC; ++i)
			{
				for (size_t j = 0; j != config_MC; ++j)
				{
					updateCell(i_0 + i, j_0 + j); // write to update_env[][] based on data in env[][]
				}
			}
		}
		usleep(512);
	}
}
