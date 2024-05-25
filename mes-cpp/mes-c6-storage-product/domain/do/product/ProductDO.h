#pragma once

#ifndef _PRODUCT_DO_
#define _PRODUCT_DO_
#include "../DoInclude.h"
/**
 * �����������ݿ�ʵ����
 */
class ProductTableDO {
	//���ϵ�id
	CC_SYNTHESIZE(uint64_t, pid, Pid);
	//���ϵ����
	CC_SYNTHESIZE(string, pnum, Pnum);
	//���ϵ�����
	CC_SYNTHESIZE(string, pname, Pname);
	//��������
	CC_SYNTHESIZE(string, plist, Plist);
	//�ͻ����
	CC_SYNTHESIZE(string, pcnum, Pcnum);
	//�ͻ�����
	CC_SYNTHESIZE(string, pcname, Pcname);
	//��������
	CC_SYNTHESIZE(string, pdate, Pdate);
	//����״̬
	CC_SYNTHESIZE(string, pstatus, Pstatus);
public:
	ProductTableDO() {
		pid = 200;
		pnum = "ISSUE20221115004";
		pname = "";
		plist = "MO202211030003";
		pcnum = "C00197";
		pcname = "";
		pdate = "2022-11-15 00:00:00";
		pstatus = "FINISHED";
	}
};
/**
 * ���������������ݿ�ʵ����
 */
class ProductDetailDO :public ProductTableDO{
	//���ϲֿ�
	CC_SYNTHESIZE(string, prname, Prname);
	//��ע
	CC_SYNTHESIZE(string, premark, Premark);
public:
	ProductDetailDO() {
		prname = "";
		premark = "";
	}
};
#endif 