/*
============================================================================
Name : 29.c
Author : Rishabh Kumar Rai
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 08th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<sched.h>

int main(void) {
	int policy = sched_getscheduler(0);

	switch (policy) {
		case SCHED_OTHER:
			printf ("Policy is normal\n");
			break;
		case SCHED_RR:
			printf ("Policy is round-robin\n");
			break;
		case SCHED_FIFO:
			printf ("Policy is first-in, first-out\n");
			break;
		default:
			printf ("Unknown policy!\n");
	}

	struct sched_param sp;
	sp.sched_priority = 50;
	sched_setscheduler (0, SCHED_RR, &sp);
	policy = sched_getscheduler(0);

	switch (policy) {
		case SCHED_OTHER:
			printf ("Policy is normal\n");
			break;
		case SCHED_RR:
			printf ("Policy is round-robin\n");
			break;
		case SCHED_FIFO:
			printf ("Policy is first-in, first-out\n");
			break;
		default:
			printf ("Unknown policy!\n");
	}
	getchar();
	return 0;
}
