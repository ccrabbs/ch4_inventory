// ch4_inventory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "platform.h"
#include <stdlib.h>
#include <string.h>

#define	INITALS_SIZE		(3)
#define	DESCRIPTION_SIZE	(25)

static	long	get_item_number(void);
static	short	get_quanitiy(void);
static	void	get_description(char[]);
static	void	print_data(long, char *, short, char *);

int main()
{
	char	initials[INITALS_SIZE + 1] = "";
	long	item_no = 0;
	char	description[DESCRIPTION_SIZE + 1] = "";
	short	quanity = 0;

	system(CLEAR);

	puts("Enter initials:");
	gets_s(initials);

	item_no = get_item_number();

	get_description(description);

	quanity = get_quanitiy();

	print_data(item_no, description, quanity, initials);

	return 0;
}

long	get_item_number(void)
{
	long	my_number = 0;
	bool	valid_number = false;
	char	char_number[BUFSIZ + 1],
		dummy;

	while (!valid_number)
	{
		printf("Enter an item number:");
		fflush(stdin);
		gets_s(char_number);
		if (sscanf_s(char_number, "%d%c", &my_number, &dummy) == 1)
			valid_number = true;
		else
			printf("Item Number must be numeric\n");
	}
	return my_number;
}

short	get_quanitiy(void)
{
	short	my_number = 0;
	bool	valid_number = false;
	char	char_number[BUFSIZ + 1],
		dummy;

	while (!valid_number)
	{
		printf("Enter a quanity:");
		fflush(stdin);
		gets_s(char_number);
		if (sscanf_s(char_number, "%hi%c", &my_number, &dummy) == 1)
			valid_number = true;
		else
			printf("Quanity must be numeric\n");
	}
	return	my_number;
}

void	get_description(char desc[])
{
	char	work_area[BUFSIZ + 1] = "";
	int		count = 0,
		inx = 0;

	while ((count > (DESCRIPTION_SIZE + 1)) || (count == 0))
	{
		printf("Enter a Description (no more than 25 characters):");
		fflush(stdin);
		gets_s(work_area);

		for (inx = 0; inx == DESCRIPTION_SIZE || work_area[inx] != '\0'; inx++)
		{
			desc[inx] = work_area[inx];
		}
		if (inx > (DESCRIPTION_SIZE + 1))
			count = 0;
		else
			count = inx;

		desc[inx] = '\0';
	}
}

void	print_data(long item_no, char * description, short quanity, char * initials)
{
	char	title_1[] = "We've Got It, Inc.",
		title_2[] = "Inventory Report",
		heading_item[] = "Item Number",
		heading_desc[] = "Description",
		heading_quanity[] = "Quanity";

	system(CLEAR);

	printf("%40.18s\n", title_1);
	printf("%40.16s\n\n\n", title_2);
	printf("%-21s%-35s%s\n\n", heading_item, heading_desc, heading_quanity);

	printf("%-21d", item_no);
	printf("%-31s", description);
	printf("%8d\n\n", quanity);
	printf("Processed by: %s\n\n", initials);
	fflush(stdout);
}