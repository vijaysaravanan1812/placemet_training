int top = 0, left = 0 ;
    int bottom = r - 1 , right  = c - 1 ;
    int dir = 0, j = 0 ;
    int * result =  new int(r*c);
    while(top <= bottom && left <= right ){
        if(dir == 0){
            for(int i = left ; i <= right; i++){
                int s = result[j] = matrix[top][i]; 
               cout<<s<<" ";
               j++;
            }
            top++;
        }
        else if(dir == 1){
            for(int i = top ; i <= bottom ; i++){
               int s =  result[j] = matrix[i][right];
               cout<<s<<" ";
               j++;
            }
            right--;
        }
        else if(dir == 2){
            for(int i = right; i >= left; i--){
                result[j] = matrix[bottom][i];
             int s = cout<<s<<" ";
               j++;
            }
            bottom--;
        }
        else if(dir == 3){
            for(int i = bottom ; i >= top ; i--){
                int s = result[j] = matrix[i][left];
               cout<<s<<" ";
               j++;
            }
            left++;
        }
        dir = dir % 4;
    }
    return result;