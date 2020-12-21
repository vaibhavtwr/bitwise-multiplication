#include<stdio.h>
#include<math.h>
int output_ha[2],output_fa[2],out[10],count,output[100];
int and_operation(int a,int b);
int binary(int num);
int binary_to_int(int num);
int halfadder(int a, int b);
int fulladder(int a, int b, int cin);
int main(){
	//variables
	int a, b, i,binary_a[10],binary_b[10],size_a,size_b,and[100][100],j=0,k=0,input[100],carry=0,l,sum,m,mult;
	
	//take input from user 
	printf("enter two digits");
	scanf("%d%d",&a,&b);
	
	//convert normal input to binary
	binary(a);
	size_a = count;
	for(i=0;i<size_a;i++)
		binary_a[i] = out[i];

	binary(b);
	size_b = count;
	for(i=0;i<size_b;i++)
		binary_b[i] = out[i];

	//and operation for all input bytes
	for(i=0;i<size_b;i++){
		for(j=size_a-1;j>= 0;j--){
		and[i][j] = and_operation(binary_a[j] , binary_b[i]);
		}
	}

	// main logic
	for(i=0;i<size_b;i++){
		k=0;
		l=0;
		if(i==0){
			for(j=size_a-1;j>=0;j--){
				halfadder(carry,and[i][j]);
				input[k] = output_ha[0];
				carry = output_ha[1];
				k++;
			}
			input[k] = carry;
		}
		else{
			for(j=size_a-1;j>-1;j--){	
				if(k==0){	
					halfadder(0,and[i][j]);
					output[k] = output_ha[0];
					carry = output_ha[1];
					k++;
				}
				else if(k<size_a && k!=0){
					fulladder(input[l],and[i][j],carry);
					output[k] = output_fa[0];
					k++;
					l++;
					carry = output_fa[1];
				}
			}
			for(m=0;m<2*i;m++){
				halfadder(input[l],carry);
				output[k] = output_ha[0];
				carry = output_ha[1];
				k++;
				l++;					
			}
			for(m=0;m<k;m++)
				input[m] = output[m];
		}
	}
	printf("binary output : ");
	for(i=k+1;i>=0;i--)
		printf("%d,",output[i]);
	mult = binary_to_int(k+1);
	printf("\ninteger output:  %d",mult);
	return(0);	
}
int binary_to_int(int size){
	int sum=0,i,power,p;
	for(i=0;i<size;i++){
		power = 0;
		power = output[i] * pow(2,i);
		sum+=power;
	}
	return(sum);
}

int binary(int num){
	int binary_num[10],end_num,start=0,i,temp,l;
	count = 0;
	for(i=0;i<10;i++)
		out[i] = -1;
	for(i=0;num>0;i++){
		binary_num[i]=num %2;
		num = num/2;
		count++;
	}
	end_num =l= i-1;
	while(start<end_num){
		temp = binary_num[start];
		binary_num[start] = binary_num[end_num];
		binary_num[end_num]=temp;
		start++;
		end_num--;
	}
	for(i=0;i<=l;i++)
		out[i]=binary_num[i];
}
int fulladder(int a, int b, int cin){
	output_fa[0] = -1;
	output_fa[1] = -1;
	if(a==0 && b==0 && cin==0){
		output_fa[0] = 0;//sum
		output_fa[1] = 0;//carry
	}
	if(a==0 && b==0 && cin==1){
		output_fa[0] = 1;
		output_fa[1] = 0;
	}
	if(a==0 && b==1 && cin==0){
		output_fa[0] = 1;
		output_fa[1] = 0;
	}
	if(a==0 && b==1 && cin==1){
		output_fa[0] = 0;
		output_fa[1] = 1;
	}
	if(a==1 && b==0 && cin==0){
		output_fa[0] = 1;
		output_fa[1] = 0;
	}
	if(a==1 && b==0 && cin==1){
		output_fa[0] = 0;
		output_fa[1] = 1;
	}
	if(a==1 && b==1 && cin==0){
		output_fa[0] = 0;
		output_fa[1] = 1;
	}
	if(a==1 && b==1 && cin==1){
		output_fa[0] = 1;
		output_fa[1] = 1;
	}
}
int and_operation(int a, int b){
	int output;
	if(a==0 && b==0)
		output=0;
	if(a==1 && b==0)
		output=0;
	if(a==0 && b==1)
		output=0;
	if(a==1 && b==1)
		output=1;
	return (output);
}
int halfadder(int a, int b){
	output_ha[0] = -1;
	output_ha[1] = -1;
	if(a==0 && b==0){
		output_ha[0] = 0;//sum
		output_ha[1] = 0;//carry
	}
	if(a==0 && b==1){
		output_ha[0] = 1;
		output_ha[1] = 0;
	}
	if(a==1 && b==0){
		output_ha[0] = 1;
		output_ha[1] = 0;
	}
	if(a==1 && b==1){
		output_ha[0] = 0;
		output_ha[1] = 1;
	}
}
	
