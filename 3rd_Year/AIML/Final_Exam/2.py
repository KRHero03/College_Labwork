
from queue import PriorityQueue


class MazeSolver:

    def __init__(self,rows,cols,start,end):
        '''
        MazeSolver Constructor
        rows: No. of rows in Maze
        cols: No. of cols in Maze
        start: Starting Coordinates
        end: Ending Coordinates
        '''
        self.rows = rows
        self.cols = cols
        self.matrix = [['_' for i in range(cols)] for j in range(rows)]
        self.start = start
        self.end = end

        print('Initialised MazeSolver with Following Configuration:')
        print('Rows: ',self.rows)
        print('Columns: ',self.cols)
        print('Start: ',self.start)
        print('End: ',self.end)
        print('')

    def add_wall(self,wall_points):
        '''
        Adds Walls in Maze
        '''
        self.matrix[wall_points[0]][wall_points[1]] = '•'

    
    def solve(self):
        '''
        Solves the Maze using the Greedy Algorithm
        The Greedy Algorithm works similar to Dijstra's Algorithm using a Priority Queue
        Complexity: O(rows*cols*log(rows*cols))
        '''
        fringes = PriorityQueue()

        fringes.put((1,self.start))

        while fringes.empty()==False:
            f,coords = fringes.get()
            x,y = coords
            if self.matrix[x][y]=='•' or self.matrix[x][y]!='_':
                continue
            self.matrix[x][y] = f
            
            if(coords == self.end):
                return
            if(x+1<self.rows):
                fringes.put(((f+1),(x+1,y)))
            if(y+1<self.cols):
                fringes.put(((f+1),(x,y+1)))
            if(x-1>=0):
                fringes.put(((f+1),(x-1,y)))
            if(y-1>=0):
                fringes.put(((f+1),(x,y-1)))
            if(x+1<self.rows and y+1<self.cols):
                fringes.put(((f+1),(x+1,y+1)))
            if(x-1>=0 and y+1<self.cols):
                fringes.put(((f+1),(x-1,y+1)))
            if(x+1<self.rows and y-1>=0):
                fringes.put(((f+1),(x+1,y-1)))
            if(x-1>=0 and y-1>=0):
                fringes.put(((f+1),(x-1,y-1)))
        


    def print_matrix(self):
        '''
        Prints Maze
        '''
        print('Printing Maze: ')
        for i in range(self.rows):
            for j in range(self.cols):
                print(self.matrix[i][j],end=' ')
            print('')     
        print('')


my_maze_solver = MazeSolver(11,21,(0,1),(10,19))


# Adding Walls
for i in range(11):
    my_maze_solver.add_wall((i,0))
    my_maze_solver.add_wall((i,20))

for i in range(21):
    if(i!=1):
        my_maze_solver.add_wall((0,i))
    if(i!=19):
        my_maze_solver.add_wall((10,i))

for i in range(0,5):
    my_maze_solver.add_wall((i,6))
for i in range(0,2):
    my_maze_solver.add_wall((i,12))
for i in range(2,5):
    my_maze_solver.add_wall((i,2))
for i in range(4,6):
    my_maze_solver.add_wall((i,4))
for i in range(4,7):
    my_maze_solver.add_wall((i,8))
for i in range(6,9):
    my_maze_solver.add_wall((i,6))
for i in range(9,11):
    my_maze_solver.add_wall((i,8))
for i in range(7,9):
    my_maze_solver.add_wall((i,10))
for i in range(8,11):
    my_maze_solver.add_wall((i,12))
for i in range(6,9):
    my_maze_solver.add_wall((i,14))
for i in range(2,5):
    my_maze_solver.add_wall((i,10))
for i in range(4,7):
    my_maze_solver.add_wall((i,12))
for i in range(2,7):
    my_maze_solver.add_wall((i,16))
for i in range(4,7):
    my_maze_solver.add_wall((i,18))
for i in range(2,5):
    my_maze_solver.add_wall((i,14))


for i in range(2,5):
    my_maze_solver.add_wall((2,i))
for i in range(8,11):
    my_maze_solver.add_wall((2,i))
for i in range(14,19):
    my_maze_solver.add_wall((2,i))
for i in range(2,9):
    my_maze_solver.add_wall((4,i))
for i in range(10,13):
    my_maze_solver.add_wall((4,i))
for i in range(18,21):
    my_maze_solver.add_wall((4,i))
for i in range(0,2):
    my_maze_solver.add_wall((6,i))
for i in range(6,9):
    my_maze_solver.add_wall((6,i))
for i in range(12,17):
    my_maze_solver.add_wall((6,i))
for i in range(2,7):
    my_maze_solver.add_wall((8,i))
for i in range(10,15):
    my_maze_solver.add_wall((8,i))
for i in range(16,21):
    my_maze_solver.add_wall((8,i))


my_maze_solver.print_matrix()

my_maze_solver.solve()

my_maze_solver.print_matrix()

