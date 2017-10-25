Notes for October 24, 2017

Synchronization

mutex: Mutual Exclusion Device

Is this legal code? Will it compile? Will there be a compile time error?

```C
//ThreadA		
lock(mutexA);
shared+=2;
unlock(mutexA);

shared = 1;
```
It is legal code, but it is a very bad idea

```C
//ThreadA		//ThreadB
lock(mutexA);	lock(mutexA);
shared+=2;		shared-=2;
unlock(mutexA);	unlock(mutexA);

shared = 1;
```
Who Locks?
USR

- USR has no control of scheduler
- 

SYS:

- Just too slow to context switch twice...into OS and out for mutexes

```C
//ThreadA		//ThreadB
shared = 1;	shared = 1;

int lock(int mutexNum){
	while(mutexNum!=){}
		mutexNum = 1;
		
		return 1;
}

```

Implementation Synchronization
