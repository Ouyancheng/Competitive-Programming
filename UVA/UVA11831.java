import java.util.*;

class Main {
	static final int N = 0,S = 1,L = 2,O = 3,D = 0,E = 1,F = 0;
	static int[][] xMov = new int[2][4];
	static int[][] yMov = new int[2][4];
	static int[][] rotation = new int[2][4];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		// Assign x-movement to the directions
		xMov[F][N] = 0;
		xMov[F][S] = 0;
		xMov[F][L] = 1;
		xMov[F][O] = -1;

		// Assign y-movement to the directions
		yMov[F][N] = -1;
		yMov[F][S] = 1;
		yMov[F][L] = 0;
		yMov[F][O] = 0;

		// Assign rotation for CW movement
		rotation[D][N] = L;
		rotation[D][S] = O;
		rotation[D][L] = S;
		rotation[D][O] = N;

		// Assign rotation for ACW movement
		rotation[E][N] = O;
		rotation[E][S] = L;
		rotation[E][L] = N;
		rotation[E][O] = S;

		while(in.hasNext()) {
			int rows = in.nextInt();
			int cols = in.nextInt();
			int numCommands = in.nextInt();
			if(rows == 0 || cols == 0 || numCommands == 0) break;

			char[][] grid = new char[rows][];
			char[] commands = null;

			int direction = -1;
			int xPos = -1;
			int yPos = -1;

			for(int row = 0; row < rows; row++) {
				grid[row] = in.next().toCharArray();
				for(int col = 0; xPos == -1 && col < cols; col++) {
					if(grid[row][col] == 'N' || grid[row][col] == 'S' || grid[row][col] == 'L' || grid[row][col] == 'O') {
						xPos = col;
						yPos = row;
						direction = (grid[row][col] == 'N') ? N : (grid[row][col] == 'S') ? S : (grid[row][col] == 'L') ? L : O;
						grid[row][col] = '.'; // Mark the start cell as a normal cell
					}
				}
			}

			// Read in the string of commands
			commands = in.next().toCharArray();

			// Process the input
			System.out.println(numOfStickers(grid,xPos,yPos,commands,0,direction));
		}

	}

	public static int numOfStickers(char[][] matrix,int xPos,int yPos,char[] commands,int cmdIndex,int direction) {
		if(cmdIndex >= commands.length) {
			return 0;
		} else {
			if (commands[cmdIndex] == 'F') {
				int newX = xPos+xMov[F][direction];
				int newY = yPos+yMov[F][direction];
				if(newX < 0 || newX >= matrix[yPos].length || newY < 0 || newY >= matrix.length || matrix[newY][newX] == '#') {
					return numOfStickers(matrix,xPos,yPos,commands,cmdIndex+1,direction);
				} else if(matrix[newY][newX] == '*') {
					matrix[newY][newX] = '.';
					return 1 + numOfStickers(matrix,newX,newY,commands,cmdIndex+1,direction);
				}
				return numOfStickers(matrix,newX,newY,commands,cmdIndex+1,direction);
			} else {
				return numOfStickers(matrix,xPos,yPos,commands,cmdIndex+1,rotation[commands[cmdIndex] == 'D' ? D : E][direction]);
			}
		}
	}
}
