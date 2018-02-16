{
  "targets": [
    {
      "target_name": "sbinlignum",
      "sources": [ "main.cpp", "include/bst.cpp" ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      "xcode_settings": {
	      'OTHER_CFLAGS': [ '-fexceptions' ]
      }
    }
  ]
}
