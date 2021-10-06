
# IMPORT NEEDED LIBRARIES
from math import inf
from random import choice


# BOARD CONFIGARATION

board = [[0, 0, 0],
         [0, 0, 0],
         [0, 0, 0]]


# GAME CONFIGURATION PRINT AT RUNTIME
def Gameboard(board):
    chars = {1: 'X', -1: 'O', 0: ' '}
    for x in board:
        for y in x:
            ch = chars[y]
            print(f'| {ch} |', end='')
        print('\n' + '---------------')
    print('===============')


# FUNCTION TO CLEAR BOARD
def Clearboard(board):
    for x, row in enumerate(board):
        for y, col in enumerate(row):
            board[x][y] = 0



def winningPlayer(board, player):
    conditions = [[board[0][0], board[0][1], board[0][2]],
                     [board[1][0], board[1][1], board[1][2]],
                     [board[2][0], board[2][1], board[2][2]],
                     [board[0][0], board[1][0], board[2][0]],
                     [board[0][1], board[1][1], board[2][1]],
                     [board[0][2], board[1][2], board[2][2]],
                     [board[0][0], board[1][1], board[2][2]],
                     [board[0][2], board[1][1], board[2][0]]]

    if [player, player, player] in conditions:
        return True

    return False



def gameWon(board):
    return winningPlayer(board, 1) or winningPlayer(board, -1)


# FUNCTION TO PRINT THE RESULTS
def printResult(board):
    if winningPlayer(board, 1):
        Gameboard(board)
        print('YOU HAVE WON, CONGRATULATIONS!' + '\n')

    elif winningPlayer(board, -1):
        print('YOU LOOSE! BETTER LUCK NEXT TIME' + '\n')

    else:
        Gameboard(board)
        print('ITS A DRAW' + '\n')


# CHECK THE BLANK BOXES AT ANY POINT OF TIME
def blanks(board):
    blank = []
    for x, row in enumerate(board):
        for y, col in enumerate(row):
            if board[x][y] == 0:
                blank.append([x, y])

    return blank


# FUNCTION TO CHECK IF THE BOARD IS ALREADY FULL
def boardFull(board):
    if len(blanks(board)) == 0:
        return True
    return False

# FUNCTION TO IMPLEMENT THE PLAYER MOVE
def setMove(board, x, y, player):
    board[x][y] = player


# FUNCTION TO INPUT THE MOVE
def playerMove(board):
    e = True
    moves = {1: [0, 0], 2: [0, 1], 3: [0, 2],
             4: [1, 0], 5: [1, 1], 6: [1, 2],
             7: [2, 0], 8: [2, 1], 9: [2, 2]}
    while e:
        try:
            move = int(input('ENTER A NUMBER BETWEEN 1-9: '))
            if move < 1 or move > 9:
                print('OOPS! INVALID VALID MOVE, TRY AGAIN.')
            elif not (moves[move] in blanks(board)):
                print('OOPS! INVALID VALID MOVE, TRY AGAIN.')
            else:
                setMove(board, moves[move][0], moves[move][1], 1)
                # Gameboard(board) 
                e = False
        except(KeyError, ValueError):
            print('ENTER A NUMBER: ')



def getScore(board):
    if winningPlayer(board, 1):
        return 10
    elif winningPlayer(board, -1):
        return -10
    else:
        return 0



def abminimax(board, depth, alpha, beta, player):
    row = -1
    col = -1
    if depth == 0 or gameWon(board):
        return [row, col, getScore(board)]
    else:
        for cell in blanks(board):
            setMove(board, cell[0], cell[1], player)
            score = abminimax(board, depth - 1, alpha, beta, -player)
            if player == 1:
                # X is always the max player
                if score[2] > alpha:
                    alpha = score[2]
                    row = cell[0]
                    col = cell[1]

            else:
                if score[2] < beta:
                    beta = score[2]
                    row = cell[0]
                    col = cell[1]

            setMove(board, cell[0], cell[1], 0)

            if alpha >= beta:
                break

        if player == 1:
            return [row, col, alpha]
        else:
            return [row, col, beta]



def o_comp(board):
    if len(blanks(board)) == 9:
        x = choice([0, 1, 2])
        y = choice([0, 1, 2])
        setMove(board, x, y, -1)
        Gameboard(board)
    else:
        result = abminimax(board, len(blanks(board)), -inf, inf, -1)
        setMove(board, result[0], result[1], -1)
        Gameboard(board)



def x_comp(board):
    if len(blanks(board)) == 9:
        x = choice([0, 1, 2])
        y = choice([0, 1, 2])
        setMove(board, x, y, 1)
        Gameboard(board)

    else:
        result = abminimax(board, len(blanks(board)), -inf, inf, 1)
        setMove(board, result[0], result[1], 1)
        Gameboard(board)



# FUNCTION TO MAKE A MOVE

def makeMove(board, player, mode):
    if mode == 1:
        if player == 1:
            playerMove(board)

        else:
            o_comp(board)
    else:
        if player == 1:
            o_comp(board)
        else:
            x_comp(board)



# DRIVER FUNCTION
def main():

    print("***************** TIC TAC TOE USING ALPHA BETA PRUNNING *****************\n")

    # THE HUMAN PLAYER WILL ALWAYS BE X
    # I.E IT WILL ALWAYS PLAY FIRST
    currentPlayer = 1

    print("YOU WILL BE PLAYING AS X\n")
    while not (boardFull(board) or gameWon(board)):
        makeMove(board, currentPlayer, 1)
        currentPlayer *= -1

    printResult(board)



main()
