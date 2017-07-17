import os 
import sys
import uuid 
from PIL import image 
import PIL.image

def handler(event):
	if event['thumbnail']:
		#path at which image is situated
		image_path='/xx/xx/xx'
		#path at which resized image(thumbnail) will be stored. 
		resized_path='/xx/xx/xx'
		with Image.open(image_path) as image:
			image.thumbnail(tuple(x/2 for x in image.size))
			image.save(resized_path)
	else:
		print('Sorry! No thumbnail found!')

