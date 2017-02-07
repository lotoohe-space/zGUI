#pragma once

#include "ZObject.h"
#include "ZTypes.h"
#include <list>   
using namespace std;
/* ��Ϣ�¼��Ķ��� */
#define MOUSE_MSG_DOWN 0x0200 //��갴��
#define MOUSE_MSG_RELEASE 0x0201 //����ɿ�
#define MOUSE_MSG_MOVE    0x0204 //����ƶ�
#define CONTROL_DOWN 0x0202 //�ؼ�����
#define CONTROL_RELEASE 0x0203//�ؼ��ͷ�


/* ��Ϣ�Ľṹ�� */
typedef struct _Msg {
	u32 hwnd;          // ���ܸ���Ϣ�Ĵ��ھ��
	u32 message;         // ��Ϣ������ʶ����Ҳ��������ͨ����˵����Ϣ�� 
	u32 wParam;     // 32λ��Ϣ���ض�������Ϣ��ȷ�к�����������Ϣֵ 
	u32 lParam;       // 32λ��Ϣ���ض�������Ϣ��ȷ�к�����������Ϣֵ 
	u64 time;         // ��Ϣ����ʱ��ʱ�� 
	Point pt;             // ��Ϣ����ʱ�����/�������Ļ����ϵ�е�λ�� 
}Msg;


class ZMsgDispose {
protected:

public :
	ZMsgDispose();
	/* ע��һ���ؼ� */
	void addControlPanel(ZObject *mZObject);
	/* ���һ����Ϣ */
	void addMsg(Msg *msg);
	/*  �ַ���Ϣ-->ѭ������ */
	void msgDistribution();
	/* ����GUI��Ϣ�Ĵ�����,���������������д��ڵ���Ϣ������*/
	void msgWindowsDispose();
private:
	/* ���gui�����еĿؼ� */
	list<u32>  mControlList;
	/* ��Ϣ�б� */
	list<Msg*>  mMsgList;

};

