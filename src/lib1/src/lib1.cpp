#include "lib1/api.h"
#include <stdio.h>
#include "humblelogging/api.h"

using namespace humble::logging;

HUMBLE_LOGGER(HL, "lib1");

void lib1func()
{
    // Initialize humble logging.
    Factory& fac = Factory::getInstance();
    fac.setConfiguration(new humble::logging::SimpleConfiguration(LogLevel::All));
// Add Appender which doesn't log anywhere.
    fac.registerAppender(new NullAppender());
// Add appender as logging output.
// Add Appender which logs to STDOUT.
    fac.registerAppender(new ConsoleAppender());
// Change the default LogLevel, which every NEW Logger will have.
//\TODO TO BE REMOVED   fac.setDefaultLogLevel(LogLevel::All);
    // Change the default Formatter (optional).
    fac.setDefaultFormatter(new PatternFormatter("[%date] [%lls] [line=%line] [file=%filename] %m\n"));
    fprintf(stdout, "fprint within lib1func \n");
    HL_FATAL(HL, "TEST lib1func logging  to  log as fatal level  ");
    HL_DEBUG(HL, "lib1func  logging as debug level \n");
}
