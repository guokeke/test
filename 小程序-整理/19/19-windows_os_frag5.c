//#Safe
// ****************************************************
//
//     Making Prophecies with Decision Predicates
//
//              Byron Cook * Eric Koskinen
//                     July 2010
//
// ****************************************************

//@ ltl invariant positive: []( AP(lock == 1) ==> <>AP( lock == 0));

//extern void __VERIFIER_error() __attribute__((__noreturn__));
//extern void __VERIFIER_assume();
//extern int __VERIFIER_nondet_int();
#include<stdlib.h>
#define NTSTATUS int
#define PIRP int
#define PDEVICE_OBJECT int
#define KIRQL int
#include<stdio.h>
#define STATUS_UNSUCCESSFUL 1
#define STATUS_SUCCESS 2
#define IOCTL_SERIAL_GET_WAIT_MASK 3
#define STATUS_BUFFER_TOO_SMALL 4
#define IOCTL_SERIAL_SET_WAIT_MASK 5
#define ULONG int
#define IOCTL_SERIAL_WAIT_ON_MASK 6
#define STATUS_PENDING 7
#define IOCTL_SERIAL_PURGE 8
#define PULONG int
#define IOCTL_SERIAL_GET_MODEMSTATUS 9
#define SERIAL_PURGE_RXABORT 10
#define STATUS_CANCELLED 11
#define IOCTL_SERIAL_SET_TIMEOUTS 12
#define PSERIAL_TIMEOUTS int
#define PSERIAL_STATUS int
#define PSERIAL_BAUD_RATE int
#define SERIAL_TIMEOUTS 14
#define STATUS_INVALID_PARAMETER 15
#define IOCTL_SERIAL_GET_TIMEOUTS 16
#define IOCTL_SERIAL_SET_DTR 17
#define IOCTL_SERIAL_CLR_DTR 18
#define IOCTL_SERIAL_GET_COMMSTATUS 19
#define IOCTL_SERIAL_GET_BAUD_RATE 20
#define IOCTL_SERIAL_SET_BAUD_RATE 21
#define IOCTL_SERIAL_SET_QUEUE_SIZE 22
#define SERIAL_BAUD_RATE int
#define IOCTL_SERIAL_SET_LINE_CONTROL 23
#define UCHAR int
#define SERIAL_LINE_CONTROL int
#define PSERIAL_LINE_CONTROL int
#define SERIAL_6_DATA 24
#define SERIAL_7_DATA 25
#define SERIAL_8_DATA 26
#define SERIAL_5_DATA 27
#define NO_PARITY 28
#define SERIAL_NONE_PARITY 29
#define EVEN_PARITY 30
#define SERIAL_EVEN_PARITY 31
#define ODD_PARITY 32
#define SERIAL_ODD_PARITY 33
#define SPACE_PARITY 34
#define SERIAL_SPACE_PARITY 35
#define MARK_PARITY 36
#define SERIAL_MARK_PARITY 37
#define STOP_BIT_1 28
#define STOP_BITS_2 29
#define STOP_BIT_3 30
#define STOP_BIT_4 31
#define SERIAL_1_STOP 32
#define SERIAL_2_STOP 33
#define SERIAL_3_STOP 34
#define SERIAL_4_STOP 35
#define STOP_BITS_1_5 36
#define SERIAL_1_5_STOP 37
#define SERIAL_LCR_BREAK 38
#define IOCTL_SERIAL_GET_LINE_CONTROL 39
#define IOCTL_SERIAL_SET_RTS 40
#define STATUS_NOT_SUPPORTED 41
int lock;
int CancelIrql;
int irql;
int csl;
PIRP    CurrentWaitIrp = 0;
ULONG NewMask;
PIRP CancelIrp;
ULONG Mask;
int length;
PSERIAL_TIMEOUTS NewTimeouts;
PSERIAL_STATUS SerialStatus;
PSERIAL_BAUD_RATE pBaudRate;
PSERIAL_LINE_CONTROL pLineControl;
UCHAR LData;
UCHAR LStop;
UCHAR LParity;

int keA;
int keR;
/*
void KeAcquireSpinLock(int * lp, int * ip) {
(*lp) = 1;
(*ip) = irql;
}
*/
/*
void KeReleaseSpinLock(int * lp, int i) {
(*lp) = 0;
irql = i;
}
*/
void IoAcquireCancelSpinLock(int * ip) {
	csl = 1;
	(*ip) = irql;
}
void IoReleaseCancelSpinLock(int ip) {
	csl = 0;
	irql = ip;
}
void IoMarkIrpPending(int x) {}
// This could be modelled in more detail
void RemoveReferenceAndCompleteRequest(int x, int y) {}
// This could be modelled in more detail
void RemoveReferenceForDispatch(int x) {}
// This could be modelled in more detail
void ProcessConnectionStateChange(int x) {}
int DeviceObject;
int Irp;
NTSTATUS          status;
KIRQL             OldIrql;

