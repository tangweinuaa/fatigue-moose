#include "seiler2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
seiler2App::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

seiler2App::seiler2App(InputParameters parameters) : MooseApp(parameters)
{
  seiler2App::registerAll(_factory, _action_factory, _syntax);
}

seiler2App::~seiler2App() {}

void
seiler2App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"seiler2App"});
  Registry::registerActionsTo(af, {"seiler2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
seiler2App::registerApps()
{
  registerApp(seiler2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
seiler2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  seiler2App::registerAll(f, af, s);
}
extern "C" void
seiler2App__registerApps()
{
  seiler2App::registerApps();
}
