#include <unistd.h>
#define BOARD_SIZE 10


void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putbnr(int nbr)
{
    if (nbr >= 0 && nbr <= 9)
        ft_putchar(nbr + 48);
    else if (nbr == -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        ft_putbnr(147483648);
    }
    else if (nbr < 0)
    {
        ft_putchar('-');
        ft_putbnr(nbr);
    }
    else
    {
        ft_putbnr(nbr / 10);
        ft_putchar(nbr % 10 + 48);
    }
    
}

int ft_is_valid(int board[BOARD_SIZE][BOARD_SIZE], int x, int y)
{

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][x] == 1)
            return 0;
    }

    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (board[j][i] == 1)
            return 0;
    }

    for (int i = x, j = y; i < BOARD_SIZE && j >= 0; i++, j--)
    {
        if (board[j][i] == 1)
            return 0;
    }

    return 1;
}

void print_solution(int board[BOARD_SIZE][BOARD_SIZE])
{

    for (int y = 0; y < BOARD_SIZE; y++)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            if (board[y][x] == 1)
            {
                ft_putbnr(x);

                if(!(y + 1 == BOARD_SIZE))
                {
                    ft_putchar(',');
                    ft_putchar(' ');
                }
            }
        }
    }
    ft_putchar('\n');
}

void queens_rec(int board[BOARD_SIZE][BOARD_SIZE], int y)
{
    if (y == BOARD_SIZE)
    {
        print_solution(board);
        return;
    }

    for (int x = 0; x < BOARD_SIZE; x++)
    {
        if (ft_is_valid(board, x, y))
        {
            board[y][x] = 1;
            queens_rec(board, y + 1);
            board[y][x] = 0; 
        }
    }
}

void ft_ten_queens_puzzle(void)
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    queens_rec(board, 0);    
}

int main()
{
   ft_ten_queens_puzzle();

   return 0;
}
