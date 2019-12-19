#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void getChildren(void);
void getCount(void);

int
main(int argc, char *argv[])
{
    
    printf(1," \n getcount  : \n ");
    getCount();  
    printf(1,"getchildren whit 3 forks : \n ");
    getChildren();
}

void getCount()
{
    
    printf(1,"exec : %d\n",getcount(7,getpid()));
    printf(1,"write : %d\n",getcount(16,getpid()));
    printf(1,"close : %d\n",getcount(21,getpid()));
    printf(1,"getchildren : %d\n",getcount(22,getpid()));
    printf(1,"get count : %d\n",getcount(23,getpid()));
    //exit();
}

void getChildren()
{
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
//int main()
//{
	//printf("parent id is : %d \n" , (int) getpid());
	//printf("firsr fork child id is : %d \n" , (int) fork());
	//printf("second child id is : %d \n" , (int) fork());
	//printf("3th fork child id is : %d \n" , (int) fork());
//	
//}