NTSTATUS main()
{
	keA = 0;
	keR = 0;
	//DD: init lock with 0 to avoid trivial satisfaction
	lock = 0;
	CancelIrql = rand();
	irql = rand();
	csl = rand();
	DeviceObject = rand();
	Irp = rand();
	status = STATUS_UNSUCCESSFUL;
	OldIrql;
	status = rand();
	keA = 0;
	keR = 0;
	length = rand();
	NewTimeouts = rand();
	SerialStatus = rand();
	pBaudRate = rand();
	pLineControl = rand();
	LData = 0;
	LStop = 0;
	LParity = 0;
	Mask = 0xff;
	if (STATUS_SUCCESS != status)
	{
		while (1) { int ddd2=0; ddd2 = ddd2; }
	}

	if (1)
	{
		int rand_x = rand();
		int rand_x2 = rand();
		int rand_x4 = rand();
		int rand_x7 = rand();
		int rand_x11 = rand();
		int rand_x13 = rand();
		int rand_x16 = rand();
		int rand_x18 = rand();
		int rand_x20 = rand();
		int rand_x23 = rand();
		int rand_x25 = rand();
		int rand_x27 = rand();
		int rand_x29 = rand();
		int rand_x30 = rand();
		int rand_x31 = rand();

		if (rand_x)
		{
			int rand_x1 = rand();
			if (rand_x1)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
		}		
		else if (rand_x2)
		{
			CurrentWaitIrp = 0;
			NewMask = rand();

			int rand_x3 = rand();
			if (rand_x3)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			else
			{
				keA = 1; keA = 0;
				lock = 1; OldIrql = irql;
				NewMask = rand();
				keR = 1; keR = 0;
				lock = 0; irql = OldIrql;
				if (CurrentWaitIrp != 0)
				{
					RemoveReferenceAndCompleteRequest(CurrentWaitIrp, STATUS_SUCCESS);
				}
			}
		}
		else if (rand_x4)
		{
			CurrentWaitIrp = 0;

			int rand_x5 = rand();
			if (rand_x5)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			keA = 1; keA = 0;
			lock = 1; OldIrql = irql;
			CurrentWaitIrp = rand();

			int rand_x6 = rand();
			if (rand_x6)
			{
				status = STATUS_UNSUCCESSFUL;
			}
			else
			{
				IoMarkIrpPending(Irp);
				status = STATUS_PENDING;
			}
			keR = 1; keR = 0;
			lock = 0; irql = OldIrql;
			if (CurrentWaitIrp != 0)
			{
				RemoveReferenceAndCompleteRequest(CurrentWaitIrp, STATUS_SUCCESS);
			}
		}
		else if (rand_x7)
		{
			CancelIrp = rand();
			Mask = rand();

			int rand_x8 = rand();
			if (rand_x8)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			//DD: Changed & to && to prevent LassoRanker error
			if (Mask && SERIAL_PURGE_RXABORT)
			{
				keA = 1; keA = 0;
				lock = 1; OldIrql = irql;
				length = rand();
				while (length>0)
				{
					length--;
					CancelIrp = rand();
					IoAcquireCancelSpinLock(&CancelIrql);

					int rand_x9 = rand();
					if (rand_x9)
					{
						IoReleaseCancelSpinLock(CancelIrql);
						continue;
					}
					IoReleaseCancelSpinLock(CancelIrql);
					keR = 1; keR = 0;
					lock = 0; irql = OldIrql;
					RemoveReferenceAndCompleteRequest(CancelIrp, STATUS_CANCELLED);
					keA = 1; keA = 0;
					lock = 1; OldIrql = irql;
				}
				CancelIrp = NULL;

				int rand_x10 = rand();
				if (rand_x10)
				{
					CancelIrp = rand();
				}
				keR = 1; keR = 0;
				lock = 0; irql = OldIrql;
				if (CancelIrp != NULL)
				{
					RemoveReferenceAndCompleteRequest(CancelIrp, STATUS_CANCELLED);
				}
			}
		}
		else if (rand_x11)
		{
			int rand_x12 = rand();
			if (rand_x12)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
		}
		else if (rand_x13)
		{
			NewTimeouts = rand();
			int rand_x14 = rand();
			if (rand_x14)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}

			int rand_x15 = rand();
			if (rand_x15)
			{
				status = STATUS_INVALID_PARAMETER;
			}
			keA = 1; keA = 0;
			lock = 1; OldIrql = irql;
			keR = 1; keR = 0;
			lock = 0; irql = OldIrql;
		}
		else if (rand_x16)
		{
			int rand_x17 = rand();
			if (rand_x17)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			keA = 1; keA = 0;
			lock = 1; OldIrql = irql;
			keR = 1; keR = 0;
			lock = 0; irql = OldIrql;
		}
		else if (rand_x18)
		{
			SerialStatus = rand();

			int rand_x19 = rand();
			if (rand_x19)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			keA = 1; keA = 0;
			lock = 1; OldIrql = irql;
			keR = 1; keR = 0;
			lock = 0; irql = OldIrql;
		}
		else if (rand_x20)
		{
			keA = 1; keA = 0;
			lock = 1; OldIrql = irql;

			int rand_x21 = rand();
			if (rand_x21)
			{
			}
			else
			{
				int rand_x22 = rand();
				if (rand_x22)
				{
				}
			}
			keR = 1; keR = 0;
			lock = 0; irql = OldIrql;
			ProcessConnectionStateChange(DeviceObject);
		}
		else if (rand_x23)
		{
			int rand_x24 = rand();
			if (rand_x24)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
		}
		else if (rand_x25)
		{
			int rand_x26 = rand();
			if (rand_x26)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			else
			{
				keA = 1; keA = 0;
				lock = 1; OldIrql = irql;
				keR = 1; keR = 0;
				lock = 0; irql = OldIrql;
			}
		}
		else if (rand_x27)
		{
			pBaudRate = rand();

			int rand_x28 = rand();

			if (rand_x28)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			else
			{
				keA = 1; keA = 0;
				lock = 1; OldIrql = irql;
				keR = 1; keR = 0;
				lock = 0; irql = OldIrql;
			}
		}
		else if (rand_x29)
		{
			pLineControl = rand();
			LData = 0;
			LStop = 0;
			LParity = 0;
			Mask = 0xff;

			int rand_x30 = rand();
			if (rand_x30)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			if (1)
			{
				int rand_x31 = rand();
				int rand_x32 = rand();
				int rand_x33 = rand();
				int rand_x34 = rand();

				if (rand_x31) /* case 5:*/
				{
					LData = SERIAL_5_DATA;
					Mask = 0x1f;
				}
				else if (rand_x32) /* case 6:*/
				{
					LData = SERIAL_6_DATA;
					Mask = 0x3f;
				}
				else if (rand_x33) /* case 7:*/
				{
					LData = SERIAL_7_DATA;
					Mask = 0x7f;
				}
				else if (rand_x34) /* case 8:*/
				{
					LData = SERIAL_8_DATA;
				}
				else /*default:*/
				{
					status = STATUS_INVALID_PARAMETER;
				}
			}
			if (status != STATUS_SUCCESS)
			{
				/*break*/;
			}
			if (1)
			{
				int rand_x35 = rand();
				int rand_x36 = rand();
				int rand_x37 = rand();
				int rand_x38 = rand();
				int rand_x39 = rand();
				
				if (rand_x35)
				{
					LParity = SERIAL_NONE_PARITY;
				}
				else if (rand_x36)
				{
					LParity = SERIAL_EVEN_PARITY;
				}
				else if (rand_x37)
				{
					LParity = SERIAL_ODD_PARITY;
				}
				else if (rand_x38)
				{
					LParity = SERIAL_SPACE_PARITY;
				}
				else if (rand_x39)
				{
					LParity = SERIAL_MARK_PARITY;
				}
				else
				{
					status = STATUS_INVALID_PARAMETER;
				}
			}
			if (status != STATUS_SUCCESS)
			{

			}
			if (1)
			{
				int rand_x40 = rand();
				int rand_x41 = rand();
				int rand_x42 = rand();
				int rand_x43 = rand();
				
				if (rand_x40)
				{
					LStop = SERIAL_1_STOP;
				}
				else if (rand_x41)
				{
					if (LData != SERIAL_5_DATA)
					{
						status = STATUS_INVALID_PARAMETER;
					}
					LStop = SERIAL_1_5_STOP;
				}
				else if (rand_x42)
				{
					if (LData == SERIAL_5_DATA)
					{
						status = STATUS_INVALID_PARAMETER;
					}
					LStop = SERIAL_2_STOP;
				}
				else
				{
					status = STATUS_INVALID_PARAMETER;
				}
			}
			if (status != STATUS_SUCCESS)
			{

			}
			keA = 1; keA = 0;
			lock = 1; OldIrql = irql;
			keR = 1; keR = 0;
			lock = 0; irql = OldIrql;
		}
		else if (rand_x30)
		{
			int rand_x32 = rand();
			if (rand_x32)
			{
				status = STATUS_BUFFER_TOO_SMALL;
			}
			keA = 1; keA = 0;
			lock = 1; OldIrql = irql;
			keR = 1; keR = 0;
			lock = 0; irql = OldIrql;
		}
		else if (rand_x31)
		{
		}
		else
		{
			status = STATUS_NOT_SUPPORTED;
		}
	}
	if (status != STATUS_PENDING)
	{
		if (Irp != NULL)
		{
			RemoveReferenceAndCompleteRequest(Irp, status);
		}
	}
	RemoveReferenceForDispatch(DeviceObject);
	while (1) { int rrr=0; rrr = rrr; }
}