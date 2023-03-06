class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        
        int totX = 0, totO = 0;
        //check on columns and rows winners
        bool winFirst = 0, winSecond = 0;
        for(int i = 0; i < board.size(); ++i)
        {
            if(board[i] == "XXX")
                winFirst = 1;
            if(board[i] == "OOO")
                winSecond = 1;
        }
        for(int j = 0; j < board[0].size(); ++j)
        {
            int cntX = 0, cntO = 0;
            for(int i = 0; i < board.size(); ++i)
            {
                cntX += (board[i][j] == X)? 1:0;
                cntO += (board[i][j] == O)? 1:0;
            }
            if(cntX == 3)
                winFirst = 1;
            if(cntO == 3)
                winSecond = 1;
            totX += cntX, totO += cntO;
        }
        //check the diagonals
        int cntX1 = 0, cntX2 = 0, cntO1 = 0, cntO2 = 0;
        for(int i = 0; i < board.size(); ++i)
        {
            
            cntX1 += (board[i][i] == X)? 1:0;
            cntX2 += (board[i][board.size() - 1 - i] == X)? 1:0;
            cntO1 += (board[i][i] == O)? 1:0;
            cntO2 += (board[i][board.size() - 1 - i] == O)? 1:0;
        }
        if(cntX1 == 3 || cntX2 == 3)
            winFirst = 1;
        if(cntO1 == 3 || cntO2 == 3)
            winSecond = 1;
        
        if(winFirst && winSecond)
            return 0;
        
        if(totX - totO > 1 || totX - totO < 0)
            return 0;
        
        if(winFirst)
            return totX - totO == 1;
        
        if(winSecond)
            return totX == totO;
        
        return 1;
        
        
    }
};
