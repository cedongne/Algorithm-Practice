/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int flippingMatrix(vector<vector<int>> matrix) {
    int size = matrix.size();
    int rowSize = size / 2;
    int colSize = rowSize;
    
    int sum = 0;
    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            int rowSeq[4] = {row, size - row - 1, row, size - row - 1};
            int colSeq[4] = {col, col, size - col - 1, size - col - 1};
            
            int max = 0;
            for(int count = 0; count < 4; count++){
                if(max < matrix[rowSeq[count]][colSeq[count]]){
                    max = matrix[rowSeq[count]][colSeq[count]];
                }
            }
            sum += max;
        }
    }
    
    return sum;
}