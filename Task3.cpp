#include <iostream>
#include <string>
using namespace std;

#define RESET "\033[0m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"

#ifdef _WIN32
#define CLEAR() system("cls")
#else
#define CLEAR() system("clear")
#endif
char board[3][3];
string playerX, playerO;
int scoreX = 0, scoreO = 0;
char currentplayer;

void resetBoard()
{
    char cell = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = cell++;
}

void displayBoard()
{
    CLEAR();

    cout << "\nPlayer X: " << BRIGHT_RED << playerX << RESET << " | Player O: " << BRIGHT_BLUE << playerO << RESET << "\n";
    cout << "Scores :- " << BRIGHT_RED << playerX << ": " << scoreX << RESET << " | " << BRIGHT_BLUE << playerO << ": " << scoreO << RESET << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << (board[i][j] == 'X' ? BRIGHT_RED : (board[i][j] == 'O' ? BRIGHT_BLUE : BRIGHT_CYAN)) << board[i][j] << RESET;
            if (j < 2)
                cout << BRIGHT_CYAN << "  |" << RESET;
        }
        cout << "\n";
        if (i < 2)
            cout << BRIGHT_CYAN << " ---+---+---\n"<< RESET;
    }
    cout << "\n";
}

bool checkWin(char mark)
{
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
            return true;
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) || (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return true;
    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void playGame()
{
    resetBoard();
    currentplayer = 'X';
    bool gameOn = true;

    while (gameOn)
    {
        displayBoard();
        string currentName = (currentplayer == 'X') ? playerX : playerO;
        cout << "TURN: " << (currentplayer == 'X' ? BRIGHT_RED : BRIGHT_BLUE) << currentName << RESET << "(" << currentplayer << ")\n";
        cout << BRIGHT_GREEN << "ENTER CELL NUMBER(1-9): " << RESET << "\n";
        int cell;
        cin >> cell;
        if (cell < 1 || cell > 9)
        {
            cout << "Invalid Input!Try again.\n";
            continue;
        }

        int row = (cell - 1) / 3;
        int col = (cell - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Cell already taken!Try another.\n";
            continue;
        }

        board[row][col] = currentplayer;
        if (checkWin(currentplayer))
        {
            displayBoard();
            cout << BRIGHT_YELLOW << "Congratulations " << (currentplayer == 'X' ? playerX : playerO) << "! You win!\n"<< RESET;
            if (currentplayer == 'X')
                scoreX++;
            else
                scoreO++;
            gameOn = false;
        }
        else if (checkDraw())
        {
            displayBoard();
            cout << BRIGHT_YELLOW << "It's a draw!\n"<< RESET;
            gameOn = false;
        }
        else
        {
            currentplayer = (currentplayer == 'X') ? 'O' : 'X';
        }
    }
}

int main()
{
    cout << "Enter Player X Name: ";
    cin >> playerX;
    cout << "Enter Player O Name: ";
    cin >> playerO;

    char playAgain;
    do
    {
        playGame();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        playAgain = toupper(playAgain);
    } while (playAgain == 'Y');
    cout << BRIGHT_MAGENTA << "===============================" << RESET << "\n";
    cout << BRIGHT_MAGENTA << "       Final Scores\n"<< RESET;
    cout << BRIGHT_MAGENTA << "=================================" << RESET << "\n";
    if (scoreX > scoreO)
        cout << BRIGHT_RED << playerX << " wins with a score of " << scoreX << "!" << RESET << "\n";
    else if (scoreO > scoreX)
        cout << BRIGHT_BLUE << playerO << " wins with a score of " << scoreO << "!" << RESET << "\n";
    else
        cout << "It's a tie with both players scoring " << scoreX << "!" << "\n";

    cout << "Thanks for playing!\n";
    return 0;
}