/*
 * pointers_to_pointers.c
 *
 *  Created on: 04-Apr-2016
 *      Author: Mrunmoy Samal
 *
 *  LICENSE:-
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */





/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */
#include<stdio.h>
/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Variables (static)
*----------------------------------------------------------------------
*/
int varB = 20;

/*
*----------------------------------------------------------------------
*   Public Constants
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Constants (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Function Prototypes (static)
*----------------------------------------------------------------------
*/
static void GetIntFromPtr(int *some_ptr);

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

/* Passing an integer pointer to a function "by-value" */
static void GetIntFromPtr(int *some_ptr)
{
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr);
	/* The value of the variable passed to this function is
	 * copied into some_ptr when this function code is executed.
	 * we can get the value passed to this function by accessing
	 * some_ptr
	 * */
	printf("The value of ptrA is: %d (passed to function by-value)\n", (int)some_ptr);
	if(some_ptr != NULL)
	{
		printf("The value at address pointed to by ptrA is: %d \n", *some_ptr);
	}
	else
	{
		printf("Null pointer exception\n");
	}
}

/* Passing an integer pointer to a function "by-reference" */
static void GetIntFromPtrToPtr(int **some_ptr_to_ptr)
{
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr_to_ptr);
	/* The value of the variable passed to this function is
	 * copied into some_ptr when this function code is executed.
	 * we can get the value passed to this function by accessing
	 * some_ptr_to_ptr.
	 *
	 * The first level of indirection using the "*" operator
	 * dereferences the pointer to point to the pointer.
	 * The second level of indirection using the "*" operator
	 * dereferences the pointer to value.
	 *
	 * */
	if (some_ptr_to_ptr != NULL)
	{
		printf("The address of ptrA is: %d (passed to function by-reference)\n", (int)*some_ptr_to_ptr);
		if (*some_ptr_to_ptr != NULL)
		{
			printf("The value at address pointed to by ptrA is: %d \n", **some_ptr_to_ptr);
		}
		else
		{
			printf("Null pointer exception\n");
		}
	}
	else
	{
		printf("Null pointer exception\n");
	}
}

/* Passing an integer to a function "by-value"
 * Modifying the value by using the pointer */
static void ModifyIntPtrByUsingValue(int *some_ptr)
{
	/* Since the variable's value is passed,
	 * we cannot modify the original variable's
	 * value, but we can modify the value of
	 * its copy which is in some_value
	 * */
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr);
	printf("The value of ptrA is: %d (passed to function by-value)\n", (int)some_ptr);
	
	if (some_ptr != NULL)
	{
		printf("The value at address pointed to by ptrA is: %d (passed to function by-value)\n", *some_ptr);
		some_ptr = &varB;
		printf("The value at address pointed to by ptrA is: %d (modified some_ptr to point to varB)\n", *some_ptr);
	}
	else
	{
		printf("Null pointer exception\n");
	}
}


/* Passing an integer to a function "by-reference"
 * Modifying the value by using the pointer */
static void ModifyIntPtrByUsingReference(int **some_ptr_to_ptr)
{
	/* Since the variable's reference is passed,
	 * we can modify the original variable's
	 * value
	 * */
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr_to_ptr);
	printf("The value of pointer to ptrA is: %d (passed to function by-reference)\n", (int)some_ptr_to_ptr);
	if (some_ptr_to_ptr != NULL)
	{
		if(*some_ptr_to_ptr != NULL)
		{
			printf("The value at address pointed to by ptrA is: %d (passed to function by-value)\n", **some_ptr_to_ptr);
			*some_ptr_to_ptr = &varB;
			printf("The value at address pointed to by ptrA is: %d (modified some_ptr to point to varB)\n", **some_ptr_to_ptr);
		}
		else
		{
			printf("Null pointer exception\n");
		}
	}
	else
	{
		printf("Null pointer exception\n");
	}
}

/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/

void PointersToPointers(void)
{
	/* define a integer variable */
	int varA; /* contains junk value because it is not initialized here */

	/* define a pointer to the integer */
	int *ptrA; /* contains junk value because it is not initialized here */

	/* define a pointer to an integer pointer */
	int **ptrToptrA; /* contains junk value because it is not initialized here */

	printf("\n-----------------------\n");
	printf("Pointer to pointers\n");
	printf("-----------------------\n\n");
	printf("%s()\n", __FUNCTION__);

	/* set some values in the integer variable */
	varA = 5; /* varA now contains 5 */

	/* set the integer pointer to point to the integer variable */
	ptrA = &varA; /* the & operator preceding varA gets the address of varA, ptrA now "points" to varA */

	/* set the pointer to point to an integer pointer */
	ptrToptrA = &ptrA; /* the & operator preceding ptrA gets the address of ptrA, ptrToptrA now "points" to ptrA */

	/* get the address of varA directly */
	printf("The address of varA is: %d (using &varA)\n", (int)&varA);

	/* get the address of varA indirectly using ptrA */
	printf("The address of varA is: %d (using ptrA)\n", (int)ptrA);

	/* get the address of varA indirectly using ptrToptrA */
	printf("The address of varA is: %d (using ptrToptrA)\n", (int)*ptrToptrA);

	/* get the value of varA directly */
	printf("The value of varA is: %d (reading via varA)\n", varA);

	/* get the value of varA indirectly using ptrA */
	printf("The value of varA is: %d (reading via ptrA)\n", *ptrA);

	/* get the value of varA directly indirectly using ptrToptrA */
	printf("The value of varA is: %d (reading via ptrToptrA)\n", **ptrToptrA);

	/* Pass ptrA by-value */
	GetIntFromPtr(ptrA);

	/* Pass ptrA by-reference */
	GetIntFromPtrToPtr(ptrToptrA);

	/* Try to Modify the pointer to point to varB instead of varA */
	ModifyIntPtrByUsingValue(ptrA);

	printf("After call to ModifyIntPtrByUsingValue(), the value of address pointed to by ptrA is: %d\n", *ptrA);

	/* Try to Modify the pointer to point to varB instead of varA */
	ModifyIntPtrByUsingReference(ptrToptrA);

	printf("After call to ModifyIntPtrByUsingReference(), the value of address pointed to by ptrA is: %d\n", *ptrA);
}

