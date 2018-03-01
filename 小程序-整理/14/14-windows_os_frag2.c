//#Safe
// ****************************************************
//
//     Making Prophecies with Decision Predicates
//
//              Byron Cook * Eric Koskinen
//                     July 2010
//
// ****************************************************

//@ ltl invariant positive: <>[]AP(polling==1);

//extern void __VERIFIER_error() __attribute__((__noreturn__));
//extern void __VERIFIER_assume();
//extern int __VERIFIER_nondet_int();
#include <stdlib.h>
int WarmPollPeriod;
int status;
int polling;
int PowerStateIsAC;
#define NT_SUCCESS(s) s>0
#define STATUS_SUCCESS 1
#define STATUS_UNSUCCESSFUL 0
#define STATUS_TIMEOUT (-1)
#define LARGE_INTEGER int
#define NTSTATUS int
#define UCHAR int
#define PCHAR int
#define BOOLEAN int
#define ULONG int
#define NULL 0
#define FALSE 0
#define TRUE 1
void ExAcquireFastMutex() {}
void ExReleaseFastMutex() {}
#define GetStatus __VERIFIER_nondet_int
#define IoInvalidateDeviceRelations __VERIFIER_nondet_int
#define KeWaitForSingleObject __VERIFIER_nondet_int
#define P4ReadRawIeee1284DeviceId __VERIFIER_nondet_int
#define HTPnpFindDeviceIdKeys __VERIFIER_nondet_int
#define HtFreePort __VERIFIER_nondet_int
#define HtRegGetDword __VERIFIER_nondet_int
#define HtTryAllocatePort __VERIFIER_nondet_int
#define SetFlags __VERIFIER_nondet_int


int main() {
	WarmPollPeriod = rand();
	status = rand();
	polling = rand();
	PowerStateIsAC = rand();

	if (NT_SUCCESS(status)) {
		ExAcquireFastMutex();
		//SetFlags();
		rand();
		ExReleaseFastMutex();
		WarmPollPeriod = rand();
		if (WarmPollPeriod < 5) {
			WarmPollPeriod = 5;
		}
		else {
			if (WarmPollPeriod > 20) {
				WarmPollPeriod = 20;
			}
		}
	   {
		   int rand_x = rand();
		   if (rand_x) {
			   // We've got it.  Now get a pointer to it.
			   polling = 1;
			   int rand_x1 = rand();
			   if (rand_x1) {
				   //---------------------------------------------
				   {
					   LARGE_INTEGER   timeOut1;
					   NTSTATUS        status;
					   UCHAR           deviceStatus;
					   PCHAR           devId;
					   BOOLEAN         requestRescan;
					   const ULONG     pollingFailureThreshold = 10; //pick an arbitrary but reasonable number
					   do {
						   if (PowerStateIsAC) {
						   }
						   else {
						   }
						   status = rand();
						   
						   int rand_x2 = rand();
						   if (rand_x2) {
							   break;
						   }
						   if (!PowerStateIsAC) {
							   goto loc_continue;
						   }
						   if (STATUS_TIMEOUT == status) {

							   int rand_x3 = rand();
							   if (rand_x3) {
								   // try to acquire port
								   int rand_x3 = rand();
								   if (rand_x3) {
									   requestRescan = FALSE;
									   // check for something connected
									   deviceStatus = rand();
									   
									   int rand_x4 = rand();
									   if (rand_x4) {
									   }
									   else {
										   // we might have something connected
										   // try a device ID to confirm
										   devId = rand();
										   if (devId) {
											   PCHAR  mfg=0, mdl=0, cls, des, aid, cid;
											   // RawIeee1284 string includes 2 bytes of length data at beginning
											   rand();
											   if (mfg && mdl) {
												   requestRescan = TRUE;
											   }
										   }
										   else {
										   }
										   if (requestRescan) {
										   }
										   else {
											   int rand_x5 = rand();
											   if (rand_x5) {
											   }
										   }
									   }
									   rand();
									   if (requestRescan) {
										   rand();
									   }
								   }
								   else {
								   }
							   }
							   else {
							   }
						   }
					   loc_continue: { int ddd=0; ddd = ddd; }
					   } while (TRUE);
				   }
				   //---------------------------------------------
				   polling = 0;
			   }
			   else {
				   polling = 0;
				   // error
			   }
		   }
		   else {
		   }
	   }
	}
	// Failsafe
	polling = 1;
	while (1) {
		rand();
	}
}