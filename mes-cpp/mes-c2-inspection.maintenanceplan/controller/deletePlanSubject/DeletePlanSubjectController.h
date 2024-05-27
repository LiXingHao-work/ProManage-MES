#ifndef _REMOVEDEVICECONTROLLER_H_
#define _REMOVEDEVICECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
//---
#include "../../domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

// ɾ�����ݲ���Ҫ�Զ���JsonVO��ֻҪ����true��false���ɣ�ֱ��ʹ��ѧ����BaseJsonVO.h�ж����BooleanJsonVO����
// ɾ�����ݲ���ҪQuery������û�з�ҳ��ѯ������������Ĳ���������ɾ����ͨ��ǰ�����û��ڻ������������й�ѡ�õ���

class DeletePlanSubjectController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DeletePlanSubjectController)
public: // ����ӿ�
	/*
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("planSubject.op.deleteT"), deletePlanSubject, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/inspection-maintennace/delete-opration", deletePlanSubject, BODY_DTO(DeletePlanSubjectDTO::Wrapper, dto), execDeletePlanSubject(dto))

	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("planSubject.op.deleteOneToMany"), deletePlanSubjectOneToMany, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/inspection-maintennace/del-one-to-many", deletePlanSubjectOneToMany, BODY_DTO(DeletePlanSubjectOneToManyDTO::Wrapper, dto), execDeletePlanSubjectOneToMany(dto))
	*/
	/*
	//-------------��abf�����䣨ʾ����
	//��һ����
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteTemplate.summary.deleteUnique"), deleteUnique, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/delete-template/keyUnique", deleteUnique, BODY_DTO(DeleteTableUniqueDTO::Wrapper, dto), execDeleteUnique(dto))
	//��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteTemplate.summary.deleteShared"), deleteShared, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/delete-template/keyShared", deleteShared, BODY_DTO(DeleteTableSharedDTO::Wrapper, dto), execDeleteShared(dto))
	*/
	//----��abf��ɾ�����ƻ����ƻ��漰����Ŀ���ƻ��漰���豸��

	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteOP.summary.machiner"), deletePlanMachiner, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/device-manage/delete-plan-machiner", deletePlanMachiner, BODY_DTO(DeleteMachinerDTO::Wrapper, dto), execDeletePlanMachiner(dto))

	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteOP.summary.subject"), deletePlanSubject, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/device-manage/delete-plan-subject", deletePlanSubject, BODY_DTO(DeleteSubjectDTO::Wrapper, dto), execDeletePlanSubject(dto))

	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteOP.summary.plan"), deletePlan, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/device-manage/delete-plan", deletePlan, BODY_DTO(DeletePlanDTO::Wrapper, dto), execDeletePlan(dto))
		
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("machinery-plan.query-details.summary"), deletePlanQuery, DeletePlanQueryJsonVO::Wrapper)
	//API_HANDLER_ENDPOINT(API_M_GET, "/device-manage/delete-plan", deletePlanQuery, BODY_DTO(DeletePlanQuery::Wrapper, dto), execDeletePlanQuery(dto))

	//--------��һ������
	// ������/�����豸�ƻ��б�ӿ�����
	ENDPOINT_INFO(deletePlanQuery) {
	// ����ӿڱ���
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-plan.query-details.summary"));
	// ����Ĭ����Ȩ����
	API_DEF_ADD_AUTH();
	// ������Ӧ������ʽ
	API_DEF_ADD_RSP_JSON_WRAPPER(DeletePlanQueryJsonVO);
	// ����������������
	API_DEF_ADD_QUERY_PARAMS(Int64, "plan_id", ZH_WORDS_GETTER("machinery-plan.field.plan-id"), 69, true);
	}
	// �����ѯ�豸�嵥�б�ӿڴ���
	ENDPOINT(API_M_GET, "/device-manage/delete-plan-query", deletePlanQuery, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	// ��������ģ��
	API_HANDLER_QUERY_PARAM(query_delete_plan, DeletePlanQuery, queryParams);
	// ����ִ�к�����Ӧ���
	API_HANDLER_RESP_VO(execDeletePlanQuery(query_delete_plan));
	}

	//// ������/�����豸�ƻ��б�ӿ�����
	//ENDPOINT_INFO(deletePlanQuery)
	//{
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-plan.query-details.summary"));
	//    // ����Ĭ����Ȩ����
	//    API_DEF_ADD_AUTH();
	//    // ������Ӧ������ʽ
	//    API_DEF_ADD_RSP_JSON_WRAPPER(DeletePlanQueryJsonVO);
	//    // ����������������
	//    API_DEF_ADD_QUERY_PARAMS(String, "plan_id", ZH_WORDS_GETTER("machinery-plan.field.plan-id"), "65", true);
	//}
	//// �����ѯ�豸�嵥�б�ӿڴ���
	//ENDPOINT(API_M_GET, "/device-manage/delete-plan-query", deletePlanQuery, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) 
	//{
	//// ��������ģ��
	//API_HANDLER_QUERY_PARAM(queryPlan, DeletePlanQueryJsonVO, queryParams);
	//// ����ִ�к�����Ӧ���
	//API_HANDLER_RESP_VO(execDeletePlanQuery(queryPlan));
	//}


private: // ����ӿ�ִ�к���

	// ǰ�˷�������dto���������ִ��
	/*
	BooleanJsonVO::Wrapper execDeletePlanSubject(const DeletePlanSubjectDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeletePlanSubjectOneToMany(const DeletePlanSubjectOneToManyDTO::Wrapper& dto);
	*/

	/*
	//----------------��abf�����䣨ʾ����
	BooleanJsonVO::Wrapper execDeleteUnique(const DeleteTableUniqueDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeleteShared(const DeleteTableSharedDTO::Wrapper& dto);
	//----��abf��ɾ�����ƻ����ƻ��漰����Ŀ���ƻ��漰���豸��
	*/
	BooleanJsonVO::Wrapper execDeletePlanMachiner(const DeleteMachinerDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeletePlanSubject(const DeleteSubjectDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeletePlan(const DeletePlanDTO::Wrapper& dto);

	DeletePlanQueryJsonVO::Wrapper execDeletePlanQuery(const DeletePlanQuery::Wrapper& query);


	//MachineryPlanDetailsJsonVO::Wrapper execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_REMOVEDEVICECONTROLLER_H_
