
/*
 * Get Device information Module
 * 2013. 1. 21, v 0.0.1
 * �ý��ۿ� Mount�� ��ġ���� ������ Ž���Ѵ�.
 * ��ü ��ġ, Ư��Ÿ���� ��ġ, Ư�� ����� ��ġ�� Ž��
 * ���� ����Ʈ ���·� ��ȯ�Ѵ�.
 * Author	: Seungjae, Lee
 * 2013 Spring semester, Capstone Project
 * Handong University
 */
#ifndef _GET_DEVICE_H_
#define _GET_DEVICE_H_

#define MT_INFO_PATH "/proc/mounts"

struct DEVLIST
{
	char fs_dev[256];
	char mount_dir[256];
	char fs_type[256];
	char mount_opts[256];
	long long total_size;
	long long free_size;
	struct DEVLIST* next;
};

struct DEV_INFO {
	char fs_dev[256];
	char mount_dir[256];
	char fs_type[256];
};

typedef struct DEVLIST DEVLIST;

extern int get_device_list(DEVLIST **head);
extern int get_device_list_with_type(DEVLIST** head, const char* type);
extern void free_device_list(DEVLIST **head);
extern long long get_device_free_size(const char* mount_point);
extern int get_device_info(const char* devpath, struct DEV_INFO* const dev);
extern void print_device_list(DEVLIST *head); // for debugging

#endif