#ifndef _REMOVEDEVICECONTROLLER_H_
#define _REMOVEDEVICECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

// ɾ�����ݲ���Ҫ�Զ���JsonVO��ֻҪ����true��false���ɣ�ֱ��ʹ��ѧ����BaseJsonVO.h�ж����BooleanJsonVO����
// ɾ�����ݲ���ҪQuery������û�з�ҳ��ѯ������������Ĳ���������ɾ����ͨ��ǰ�����û��ڻ������������й�ѡ�õ���

class DeletePlanSubjectController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DeletePlanSubjectController)
public: // ����ӿ�
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("planSubject.op.deleteT"), deletePlanSubject, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/inspection-maintennace/delete-opration", deletePlanSubject, BODY_DTO(DeletePlanSubjectDTO::Wrapper, dto), execDeletePlanSubject(dto))
private: // ����ӿ�ִ�к���

	// ǰ�˷�������dto���������ִ��
	BooleanJsonVO::Wrapper execDeletePlanSubject(const DeletePlanSubjectDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_REMOVEDEVICECONTROLLER_H_
