#include <napi.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage *tree_sitter_javascript();

const napi_type_tag LANGUAGE_TYPE_TAG = {
  0x95840BEBF71E4E90, 0x9DC9419B874C0271
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports["name"] = Napi::String::New(env, "javascript");
    auto language = Napi::External<TSLanguage>::New(env, tree_sitter_javascript());
    language.TypeTag(&LANGUAGE_TYPE_TAG);
    exports["language"] = language;
    return exports;
}

NODE_API_MODULE(tree_sitter_javascript_binding, Init)
