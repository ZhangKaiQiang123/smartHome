#include "dev.h"

void* pthread_get_data(void* arg);
void* pthread_use_data(void* arg);
void* pthread_show_data(void* arg);
void* pthread_inter_data(void* arg);

//创建互斥锁
pthread_mutex_t fastmutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, const char* argv[])
{
	Fd_tid fd_tid;
	Temp_hump th;
	int ret;

	/************打开所有的文件描述符**************/


	/************创建数据采集线程******************/
	pthread_create(&fd_tid.tid[0], NULL, pthread_get_data, NULL);	
	ret = pthread_detach(fd_tid.tid[0]);
	if(ret) 
	{
		perror("detach use data thread");
		exit(EXIT_FAILURE);
	} 
	else
	{
		printf("detach get data thread success\n");
	}

	/************创建数据处理线程******************/
	ret = pthread_create(&fd_tid.tid[1], NULL, pthread_use_data, NULL);	
	printf("%d\n", ret);
	
	ret = pthread_detach(fd_tid.tid[1]);
	if(ret) 
	{
		perror("detach sue data thread");
		exit(EXIT_FAILURE);
	} 
	else
	{
		printf("detach use data thread success\n");
	}

	/************创建数据显示线程******************/
	pthread_create(&fd_tid.tid[2], NULL, pthread_show_data, NULL);	
	
	ret = pthread_detach(fd_tid.tid[2]);
	if(ret) 
	{
		perror("detach data show thread");
		exit(EXIT_FAILURE);
	} 
	else
	{
		printf("detach data show thread success\n");
	}


	/************创建用户交互线程******************/
	pthread_create(&fd_tid.tid[3], NULL, pthread_inter_data, NULL);	
	
	ret = pthread_detach(fd_tid.tid[3]);
	if(ret) 
	{
		perror("detach inter thread");
		exit(EXIT_FAILURE);
	} 
	else
	{
		printf("detach inter thread success\n");
	}

	/************关闭所有的文件描述符**************/


	pthread_join(fd_tid.tid[0], NULL);
	pthread_join(fd_tid.tid[1], NULL);
	pthread_join(fd_tid.tid[2], NULL);
	pthread_join(fd_tid.tid[3], NULL);
	exit(EXIT_SUCCESS);
}

void* pthread_get_data(void* arg)
{
	pthread_mutex_lock(&fastmutex);

	printf("pthread_get_data\n");

	pthread_mutex_unlock(&fastmutex);
}

void* pthread_use_data(void* arg)
{
	//pthread_mutex_lock(&fastmutex);

	printf("pthread_use_data\n");

	//pthread_mutex_unlock(&fastmutex);
}

void* pthread_show_data(void* arg)
{
	pthread_mutex_lock(&fastmutex);

	printf("pthread_show_data\n");

	pthread_mutex_unlock(&fastmutex);
}

void* pthread_inter_data(void* arg)
{
	pthread_mutex_lock(&fastmutex);

	printf("pthread_inter_data\n");

	pthread_mutex_unlock(&fastmutex);
}

