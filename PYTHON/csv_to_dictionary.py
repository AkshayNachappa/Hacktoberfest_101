#!/usr/bin/env python
                                                       
#/- Simple Script to convert a CSV to a Python Dictionary

#/- importing the "csv" module to work with it
import csv

def csvtodict(csvfile):

	#/- 'csvfile' is a string containing the filepath
	#/- alongwith the filename

   with open(csvfile, "r") as a_csv_file:

   	#/- reading the CSV file into a dictionary using
   	#/- the CSV module

    dict_reader = csv.DictReader(a_csv_file)

    #/- creating an empty list

    mainlist=[]

    for i in list(dict_reader):

    	#/- converting the format of the dictionary to such a way that
    	#/- each row would be a dictionary with the top row as header
    	#/- row

        mainlist.append(dict(i))

    #/- returning the final list of dictionaries for further use in-program
    return mainlist

#/- to run this script, uncomment and run
# csvtodict("csvfile.csv")
#/- where 'csvfile.csv' is the name of the csv you would like
#/- to see as a python dictionary // JSON Object.

'''
script by Aaditya Rengarajan for Hacktoberfest 2021, timestamp : 16:51:39IST October 21 2021
see GitHub @aadityarengarajan or https://aaditya.intellx.co.in/
'''