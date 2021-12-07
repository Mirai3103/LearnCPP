import os
import sys
import pyttsx3
import time
def tounicode(a):
	a = a.replace("mot", "một")
	a = a.replace("khong", "không")
	a = a.replace("hai", "hai")
	a = a.replace("bon", "bốn")
	a = a.replace("nam", "năm")
	a = a.replace("sau", "sáu")
	a = a.replace("bay", "bảy")
	a = a.replace("tam", "tám")
	a = a.replace("chin", "chín")
	
	return a
def speak(a):
	a = a.replace("speak.py", "")
	print(a)
	a = tounicode(a)
	engine = pyttsx3.init()
	engine.setProperty('voice', "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\MSTTS_V110_viVN_An")                       #printing current voice rate
	engine.setProperty('rate', 100)
	engine.say(a)

	engine.runAndWait()


if __name__ == "__main__":
	a = ' '.join(map(str, sys.argv))
	os.system("clear")
	speak(a)