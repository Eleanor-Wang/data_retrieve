//
//  MyForm.cpp
//  MarketData
//
//  Created by 汪念怡 on 23/04/16.
//  Copyright (c) 2016 汪念怡. All rights reserved.
//

#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	FinalProject::MyForm form;
	Application::Run(%form);
}

