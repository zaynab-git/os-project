#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main()
{
	//printf("parent id is : %d \n" , (int) getpid());
	//printf("firsr fork child id is : %d \n" , (int) fork());
	//printf("second child id is : %d \n" , (int) fork());
	//printf("3th fork child id is : %d \n" , (int) fork());
	int parent = getpid();
	printf(1 ,"parent id is : %d \n",parent);

	if(getpid()==parent)
		fork();
	else
		exit();
	if(getpid()==parent)
		fork();
	else
		exit();
	if(getpid()==parent)
		fork();
	else
		exit();
	
	
	if(getpid() == parent)
	{
		int children = getchildren(parent);
		printf(1 ,"children id is : %d \n",children);
	}	
	exit();
}
