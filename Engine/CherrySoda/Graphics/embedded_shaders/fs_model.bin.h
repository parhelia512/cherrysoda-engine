static const uint8_t fs_model_glsl[247] =
{
	0x46, 0x53, 0x48, 0x0b, 0x13, 0x17, 0xa9, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73, // FSH....l.......s
	0x5f, 0x74, 0x65, 0x78, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd4, 0x00, // _tex............
	0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x76, // ..varying vec2 v
	0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, // _texcoord0;.unif
	0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, // orm sampler2D s_
	0x74, 0x65, 0x78, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, // tex;.void main (
	0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, // ).{.  vec4 tmpva
	0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, // r_1;.  tmpvar_1 
	0x3d, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x20, 0x28, 0x73, 0x5f, 0x74, // = texture2D (s_t
	0x65, 0x78, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, // ex, v_texcoord0)
	0x3b, 0x0a, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // ;.  if ((tmpvar_
	0x31, 0x2e, 0x77, 0x20, 0x3c, 0x20, 0x30, 0x2e, 0x30, 0x30, 0x33, 0x39, 0x32, 0x31, 0x35, 0x36, // 1.w < 0.00392156
	0x39, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x73, 0x63, 0x61, 0x72, // 9)) {.    discar
	0x64, 0x3b, 0x0a, 0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, // d;.  };.  gl_Fra
	0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // gColor = tmpvar_
	0x31, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                       // 1;.}...
};
static const uint8_t fs_model_essl[258] =
{
	0x46, 0x53, 0x48, 0x0b, 0x13, 0x17, 0xa9, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73, // FSH....l.......s
	0x5f, 0x74, 0x65, 0x78, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x00, // _tex............
	0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, // ..varying highp 
	0x76, 0x65, 0x63, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, // vec2 v_texcoord0
	0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, // ;.uniform sample
	0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, // r2D s_tex;.void 
	0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77, 0x70, // main ().{.  lowp
	0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, //  vec4 tmpvar_1;.
	0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x74, 0x65, 0x78, //   tmpvar_1 = tex
	0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x20, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x2c, 0x20, 0x76, // ture2D (s_tex, v
	0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x69, // _texcoord0);.  i
	0x66, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x77, 0x20, 0x3c, // f ((tmpvar_1.w <
	0x20, 0x30, 0x2e, 0x30, 0x30, 0x33, 0x39, 0x32, 0x31, 0x35, 0x36, 0x39, 0x29, 0x29, 0x20, 0x7b, //  0.003921569)) {
	0x0a, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x73, 0x63, 0x61, 0x72, 0x64, 0x3b, 0x0a, 0x20, 0x20, // .    discard;.  
	0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, // };.  gl_FragColo
	0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, 0x0a, // r = tmpvar_1;.}.
	0x0a, 0x00,                                                                                     // ..
};
static const uint8_t fs_model_spv[854] =
{
	0x46, 0x53, 0x48, 0x0b, 0x13, 0x17, 0xa9, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73, // FSH....l.......s
	0x5f, 0x74, 0x65, 0x78, 0x30, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x22, 0x00, 0x30, 0x03, // _tex0.......".0.
	0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x0b, 0x00, 0x08, 0x00, 0xab, 0x00, // ....#...........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, // ................
	0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34, // ......GLSL.std.4
	0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, // 50..............
	0x00, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, // ..............ma
	0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x10, 0x00, // in....a...s.....
	0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, // ................
	0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, // ..............ma
	0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00, 0x26, 0x00, 0x00, 0x00, 0x73, 0x5f, // in........&...s_
	0x74, 0x65, 0x78, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, // texSampler......
	0x06, 0x00, 0x29, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x54, 0x65, 0x78, 0x74, 0x75, // ..)...s_texTextu
	0x72, 0x65, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x61, 0x00, 0x00, 0x00, 0x76, 0x5f, // re........a...v_
	0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x00, 0x05, 0x00, 0x06, 0x00, 0x73, 0x00, // texcoord0.....s.
	0x00, 0x00, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, // ..bgfx_FragData0
	0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, // ..G...&...".....
	0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x12, 0x00, // ..G...&...!.....
	0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x29, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, // ..G...)...".....
	0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x29, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x02, 0x00, // ..G...)...!.....
	0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x61, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, // ..G...a.........
	0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x73, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, // ..G...s.........
	0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x03, 0x00, // ..........!.....
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x02, 0x00, 0x06, 0x00, 0x00, 0x00, 0x16, 0x00, // ................
	0x03, 0x00, 0x07, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x19, 0x00, 0x09, 0x00, 0x08, 0x00, // ...... .........
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, // ................
	0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x17, 0x00, // ................
	0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x00, // .............. .
	0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x3b, 0x00, // ..%...........;.
	0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, // ..%...&....... .
	0x04, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x3b, 0x00, // ..(...........;.
	0x04, 0x00, 0x28, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, // ..(...).........
	0x03, 0x00, 0x35, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x07, 0x00, // ..5.......+.....
	0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x81, 0x80, 0x80, 0x3b, 0x14, 0x00, 0x02, 0x00, 0x51, 0x00, // ..P......;....Q.
	0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x60, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, // .. ...`.........
	0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x60, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0x01, 0x00, // ..;...`...a.....
	0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x72, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0d, 0x00, // .. ...r.........
	0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x72, 0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x03, 0x00, // ..;...r...s.....
	0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, // ..6.............
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x05, 0x00, 0x00, 0x00, 0x3d, 0x00, // ..............=.
	0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x3d, 0x00, // ......'...&...=.
	0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x3d, 0x00, // ......*...)...=.
	0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0x56, 0x00, // ......b...a...V.
	0x05, 0x00, 0x35, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x27, 0x00, // ..5.......*...'.
	0x00, 0x00, 0x57, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xaa, 0x00, 0x00, 0x00, 0xa8, 0x00, // ..W.............
	0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x95, 0x00, // ..b...Q.........
	0x00, 0x00, 0xaa, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x05, 0x00, 0x51, 0x00, // ..............Q.
	0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0xf7, 0x00, // ..........P.....
	0x03, 0x00, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x04, 0x00, 0x96, 0x00, // ................
	0x00, 0x00, 0x97, 0x00, 0x00, 0x00, 0x98, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x97, 0x00, // ................
	0x00, 0x00, 0xfc, 0x00, 0x01, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x98, 0x00, 0x00, 0x00, 0x3e, 0x00, // ..............>.
	0x03, 0x00, 0x73, 0x00, 0x00, 0x00, 0xaa, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, // ..s...........8.
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00,                                                             // ......
};
static const uint8_t fs_model_mtl[674] =
{
	0x46, 0x53, 0x48, 0x0b, 0x13, 0x17, 0xa9, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x0c, 0x73, // FSH....l.......s
	0x5f, 0x74, 0x65, 0x78, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x11, 0x01, 0xff, 0xff, 0x01, // _texSampler.....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x54, 0x65, 0x78, 0x74, 0x75, // ......s_texTextu
	0x72, 0x65, 0x11, 0x01, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x73, 0x5f, 0x74, // re...........s_t
	0x65, 0x78, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4e, 0x02, 0x00, 0x00, // ex..........N...
	0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, // #include <metal_
	0x73, 0x74, 0x64, 0x6c, 0x69, 0x62, 0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, // stdlib>.#include
	0x20, 0x3c, 0x73, 0x69, 0x6d, 0x64, 0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, 0x0a, 0x0a, //  <simd/simd.h>..
	0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, 0x65, 0x20, // using namespace 
	0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, // metal;..struct x
	0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x0a, 0x7b, // latMtlMain_out.{
	0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x62, 0x67, 0x66, 0x78, // .    float4 bgfx
	0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x20, 0x5b, 0x5b, 0x63, 0x6f, 0x6c, // _FragData0 [[col
	0x6f, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, // or(0)]];.};..str
	0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, // uct xlatMtlMain_
	0x69, 0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, // in.{.    float2 
	0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, // v_texcoord0 [[us
	0x65, 0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, // er(locn1)]];.};.
	0x0a, 0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, // .fragment xlatMt
	0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, // lMain_out xlatMt
	0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x28, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, // lMain(xlatMtlMai
	0x6e, 0x5f, 0x69, 0x6e, 0x20, 0x69, 0x6e, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, // n_in in [[stage_
	0x69, 0x6e, 0x5d, 0x5d, 0x2c, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x64, 0x3c, // in]], texture2d<
	0x66, 0x6c, 0x6f, 0x61, 0x74, 0x3e, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x20, 0x5b, 0x5b, 0x74, // float> s_tex [[t
	0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x2c, 0x20, 0x73, 0x61, 0x6d, // exture(0)]], sam
	0x70, 0x6c, 0x65, 0x72, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, // pler s_texSample
	0x72, 0x20, 0x5b, 0x5b, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, // r [[sampler(0)]]
	0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, // ).{.    xlatMtlM
	0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d, 0x20, 0x7b, 0x7d, // ain_out out = {}
	0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x5f, 0x31, 0x36, // ;.    float4 _16
	0x37, 0x20, 0x3d, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x2e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, // 7 = s_tex.sample
	0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x2c, 0x20, 0x69, // (s_texSampler, i
	0x6e, 0x2e, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, 0x3b, 0x0a, // n.v_texcoord0);.
	0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x5f, 0x31, 0x36, 0x37, 0x2e, 0x77, 0x20, 0x3c, //     if (_167.w <
	0x20, 0x30, 0x2e, 0x30, 0x30, 0x33, 0x39, 0x32, 0x31, 0x35, 0x36, 0x38, 0x38, 0x35, 0x39, 0x33, //  0.0039215688593
	0x36, 0x38, 0x35, 0x36, 0x32, 0x36, 0x39, 0x38, 0x33, 0x36, 0x34, 0x32, 0x35, 0x37, 0x38, 0x31, // 6856269836425781
	0x32, 0x35, 0x29, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, // 25).    {.      
	0x20, 0x20, 0x64, 0x69, 0x73, 0x63, 0x61, 0x72, 0x64, 0x5f, 0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, //   discard_fragme
	0x6e, 0x74, 0x28, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x0a, 0x20, 0x20, 0x20, 0x20, // nt();.    }.    
	0x6f, 0x75, 0x74, 0x2e, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, // out.bgfx_FragDat
	0x61, 0x30, 0x20, 0x3d, 0x20, 0x5f, 0x31, 0x36, 0x37, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, // a0 = _167;.    r
	0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00, 0x00, // eturn out;.}....
	0x20, 0x00,                                                                                     //  .
};
extern const uint8_t* fs_model_pssl;
extern const uint32_t fs_model_pssl_size;
