#ifndef _MACHINERY_SUBJECT_QUERY_
#define _MACHINERY_SUBJECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)	

/*
* ���/�����豸�б��ҳ��ѯ����
*/
class MachinerySubjectQuery : public PageQuery
{
	DTO_INIT(MachinerySubjectQuery, PageQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_SUBJECT_QUERY_