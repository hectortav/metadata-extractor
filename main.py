import ctypes
import json

def metadata(url):
    dll = ctypes.CDLL("./extractor.so")
    dll.extract.restype = ctypes.c_char_p
    dll.extract.argtypes = [ctypes.c_char_p]
    result = dll.extract(url)
    # should result be freed ?
    # libc = ctypes.CDLL("libc.so.6") 
    # libc.free(_result)
    dict = json.loads(result.replace('%s', ''))
    return dict["metadata"]

meta = metadata('https://interestingengineering.com/canada-is-banning-internal-combustion-engines-but-what-about-the-cold')
print(meta["twitter:image"])