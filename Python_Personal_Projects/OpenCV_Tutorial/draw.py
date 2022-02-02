import numpy as np
import cv2 as cv

 

# Draw on Image
def drawRectangle():
    blank = np.zeros((500,500,3), dtype='uint8')
    print(blank.shape)
    cv.rectangle(blank, (0,0), (blank.shape[1] // 2, blank.shape[0] // 2), (0,255,0), thickness=cv.FILLED)
    cv.imshow('Rectangle', blank)
    cv.waitKey(0)

def drawCircle():
    blank = np.zeros((500,500,3), dtype='uint8')
    cv.circle(blank, (blank.shape[0] // 2, blank.shape[1] // 2), 40, (0,0,255), thickness=3)
    cv.imshow("Circle", blank)
    cv.waitKey(0)

def drawLine():
    blank = np.zeros((500,500,3), dtype='uint8')
    cv.line(blank, (100,250), (blank.shape[0] // 3, blank.shape[1] // 4), (255,255,255), thickness=3)
    cv.imshow("Line", blank)
    cv.waitKey(0)

def writeOnImage():
    blank = np.zeros((1000,1000,3), dtype='uint8')
    cv.putText(blank, "Tesla to The Fucking Moon", (250,500), cv.FONT_HERSHEY_TRIPLEX, 1.0, (0,255,0), thickness=1)
    cv.imshow("Tesla", blank)
    cv.waitKey(0)
# drawRectangle()
# drawCircle()
# drawLine()
# writeOnImage()