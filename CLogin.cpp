//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : CLogin.cpp
//  @ Date : 2007-04-10
//  @ Author : 
//
//


#include "CLogin.h"
CLogin::CLogin()
{
	m_iMaterialPW = "1234";
	m_iProducePW = "0000";
}

int CLogin::checkPW(string _pw) {

	if(_pw == m_iMaterialPW)
		return 1;
	else if(_pw == m_iProducePW)
		return 2;
	else
		return 0;
}