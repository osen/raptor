#include "LoginForm.h"

void LoginForm::createWindow()
{
  // |expand|vBox|expand|

  add<raptor::Container>()->setExpand(true);

  raptor::Container* vBox = add<raptor::Container>();
  vBox->setDirection(1);

  // vBox
  //
  // |expand|
  // |windowBox|
  // |copyrightLabel|
  // |expand|

  vBox->add<raptor::Container>()->setExpand(true);
  raptor::Container* windowBox = vBox->add<raptor::Container>();
  createLogin(windowBox);

  raptor::Label* copyrightLabel = vBox->add<raptor::Label>();
  copyrightLabel->setText("Copyright &copy; 2018 Karsten Pedersen");
  copyrightLabel->setPadding(0, 0, 10, 0);

  vBox->add<raptor::Container>()->setExpand(true);

  add<raptor::Container>()->setExpand(true);
}

void LoginForm::createLogin(raptor::Container* container)
{
  container->setExpand(false);
  container->setBorderWidth(1);

  // |label|loginBox|

  raptor::Label* label = container->add<raptor::Label>();
  label->setText("Welcome");
  label->setPadding(100);

  raptor::Container* loginBox = container->add<raptor::Container>();
  loginBox->setDirection(1);
  //loginBox->setBorderWidth(1);
  loginBox->setPadding(5, 15, 5, 5);
  loginBox->setExpand(true);

  // loginBox
  //
  // |expand|
  // |hBox|
  // |hBox|
  // |buttonBox|
  // |expand|

  loginBox->add<raptor::Container>()->setExpand(true);

  raptor::Container* hBox = loginBox->add<raptor::Container>();
  hBox->setPadding(5, 5, 5, 0);

  // hBox
  //
  // |expand|usernameLabel|usernameTextBox|

  hBox->add<raptor::Container>()->setExpand(true);
  raptor::Label* usernameLabel = hBox->add<raptor::Label>();
  usernameLabel->setText("Username:");
  usernameLabel->setPadding(0, 5, 0, 0);

  raptor::TextBox* usernameTextBox = hBox->add<raptor::TextBox>();
  //usernameTextBox->setText("Woopy");

  hBox = loginBox->add<raptor::Container>();
  hBox->setPadding(5);

  // hBox
  //
  // |expand|passwordLabel|passwordTextBox|

  hBox->add<raptor::Container>()->setExpand(true);
  raptor::Label* passwordLabel = hBox->add<raptor::Label>();
  passwordLabel->setText("Password:");
  passwordLabel->setPadding(0, 5, 0, 0);

  raptor::TextBox* passwordTextBox = hBox->add<raptor::TextBox>();
  //passwordTextBox->setText("Woopy");
  passwordTextBox->setPassword(true);

  raptor::Container* buttonBox = loginBox->add<raptor::Container>();
  buttonBox->setPadding(5);

  // buttonBox
  //
  // |expand|registerButton|loginButton|

  buttonBox->add<raptor::Container>()->setExpand(true);

  raptor::Button* registerButton = buttonBox->add<raptor::Button>();
  registerButton->setText("Register");
  registerButton->setPadding(0, 5, 0, 0);

  raptor::Button* loginButton = buttonBox->add<raptor::Button>();
  loginButton->setText("Login");

  loginBox->add<raptor::Container>()->setExpand(true);
}

void LoginForm::onCreate()
{
  setTitle("raptor - Login Example");
  //setExpand(false);

  createWindow();
}
