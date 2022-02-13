#include "react-native-ad-manager.h"
#include <jsi/jsi.h>

using namespace facebook::jsi;
using namespace std;

int multiply(float a, float b)
{
	return a * b;
}
void installExample(Runtime &jsiRuntime)
{
	auto helloWorld = Function::createFromHostFunction(jsiRuntime,
													   PropNameID::forAscii(jsiRuntime,
																			"helloWorld"),
													   0,
													   [](Runtime &runtime,
														  const Value &thisValue,
														  const Value *arguments,
														  size_t count) -> Value
													   {
														   string helloworld = "hello world";

														   return Value(runtime,
																		String::createFromUtf8(
																			runtime,
																			helloworld));
													   });

	jsiRuntime.global().setProperty(jsiRuntime, "helloWorld", move(helloWorld));
}

// namespace example
// {
// 	int multiply(float a, float b)
// 	{
// 		return a * b;
// 	}
// 	void installExample(Runtime &jsiRuntime)
// 	{
// 		auto helloWorld = Function::createFromHostFunction(jsiRuntime,
// 														   PropNameID::forAscii(jsiRuntime,
// 																				"helloWorld"),
// 														   0,
// 														   [](Runtime &runtime,
// 															  const Value &thisValue,
// 															  const Value *arguments,
// 															  size_t count) -> Value
// 														   {
// 															   string helloworld = "hello world";

// 															   return Value(runtime,
// 																			String::createFromUtf8(
// 																				runtime,
// 																				helloworld));
// 														   });

// 		jsiRuntime.global().setProperty(jsiRuntime, "helloWorld", move(helloWorld));
// 	}
// }
