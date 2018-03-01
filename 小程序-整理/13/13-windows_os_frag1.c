//#Safe
// ****************************************************
//
//     Making Prophecies with Decision Predicates
//
//              Byron Cook * Eric Koskinen
//                     July 2010
//
// ****************************************************

//@ ltl invariant positive: [](AP(a!= 0) ==> <>AP(r != 0));

//extern void __VERIFIER_error() __attribute__((__noreturn__));
//extern void __VERIFIER_assume();
//extern int __VERIFIER_nondet_int();
#include <stdlib.h>
#define NTSTATUS int
#define STATUS_CANCELLED 2
#define STATUS_UNSUCCESSFUL 1
#define STATUS_SUCCESS 1
#define STATUS_TIMEOUT 3
#define SERIAL_TIMEOUTS int
#define PLIST_ENTRY int
#define PIRP int
#define KIRQL int
#define ULONG int
#define PIO_STACK_LOCATION int
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

#include<stdio.h>

int a; int r;
int irql;
int csl;
NTSTATUS          status;
KIRQL             OldIrql;
SERIAL_TIMEOUTS   CurrentTimeouts;
int lock;
int k;
PLIST_ENTRY         ListElement;
PIRP                Irp;
PIO_STACK_LOCATION  IrpSp;
KIRQL               CancelIrql;
ULONG             BytesToMove;
ULONG             FirstHalf;
ULONG             SecondHalf;
BOOLEAN           LockHeld;




void KeAcquireSpinLock(int * lp, int * ip) {
	(*lp) = 1;
	(*ip) = irql;
}

void KeReleaseSpinLock(int * lp, int i) {
	(*lp) = 0;
	irql = i;
}


void IoAcquireCancelSpinLock(int * ip) {
	csl = 1;
	(*ip) = irql;
}

void IoReleaseCancelSpinLock(int ip) {
	csl = 0;
	irql = ip;
}

int IoGetCurrentIrpStackLocation(int a) { int rand_x = rand();  return rand_x; }

void RemoveReferenceAndCompleteRequest(int a, int b) {}

void main()
{
	//A = R = 0;
	status = STATUS_UNSUCCESSFUL;
	CurrentTimeouts = rand();
	k = rand();
	
	a = 1; 
	a = 0; // KeAcquireSpinLock( &lock, &OldIrql);

	
	int rand_x=rand();
	int rand_x1=rand();
	int rand_x2=rand();
	while ((rand_x && k>0) && (rand_x1 || rand_x2)) {

		ListElement = rand();
		Irp = rand();
		IrpSp = rand();
		CancelIrql = rand();

		k--;

		Irp = rand();

		IoAcquireCancelSpinLock(&CancelIrql);

		int rand_x3 = rand();
		if (rand_x3) {

			IoReleaseCancelSpinLock(CancelIrql);

			continue;
		}

		// IoSetCancelRoutine(Irp, NULL);
		IoReleaseCancelSpinLock(CancelIrql);
		r = 1; r = 0; // KeReleaseSpinLock(&lock, OldIrql);

		//CALL TO TryToSatisfyRead( deviceExtension);
		{
			status = STATUS_UNSUCCESSFUL;
			Irp = NULL;
			LockHeld = TRUE;

			a = 1; a = 0; //KeAcquireSpinLock(&lock,&OldIrql);

			int rand_x4 = rand();
			int rand_x5 = rand();
			if (rand_x4 && rand_x5) {
				//
				//  there is an IRP and there are characters waiting
				//
				Irp = rand();

				IrpSp = IoGetCurrentIrpStackLocation(Irp);

				BytesToMove = rand();

				int rand_x6 = rand();
				if (rand_x6) {
					FirstHalf = rand();

					SecondHalf = BytesToMove - FirstHalf;


				}
				else {
				}
			}
			else
			{
				int rand_x7 = rand();
				if (rand_x7)
				{
					Irp = rand();


					IoAcquireCancelSpinLock(&CancelIrql);

					int rand_x8 = rand();
					if (rand_x8)
					{
						IoReleaseCancelSpinLock(CancelIrql);

						r = 1; r = 0; // KeReleaseSpinLock( &lock, OldIrql);

						RemoveReferenceAndCompleteRequest(Irp,
							STATUS_CANCELLED);
						LockHeld = FALSE;
					}
					else
					{
						CurrentTimeouts = rand();

						int rand_x8 = rand();
						if (rand_x8)
						{
							IoReleaseCancelSpinLock(CancelIrql);

							r = 1; r = 0; // KeReleaseSpinLock( &lock, OldIrql);

							RemoveReferenceAndCompleteRequest(
								Irp, STATUS_TIMEOUT);

							LockHeld = FALSE;
						}
						else
						{
							IoReleaseCancelSpinLock(CancelIrql);
							k--;
						}
					}

					Irp = NULL;
				}

			}

			if (LockHeld == 1)
			{
				r = 1; r = 0; //KeReleaseSpinLock( &lock, OldIrql);
			}

			if (Irp != 0) {
				//
				//  if irp isn't null, then we handled one
				//
				RemoveReferenceAndCompleteRequest(Irp, STATUS_SUCCESS);


			}



		}
		//-------------------------------------------------------------
		a = 1; a = 0; // KeAcquireSpinLock(&lock, &OldIrql)
	}

	r = 1; r = 0; //KeReleaseSpinLock( &lock, OldIrql);

	while (1) {
		{ int ddd=0; ddd = ddd; }
	}
}
