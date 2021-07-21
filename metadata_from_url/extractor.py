import os
import ctypes
import json

def metadata(url):
    dll = ctypes.CDLL(os.path.join(os.path.dirname(os.path.realpath(__file__)), "_extractor.so"))
    dll.extract.restype = ctypes.c_char_p
    dll.extract.argtypes = [ctypes.c_char_p]
    result = dll.extract(url.encode('utf-8'))
    # should result be freed ?
    # libc = ctypes.CDLL("libc.so.6") 
    # libc.free(_result)
    dict = json.loads(result.replace('%s'.encode(), ''.encode()))
    if not dict:
        return None
    else:        
        return dict["metadata"]
