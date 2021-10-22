row_num=int(input('Enter number of rows'))
column_num=int(input('Enter the number of columns'))

for i in range(row_num):
    for j in range(0,column_num-i):
        print('*',end=' ')
        
    print()
    
