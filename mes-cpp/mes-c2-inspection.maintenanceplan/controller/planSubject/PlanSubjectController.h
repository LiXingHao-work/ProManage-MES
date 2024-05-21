#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTCONTROLLER_H_
#define _PLANSUBJECTCONTROLLER_H_

//#include "../../domin/vo/dept/DeptVO.h"
#include "../../domain/vo/planSubject/PlanSubjectVO.h"
#include "../../domain/query/planSubject/PlanSubjectQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ���Ź��� ������
 */
class PlanSubjectController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PlanSubjectController);
	// 3 ����ӿ�
public:

	

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	PlanSubjectTablePageJsonVO::Wrapper execPlanSubjectTablePage(const PlanSubjectQuery::Wrapper& query);//����Ǹ������Ȳ�Ҫ
	//������Ҫдһ��cpp�ļ�����execDeptTable
	//PlanSubjectDetailPageJsonVO::Wrapper execQuerySample(const PlanSubjectQuery::Wrapper& query, const PayloadDTO& payload);

	//��ʱΪ�հ׶��գ�����Ĳ�������û�ж���
	PlanSubjectDetailPageJsonVO::Wrapper execPlanSubjectDetailPage(const PlanSubjectQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
