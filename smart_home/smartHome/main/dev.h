#ifndef __DEV_H__
#define __DEV_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <unistd.h>
#include <sqlite3.h>

//led驱动接口
#define LED_MAGIC  'h'
#define CMD_ON	  1
#define CMD_OFF   0
#define CMD_FALSH 2
#define LED_ON    _IOW(LED_MAGIC, CMD_ON,    int)
#define LED_OFF   _IOW(LED_MAGIC, CMD_OFF,   int)
#define LED_FLASH _IOW(LED_MAGIC, CMD_FALSH, int)

//蜂鸣器驱动接口
#define BEEP_MAGIC  'b'
#define BEEP_ON  _IOW(BEEP_MAGIC, CMD_ON,  int)
#define BEEP_OFF _IOW(BEEP_MAGIC, CMD_OFF, int)

//风扇驱动
#define FAN_MAGIC  'f'
#define CMD_LEVEL_1	1
#define CMD_LEVEL_2	2
#define CMD_LEVEL_3	3
#define FAN_LEVEL_1  _IOW(FAN_MAGIC, CMD_LEVEL_1, int)
#define FAN_LEVEL_2  _IOW(FAN_MAGIC, CMD_LEVEL_2, int)
#define FAN_LEVEL_3  _IOW(FAN_MAGIC, CMD_LEVEL_3, int)
#define FAN_OFF _IOW(FAN_MAGIC, CMD_OFF, int)

//数码管
#define SEG_MAGIC  's'
#define CMD_SWICH	1
#define CMD_DATE	2
#define SEG_WHICH _IOW(SEG_MAGIC, CMD_SWICH, int)
#define SEG_DAT  _IOW(SEG_MAGIC, CMD_DATE,  int)

//温湿度驱动接口
#define si7006_MAJIC 'w'
#define CMD_TEMP 1
#define CMD_HUMP 2
#define READ_TEMP _IOW(si7006_MAJIC, CMD_TEMP, int);
#define READ_HUMP _IOW(si7006_MAJIC, CMD_HUMP, int);

//马达驱动接口
#define MOTOR_MAJIC 'm'
#define MOTOR_ON  _IOW(MOTOR_MAJIC, CMD_TEMP, int);
#define MOTOR_OFF _IOW(MOTOR_MAJIC, CMD_HUMP, int);


/*
 *	fd[0] led驱动
 *	fd[1] 蜂鸣器驱动
 *	fd[2] 温湿度驱动
 *	fd[3] 数码管驱动
 *	fd[4] 风扇驱动
 *	fd[5] 马达驱动
 *
 *	tid[0] 数据采集线程
 *	tid[1] 数据处理线程
 *	tid[2] 数据显示线程
 *	tid[3] 用户交互线程
 */
typedef struct{
	int fd[6];
	pthread_t tid[4];
}Fd_tid;

/*
 *	si7006接收到的数据通过该结构体进行传递
 */
typedef struct{
	double temp;
	double hump;
}Temp_hump;

/*****    温湿度超过阈值，风扇  ，蜂鸣器，LED灯，马达均会产生报警信号      			         	  ********/
#define ALARM_START do{\
	ioctl(fd_tid.fd[0], LED_FLASH);\
	ioctl(fd_tid.fd[1], BEEP_ON);\
	ioctl(fd_tid.fd[4], FAN_LEAVE_3);\
	ioctl(fd_tid.fd[5], MOTOR_ON);\
}while(0)


/******   温湿度恢复到阈值，风扇  ，蜂鸣器，LED灯，马达报警信号消失  			                ********/
#define ALARM_STOP do{\
	ioctl(fd_tid.fd[0], LED_OFF);\
	ioctl(fd_tid.fd[1], BEEP_OFF);\
	ioctl(fd_tid.fd[4], FAN_OFF);\
	ioctl(fd_tid.fd[5], MOTOR_OFF);\
}while(0)


#endif
