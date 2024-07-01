#include <iostream>
#include <vector>
#include <limits>

// Function to initialize the game board
void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        std::vector<char> row(3, ' ');
        board.push_back(row);
    }
}

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n    1   2   3\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "  +---+---+---+\n";
        std::cout << i + 1 << " | ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "  +---+---+---+\n\n";
}

// Function to check if the game is won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Minimax algorithm implementation
int minimax(std::vector<std::vector<char>>& board, bool isMaximizing, char player, char opponent) {
    if (checkWin(board, player)) return 10;
    if (checkWin(board, opponent)) return -10;
    if (checkDraw(board)) return 0;

    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;
                    int score = minimax(board, false, player, opponent);
                    board[i][j] = ' ';
                    bestScore = std::max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = opponent;
                    int score = minimax(board, true, player, opponent);
                    board[i][j] = ' ';
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

// Function to find the best move for the computer
std::pair<int, int> findBestMove(std::vector<std::vector<char>>& board, char player) {
    int bestScore = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                int score = minimax(board, false, player, (player == 'X') ? 'O' : 'X');
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }
    return bestMove;
}

// Function to handle a player's move
bool playerMove(std::vector<std::vector<char>>& board, char player) {
    int row, col;
    std::cout << "Player " << player << ", enter your move (row and column): ";

    // Validate input
    while (!(std::cin >> row >> col) || row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
        std::cout << "Invalid input. Please enter a valid row and column (1-3): ";
        std::cin.clear(); // clear the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    board[row - 1][col - 1] = player;
    return true;
}

// Main function to play the game
int main() {
    std::vector<std::vector<char>> board;
    initializeBoard(board);

    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard(board);

        bool validMove = false;
        if (currentPlayer == 'X') {
            while (!validMove) {
                validMove = playerMove(board, currentPlayer);
            }
        } else {
            std::pair<int, int> bestMove = findBestMove(board, currentPlayer);
            board[bestMove.first][bestMove.second] = currentPlayer;
            validMove = true;
        }

        gameWon = checkWin(board, currentPlayer);
        if (gameWon) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        gameDraw = checkDraw(board);
        if (gameDraw) {
            displayBoard(board);
            std::cout << "The game is a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
