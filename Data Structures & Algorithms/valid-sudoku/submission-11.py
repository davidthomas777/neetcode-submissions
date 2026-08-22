class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # columns
        column_list = [[] for i in range(9)]
        for __ in board:
            col_count = 0
            row_total_nums = []
            for num in __:
                if num not in row_total_nums and num != '.':
                    row_total_nums.append(num)
                    column_list[col_count].append(num)
                elif num in row_total_nums:
                    return False
                col_count += 1

        for col in column_list:
            col_total_nums = []
            for num in col:
                if num not in col_total_nums and num != '.':
                    col_total_nums.append(num)
                elif num in col_total_nums:
                    return False
        
        miniboards = [[] for x in range(9)]
        for row in board[:3]:
            miniboards[0].extend(row[0:3])
            miniboards[1].extend(row[3:6])
            miniboards[2].extend(row[6:9])
        for row in board[3:6]:
            miniboards[3].extend(row[0:3])
            miniboards[4].extend(row[3:6])
            miniboards[5].extend(row[6:9])
        for row in board[6:9]:
            miniboards[6].extend(row[0:3])
            miniboards[7].extend(row[3:6])
            miniboards[8].extend(row[6:9])

        for element in miniboards:
            total_nums = []
            for num in element:
                if num not in total_nums and num != '.':
                    total_nums.append(num)
                elif num in total_nums:
                    return False
        
        return True
