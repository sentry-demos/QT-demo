#include "mainwindow.h"
#include "eventCrashes.h"

#include <QApplication>
#include <QScopeGuard>

#ifdef _WIN32
const char *handler_path = "bin/crashpad_handler.exe";
#else
const char *handler_path = "bin/crashpad_handler";
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    sentry_options_t *options = sentry_options_new();
    sentry_options_set_handler_path(options, handler_path);

//   configure sentry project here
    sentry_options_set_environment(options, "Production");
    sentry_options_set_dsn(options, "https://yourdsn@sentry.io/1234567");
    sentry_options_set_release(options, "1.0");
   
#ifdef SENTRY_RELEASE
    sentry_options_set_release(options, SENTRY_RELEASE);
#endif
    sentry_options_set_database_path(options, "sentry-db");
    sentry_options_set_debug(options, 1);
    sentry_init(options);

   auto sentryClose = qScopeGuard([] { sentry_shutdown(); });

    w.show();
    return a.exec();
}

