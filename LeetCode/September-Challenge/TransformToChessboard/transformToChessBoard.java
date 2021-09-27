class Solution{
	public int movesToChessboard(int board[][]){
		int n = board.length;
		int rowSwap = 0, colSwap = 0, rowCount = 0, colCount = 0;

		for(int i = 0; i < n;i++){
			for(int j = 0; j < n; j++){
				int xor = board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j];
				if(xor == 1)
					return -1;
			}
		}

		for(int i = 0; i < n; i++){
			rowSwap += board[i][0] == i % 2 ? 1 : 0;
			colSwap += board[0][i] == i % 2 ? 1 : 0;
			rowCount += board[i][0];
			colCount += board[0][i];
		}

		if( (rowCount != n / 2 && rowCount != (n + 1)/2) || (colCount != n/2 && colCount != (n+1)/2))
			return -1;

		if(n % 2 == 0){
			rowSwap = Math.min(rowSwap, n - rowSwap);
			colSwap = Math.min(colSwap, n - colSwap);
		}
		else{
			if(rowSwap % 2 == 1)
				rowSwap = n - rowSwap;
			if(colSwap % 2 == 1)
				colSwap = n - colSwap;
		}

		return (rowSwap + colSwap) / 2;
	}
}