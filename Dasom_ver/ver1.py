# -*- coding: utf-8 -*-
"""
Created on Fri Feb 21 03:34:56 2020

@author: DASOM
"""

import operator
import math

class Library:
    def __init__(self,lib_idx,max_ship,book_num,signup_days,books):
        self.idx=lib_idx;
        self.max_ship=max_ship
        self.book_num=book_num
        self.signup_days=signup_days
        self.books=sorted(books,key=operator.attrgetter('score'))
        self.books.reverse()
        self.scanning_days=math.ceil(book_num/max_ship)
        
        temp=0
        for book in books:
            temp+=book.score
        
        self.total_book_score=temp
        self.lib_score=self.total_book_score/(self.signup_days*self.scanning_days)

class Book:
    def __init__(self,idx,score):
        self.idx=idx
        self.score=score
  

f = open("e_so_many_books.txt", 'r')

# task 정보
inpt = list(map(int,f.readline().split()))
#print(inpt)

book_num=inpt[0]
lib_num=inpt[1]
given_days=inpt[2]


# book score
book_scores=list(map(int,f.readline().split()))
#print(book_scores)

book_list=[]
for idx,score in enumerate(book_scores):
    book_list.append(int(score))
    



lib_list=[]
# lib info
for lib in range(lib_num):
    
    book_num,signup_days,max_ship=list(map(int,f.readline().split()))
    books_info=list(map(int,f.readline().split()))
    
    books=[]
    for book_idx in books_info:
        books.append(Book(book_idx,book_list[book_idx]))
    
    
    lib_list.append(Library(lib,max_ship,book_num,signup_days,books))

    
f.close()

lib_list=sorted(lib_list,key=operator.attrgetter('lib_score'))
lib_list.reverse()


    
count_lib=0
temp=given_days
for lib in lib_list:
    if(temp>lib.signup_days):
        temp-=lib.signup_days;
        count_lib+=1;
    else:
        break;





left_days=given_days

file = open('output_e.txt','w')

file.write(str(count_lib)+"\n");
print(count_lib)



for lib in lib_list:

    left_days-=lib.signup_days;
    if left_days<=0:
        break;
    #total_max_ship=left_days*lib.max_ship
    scan_num=min(left_days*lib.max_ship,lib.book_num)
    file.write(str(lib.idx)+" "+str(scan_num)+'\n')
    print("print lib info")
    print(str(lib.idx)+" "+str(scan_num))
    book_order=""
    for i in range(scan_num):
        book_order+=str(lib.books[i].idx)+" "
        
    file.write(book_order+"\n")
    print("print book order")
    print(book_order)
    

        
    

file.close()
    

    


