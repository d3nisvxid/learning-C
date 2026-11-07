#include <stdio.h>
#include <unistd.h>


#define GRID_COLS 20 //y
#define GRID_ROWS 20 //x
#define GRID_CELLS (GRID_COLS*GRID_ROWS)
#define ALIVE '*'
#define DEAD '.'

/*translate the point x y into the index of the linear array grid
with wrapping so negative and positive coords that are out of the grid
will wrap around*/
int cellToOffset(int x, int y){
	/*allora, se passo 0 25 praticamente sto accedendo a una colonna
	che non esiste, perche arrivano fino a 24, quindi deve diventare
	0 0, se passo 50, praticamente ho fatto due giri,
	0 ------ 24 25(0) ----- 24 25 (0) mhh penso di dover prendere il resto
	ad esempio con 26 devo avere 0 1, 25%26 fa 1 perche ci entra 25 volte
	col resto di 1 appunto, quindi facile
	per i negativi -1 corrisponde a 24, il primo partendo da dx basically,
	-2 sarebbe 23.. -24 ritorna a 0 e -25 è di nuovo come -1 quindi 24
	quindi basta aggiungere alle colonne la x negativa e si andra a togliere 
	e alla righe la y negativa
	*/
	if(x<0) {
		x = (-x) % GRID_COLS; //lo normalizzo col wrap around normale positivo
		x = GRID_COLS - x; //poi tolgo
	}
	if(y<0) {
		y = (-y) % GRID_ROWS;
		y = GRID_ROWS - y;
	}
	if(x>=GRID_COLS) x = x % GRID_COLS;
	if(y>=GRID_ROWS) y = y % GRID_ROWS;
	return y*GRID_ROWS+x;
}

/*Sets the specified cell at x y to the specified status*/
void set_cell(char *grid, int x, int y, char status){
	grid[cellToOffset(x, y)] = status;
   /*
	**** questo corrisponde a grid totale 16, passando 
	**** un punto devo fare y per quante righe ho e poi dare l'offset
	**** a destra con la x, passando 0 0 avro grid[0], con 0 1 grid [1]
   */

}

/*returns the state of grid at x y*/
char get_cell(char *grid, int x, int y){
	return grid[cellToOffset(x,y)];
}


/*shows the grid on the screen (clearing the terminal)*/
void print_grid(char *grid){
	printf("\x1b[3J\x1b[H\x1b[2J");
	for(int y=0; y<GRID_ROWS; y++){
		for(int x=0; x<GRID_COLS; x++){
			printf("%c", get_cell(grid, x, y));
		}
		printf("\n");
	}
}

/*reset the board to all dead*/
void reset_grid(char *grid){
	for(int y=0; y<GRID_ROWS; y++){
		for(int x=0; x<GRID_COLS; x++){
			set_cell(grid, x, y, DEAD);
		}
	}
}

/*return number of living cells neighboring xy*/
int count_living_neightbors(char *grid, int x, int y){
	int alive=0;
	for(int yo=-1; yo<=1; yo++){
		for(int xo=-1; xo<=1; xo++){
			if(xo == 0 && yo==0) continue;
			if(get_cell(grid, x+xo, y+yo) == ALIVE) ++alive;
		}
	}
	return alive;
}


/*compute the new state according to GOL rules*/
void compute_new_state(char *old, char *new){
	for(int y=0; y<GRID_ROWS; y++){
		for(int x=0; x<GRID_COLS; x++){
			int n_alive = count_living_neightbors(old, x, y);
			int new_state = DEAD;
			if(get_cell(old, x, y) == ALIVE){
				if(n_alive==2 || n_alive==3) new_state = ALIVE;
			}
			else{ //se è morta deve avere 3 vicini vivi per vivere
				if(n_alive==3) new_state = ALIVE;
			}
			set_cell(new, x, y, new_state);
		}
	}
}




int main(void){
	char old_grid[GRID_CELLS];
	char new_grid[GRID_CELLS];
	reset_grid(old_grid);
	set_cell(old_grid, 10, 10, ALIVE);
	set_cell(old_grid, 9, 10, ALIVE);
	set_cell(old_grid, 11, 10, ALIVE);
	set_cell(old_grid, 11, 9, ALIVE);
	set_cell(old_grid, 10, 8, ALIVE);
	while(1){
		compute_new_state(old_grid, new_grid);
		print_grid(new_grid);
		usleep(100000);
		compute_new_state(new_grid, old_grid);
		print_grid(old_grid);
		usleep(100000);
	}	
	printf("%d\n", count_living_neightbors(old_grid, 2, 6));
}








