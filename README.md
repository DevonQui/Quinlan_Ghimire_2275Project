# Quinlan_Ghimire_2275Project

Project goal:
To compare the runtimes between two datastructures: BST and Trie by adding all the words in the dictionary to each and removing each node one by one
____
Assignment overview:
Each data structure is made up of nodes that are structs with a word in them. 
The BST is ordered by length then alphabetical order.
The Trie just adds all of the words normally.
Each structure also has a remove function that is used for the project in final.cpp
The words that are added through the text file are all the words in the english dictionary without any hyphens and/or numbers
___
How to run:
Have all the files in one folder and compile on command line using g++

g++ final.cpp BST.cpp Trie.cpp -o final

and then run the program on the command line using

./final words_alpha.txt

WARNING: THE PROGRAM CAN TAKE ANYWHERE FROM 5-20 MINS TO RUN COMPLETELY

Trie is currently running extremely quickly (~250 ms). We don't think this is reasonable but the program is working as intended and using other methods for getting runtime gives the same results.
___
Bugs/Issues:
Since the data structures have to insert and remove hundreds of thousands of nodes, your computer will slow down, possibly crash, and the program might not function properly if your computer can not handle the amount of memory usage.

This can be avoided by modifying the text file to have fewer words if needed 
___
Project thesis:
Ryan Quinlan and I(Samyak Ghimire) are going to get a text file with all the words in the dictionary and are gonna use it to compare BST and Trie data structures. Since the words are already ordered in alphabetical order, we will order them by length (if two words are the same length, alphabetical order will take priority) and then put them into the respective structures. Each word is then going to be removed one by one and then runtime analyzed to see which structure is better for searching and removing nodes. 
