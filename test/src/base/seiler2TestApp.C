//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "seiler2TestApp.h"
#include "seiler2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
seiler2TestApp::validParams()
{
  InputParameters params = seiler2App::validParams();
  return params;
}

seiler2TestApp::seiler2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  seiler2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

seiler2TestApp::~seiler2TestApp() {}

void
seiler2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  seiler2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"seiler2TestApp"});
    Registry::registerActionsTo(af, {"seiler2TestApp"});
  }
}

void
seiler2TestApp::registerApps()
{
  registerApp(seiler2App);
  registerApp(seiler2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
seiler2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  seiler2TestApp::registerAll(f, af, s);
}
extern "C" void
seiler2TestApp__registerApps()
{
  seiler2TestApp::registerApps();
}
