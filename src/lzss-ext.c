#include <ruby.h>

size_t Encode(size_t ilen, char* istr, size_t olen, char* ostr);
// note: should free the returned ptr
char* Decode(size_t ilen, unsigned char* istr, size_t *olen);

static VALUE encode(VALUE self, VALUE str) {
	size_t ilen = RSTRING_LEN(str);
	char* buff = (char*)malloc(ilen * 2);
	size_t olen = Encode(RSTRING_LEN(str), RSTRING_PTR(str), ilen * 2, buff);
	VALUE ret = rb_str_new(buff, olen);
	free(buff);
	return ret;
}

static VALUE decode(VALUE self, VALUE str) {
	size_t olen = 0;
	char* buff = Decode(RSTRING_LEN(str), RSTRING_PTR(str), &olen);
	VALUE ret = rb_str_new(buff, olen);
	free(buff);
	return ret;
}

void Init_lzss() {
	VALUE Compress = rb_define_module("Compress");
	VALUE LZSS = rb_define_module_under(Compress, "LZSS");
	rb_define_module_function(LZSS, "encode", RUBY_METHOD_FUNC(encode), 1);
	rb_define_module_function(LZSS, "decode", RUBY_METHOD_FUNC(decode), 1);
}
