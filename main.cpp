#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Board {
private:
    std::vector<std::vector<int>> board;
    int emptyRow, emptyCol;

    // Helper function to initialize the board in a solvable state
    void initializeBoard() {
        std::vector<int> tiles(16);
        for (int i = 0; i < 16; ++i) {
            tiles[i] = i;
        }

        std::random_device rd; 
        std::mt19937 g(rd());   

        // Shuffle the tiles
        do {
            std::shuffle(tiles.begin(), tiles.end(), g);
        } while (!isSolvable(tiles));

        // Populate the board with shuffled tiles
        for (int i = 0; i < 16; ++i) {
            board[i / 4][i % 4] = tiles[i];
            if (tiles[i] == 0) {
                emptyRow = i / 4;
                emptyCol = i % 4;
            }
        }
    }

    // Check if a shuffled board is solvable
    bool isSolvable(const std::vector<int>& tiles) {
        int inv = 0;
        for (int i = 0; i < 16; ++i) {
            for (int j = i + 1; j < 16; ++j) {
                if (tiles[i] && tiles[j] && tiles[i] > tiles[j]) {
                    ++inv;
                }
            }
        }
        int emptyRowFromBottom = 3 - emptyRow;
        return (inv + emptyRowFromBottom) % 2 == 0;
    }

public:
    // Constructor of the Board class
    Board() : board(4, std::vector<int>(4)) {
        initializeBoard();
    }

    // Display the board
    void display() const {
        for (const auto& row : board) {
            for (int tile : row) {
                if (tile == 0) {
                    std::cout << "\t";
                } else {
                    std::cout << tile << "\t";
                }
            }
            std::cout << std::endl;
        }
    }

    // Move a tile
    bool moveTile(char direction) {
        int newRow = emptyRow, newCol = emptyCol;
        switch (direction) {
            case 'w': newRow--; break;
            case 's': newRow++; break;
            case 'a': newCol--; break;
            case 'd': newCol++; break;
            default: return false;
        }
        if (newRow < 0 || newRow >= 4 || newCol < 0 || newCol >= 4) {
            return false;
        }
        std::swap(board[emptyRow][emptyCol], board[newRow][newCol]);
        emptyRow = newRow;
        emptyCol = newCol;
        return true;
    }

    // Check if the player has won
    bool isSolved() const {
        int correctTile = 1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == 3 && j == 3) return board[i][j] == 0;
                if (board[i][j] != correctTile++) return false;
            }
        }
        return true;
    }
};

int main() {
    Board board;

    std::cout << "Sliding Puzzle 4x4 Game!" << std::endl;
    std::cout << "Use \n'w'(town)\n'a'(left)\n's'(down)\n'd'(right)\nto move the tiles." << std::endl;
    std::cout << "Press 'q' to quit the game." << std::endl;

    while (true) {
        board.display();
        if (board.isSolved()) {
            std::cout << "Congratulations! You've solved the puzzle!" << std::endl;
            break;
        }

        std::cout << "Move (w/a/s/d) or quit (q): ";
        char move;
        std::cin >> move;

        if (move == 'q') {
            std::cout << "Quitting the game..." << std::endl;
            break;
        }

        if (!board.moveTile(move)) {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}