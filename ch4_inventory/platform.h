#define PC		(1)
#define UNIX	(2)
#define	OTHER	(3)

#define	PLATFORM	( PC )

#if PLATFORM == PC
#define CLEAR	("cls")
#elif	PLATFORM == UNIX
#define CLEAR	("clear")
#endif