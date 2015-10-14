#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
    srand((unsigned) time(NULL));   //時間による乱数生成
    int n,i,j;
    int *team;
    char *a,*b,*tmp;
    printf("チーム数 = ");
    scanf( "%d", &n );
    team = (int *)malloc( sizeof( int ) * n );	//配列teamを動的確保
    
    //チーム名を配列teamに代入
    for(i=0;i<n;i++){
        team[i] = i;
    }
    
    //実行ごとに違う組み合わせになるようにランダムに入れ替え
    
    for(i=0;i<n;i++){
        int ran = rand()%n;
        int t = team[i];
        team[i] = team[ran];
        team[ran] = t;
    }
    
    
    //組み合わせ表を作成
    for(i=0;i<n-1;i++){
        a = "A";
        b = "H";
        printf("第%d節\n",i+1);
        for(j=0;j<n/2-1;j++){
            printf("[%s]%2d - %2d[%s]\n",b,team[(j+i+1)%(n-1)],team[(n-j-2+i)%(n-1)],a);
            tmp = a;
            a = b;
            b = tmp;
        }
        if(i==0){
            a = "H";
            b = "A";
        }else if(i%2!=0){
            a = "H";
            b = "A";
        }else{
            a = "A";
            b = "H";
        }
        printf("[%s]%2d - %2d[%s]\n",b,team[i],team[n-1],a);
        printf("\n");

    }
    
    //メモリの解放
    free( team );
}
