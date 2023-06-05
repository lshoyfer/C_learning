// Conways Game of Life

#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 38
#define MAX_COLS 143
#define MAX_TICKS 100
#define NANOSECONDS_PER_TICK 500000000L // 0.5s, 500,000,000 ns
#define SPAWN_REGIONS 9 /* number of spawn clusters when initializing,
                            regions overlap/write each other, so you wont get the 
                            actual expected number of regions, oh well! */
#define REGION_LEN 9 // length of a region (a region is a len X len square)

#define DEAD 0
#define ALIVE 1
#define DYING 2
#define GROWING 3

void init(int game_state[MAX_ROWS][MAX_COLS]);
void pgs(int game_state[MAX_ROWS][MAX_COLS]); // debugging, prints raw gs
void display(int game_state[MAX_ROWS][MAX_COLS]);
void tick(int game_state[MAX_ROWS][MAX_COLS]);
void calc_states(int game_state[MAX_ROWS][MAX_COLS]);
void apply_states(int game_state[MAX_ROWS][MAX_COLS]);

int main() {
    int i, j;
    int game[MAX_ROWS][MAX_COLS];
    struct timespec ts;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    for (i = 0; i < MAX_ROWS; ++i)
        for (j = 0; j < MAX_COLS; ++j)
            game[i][j] = DEAD;

    init(game);
    display(game);

    ts.tv_sec = 0;
    ts.tv_nsec = NANOSECONDS_PER_TICK;
    for (i = 0; i < MAX_TICKS; ++i) {
        tick(game);
        display(game);
        nanosleep(&ts, NULL);
    }

    return 0;
}


void init(int gs[MAX_ROWS][MAX_COLS]) {
    int i, j, x, y, squares, clusters;

    squares = MAX_ROWS * MAX_COLS;
    clusters = SPAWN_REGIONS;

    for (i = 0; i < clusters; ++i) {
        // pick top left square of a region
        x = rand() % (MAX_ROWS - REGION_LEN + 1);
        y = rand() % (MAX_COLS - REGION_LEN + 1);

        for (j = 0; j < REGION_LEN; ++j) {
            gs[x+j][y] = (rand() % 10) < 8 ? ALIVE : DEAD;
        }
        for (j = 0; j < REGION_LEN; ++j) {
            gs[x][y+j] = (rand() % 10) < 8 ? ALIVE : DEAD;
        }
    }
}

void pgs(int gs[MAX_ROWS][MAX_COLS]) {
    int i, j;

    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = 0; j < MAX_COLS; ++j)
            printf("%d", gs[i][j]);
        putchar('\n');
    }

    putchar('\n');
}

void display(int gs[MAX_ROWS][MAX_COLS]) {
    int i, j;

    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = 0; j < MAX_COLS; ++j)
            wprintf(L"%lc", gs[i][j] ? L'\u25FC' : L'\u2800');
        putchar('\n');
    }

    putchar('\n');
}

void tick(int gs[MAX_ROWS][MAX_COLS]) {
    calc_states(gs);
    apply_states(gs);
}

void calc_states(int gs[MAX_ROWS][MAX_COLS]) {
    int i, j, neighbors, ivec, jvec, nbr_i, nbr_j; 
    /* ivec & jvec are offsets for i&j when searching 
        neighbors to help reduce code size, but
        lol the quadruple nest looks 10/10 beautiful 
        and i think it ended up longer anyways:
        oh well!

        nbr_i & nbr_j are coordinates of the current
        nbr we are examining    
    */

    for (i = 0; i < MAX_ROWS; ++i)
        for (j = 0; j < MAX_COLS; ++j) {
            neighbors = 0;
            for (ivec = -1; ivec < 2; ++ivec)
                for (jvec = -1; jvec < 2; ++jvec) {
                    if (ivec == 0 && jvec == 0)
                        continue;

                    nbr_i = i + ivec;
                    nbr_j = j + jvec;

                    if (nbr_i < 0 || nbr_i > MAX_ROWS)
                        continue;
                    if (nbr_j < 0 || nbr_j > MAX_COLS)
                        continue;

                    if (gs[nbr_i][nbr_j] == 1 || gs[nbr_i][nbr_j] == 2)
                        ++neighbors;
                }
            
            // cant be immediately grown/deleted, rather flagged,
            // due to "tick" game nature. See: "NaiveLife"
            if (gs[i][j] == DEAD && neighbors == 3)
                gs[i][j] = GROWING;
            else if (gs[i][j] == ALIVE && (neighbors < 2 || neighbors > 3))
                gs[i][j] = DYING;
        }
}

void apply_states(int gs[MAX_ROWS][MAX_COLS]) {
    int i, j;

    for (i = 0; i < MAX_ROWS; ++i)
        for (j = 0; j < MAX_COLS; ++j) {
            if (gs[i][j] == DYING)
                gs[i][j] = DEAD;
            else if (gs[i][j] == GROWING)
                gs[i][j] = ALIVE;
        }
}