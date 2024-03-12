#include "headers\\FindPath.h"

int bfs(Coordinate from, Coordinate to){
	
	int i, j;
    int flag = FALSE;

	/* define a Queue */
	Coordinate Queue[MAP_MAX * MAP_MAX];
	int Qhead = 0, Qtail;
	
	/* initialize distance matrix */
	for (i = 0; i < map.size; i++){
		for (j = 0; j < map.size; j++){
			dist[i][j] = INX_MAX;
		}
	}
	dist[to.x][to.y] = 0;

	// point the first node to coordinate to 
	Coordinate node;

	Queue[Qhead].x = to.x;
    Queue[Qhead].y = to.y;

	Qtail = 1;
	Coordinate temp;

	while (Qhead != Qtail) {

        node.x = Queue[Qhead].x;
        node.y = Queue[Qhead].y;
        Qhead++;

        for (i = 0; i < 4; i++){
            temp.x = node.x + direction[i].x;
            temp.y = node.y + direction[i].y;
            if (temp.x >= 0 && temp.x < map.size && temp.y >= 0 && temp.y < map.size && dist[temp.x][temp.y] == INX_MAX &&
                map.arrangement[temp.x][temp.y] != TREE) {

                dist[temp.x][temp.y] = dist[node.x][node.y] + 1;
                Queue[Qtail].x = temp.x;
                Queue[Qtail].y = temp.y;
                Qtail++;

                // the source has been ever enqueued
                if (temp.x == from.x && temp.y == from.y)
                    flag = TRUE;
            }
        }
    }
        return flag;
}

/// @brief renew the path[][]
/// @return flag. if 1: starting point reachable. 0: not reachable
int findPath(Coordinate from, Coordinate to){
	
	int i, j;
    int flag = FALSE;
    
//  /* initialize path matrix */
//	for (i = 0; i < map.size; i++)
//		for (j = 0; j < map.size; j++)
//			path[i][j] = 0;	
//	
	flag = bfs(from, to);

	if (flag == TRUE)
        minStep = dist[from.x][from.y];
    if (flag == FALSE)
        return flag;
	
	Coordinate current, temp;
	current.x = from.x;
	current.y = from.y;
	
	
	while (current.x != to.x || current.y != to.y) {
        /* loop 4 directions */
        for (i = 0; i < 4; i++) {
            temp.x = current.x + direction[i].x;
            temp.y = current.y + direction[i].y;
            // check still in the map && not wall
            if (temp.x >= 0 && temp.x < map.size && temp.y >= 0 && temp.y < map.size &&
                map.arrangement[temp.x][temp.y] != TREE) {
                // can reach within one step
                if (dist[current.x][current.y] == dist[temp.x][temp.y] + 1) {
                    // mark as path
                    path[temp.x][temp.y] = PATH;
                    // renew current
                    current.x = temp.x;
                    current.y = temp.y;
                    break;
                }
            }
        }
    }

    return flag;
}

