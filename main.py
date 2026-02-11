import tkinter
from PIL import Image, ImageTk
import random
root = tkinter.Tk()
root.attributes('-fullscreen', True)
root.attributes('-topmost', True)
root.attributes('-transparentcolor', 'white')
width = root.winfo_screenwidth()
height = root.winfo_screenheight()
canvas = tkinter.Canvas(root, width=width, height=height, bg='white', highlightthickness=0)
canvas.pack()
img = Image.open('spider.png')
img = img.resize((150, 150))
spider_img = ImageTk.PhotoImage(img)
spider = canvas.create_image(width//2, height//2, image=spider_img)
def add_spider(count=0):
    if count < 500:
        x = random.randint(0, width)
        y = random.randint(0, height)
        canvas.create_image(x, y, image=spider_img)
        root.after(500, add_spider, count + 1)

add_spider()

root.mainloop()
