//[In reply to Istahak Islam]
//eita korsllam. hoise kinah janinah. dekhish parle. 
#include <stdio.h>

int main(){
    char c;
    char arr[101];
    int idx = 0;
    char ans[101][101];
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++)
            ans[i][j] = '\0';
    }
    int word = 0;
    int flag = 0;
    while(1){
        scanf("%c", &c);
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            arr[idx++] = c;
            if(flag == 0){
                flag = 1;
                word++;
            }
        }
        else{
            if(flag == 1){
                for(int i = 0; i < idx; i++){
                    ans[word-1][i] = arr[i];
                }
                flag = 0;
            }
            idx = 0;
            if(c == '\n')
                break;
        }
    }
    for(int i = 0; i < word; i++){
        for(int j = 0; j < word-i-1; j++){
            for(int k = 0; k < 101 ; k++){
                if(ans[j][k] < ans[j+1][k])
                    break;
                if(ans[j][k] > ans[j+1][k]){
                    for(int idx = 0; idx < 101; idx++){
                        char temp = ans[j][idx];
                        ans[j][idx] = ans[j+1][idx];
                        ans[j+1][idx] = temp;
                    }
                    break;
                }
            }
        }
    }
    for(int i = 0; i < word; i++){
        for(int j = 0; ans[i][j] != '\0'; j++){
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}