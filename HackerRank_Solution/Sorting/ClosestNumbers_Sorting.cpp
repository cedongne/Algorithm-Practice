/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
const int MAX = 1000000000;

vector<int> closestNumbers(vector<int> arr) {
    int size = arr.size();
    sort(arr.begin(), arr.end());
    
    int minDiff = MAX;
    vector<int> answer;
    for(int index = 0; index < size - 1; index++){
        int diff = arr[index + 1] - arr[index];
        
        if(minDiff > diff){
            minDiff = diff;
            
            answer.clear();
        }
        if(minDiff == diff){
            answer.push_back(arr[index]);
            answer.push_back(arr[index + 1]);
        }
    }
    
    return answer;
}