frame(a,r,fp_values,fp_executionPath) and (
FILE* fp_executionPath <== fopen("executionPath.txt", "w") and skip;
//FILE * file <== freopen("D:\\Evalues.txt", "r", stdin) and skip;
FILE * fp_values <== fopen("values.txt", "r") and skip;
int a<==0 and skip;
int r<==0 and skip;
 function main ( int RValue )
 {
     frame(main_n,main_rand_x,main_3_x,return) and (
     int return<==0 and skip;
     int main_n and skip;
     int main_rand_x and skip;
     //main_rand_x:=rand(RValue);
	 fscanf(fp_values, "%d", &main_rand_x) and skip;
     while( main_rand_x)
     {
         fputs("[rand_x]#" ,fp_executionPath ) and skip;
         a:=1;
         a:=0;
         //main_n:=rand(RValue);
		 fscanf(fp_values, "%d", &main_n) and skip;
         while( main_n>0)
         {
              fputs("[n>0]#" ,fp_executionPath ) and skip;
              main_n:=main_n-1
         };
         fputs("[!(n>0)]#",fp_executionPath) and skip ;
         r:=1;
         r:=0
     };
     fputs("[!(rand_x)]#",fp_executionPath) and skip ;
    /* while( 1)
     {
          fputs("[1]\n" ,fp_executionPath ) and skip;
         int main_3_x and skip;
         main_3_x:=main_3_x
     };*/
     fputs("[!(1)]#",fp_executionPath) and skip ;
     return<==1 and RValue:=0;
     skip
     )
 };
  main(RValue)
 )
