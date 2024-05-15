import pyautogui
import time
time.sleep(5)
limit=input("Enter limit: ")
message=input("Enter message: ")
i=0
time.sleep(5)
while i<int(limit):
    pyautogui.typewrite(message)
    pyautogui.press("Enter")
    i+=1
