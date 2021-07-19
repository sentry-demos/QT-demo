#include "eventCrashes.h"
#include <string.h>

void initialize_memory(char *mem)
{
   qInfo() << "Initalizing Memory";
   memset(mem, 1, 100);
}

void startup(void)
{
   sentry_set_transaction("startup");
   sentry_set_level(SENTRY_LEVEL_ERROR);

   qInfo() << "Setting user to John Doe";

   sentry_value_t user = sentry_value_new_object();
   sentry_value_set_by_key(user, "id", sentry_value_new_int32(42));
   sentry_value_set_by_key(user, "email", sentry_value_new_string("john.doe@example.org"));
   sentry_value_set_by_key(user, "username", sentry_value_new_string("John Doe"));
   sentry_set_user(user);

   initialize_memory((char *)0x0);

   qInfo() << "Finished setup";
}

void send_event(void)
{
   sentry_set_transaction("send_event");

   qInfo() <<  "Configuring GPU Context";

   sentry_value_t gpu = sentry_value_new_object();
   sentry_value_set_by_key(gpu, "name", sentry_value_new_string("AMD Radeon Pro 560"));
   sentry_value_set_by_key(gpu, "vendor_name", sentry_value_new_string("Apple"));
   sentry_value_set_by_key(gpu, "memory_size", sentry_value_new_int32(4096));
   sentry_value_set_by_key(gpu, "api_type", sentry_value_new_string("Metal"));
   sentry_value_set_by_key(gpu, "multi_threaded_rendering", sentry_value_new_bool(1));
   sentry_value_set_by_key(gpu, "version", sentry_value_new_string("Metal"));

   sentry_value_t os = sentry_value_new_object();
   sentry_value_set_by_key(os, "name", sentry_value_new_string("macOS"));
   sentry_value_set_by_key(os, "version", sentry_value_new_string("10.14.6 (18G95)"));

   sentry_value_t contexts = sentry_value_new_object();
   sentry_value_set_by_key(contexts, "gpu", gpu);
   sentry_value_set_by_key(contexts, "os", os);

   sentry_value_t event = sentry_value_new_event();
   sentry_value_set_by_key(event, "message", sentry_value_new_string("Sentry Message Capture"));
   sentry_value_set_by_key(event, "contexts", contexts);

   sentry_set_tag("key_name", "value");

   sentry_capture_event(event);

}
