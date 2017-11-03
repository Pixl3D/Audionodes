
import cffi, os

ffi = cffi.FFI()

with open(os.path.join(os.path.dirname(__file__), "native/interface.h"), 'r') as file:
    interface = file.read()
    ffi.cdef(interface)

native = ffi.dlopen(os.path.join(os.path.dirname(__file__), "native.so"))

