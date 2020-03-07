import ctypes


def hostid_py():
    hostid_lib = ctypes.CDLL("libhostid.so")

    hostid = hostid_lib.hostid

    hostid()


hostid_py()
