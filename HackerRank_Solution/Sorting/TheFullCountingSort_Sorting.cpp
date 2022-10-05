/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */

void countSort(vector<vector<string>> arr) {
    int size = arr.size();
    unordered_map<string, vector<string>> sortedArr(100);
    int index = 0;
    for(;index < size/2; index++){
        arr[index][1] = '-';
        sortedArr[arr[index][0]].push_back(arr[index][1]);
    }
    for(;index < size; index++){
        sortedArr[arr[index][0]].push_back(arr[index][1]);
    }
    
    for(int index = 0; index < 100; index++){
        if(!sortedArr[to_string((index))].empty()){
            for(auto ele : sortedArr[to_string(index)]){
                cout << ele << " ";
            }
        }
    }
    cout << endl;
}