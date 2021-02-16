import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;

public class Minesweeper {
    static class Game {
        private int[][] arr, mask;
        private String[][] board;
        private int m, n;
        private double p;
        private int score;
        private boolean gameOver, gameWon;

        Game(int m, int n, double p) {
            this.m = m;
            this.n = n;
            this.p = p;
            this.score = 0;
            this.gameOver = false;
            this.gameWon = false;
            arr = new int[this.m][this.n];
            mask = new int[this.m][this.n];
            board = new String[this.m][this.n];
            for (int i = 0; i < this.m; i++) {
                for (int j = 0; j < this.n; j++) {
                    double r = Math.random();
                    arr[i][j] = (r > p) ? 0 : 1;
                    board[i][j] = "□";
                    mask[i][j] = 0;
                }
            }
        }

        public void resetBoard() {
            this.score = 0;
            this.gameWon = false;
            this.gameOver = false;
            arr = new int[this.m][this.n];
            mask = new int[this.m][this.n];
            board = new String[this.m][this.n];
            for (int i = 0; i < this.m; i++) {
                for (int j = 0; j < this.n; j++) {
                    arr[i][j] = (Math.random() > p) ? 0 : 1;
                    board[i][j] = "□";
                    mask[i][j] = 0;
                }
            }
        }

        public void playMove(int i, int j) throws Exception {
            if (this.gameOver == true) {
                throw new Exception("Invalid Move Error: Game Already Over!");
            }
            if (!(i >= 0 && i < this.m && j >= 0 && j < this.n)) {
                throw new Exception("Invalid Move Error: Please enter valid Move!");
            }
            if (this.mask[i][j] == 1) {
                throw new Exception("Invalid Move Error: Cell already unlocked!");
            }
            if (this.arr[i][j] == 1) {
                this.gameOver = true;
                this.revealBoard();
                return;
            }

            Queue<ArrayList<Integer>> q = new LinkedList<>();

            ArrayList<Integer> start = new ArrayList<Integer>();
            start.add(i);
            start.add(j);
            q.add(start);
            while (q.size() != 0) {
                ArrayList<Integer> node = q.peek();
                q.remove();
                int count = 0;
                int x = node.get(0);
                int y = node.get(1);
                if (this.mask[x][y] == 1)
                    continue;
                this.mask[x][y] = 1;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (a == 0 && b == 0)
                            continue;
                        if (x + a >= 0 && x + a < this.m && y + b >= 0 && y + b < this.n) {
                            if (this.arr[x + a][y + b] == 1)
                                count++;
                            else {
                                if(Math.abs(a)+Math.abs(b)>1) continue;
                                ArrayList<Integer> t = new ArrayList<Integer>();
                                t.add(x + a);
                                t.add(y + b);
                                q.add(t);
                            }
                        }
                    }
                }
                this.board[x][y] = Integer.toString(count);
                this.score = this.score + count;

            }

            int pass = 1;
            for (int a = 0; a < this.m; a++) {
                for (int b = 0; b < this.n; b++) {
                    if (this.arr[a][b] == 0 && this.mask[a][b] != 1) {
                        pass = 0;
                    }
                }
            }
            if (pass == 1) {
                this.gameWon = true;
                this.gameOver = true;
                this.revealBoard();
            }

            return;

        }
        
        private void revealBoard() {
            for (int i = 0; i < this.m; i++) {
                for (int j = 0; j < this.n; j++) {
                    if (this.arr[i][j] == 1 && this.gameWon == false) {
                        this.board[i][j] = "💥";
                    } else if (this.arr[i][j] == 1 && this.gameWon == true) {
                        this.board[i][j] = "💣";
                    }
                }
            }

        }

        public void printBoard() {
            System.out.println("Board Status:");
            for (int i = 0; i < this.m; i++) {
                for (int j = 0; j < this.n; j++) {
                    System.out.print(this.board[i][j]);
                }
                System.out.println("");
            }
            System.out.println("Score: " + this.score);

        }

        public boolean getGameOver() {
            return this.gameOver;
        }

        public boolean getGameWon() {
            return this.gameWon;
        }

        public int getScore() {
            return this.score;
        }

    }

    public static void main(String[] arr) {
        try {
            if (arr.length != 3) {
                System.out.println("Minesweeper Help");
                System.out.println("Three Arguments Required:");
                System.out.println("M - No. of rows (Integer)");
                System.out.println("N - No. of columns (Integer)");
                System.out.println("P - Probability of Mines (Double)");
                System.out.println("Example: >java ./Minesweeper.java <M> <N> <P>");
                throw new Exception("Insufficient Arguments error!");
            }
            int m = Integer.parseInt(arr[0]);
            int n = Integer.parseInt(arr[1]);
            double p = Double.parseDouble(arr[2]);
            if (p <= 0 && p >= 1)
                throw new Exception("Invalid Argument Error! Probability should be between 0 and 1 exclusive!");
            Scanner sc = new Scanner(System.in);

            Minesweeper.Game newGame = new Minesweeper.Game(m, n, p);
            while (!newGame.getGameOver()) {
                try {
                    newGame.printBoard();
                    System.out.print(">Your Move: ");
                    String[] res = sc.nextLine().split(" ");
                    if (res.length != 2)
                        throw new Exception(
                                "Invalid Input Error: Please enter Input of the form <X> <Y> (X between 0 and M; Y between 0 and N) !");
                    int i = Integer.parseInt(res[0]);
                    int j = Integer.parseInt(res[1]);
                    newGame.playMove(i, j);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
            newGame.printBoard();
            if (newGame.getGameWon() == true) {
                System.out.println("Game Over! You Won!");
            } else {
                System.out.println("Gamve Over! You Lost!");
            }

            sc.close();

        } catch (Exception e) {
            System.out.println("Program exited due to unforeseen error!");
        }
    }

}
