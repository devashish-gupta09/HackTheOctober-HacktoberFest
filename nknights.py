def max_knights(rows, cols):
    #IF ANY ONE OF ROWS OR COLUMNS ARE ONE THEN, ALL CAN BE ADJACENT TO EACH OTHER AS THE KNIGHT CANT MOVE
    if (cols == 1 or rows == 1):
        if cols > rows:
            for col in range(cols-1, -1, -1):
                    chess[0][col] = 1
        else:
            for row in range(rows-1, -1, -1):
                chess[row][0] = 1

        return max(cols, rows) #number possible will be the maximum of the either row or column which

    #IF ROWS OR COLUMNS IS OF SIZE TWO
    elif (cols == 2 or rows == 2):

        #IF YES THEN LOOK FOR CONSECUTIVE ROWS OR COLS

        n_sol = (max(cols, rows) // 4) * 4

        if (max(cols, rows) % 4 == 1):

            n_sol += 2

        elif (max(cols, rows) % 4 > 1):
            n_sol += 4

        if cols > rows:
            for col in range(0, cols):
                for row in range(0, rows, 2):
                    chess[row+1][col] = 1
        else:
            for row in range(0, rows):
                for col in range(0, cols, 2):
                    chess[row][col + 1] = 1
        return n_sol

   #GENERAL CASE
    else:
        for col in range(0, cols):
            j = 1 if col % 2 == 1 else 0
            for row in range(j, rows, 2):
                chess[row][col] = 1

        return (((cols * rows) + 1) // 2)

rows = int(input('Enter the number of rows: '))
cols = int(input('Enter the number of columns: '))
chess = [[-1 for i in range(cols)]for i in range(rows)]
print(chess)
op = max_knights(rows, cols)
print('Maximum Number of knights possible on {0} x {1} chess board, such that they do not attack each other are: {2}.'.format(rows,cols,op))
for row in range(0, rows):
    for col in range(0, cols):
        if chess[row][col] == 1:
            chess[row][col] = 'N'
        else:
            chess[row][col]= '_'

print('One such possible configuration is:')
for row in range(rows):
    for col in range(cols):
        print(chess[row][col], end=' ')
    print()
