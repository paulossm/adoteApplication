/* COMPILATION */
// g++ main.cpp Adote.cpp -o Template.wt -lwt -lwthttp -lboost_system -lboost_signals
// ./testing.wt --docroot . --http-address 0.0.0.0 --http-port 9090

#include <iostream>

#include <Wt/WApplication>
#include <Wt/WServer>

#include <Wt/WBootstrapTheme>
#include <Wt/WEnvironment>
#include <Wt/WHBoxLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WCssTheme>

#include "headers/Adote.h"

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    Wt::WApplication *app = new Wt::WApplication(env);
    app->setTitle("Adote");
    app->messageResourceBundle().use(app->appRoot() + "templates");
//    Wt::WBootstrapTheme *bootstrap_ = new Wt::WBootstrapTheme(app);
//    app->setTheme(bootstrap_);
    app->useStyleSheet("css/bootstrap.min.css");
    app->useStyleSheet("css/bootstrap-theme.min.css");
    new Adote(app->root());
    return app;
}

int main(int argc, char **argv)
{
//    try {
//        Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);
//        server.addEntryPoint(Wt::Application, createApplication);
//        server.run();
//    } catch (Wt::WServer::Exception& e) {
//        std::cerr << e.what() << std::endl;
//    } catch (std::exception &e) {
//        std::cerr << "exception: " << e.what() << std::endl;
//    }
    return Wt::WRun(argc, argv, &createApplication);
}
