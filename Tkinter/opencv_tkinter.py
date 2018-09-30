import tkinter as tk
import cv2 
import PIL.Image, PIL.ImageTk
import time


root = tk.Tk()

class MyVideoCapture:
    def __init__(self,video_source=0):
        self.vid = cv2.VideoCapture(video_source)
        if not self.vid.isOpened:
            raise ValueError("Unable to open", video_source)
        
        self.width = self.vid.get(cv2.CAP_PROP_FRAME_WIDTH)
        self.height = self.vid.get(cv2.CAP_PROP_FRAME_HEIGHT)

    def __del__(self):
        if self.vid.isOpened:
            self.vid.release
        #self.root.mainloop()

    def get_frame(self):
        if self.vid.isOpened():
            ret, frame = self.vid.read()
            if ret:
                return (ret, cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
            else:
                return (ret, None)
        else:
            return (ret, None)

class App:
    def __init__(self,root,window_title,video_source=0):
        self.root=root
        self.root.title(window_title)
        self.video_source=video_source

        self.vid = MyVideoCapture(video_source)

        self.canvas = tk.Canvas(root, width=self.vid.width, height=self.vid.height)
        self.canvas.pack()

        self.snap = tk.Button(root, text="Snap", width=50, command=self.snapshot)
        self.snap.pack(anchor=tk.CENTER)
        self.quit = tk.Button(root, text="Quit", width=35, command=root.quit)
        self.quit.pack(anchor=tk.CENTER)

        self.delay = 15
        self.update()

        self.root.mainloop()

    def snapshot(self):
        ret, frame = self.vid.get_frame()
        if ret:
            cv2.imwrite("Frame-" + time.strftime("%d-%m-%Y-%H-%M-%S") + ".jpg", cv2.cvtColor(frame, cv2.COLOR_RGB2BGR))
        
    def update(self):
        ret, frame = self.vid.get_frame()
        if ret:
            self.photo = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
            self.canvas.create_image(0,0, image=self.photo, anchor=tk.NW)
        
        self.root.after(self.delay, self.update)


App(root,"Tkinter and OpenCV")

