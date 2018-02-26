#include "Application.h"

#include <iostream>
#include <sstream>

namespace raptor
{

Application::Application(int argc, char* argv[])
{

}

int Application::begin_request_handler(struct mg_connection* conn)
{
  mg_request_info* request_info = mg_get_request_info(conn);

  Application* context = (Application*)request_info->user_data;

  std::cout << request_info->request_method << std::endl;

  std::cout << request_info->uri << std::endl;

  if(request_info->query_string)
    std::cout << request_info->query_string << std::endl;

  // Check POST data for session.
  // If not exists, create new session and add new startInfo form.
  //session->lock();

  std::shared_ptr<Form> form = context->startInfo->createForm();
  //session->setForm(form);
  std::shared_ptr<Component> base = form;
  std::stringstream ss;
  ss << "<!DOCTYPE html>" << std::endl;
  ss << "<html>" << std::endl;
  ss << "  <head>" << std::endl;
  ss << "    <title>" << form->getTitle() << "</title>" << std::endl;
  ss << "  </head>" << std::endl;
  ss << "  <body>" << std::endl;
  ss << base->serialize() << std::endl;
  ss << "  </body>" << std::endl;
  ss << "</html>" << std::endl;

  //session->unlock();

  // Send HTTP reply to the client
  mg_printf(conn,
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Content-Length: %d\r\n"
    "\r\n"
    "%s",
    (int)ss.str().length(), ss.str().c_str());

  return 1;
}

void Application::process()
{
  mg_callbacks callbacks = {0};
  callbacks.begin_request = begin_request_handler;

  const char *options[] =
  {
    "listening_ports",
    "8080",
    NULL
  };

  std::shared_ptr<mongoose::Context> ctx;
  ctx = mongoose::Context::mg_start(callbacks, this, options);

  getchar();

/*
  std::shared_ptr<Form> form = startInfo->createForm();
  std::shared_ptr<Component> base = form;
  //base->onCreate();

  std::cout << "<!DOCTYPE html>" << std::endl;
  std::cout << "<html>" << std::endl;
  std::cout << "  <head>" << std::endl;
  std::cout << "    <title>" << form->getTitle() << "</title>" << std::endl;
  std::cout << "  </head>" << std::endl;
  std::cout << "  <body>" << std::endl;
  std::cout << base->serialize() << std::endl;
  std::cout << "  </body>" << std::endl;
  std::cout << "</html>" << std::endl;
*/
}

}
