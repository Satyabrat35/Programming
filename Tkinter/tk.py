# Paint using Tkinter
height = 500
width = 300
def paint(event):
	color_fill = "#556699"
	x1,y1 = (event.x - 1),(event.y - 1)
	x2,y2 = (event.x + 1),(event.y + 1)
	w.create_oval(x1,y1,x2,y2, fill = color_fill)

master = tk.Tk()
w = tk.Canvas(master, width=width,height=height)
w.pack(expand=tk.YES, fill=tk.BOTH)
w.bind("<B1-Motion>", paint)

message = tk.Label(master, text="Drag to draw")
message.pack(side=tk.BOTTOM)

master.mainloop()