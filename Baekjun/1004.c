#include <stdio.h>
#include <math.h>

int main(void) {
	int t;
	int x,y;
	int d;
	scanf("%d",&t);
	
	while(t--){
		int x1,y1,x2,y2;
		int n;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d",&n);	//출발,도착점, 행성계 개수 입력받기
		int arr[n][4];
		
		for(int i=0; i<n; i++){
			scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
			arr[i][3]=0;
		}		//행성계 입력
		
		for(int i=0; i<n; i++){
			d=(arr[i][0]-x1)*(arr[i][0]-x1) + (arr[i][1]-y1)*(arr[i][1]-y1);		               
			if(arr[i][2]*arr[i][2]>d)
				arr[i][3]++;  
				
			d=(arr[i][0]-x2)*(arr[i][0]-x2) + (arr[i][1]-y2)*(arr[i][1]-y2);		          
			if(arr[i][2]*arr[i][2]>d)
				arr[i][3]++;  
			//출발점(도착점)이 행성계 안에있으면 +1
			//0이면 영향x, 1이면 더하고 2인것빼면 됨
		}
		int ans=0;
		for(int i=0; i<n; i++){
			if(arr[i][3]==1)
				ans++;
		}
		printf("%d \n" ,ans);
		
	}
	return 0;
}