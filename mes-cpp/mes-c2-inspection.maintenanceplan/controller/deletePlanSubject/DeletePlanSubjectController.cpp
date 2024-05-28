#include "stdafx.h"
#include "DeletePlanSubjectController.h"
//����ѯ������
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_plan/Dv_check_planService.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanMachiner(const DeleteMachinerDTO::Wrapper& dto)
{
	return BooleanJsonVO::Wrapper();
}

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanSubject(const DeleteSubjectDTO::Wrapper& dto)
{


	return BooleanJsonVO::Wrapper();
}

bool idExistIs(const DeletePlanQuery::Wrapper& query)
{
	Dv_check_planService service;
	// ��ѯ����
	DeletePlanQueryDTO::Wrapper result = service.listAll(query);
	// ��Ӧ���
	auto jvo = DeletePlanQueryJsonVO::createShared();
	jvo->success(result);

	//auto test001 = jvo.get();
	//auto test002 = jvo->data;//�õ�DTO�������ݴ������
	auto jvoData = jvo->data;
	auto plan_idJvoData = jvoData->plan_id;
	//auto test003 = test002->plan_id;//�õ���dto���plan_id����

	auto tq001 = query->plan_id;

	//�����ڲ�ѯ���ʱ�������жϻ���������Ȩ���쳣���������ԡ�
	//if (test003!=0)cout << "�����id�Ͳ��ҵ���idһ�£�����" << endl;
	//else cout << "���ҵ�id������" << endl;

	//�������
	if (plan_idJvoData != nullptr)
	{
		cout << "���ݱ���ڴ�ɾ��id��" << tq001 << endl;
		return true;
	}
	else
	{
		cout << "���ݱ�û�д�ɾ��id��" << tq001 << endl;
		return false;
	}
}

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlan(const DeletePlanDTO::Wrapper& dto)
{
	//ɾ���������̣�
	//1���ж�����Ϸ��ԣ����Ϸ����ش���
	//2����������������id���ͨ��������ɾ������׼����ʼ����
	//3�����  ��������id�Ƿ�ȫ�������ݱ��У�������������ִ��ɾ��
	//4��ɾ������*2��ɾ������*1
	//5������
	//6�����سɹ���ʾ


	auto jvo = BooleanJsonVO::createShared();
	//1������У��
	auto idListDTO = (dto->item);
	auto idList = idListDTO.get();
	//auto abf2 = idListDTO->begin();
	//auto abf11 = *(idListDTO->begin());
	//����list���в���У�飬1����Χ��⡣  2�������Լ�⡣
	for (std::list<oatpp::Int64>::iterator it = idList->begin(); it != idList->end(); ++it)
	{
		std::cout << *it << " ";//�˴���*it����ܱ�����idȥʹ��
		if (!(*it) || (*it) <= 0)
		{
			jvo->init(Boolean(false), RS_PARAMS_INVALID);//ʧ�ܷ��ز����쳣
			return jvo;
		}
	}cout << endl;

	//3����飬��ѯ
	//auto nums = idList->size();
	//auto existNums = 0;
	for (std::list<oatpp::Int64>::iterator it = idList->begin(); it != idList->end(); ++it)
	{
		//���������ȡȨ�������⣬�ò��ˣ���һ��
		//DeletePlanQuery::Wrapper query ;
		//query->plan_id = *it;

		auto query_delete_plan = DeletePlanQuery::createShared();
		//query_delete_plan[param.first.toString()] = oatpp::Int64(*it);
		//query_delete_plan= oatpp::Int64(*it);
		query_delete_plan->setPlan_id(*it);
		if (idExistIs(query_delete_plan) == false)
		{
			jvo->init(Boolean(false), RS_FAIL);
			return jvo;
		}
	}
	//4��ɾ��

	for (std::list<oatpp::Int64>::iterator it = idList->begin(); it != idList->end(); ++it)
	{

		// ����һ��Service
		Dv_check_planService service;
		service.dv_check_machineryRemoveDataIDP((*it).getValue(0));
		service.dv_check_subjectRemoveDataIDP((*it).getValue(0));
		// ִ������ɾ��
		service.dv_check_planRemoveData((*it).getValue(0));
	}
	jvo->init(Boolean(true), RS_SUCCESS);
	return jvo;

}

DeletePlanQueryJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanQuery(const DeletePlanQuery::Wrapper& query)
{
	int a = 0;
	Dv_check_planService service;
	// ��ѯ����
	DeletePlanQueryDTO::Wrapper result = service.listAll(query);
	// ��Ӧ���
	auto jvo = DeletePlanQueryJsonVO::createShared();
	jvo->success(result);

	auto test001 = jvo.get();
	auto test002 = jvo->data;//�õ�DTO�������ݴ������
	auto test003 = test002->plan_id;//�õ���dto���plan_id����

	auto tq001 = query->plan_id;

	//�����ڲ�ѯ���ʱ�������жϻ���������Ȩ���쳣���������ԡ�
	//if (test003!=0)cout << "�����id�Ͳ��ҵ���idһ�£�����" << endl;
	//else cout << "���ҵ�id������" << endl;

	//�������

	if (test003 != nullptr)
		cout << "�����id�Ͳ��ҵ���idһ�£�����" << endl;
	else
	{
		//jvo->init
		cout << "���ҵ�id������" << endl;
	}
	return jvo;
}






