#include "tree_sitter/parser.h"
#include <napi.h>

using namespace Napi;

extern "C" TSLanguage * tree_sitter_javascript();

namespace {

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports["name"] = String::New(env, "javascript");
  exports["language"] = External<TSLanguage>::New(env, tree_sitter_javascript());
  return exports;
}

NODE_API_MODULE(tree_sitter_javascript_binding, Init)

}  // namespace
