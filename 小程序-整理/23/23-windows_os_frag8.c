//p23
//#Safe
// ****************************************************
//
//     Making Prophecies with Decision Predicates
//
//              Byron Cook * Eric Koskinen
//                     July 2010
//
// ****************************************************

//@ ltl invariant positive: <>[]AP(polling == 1);

//extern void __VERIFIER_error() __attribute__((__noreturn__));
//extern void __VERIFIER_assume();
//extern int __VERIFIER_nondet_int();
#include <stdlib.h>
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
#define CountLookup __VERIFIER_nondet_int
int WarmPollPeriod;
int status;
int polling;
int PowerStateIsAC;
int Count;
int   timeOut1;
int           deviceStatus;
int           devId;
int         requestRescan;

int main() {
	WarmPollPeriod = rand();
	status = rand();
	polling = rand();
	PowerStateIsAC = rand();
	Count = rand();
	
	
	if (status>0) {
		ExAcquireFastMutex();
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
			   int rand_x1 = rand();
			   if (rand_x1) {
				   //---------------------------------------------
				   {
					   int   timeOut1;
					   int        status;
					   int           deviceStatus;
					   int           devId;
					   int         requestRescan;
					   Count = rand();
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
							   //goto mylabl;
						   }
						   if (-1 == status) {

							   int rand_x3 = rand();
							   if (rand_x3) {
								   // try to acquire port
								   int rand_x4 = rand();
								   if (rand_x4) {
									   requestRescan = 0;
									   // check for something connected
									   deviceStatus = rand();

									   int rand_x5 = rand();
									   if (rand_x5) {
									   }
									   else {
										   // we might have something connected
										   // try a device ID to confirm
										   devId = rand();
										   if (devId) {
											   int  mfg=0, mdl=0, cls, des, aid, cid;
											   // RawIeee1284 string includes 2 bytes of length data at beginning
											   rand();
											   if (mfg && mdl) {
												   requestRescan = 1;
											   }
										   }
										   else {
										   }
										   if (requestRescan) {
										   }
										   else {
											   int rand_x6 = rand();
											   if (rand_x6) {
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
					   mylabl: { int ddd=0; ddd = ddd; }
					   } while (--Count>0);
				   }
				   //---------------------------------------------
			   }
			   else {
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