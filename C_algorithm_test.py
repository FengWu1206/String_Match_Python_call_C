#!/usr/bin/env python
import os
import re
import time
import ctypes


def get_vulnerability_files(vulnerability_dir):
    vulnerability_files = os.listdir(vulnerability_dir)
    i = 0
    vulnerability_feature_all = []
    bad_char = '\n\t\r\x0a\x0d\x20'
    for file in vulnerability_files:
        i += 1
        feature = []
        with open(os.path.join(vulnerability_dir, file), 'rb') as file_read:
            lines = [line.strip().decode('utf-8', errors='ignore').translate(str.maketrans("", "", bad_char)) for line
                     in file_read]
            vulnerability_feature_all.append([re.sub(r'[^\x01-\x7F]', ' ', "".join(lines)), file])
            # print("".join(lines))
    return vulnerability_feature_all


def get_consumer_files(source_dir):
    consumer_files = os.listdir(source_dir)
    source_code_order = []
    bad_char = '\n\t\r\x0a\x0d\x20'
    for file in consumer_files:
        source_code = os.walk(os.path.join(source_dir, file))
        source_files = []
        for path, d, filelist in source_code:
            for filename in filelist:
                source_files.append(os.path.join(path, filename))
        source_code_order.append(source_files)

    source_feature_all = []
    for file in source_code_order[2]:
        source_feature = []
        with open(file, 'rb') as file_read:
            lines = [line.strip().decode('utf-8', errors='ignore').translate(str.maketrans("", "", bad_char)) for line
                     in
                     file_read]
            source_feature_all.append([re.sub(r'[^\x01-\x7F]', ' ', "".join(lines)), file])
    # print(source_feature_all)
    return source_feature_all, source_code_order[2]


ssef = ctypes.cdll.LoadLibrary("/home/wufeng/CLionProjects/ssef/ssef.so")
ssef.search.argtypes = (ctypes.c_char_p, ctypes.c_char_p)
class struct_result(ctypes.Structure):
    _fields_ = [
        ("match", ctypes.c_int),
        ("number", ctypes.c_int),
    ]
ssef.search.restype = ctypes.POINTER(struct_result)
vulnerability_dir = '/home/wufeng/data/vul'
source_dir = '/home/wufeng/data/consumer'
vul_feature = get_vulnerability_files(vulnerability_dir)
source_features, project_dir = get_consumer_files(source_dir)
start_time = time.time()
for source in source_features:
    for vul in vul_feature:
        # patt = vul[0]
        # text = source[0]
        # patt_len = len(patt)
        # text_len = len(text)
        #print(vul[1])
        #print(source[1])
        # print(patt)
        # print(patt_len)
        patt = ctypes.create_string_buffer(vul[0].encode('ascii', 'ignore'))
        text = ctypes.create_string_buffer(source[0].encode('ascii', 'ignore'))
        patt_len = ctypes.c_int(len(vul[0]))
        text_len = ctypes.c_int(len(source[0]))
        #count = str.search(patt, text)
        count = ssef.search(patt, text)
        if count.contents.match != 0:
            print("*******************************result of ssef:%s" % str(count.contents.number) + "  source file : %s" % (
                source[1]) + "  vul file: %s" % (vul[1]))
    # print(text)
    # print(patt)
    # print(text)

print(time.time() - start_time)
