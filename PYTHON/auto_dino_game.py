import pyautogui
from PIL import Image,ImageGrab
import time

def hit(key):
	pyautogui.keyDown(key)

def isCollide(data):
	#for birds
	for i in range(480,530):
		for j in range(110,195):
			if data[i,j] < 100:
				hit("down")
				return True

	#for cactus
	for i in range(480,530):
		for j in range(197,245):
			if data[i,j] < 100:
				hit("up")
				return True
	return False

if __name__ == '__main__':
	print("Hey DinoGame is start in 3 sec")
	time.sleep(2)

	while True:
		image = ImageGrab.grab().convert('L')
		data = image.load()
		isCollide(data)
