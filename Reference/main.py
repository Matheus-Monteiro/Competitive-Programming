#!/usr/bin/env python
# -*- coding: utf-8 -*-
from functions import *

extractor = Extractor()

message = extractor.login()
while message == False:
    message = extractor.login()

print(message[1])

extractor.folderStructure()
print(message[2])

print(message[3])
download_list = filterProblems(extractor.getUriProblems(), extractor.getLocalProblems())
print(message[4]+str(len(download_list))+message[5])

print(message[6])
extractor.downloadCodes(download_list)
print(message[7])