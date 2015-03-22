// Fill out your copyright notice in the Description page of Project Settings.

#include "HelloWorld.h"
#include "src/DynamicLib.h"
#include "Foo.h"
#include "ITestPlugin.h"
#include "npp/dynamic.h"

extern "C" {
  #include "extern/extern.h"
}

int32 UFoo::GetHappyMessage()
{
  auto v = new npp::DummyDynamicLoader();
  delete v;
  auto value = rs_trigger(100);
  return value;
}

void foo() {
}
