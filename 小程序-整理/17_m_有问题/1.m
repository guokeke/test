frame(fp_executionPath,fp_values,lock1,lock2,lock3,lock4,lock5,lock6,CancelIrql,irql,csl,DeviceObject,Irp,ntStatus,deviceExtension,Irql,k1,k2,k3,k4,k5,CromData,AsyncAddressData,IsochResourceData,IsochDetachData,i,pIrb,ResourceIrp,StackSize,BusResetIrp,prevCancel,keA,keR,ioA,ioR) and (
FILE* fp_executionPath <==fopen("D:\\Eclipse-TPChecker\\expliciteCegar3\\executionPath.txt", "w") and skip;
FILE * fp_values <== fopen("D:\\Eclipse-TPChecker\\expliciteCegar3\\values.txt", "r") and skip;
int lock1 and skip;
int lock2 and skip;
int lock3 and skip;
int lock4 and skip;
int lock5 and skip;
int lock6 and skip;
int CancelIrql and skip;
int irql and skip;
int csl and skip;
int DeviceObject and skip;
int Irp and skip;
int ntStatus and skip;
int deviceExtension and skip;
int Irql and skip;
int k1 and skip;
int k2 and skip;
int k3 and skip;
int k4 and skip;
int k5 and skip;
int CromData and skip;
int AsyncAddressData and skip;
int IsochResourceData and skip;
int IsochDetachData and skip;
int i and skip;
int pIrb and skip;
int ResourceIrp and skip;
int StackSize and skip;
int BusResetIrp and skip;
int prevCancel and skip;
int keA and skip;
int keR and skip;
int ioA and skip;
int ioR and skip;
 function KeAcquireSpinLock ( int *lp,int *ip )
 {
     keA:=1;
     keA:=0;
     * lp:=1;
     * ip:=irql
     
 };
 function KeReleaseSpinLock ( int *lp,int i )
 {
     keR:=1;
     keR:=0;
     * lp:=0;
     irql:=i
     
 };
 function IoAcquireCancelSpinLock ( int *ip )
 {
     ioA:=1;
     ioA:=0;
     csl:=1;
     * ip:=irql
     
 };
 function IoReleaseCancelSpinLock ( int ip )
 {
     ioR:=1;
     ioR:=0;
     csl:=0;
     irql:=ip
     
 };
 function t1394_IsochCleanup ( int a,int RValue )
 {
     frame(t1394_IsochCleanup_rand_x,return) and ( 
     int return<==0 and skip;
     int t1394_IsochCleanup_rand_x and skip;
     t1394_IsochCleanup_rand_x:=rand(RValue);
     return<==1 and RValue:=t1394_IsochCleanup_rand_x;
     skip
     )
     }; 
  function ExAllocatePool ( int a,int b,int RValue )
 {
     frame(ExAllocatePool_rand_x,return) and ( 
     int return<==0 and skip;
     int ExAllocatePool_rand_x and skip;
     ExAllocatePool_rand_x:=rand(RValue);
     return<==1 and RValue:=ExAllocatePool_rand_x;
     skip
     )
     }; 
  function t1394Diag_PnpStopDevice ( int a,int b,int RValue )
 {
     frame(t1394Diag_PnpStopDevice_rand_x,return) and ( 
     int return<==0 and skip;
     int t1394Diag_PnpStopDevice_rand_x and skip;
     t1394Diag_PnpStopDevice_rand_x:=rand(RValue);
     return<==1 and RValue:=t1394Diag_PnpStopDevice_rand_x;
     skip
     )
     }; 
  function t1394_SubmitIrpSynch ( int a,int b,int RValue )
 {
     frame(t1394_SubmitIrpSynch_rand_x,return) and ( 
     int return<==0 and skip;
     int t1394_SubmitIrpSynch_rand_x and skip;
     t1394_SubmitIrpSynch_rand_x:=rand(RValue);
     return<==1 and RValue:=t1394_SubmitIrpSynch_rand_x;
     skip
     )
     }; 
  function IoFreeIrp ( int a,int RValue )
 {
     frame(IoFreeIrp_rand_x,return) and ( 
     int return<==0 and skip;
     int IoFreeIrp_rand_x and skip;
     IoFreeIrp_rand_x:=rand(RValue);
     return<==1 and RValue:=IoFreeIrp_rand_x;
     skip
     )
     }; 
  function IoSetDeviceInterfaceState ( int RValue )
 {
     frame(IoSetDeviceInterfaceState_rand_x,return) and ( 
     int return<==0 and skip;
     int IoSetDeviceInterfaceState_rand_x and skip;
     IoSetDeviceInterfaceState_rand_x:=rand(RValue);
     return<==1 and RValue:=IoSetDeviceInterfaceState_rand_x;
     skip
     )
     }; 
  function RtlZeroMemory ( int a,int b,int RValue )
 {
     frame(RtlZeroMemory_rand_x,return) and ( 
     int return<==0 and skip;
     int RtlZeroMemory_rand_x and skip;
     RtlZeroMemory_rand_x:=rand(RValue);
     return<==1 and RValue:=RtlZeroMemory_rand_x;
     skip
     )
     }; 
  function KeCancelTimer ( int RValue )
 {
     frame(KeCancelTimer_rand_x,return) and ( 
     int return<==0 and skip;
     int KeCancelTimer_rand_x and skip;
     KeCancelTimer_rand_x:=rand(RValue);
     return<==1 and RValue:=KeCancelTimer_rand_x;
     skip
     )
     }; 
  function IoAllocateIrp ( int a,int b,int RValue )
 {
     frame(IoAllocateIrp_rand_x,return) and ( 
     int return<==0 and skip;
     int IoAllocateIrp_rand_x and skip;
     IoAllocateIrp_rand_x:=rand(RValue);
     return<==1 and RValue:=IoAllocateIrp_rand_x;
     skip
     )
     }; 
  function IoFreeMdl ( int RValue )
 {
     frame(IoFreeMdl_rand_x,return) and ( 
     int return<==0 and skip;
     int IoFreeMdl_rand_x and skip;
     IoFreeMdl_rand_x:=rand(RValue);
     return<==1 and RValue:=IoFreeMdl_rand_x;
     skip
     )
     }; 
  function IoSetCancelRoutine ( int a,int RValue )
 {
     frame(IoSetCancelRoutine_rand_x,return) and ( 
     int return<==0 and skip;
     int IoSetCancelRoutine_rand_x and skip;
     IoSetCancelRoutine_rand_x:=rand(RValue);
     return<==1 and RValue:=IoSetCancelRoutine_rand_x;
     skip
     )
     }; 
  function ExFreePool0 ( int RValue )
 {
     frame(ExFreePool0_rand_x,return) and ( 
     int return<==0 and skip;
     int ExFreePool0_rand_x and skip;
     ExFreePool0_rand_x:=rand(RValue);
     return<==1 and RValue:=ExFreePool0_rand_x;
     skip
     )
     }; 
  function ExFreePool1 ( int a,int RValue )
 {
     frame(ExFreePool1_rand_x,return) and ( 
     int return<==0 and skip;
     int ExFreePool1_rand_x and skip;
     ExFreePool1_rand_x:=rand(RValue);
     return<==1 and RValue:=ExFreePool1_rand_x;
     skip
     )
     }; 
  function ExFreePool2 ( int a,int b,int RValue )
 {
     frame(ExFreePool2_rand_x,return) and ( 
     int return<==0 and skip;
     int ExFreePool2_rand_x and skip;
     ExFreePool2_rand_x:=rand(RValue);
     return<==1 and RValue:=ExFreePool2_rand_x;
     skip
     )
     }; 
  function IoCompleteRequest ( int a,int RValue )
 {
     frame(IoCompleteRequest_rand_x,return) and ( 
     int return<==0 and skip;
     int IoCompleteRequest_rand_x and skip;
     IoCompleteRequest_rand_x:=rand(RValue);
     return<==1 and RValue:=IoCompleteRequest_rand_x;
     skip
     )
     }; 
  function main ( int RValue )
 {
     frame(main_rand_x,main_2_3_rand_x1,main_2_3_rand_x2,main_6_rand_x3,main_6_rand_x4,main_6_rand_x5,break$) and (
     int break$<==0 and skip;
     keA:=0;
     keR:=0;
     int main_rand_x and skip;
     main_rand_x:=rand(RValue);
     if(main_rand_x!=0) then 
     {
          fputs("[rand_x!=0]\n",fp_executionPath) and skip;
         ntStatus:=t1394Diag_PnpStopDevice(DeviceObject,Irp,RValue)
         
     }
     else 
     {
          fputs("[!(rand_x!=0)]\n",fp_executionPath) and skip 
     };
     ntStatus:=IoSetDeviceInterfaceState(RValue);
     keA:=1;
     keA:=0;
     KeAcquireSpinLock(&lock3,&Irql);
     k1:=rand(RValue);
     while( k1>0)
     {
          fputs("[k1>0]\n" ,fp_executionPath ) and skip;
         CromData:=rand(RValue);
         k1:=k1-1;
         if(CromData!=0) then 
         {
              fputs("[CromData!=0]\n",fp_executionPath) and skip;
             int main_2_3_rand_x1 and skip;
             main_2_3_rand_x1:=rand(RValue);
             if(main_2_3_rand_x1!=0) then 
             {
                  fputs("[rand_x1!=0]\n",fp_executionPath) and skip;
                 ExFreePool0(RValue)
             }
             else 
             {
                  fputs("[!(rand_x1!=0)]\n",fp_executionPath) and skip 
             };
             int main_2_3_rand_x2 and skip;
             main_2_3_rand_x2:=rand(RValue);
             if(main_2_3_rand_x2!=0) then 
             {
                  fputs("[rand_x2!=0]\n",fp_executionPath) and skip;
                 IoFreeMdl(RValue)
             }
             else 
             {
                  fputs("[!(rand_x2!=0)]\n",fp_executionPath) and skip 
             };
             ExFreePool1(CromData,RValue)
             
         }
         else 
         {
              fputs("[!(CromData!=0)]\n",fp_executionPath) and skip
         }
     };
     fputs("[!(k1>0)]\n",fp_executionPath) and skip ;
     keR:=1;
     keR:=0;
     KeReleaseSpinLock(&lock3,Irql);
     keA:=1;
     keA:=0;
     KeAcquireSpinLock(&lock1,&Irql);
     k2:=rand(RValue);
     while( k2>0)
     {
          fputs("[k2>0]\n" ,fp_executionPath ) and skip;
         AsyncAddressData:=rand(RValue);
         AsyncAddressData:=rand(RValue);
         k2:=k2-1;
         int main_6_rand_x3 and skip;
         main_6_rand_x3:=rand(RValue);
         if(main_6_rand_x3!=0) then 
         {
              fputs("[rand_x3!=0]\n",fp_executionPath) and skip;
             IoFreeMdl(RValue)
         }
         else 
         {
              fputs("[!(rand_x3!=0)]\n",fp_executionPath) and skip 
         };
         int main_6_rand_x4 and skip;
         main_6_rand_x4:=rand(RValue);
         if(main_6_rand_x4!=0) then 
         {
              fputs("[rand_x4!=0]\n",fp_executionPath) and skip;
             ExFreePool0(RValue)
         }
         else 
         {
              fputs("[!(rand_x4!=0)]\n",fp_executionPath) and skip 
         };
         int main_6_rand_x5 and skip;
         main_6_rand_x5:=rand(RValue);
         if(main_6_rand_x5!=0) then 
         {
              fputs("[rand_x5!=0]\n",fp_executionPath) and skip;
             ExFreePool0(RValue)
         }
         else 
         {
              fputs("[!(rand_x5!=0)]\n",fp_executionPath) and skip 
         };
         if(AsyncAddressData!=0) then 
         {
              fputs("[AsyncAddressData!=0]\n",fp_executionPath) and skip;
             ExFreePool0(RValue)
         }
         else 
         {
              fputs("[!(AsyncAddressData!=0)]\n",fp_executionPath) and skip
         }
     };
     fputs("[!(k2>0)]\n",fp_executionPath) and skip ;
     keR:=1;
     keR:=0;
     KeReleaseSpinLock(&lock1,Irql);
     break$<==0 and skip;
     while( break$=0 AND   1)
     {
          fputs("[1]\n" ,fp_executionPath ) and skip;
         keA:=1;
         keA:=0;
         KeAcquireSpinLock(&lock4,&Irql);
         k3:=rand(RValue);
         if(k3>0) then 
         {
              fputs("[k3>0]\n",fp_executionPath) and skip;
             IsochDetachData:=rand(RValue);
             i:=rand(RValue);
             IsochDetachData:=rand(RValue);
             k3:=k3-1;
             KeCancelTimer(RValue);
             keR:=1;
             keR:=0;
             KeReleaseSpinLock(&lock4,Irql);
             t1394_IsochCleanup(IsochDetachData,RValue)
         }
         else
         {
              fputs("[!(k3>0)]\n",fp_executionPath) and skip;
             keR:=1;
             keR:=0;
             KeReleaseSpinLock(&lock4,Irql);
             break$<==1 and skip
          }
     };
     break$<==0 and skip;
     fputs("[!(1)]\n",fp_executionPath) and skip ;
     k4:=rand(RValue);
     break$<==0 and skip;
	
     while( break$=0 AND   1)
     {
          fputs("[1]\n" ,fp_executionPath ) and skip;
         keA:=1;
         keA:=0;
         KeAcquireSpinLock(&lock5,&Irql);
         if(k4>0) then 
         {
              fputs("[k4>0]\n",fp_executionPath) and skip;
             IsochResourceData:=rand(RValue);
             k4:=k4-1;
             keR:=1;
             keR:=0;
             KeReleaseSpinLock(&lock5,Irql);
             if(IsochResourceData!=0) then 
             {
                  fputs("[IsochResourceData!=0]\n",fp_executionPath) and skip;
                 pIrb:=rand(RValue);
                 ResourceIrp:=rand(RValue);
                 StackSize:=rand(RValue);
                 ResourceIrp:=IoAllocateIrp(StackSize,0,RValue);
                 if(ResourceIrp=NULL) then 
                 {
                      fputs("[ResourceIrp==NULL]\n",fp_executionPath) and skip;
                     skip
                 }
                 else
                 {
                      fputs("[!(ResourceIrp==NULL)]\n",fp_executionPath) and skip;
                     pIrb:=ExAllocatePool(1,4,RValue);
                     if(!pIrb) then 
                     {
                          fputs("[!pIrb]\n",fp_executionPath) and skip;
                         IoFreeIrp(ResourceIrp,RValue)
                     }
                     else
                     {
                          fputs("[!(!pIrb)]\n",fp_executionPath) and skip;
                         RtlZeroMemory(pIrb,4,RValue);
                         ntStatus:=t1394_SubmitIrpSynch(ResourceIrp,pIrb,RValue);
                         ExFreePool1(pIrb,RValue);
                         IoFreeIrp(ResourceIrp,RValue)
                     }
                 }
                 
             }
             else 
             {
                  fputs("[!(IsochResourceData!=0)]\n",fp_executionPath) and skip
             }
         }
         else
         {
              fputs("[!(k4>0)]\n",fp_executionPath) and skip;
             keR:=1;
             keR:=0;
             KeReleaseSpinLock(&lock5,Irql);
             break$<==1 and skip
          }
     };
	 
     break$<==0 and skip;
     fputs("[!(1)]\n",fp_executionPath) and skip ;
     keA:=1;
     keA:=0;
     KeAcquireSpinLock(&lock6,&Irql);
     k5:=rand(RValue);
     while( k5>0)
     {
          fputs("[k5>0]\n" ,fp_executionPath ) and skip;
         prevCancel:=NULL;
         BusResetIrp:=rand(RValue);
         k5:=k5-1;
         prevCancel:=IoSetCancelRoutine(NULL,RValue);
         IoCompleteRequest(2,RValue);
         ExFreePool1(BusResetIrp,RValue)
     };
	 
     fputs("[!(k5>0)]\n",fp_executionPath) and skip ;
     keR:=1;
     keR:=0;
     KeReleaseSpinLock(&lock6,Irql)
     )
 };
  main(RValue);
 
  fclose(fp_executionPath) and skip;
  fclose(fp_values) and skip
 )
