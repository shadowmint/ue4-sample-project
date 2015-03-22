#include "HelloWorld.h"
#include "AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFoo, "Foo", EAutomationTestFlags::ATF_SmokeTest)

bool FFoo::RunTest(const FString& Parameters)
{
  TestEqual(TEXT("Hi == Hi"), TEXT("Hi"), TEXT("Hi"));
  return true;
}
