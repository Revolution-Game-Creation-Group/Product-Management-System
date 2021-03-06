//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : CPMSystem.cpp
//  @ Date : 2007-04-10
//  @ Author : 
//
//


#include "CPMSystem.h"


CPMSystem::CPMSystem()
{
	m_login = new CLogin;

	m_materialPart = NULL;
	m_producePart = NULL;
}

CPMSystem::~CPMSystem()
{
	if(m_login != NULL)
		delete m_login;
	if(m_materialPart != NULL)
		delete m_materialPart;
	if(m_producePart != NULL)
		delete m_producePart;
}

bool CPMSystem::Login() 
{
	char pw[8];

	printf("비밀번호:");
	scanf("%s",pw);

	if(m_login->checkPW(pw) == 1) /* 자재부 */
	{
		printf("알림 : 자재부로 로그인했습니다.\n");
		CreateMaterialPart();
		m_materialPart->LoadData();
		while(ProcessMaterial());
		m_materialPart->SaveData();
	}
	else if(m_login->checkPW(pw) == 2) /* 생산부 */
	{
		printf("알림 : 생산부로 로그인했습니다.\n");
		CreateProducePart();
		m_producePart->LoadData();
		while(ProcessProduce());
	}

	else
	{
		printf("비밀번호가 틀렸습니다.\n");
		return false;
	}

	return true;
}

void CPMSystem::CreateMaterialPart()
{
	m_materialPart = new CMaterialPart;
}

void CPMSystem::CreateProducePart()
{
	m_producePart = new CProducePart;
}

bool CPMSystem::ProcessMaterial()
{
	int input;

	printf("0. 자재주문서 전체보기\n");
	printf("1. 자재주문\n");
	printf("2. 자재입고\n");
	printf("3. 자재정보 전체보기\n");
	printf("4. 자재정보 보기\n");
	printf("5. 자재정보 추가\n");
	printf("6. 자재정보 수정\n");
	printf("7. 자재출하지시서 보기\n");
	printf("8. 자재출하지시서 승인\n");
	printf("9. 프로그램 종료\n");

	printf(">>");
	scanf("%d",&input);

	switch(input)
	{
	case 0:	m_materialPart->ShowOrderAll(); break;
	case 1: m_materialPart->AddOrder(); break;
	case 2: m_materialPart->CheckOrder(); break;
	case 3: m_materialPart->ShowMaterialAll(); break;
	case 4: m_materialPart->ShowMaterial(); break;
	case 5: m_materialPart->AddMaterial(); break;
	case 6: m_materialPart->ModifyMaterial(); break;
	case 7: m_materialPart->ShowShipAll(); break;
	case 8: m_materialPart->CheckShip(); break;
	case 9:
		return false;
	default:
		printf("잘못된 값을 입력했습니다.\n");
		break;
	}

	return true;
}

bool CPMSystem::ProcessProduce()
{
	int input;

	printf("0. 자재정보 전체보기\n");
	printf("1. 자재출하지시서 입력\n");
	printf("2. 프로그램 종료\n");

	printf(">>");
	scanf("%d",&input);

	switch(input)
	{
	case 0:	m_producePart->ShowMaterialAll(); break;
	case 1: m_producePart->AddShip(); break;
	case 2: return false;
	default:
		printf("잘못된 값을 입력했습니다.\n");
		break;
	}

	return true;
}