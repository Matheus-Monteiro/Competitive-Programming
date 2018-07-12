#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function
from bs4 import BeautifulSoup
import codecs
import os
import requests

def filterProblems(problems1, problems2):
    for key in problems2:
        if key in problems1:
            del problems1[key]
    return problems1

class Extractor(object):
    def __init__(self):
        self.s = requests.session()
        self.lang = ""
        self.folders = []
        self.header = []
        self.tokenFields = "41dcc576d590c4d85784392529146d228d160ebf%3A"
            
    def extractProblems(self, soup, problems):
        itens = soup.find_all('table')[0].find_all('tbody')[0].find_all('tr')
        for tr in itens:
            td = tr.find_all('td')
            if len(td) != 7:
                return 
            else:
                problems[td[1].find('a').text.strip()] = {
                    "id_code": td[0].find('a').text.strip(),
                    "name": td[2].find('a').text.strip(),
                    "language": td[4].text.strip()
                }

    def folderStructure(self):
        if not os.path.exists('./URI-'+self.lang.upper()+'/'):
            os.makedirs('./URI-'+self.lang.upper()+'/')
        for name in self.folders:
            if not os.path.exists('./URI-'+self.lang.upper()+'/'+name):
                os.makedirs('./URI-'+self.lang.upper()+'/'+name)

    def login(self):
        username = input('\n\nLogin e-mail: ')
        password = input('Password: ')
        self.tokenFields = self.getPage("https://www.urionlinejudge.com.br/judge/pt/login").find("input", {"name": "_Token[fields]"}).attrs['value']
        payload_login = {
            '_method': 'POST',
            '_csrfToken': self.s.cookies['csrfToken'],
            'email': username,
            'password': password,
            'remember_me': '0',
            '_Token[fields]': self.tokenFields,
            '_Token[unlocked]': ''
        }

        r = self.s.post("https://www.urionlinejudge.com.br/judge/pt/login", data=payload_login)

        if len(r.history) == 0:
            print("Invalid login. Try Again")
            return False

        self.lang = r.url.split('/')[-1]

        self.email = username
        self.author = self.getPage('https://www.urionlinejudge.com.br/judge/'+self.lang+'/account').find("input", {"name": "username"}).attrs['value']

        if self.lang == 'pt':
            self.folders = ["INICIANTE", "AD-HOC", "STRINGS", "ESTRUTURAS E BIBLIOTECAS", "MATEMÁTICA", "PARADIGMAS", "GRAFOS", "GEOMETRIA COMPUTACIONAL"]
            self.header = [" Autor: "+self.author+ "<"+self.email+">", " Nome: ", " Nível: ", " Categoria: "]
            return ["Login inválido", "\nLogado com sucesso\n", "Estrutura de pastas criada", "Criando lista de download", "Lista de download criada: ", " problemas", "\nBaixando códigos", "\nCódigos baixados com sucesso", "Nome completo: ", "Email de contato: "]
        elif self.lang == 'en':
            self.folders = ["BEGINNER", "AD-HOC", "STRINGS", "DATA STRUCTURES AND LIBRARIES", "MATHEMATICS", "PARADIGMS", "GRAPH", "COMPUTATIONAL GEOMETRY"]
            self.header = [" Author: "+self.author+ "<"+self.email+">", " Name: ", " Level: ", " Category: "]
            return ["Invalid login", "\nSuccessfully logged in\n", "Folder structure created", "Creating download list", "Download list created: ", " problems", "\nDownloading Codes", "\nCodes successfully downloaded", "Full name: ", "Email contact: "]
        elif self.lang == 'es':
            self.folders = ["INICIANTE", "AD-HOC", "STRINGS", "ESTRUTURAS E BIBLIOTECAS", "MATEMÁTICA", "PARADIGMAS", "GRAFOS", "GEOMETRIA COMPUTACIONAL"]
            self.header = [" Autor: "+self.author+ "<"+self.email+">", " Nome: ", " Nível: ", " Categoria: "]
            return ["Login inválido", "\nLogado com sucesso\n", "Estrutura de pastas criada", "Criando lista de download", "Lista de download criada: ", " problemas", "\nBaixando códigos", "\nCódigos baixados com sucesso", "Nome completo: ", "Email de contato: "]


    def getPage(self, url):
        return BeautifulSoup(self.s.get(url).content, 'html.parser')

    def getUriProblems(self):
        qt = int(self.getPage('https://www.urionlinejudge.com.br/judge/'+self.lang+'/runs?answer_id=1').find("div", {"id": "table-info"}).text.split(" ")[6])
        problems = {}
        for i in range(qt, 0, -1):
            self.extractProblems(self.getPage('https://www.urionlinejudge.com.br/judge/'+self.lang+'/runs?answer_id=1&page='+str(i)), problems)
        return problems

    def getLocalProblems(self):
        problems = []
        for path in os.listdir('./URI-'+self.lang.upper()+'/'):
            for arq in os.listdir('./URI-'+self.lang.upper()+'/'+path+'/'):
                problems.append(arq.rsplit('.', 1)[0].split('-')[0].strip())
        return problems

    def infoProblem(self, id):
        menu = self.getPage('https://www.urionlinejudge.com.br/judge/'+self.lang+'/problems/view/'+id).find("div", {"id": "problem-menu"})
        return {
            "level": menu.find("span").text.strip().split(' ', 2)[1],
            "category": menu.find_all("a")[-1].text.strip().upper()
        }

    def getCode(self, id):
        return self.getPage('https://www.urionlinejudge.com.br/judge/'+self.lang+'/runs/code/'+id).find("pre", {"id": "code"}).text

    def cleanName(self, name):
        return name.replace("\\", "").replace("/", "").replace(":", "").replace("?", "").replace("\"", "").replace("<", "").replace(">", "").replace("|", "")

    def downloadCodes(self, problems):
        for id in problems:
            if self.lang == "pt":
                print("\tProblema "+id+" baixado")
            else:
                print("\tProblem "+id+" downloaded")
            info = self.infoProblem(id)
            code = self.getCode(problems[id]["id_code"])
            extension = ""
            comment = "//"
            if problems[id]["language"] == "C++":
                extension = ".cpp"
            elif problems[id]["language"] == "C":
                extension = ".c"
            elif problems[id]["language"] == "Java":
                extension = ".java"
            else:
                extension = ".py"
                comment = "#"

            arq = codecs.open("./URI-"+self.lang.upper()+"/"+info["category"]+"/"+id+" - "+self.cleanName(problems[id]["name"])+extension, "w", "utf-8")
            arq.write(comment+self.header[0]+"\n")
            arq.write(comment+self.header[1]+problems[id]["name"]+"\n")
            arq.write(comment+self.header[2]+info["level"]+"\n")
            arq.write(comment+self.header[3]+info["category"]+"\n")
            arq.write(comment+" URL: https://www.urionlinejudge.com.br/judge/"+self.lang+"/problems/view/"+id+"\n\n")
            arq.write(code)
            arq.write("\n")
            arq.close()