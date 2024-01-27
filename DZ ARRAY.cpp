#include <iostream>
#include <cstdlib>// стандартная библиотека для С
#include <ctime> // стандартная библиотека для времени С
#include <array> // библеотека массив

using namespace std;

int main()
// Создаем двумерный массив.
{
    std::srand(std::time(nullptr));

    int** array = new int* [3];
    for (int i = 0; i < 3; i++)
    {
        array[i] = new int[4];
    }

    // Заполняем массив случайными числами.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Итерируемся по массиву, проверяя каждое значение на дубликаты.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // Итерируемся по оставшейся части массива, проверяя текущее значение на равенство остальным значениям.
            for (int k = i + 1; k < 3; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (array[i][j] == array[k][l])
                    {
                        // Если найден дубликат, то выводим его на экран.
                        cout << array[i][j] << " ";
                    }
                }
            }
        }
    }
    return 0;
}


//using namespace std;
//
//const int SIZE = 3; // Объявляет константу SIZE, определяющую размер игрового поля
//
//void drawBoard(char board[][SIZE]) // Объявляет функцию drawBoard(), которая выводит игровое поле на экран
//{
//
//
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            cout << board[i][j];
//        }
//        cout << endl;
//    }
//}// Выводит на экран игровое поле, заполненное символами из массива board
//
//bool isWinner(char board[][SIZE], char symbol) // Объявляет функцию isWinner(), которая проверяет, выиграл ли какой-либо из игроков
//{
//    for (int i = 0; i < SIZE; i++)
//    {
//        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
//        {
//            return true;
//        }
//        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
//        {
//            return true;
//        }
//    }
//    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
//    {
//        return true;
//    }
//    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
//    {
//        return true;
//    }
//    return false;
//    // Проверяет, есть ли в массиве board три символа symbol, расположенные подряд по горизонтали, вертикали или диагонали
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    // Объявляет переменную board, которая будет хранить игровое поле
//    char board[SIZE][SIZE] =
//    {
//      ' ', ' ', ' ',
//      ' ', ' ', ' ',
//      ' ', ' ', ' ',
//    };  // Инициализирует игровое поле пустыми клетками
//
//    char turn = 'X';   // Объявляет переменную turn, которая будет хранить символ хода текущего игрока
//
//    while (!isWinner(board, turn)) {
//        drawBoard(board);
//        cout << "Ходит " << turn << endl;     // Выводит на экран игровое поле и сообщает, чей сейчас ход
//
//        if (turn == 'X')
//        {
//            // Ход игрока
//            int row, col;
//            cout << "Введите номер строки и столбца:";
//            cin >> row >> col;
//            row--;
//            col--;
//            if (board[row][col] != ' ') {
//                cout << "Эта клетка уже занята!" << endl;
//                continue;
//            }
//            board[row][col] = turn;
//        }
//        else {
//            // Ход программы
//            int row, col;
//            row = -1;
//            col = -1;
//            // Ищем свободную клетку, которая позволит сделать ход, приводящий к выигрышу
//            for (int i = 0; i < SIZE; i++)
//            {
//                for (int j = 0; j < SIZE; j++)
//                {
//                    if (board[i][j] == ' ')
//                    {
//                        board[i][j] = turn;
//                        if (isWinner(board, turn))
//                        {
//                            row = i;
//                            col = j;
//                            break;
//                        }
//                        board[i][j] = ' ';
//                    }
//                }
//                if (row != -1)
//                {
//                    break;
//                }
//            }
//            // Если свободная клетка не найдена, делаем случайный ход
//            if (row == -1)
//            {
//                while (board[row][col] != ' ')
//                {
//                    row = rand() % SIZE;
//                    col = rand() % SIZE;
//                }
//            }
//            board[row][col] = turn;
//        }
//
//        turn = (turn == 'X') ? 'O' : 'X';
//    }
//
//    drawBoard(board);
//    if (isWinner(board, 'X'))
//    {
//        cout << "Победил X!" << endl;
//
//    }
//    else if (isWinner(board, 'O'))
//    {
//        cout << "Победил O!" << endl;
//    }
//    else
//    {
//        cout << "Ничья!" << endl;
//    }
//
//    return 0;
//}